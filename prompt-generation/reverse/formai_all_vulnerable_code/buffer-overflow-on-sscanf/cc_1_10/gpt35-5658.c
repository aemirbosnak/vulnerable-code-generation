//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char filename[256], command[256];
    FILE *file;

    if (argc < 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    while (1) {
        printf("ftp> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcasecmp(command, "quit") == 0) {
            break;
        } else if (sscanf(command, "get %s", filename) == 1) {
            sprintf(buffer, "RETR %s\r\n", filename);
            n = write(sockfd, buffer, strlen(buffer));
            if (n < 0) {
                error("ERROR writing to socket");
            }

            memset(buffer, 0, sizeof(buffer));
            n = read(sockfd, buffer, sizeof(buffer) - 1);
            if (n < 0) {
                error("ERROR reading from socket");
            }

            if (strstr(buffer, "550") != NULL) {
                printf("File not found\n");
            } else {
                file = fopen(filename, "wb");
                while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
                    fwrite(buffer, 1, n, file);
                }
                fclose(file);
                printf("File received successfully\n");
            }
        } else {
            printf("Invalid command\n");
        }
    }

    close(sockfd);
    return 0;
}