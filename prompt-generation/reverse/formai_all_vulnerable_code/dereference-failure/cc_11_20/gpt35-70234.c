//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 4096

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    ssize_t n;
    pid_t pid;

    if (argc != 2) {
        printf("usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind error");
        exit(1);
    }

    if (listen(listenfd, 10) == -1) {
        perror("listen error");
        exit(1);
    }

    printf("HTTP Proxy server started on port %d...\n", atoi(argv[1]));

    while (1) {
        if ((connfd = accept(listenfd, (struct sockaddr *)NULL, NULL)) == -1) {
            perror("accept error");
            continue;
        }

        if ((pid = fork()) == -1) {
            perror("fork error");
        } else if (pid == 0) {
            close(listenfd);

            memset(buff, 0, MAXLINE);
            n = read(connfd, buff, MAXLINE);
            if (n == -1) {
                perror("read error");
                exit(1);
            } else if (n == 0) {
                printf("Connection closed by client.\n");
                close(connfd);
                exit(0);
            }

            printf("Received request from client:\n%s\n", buff);

            // Parse the HTTP request
            char method[10], url[MAXLINE], version[10];
            sscanf(buff, "%s %s %s", method, url, version);

            // Check if the request is GET
            if (strcmp(method, "GET") == 0) {
                printf("GET request received for %s\n", url);

                // Create a new socket to connect to the server
                int sockfd = socket(AF_INET, SOCK_STREAM, 0);

                char *host = strtok(url, "/");
                char *path = strtok(NULL, "");

                struct sockaddr_in servaddr2;
                memset(&servaddr2, 0, sizeof(servaddr2));
                servaddr2.sin_family = AF_INET;
                servaddr2.sin_port = htons(80);
                inet_pton(AF_INET, host, &servaddr2.sin_addr);

                if (connect(sockfd, (struct sockaddr *)&servaddr2, sizeof(servaddr2)) == -1) {
                    perror("connect error");
                    close(connfd);
                    exit(1);
                }

                printf("Connected to server for %s\n", url);

                char get_request[MAXLINE];
                snprintf(get_request, sizeof(get_request), "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);

                // Send the GET request to the server
                if (write(sockfd, get_request, strlen(get_request)) == -1) {
                    perror("write error");
                    close(sockfd);
                    close(connfd);
                    exit(1);
                }

                printf("Sent GET request to server:\n%s\n", get_request);

                char response[MAXLINE];
                memset(response, 0, MAXLINE);

                // Receive the response from the server
                while ((n = read(sockfd, response, MAXLINE)) > 0) {
                    printf("Received %ld bytes from server.\n", n);

                    // Send the response to the client
                    if (write(connfd, response, n) == -1) {
                        perror("write error");
                        close(sockfd);
                        close(connfd);
                        exit(1);
                    }

                    memset(response, 0, MAXLINE);
                }

                if (n == -1) {
                    perror("read error");
                    close(sockfd);
                    close(connfd);
                    exit(1);
                }

                printf("Connection with server closed.\n");
                close(sockfd);
            }

            close(connfd);
            exit(0);
        }

        close(connfd);
    }

    return 0;
}