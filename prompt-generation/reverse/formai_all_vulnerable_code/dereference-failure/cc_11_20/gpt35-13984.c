//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER], command[MAX_BUFFER], filename[MAX_BUFFER], response[MAX_BUFFER];
    int port, data_socket;
    struct hostent *he;
    struct sockaddr_in server, data_server;
    int control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (control_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[2]);
    he = gethostbyname(argv[1]);
    if (he == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }

    memcpy(&server.sin_addr, he->h_addr, he->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(control_socket, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connection established\n");

    while (1) {
        printf("ftp> ");
        fgets(buffer, MAX_BUFFER, stdin);

        if (strlen(buffer) == 0 || strcmp(buffer, "\n") == 0) {
            continue;
        }

        sscanf(buffer, "%s %s", command, filename);

        if (strcmp(command, "quit") == 0) {
            send(control_socket, "QUIT\r\n", 6, 0);
            recv(control_socket, response, MAX_BUFFER, 0);
            printf("%s", response);
            break;

        } else if (strcmp(command, "get") == 0) {
            sprintf(buffer, "RETR %s\r\n", filename);
            send(control_socket, buffer, strlen(buffer), 0);
            recv(control_socket, response, MAX_BUFFER, 0);
            printf("%s", response);

            if (strstr(response, "150") != NULL) {
                int filesize = 0;
                FILE *fp = fopen(filename, "wb");
                data_socket = socket(AF_INET, SOCK_STREAM, 0);

                data_server.sin_family = AF_INET;
                data_server.sin_port = htons(20);

                memcpy(&data_server.sin_addr, &server.sin_addr, sizeof(struct in_addr));

                if (connect(data_socket, (struct sockaddr *) &data_server, sizeof(data_server)) == -1) {
                    perror("Error connecting to data socket");
                    exit(1);
                }

                while (1) {
                    int bytes_read = recv(data_socket, buffer, MAX_BUFFER, 0);

                    if (bytes_read == 0) {
                        break;
                    }

                    fwrite(buffer, sizeof(char), bytes_read, fp);
                    filesize += bytes_read;
                }

                fclose(fp);

                close(data_socket);
                memset(buffer, 0, MAX_BUFFER);
                recv(control_socket, buffer, MAX_BUFFER, 0);
                printf("%s", buffer);
            }

        } else if (strcmp(command, "ls") == 0) {
            sprintf(buffer, "LIST\r\n");
            send(control_socket, buffer, strlen(buffer), 0);
            recv(control_socket, response, MAX_BUFFER, 0);
            printf("%s", response);

            if (strstr(response, "150") != NULL) {
                data_socket = socket(AF_INET, SOCK_STREAM, 0);
                data_server.sin_family = AF_INET;
                data_server.sin_port = htons(20);
                memcpy(&data_server.sin_addr, &server.sin_addr, sizeof(struct in_addr));

                if (connect(data_socket, (struct sockaddr *) &data_server, sizeof(data_server)) == -1) {
                    perror("Error connecting to data socket");
                    exit(1);
                }

                while (1) {
                    int bytes_read = recv(data_socket, buffer, MAX_BUFFER, 0);

                    if (bytes_read == 0) {
                        break;
                    }

                    printf("%s", buffer);
                }

                close(data_socket);
                memset(buffer, 0, MAX_BUFFER);
                recv(control_socket, buffer, MAX_BUFFER, 0);
                printf("%s", buffer);
            }

        } else {
            printf("Invalid command\n");
        }
    }

    close(control_socket);
    return 0;
}