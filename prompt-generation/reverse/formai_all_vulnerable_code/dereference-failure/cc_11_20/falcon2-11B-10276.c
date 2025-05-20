//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PORT 8080
#define MAX_BUF 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[MAX_BUF];
    char *method;
    char *path;
    char *version;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_port = 0;
        cli_addr.sin_addr.s_addr = INADDR_ANY;

        portno = htons(PORT);
        n = sizeof(cli_addr);

        if ((sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        bzero(buffer, MAX_BUF);

        n = recv(sockfd, buffer, MAX_BUF, 0);
        if (n < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        if (buffer[0] == 'G') {
            method = strtok(buffer, " ");
            path = strtok(NULL, " ");
            version = strtok(NULL, " ");
        } else {
            method = strtok(buffer, " ");
            version = strtok(NULL, " ");
            path = strtok(NULL, " ");
        }

        if (strcmp(method, "GET") == 0) {
            if (strcmp(path, "/") == 0) {
                if (strcmp(version, "HTTP/1.1") == 0) {
                    sprintf(buffer, "HTTP/1.1 200 OK\r\n"
                        "Server: MyServer\r\n"
                        "Content-Type: text/html\r\n"
                        "Content-Length: %d\r\n\r\n"
                        "<html><head><title>Hello World!</title></head>"
                        "<body><h1>Hello World!</h1></body></html>", strlen("Hello World!"));
                    send(sockfd, buffer, strlen(buffer), 0);
                } else {
                    sprintf(buffer, "HTTP/1.1 404 Not Found\r\n"
                        "Server: MyServer\r\n"
                        "Content-Type: text/html\r\n"
                        "Content-Length: %d\r\n\r\n"
                        "<html><head><title>404 Not Found</title></head>"
                        "<body><h1>404 Not Found</h1></body></html>", strlen("404 Not Found"));
                    send(sockfd, buffer, strlen(buffer), 0);
                }
            } else {
                sprintf(buffer, "HTTP/1.1 404 Not Found\r\n"
                    "Server: MyServer\r\n"
                    "Content-Type: text/html\r\n"
                    "Content-Length: %d\r\n\r\n"
                    "<html><head><title>404 Not Found</title></head>"
                    "<body><h1>404 Not Found</h1></body></html>", strlen("404 Not Found"));
                send(sockfd, buffer, strlen(buffer), 0);
            }
        } else {
            sprintf(buffer, "HTTP/1.1 405 Method Not Allowed\r\n"
                "Server: MyServer\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: %d\r\n\r\n"
                "<html><head><title>405 Method Not Allowed</title></head>"
                "<body><h1>405 Method Not Allowed</h1></body></html>", strlen("405 Method Not Allowed"));
            send(sockfd, buffer, strlen(buffer), 0);
        }

        close(sockfd);
    }
}