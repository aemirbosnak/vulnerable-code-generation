//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096
 
int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    char *server_ip;
    char *server_port;
    char buffer[MAX_BUFFER_SIZE];

    if (argc != 3) {
        printf("Usage: ./ftpclient <server IP address> <server port>\n");
        exit(1);
    } else {
        server_ip = argv[1];
        server_port = argv[2];
    }

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        printf("Error creating client socket\n");
        exit(1);
    }

    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(server_port));

    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        printf("Error converting IP address to binary format\n");
        exit(1);
    }

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("--- FTP Client connected to server ---\n\n");

    while (1) {
        printf("ftpclient> ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        if (strlen(buffer) == 0 || strcmp(buffer, "\n") == 0) {
            continue;
        }

        buffer[strlen(buffer) - 1] = '\0';

        char *token = strtok(buffer, " ");
        char command[strlen(token)];
        strcpy(command, token);

        if (strcmp(command, "ls") == 0) {
            send(client_socket, "ls", 2, 0);

            int bytes_received;
            while ((bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
                buffer[bytes_received] = '\0';
                printf("%s", buffer);
            }

            printf("\n");
        } else if (strcmp(command, "get") == 0) {
            token = strtok(NULL, " ");
            char filename[strlen(token)];
            strcpy(filename, token);

            char message[strlen(command) + strlen(filename) + 2];
            sprintf(message, "%s %s", command, filename);

            send(client_socket, message, strlen(message), 0);

            int bytes_received;
            FILE *file = fopen(filename, "w");

            while ((bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
                fwrite(buffer, 1, bytes_received, file);

                if (bytes_received < MAX_BUFFER_SIZE - 1) {
                    break;
                }
            }

            fclose(file);

            printf("File %s downloaded successfully\n\n", filename);
        } else if (strcmp(command, "exit") == 0) {
            send(client_socket, "exit", 4, 0);
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    printf("FTP Client disconnected from server\n");

    close(client_socket);

    return 0;
}