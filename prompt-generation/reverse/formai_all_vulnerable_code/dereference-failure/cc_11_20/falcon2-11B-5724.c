//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_LINE 4096
#define MAX_CONN 10

int main(int argc, char *argv[]) {
    int server_socket, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE], *line, *line2;
    char message[MAX_LINE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket error");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(server_socket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind error");
        exit(1);
    }

    if (listen(server_socket, MAX_CONN) < 0) {
        perror("listen error");
        exit(1);
    }

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(server_socket, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept error");
            exit(1);
        }

        printf("Connection from %s\n", inet_ntoa(cli_addr.sin_addr));

        while (1) {
            bzero(buffer, MAX_LINE);
            line = fgets(buffer, MAX_LINE, stdin);
            if (line == NULL) {
                break;
            }

            if (strncmp(buffer, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n")) == 0) {
                strcpy(message, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>\r\n");
                line = fgets(buffer, MAX_LINE, stdin);
                if (line == NULL) {
                    break;
                }
                strcat(message, buffer);
                strcat(message, "\r\n\r\n");
                line = fgets(buffer, MAX_LINE, stdin);
                if (line == NULL) {
                    break;
                }
                strcat(message, buffer);
                strcat(message, "\r\n\r\n");
                line = fgets(buffer, MAX_LINE, stdin);
                if (line == NULL) {
                    break;
                }
                strcat(message, buffer);
            } else {
                strcpy(message, "HTTP/1.0 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>\r\n");
            }

            if (send(newsockfd, message, strlen(message), 0) < 0) {
                perror("send error");
                exit(1);
            }

            printf("Sent %d bytes: %s\n", strlen(message), message);

            if (strcmp(buffer, "quit\r\n") == 0) {
                break;
            }
        }

        close(newsockfd);
    }

    return 0;
}