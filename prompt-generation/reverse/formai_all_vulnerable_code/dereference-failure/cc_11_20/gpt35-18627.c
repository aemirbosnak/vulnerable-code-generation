//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

bool startswith(const char *a, const char *b) {
    return strncmp(a, b, strlen(b)) == 0;
}

int main(int argc, char **argv) {
    int server_port, client_fd, server_fd, max_fd;
    fd_set readfd, writefd;
    struct sockaddr_in client_addr, server_addr;
    char buffer[BUFFER_SIZE] = {0};

    if(argc != 2) {
        printf("Usage: %s <port number>\n", argv[0]);
        exit(1);
    }
    server_port = atoi(argv[1]);

    if((server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0) {
        perror("failed to create server socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(server_port);

    if(bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("failed to bind server socket");
        exit(1);
    }

    if(listen(server_fd, 5) < 0) {
        perror("failed to listen on server socket");
        exit(1);
    }

    FD_ZERO(&readfd);
    FD_ZERO(&writefd);
    FD_SET(server_fd, &readfd);
    max_fd = server_fd;

    while(true) {
        fd_set select_readfd = readfd;
        fd_set select_writefd = writefd;
        if(select(max_fd+1, &select_readfd, &select_writefd, NULL, NULL) < 0) {
            perror("select failed");
            exit(1);
        }

        for(fd_set *s = &readfd; s <= &writefd; s++) {
            // skip if the set is not ready
            if(!FD_ISSET(max_fd, s)) {
                continue;
            }

            // server socket is ready for incoming connection
            if(max_fd == server_fd) {
                socklen_t client_addr_size = sizeof(client_addr);
                client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_size);
                if(client_fd < 0) {
                    fprintf(stderr, "failed to accept client connection");
                    continue;
                }

                FD_SET(client_fd, &readfd);
                if(client_fd > max_fd) {
                    max_fd = client_fd;
                }
            }
            // client socket is ready for reading or writing
            else {
                ssize_t n;

                if(FD_ISSET(client_fd, &select_readfd)) {
                    if((n = read(client_fd, buffer, BUFFER_SIZE)) < 0) {
                        perror("failed to read from client socket");
                        close(client_fd);
                        FD_CLR(client_fd, &readfd);
                        continue;
                    }

                    // modify HTTP request
                    if(startswith(buffer, "GET") || startswith(buffer, "POST") || startswith(buffer, "PUT") || startswith(buffer, "DELETE")) {
                        char *p;
                        p = strstr(buffer, "HTTP/1.1");
                        if(p != NULL) {
                            strcpy(p-1, " HTTP/1.0");
                        }
                    }

                    // connect to server
                    if((server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0) {
                        perror("failed to create server socket");
                        exit(1);
                    }

                    memset(&server_addr, 0, sizeof(server_addr));
                    server_addr.sin_family = AF_INET;
                    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
                        perror("failed to convert server IP address");
                        exit(1);
                    }
                    server_addr.sin_port = htons(80);

                    if(connect(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
                        perror("failed to connect to server");
                        exit(1);
                    }

                    FD_SET(server_fd, &writefd);
                    if(server_fd > max_fd) {
                        max_fd = server_fd;
                    }
                }
                else if(FD_ISSET(server_fd, &select_writefd)) {
                    if(write(server_fd, buffer, strlen(buffer)) < 0) {
                        perror("failed to write to server socket");
                        close(server_fd);
                        FD_CLR(server_fd, &writefd);
                        continue;
                    }

                    FD_SET(server_fd, &readfd);
                    FD_CLR(server_fd, &writefd);
                }

                if(FD_ISSET(client_fd, &select_writefd)) {
                    if(write(client_fd, buffer, strlen(buffer)) < 0) {
                        perror("failed to write to client socket");
                        close(client_fd);
                        FD_CLR(client_fd, &readfd);
                        continue;
                    }

                    FD_CLR(client_fd, &writefd);
                }
            }
        }
    }

    close(server_fd);

    return 0;
}