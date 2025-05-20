//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: Linus Torvalds
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>

    #define PORT 8080
    #define BACKLOG 10
    #define MAX_MSG_SIZE 1024

    void error(const char *msg) {
        perror(msg);
        exit(1);
    }

    int main(int argc, char *argv[]) {
        int sockfd, new_fd;
        struct sockaddr_in server_addr, client_addr;
        socklen_t client_len = sizeof(client_addr);
        char buffer[MAX_MSG_SIZE];
        int n;

        if (argc != 2) {
            fprintf(stderr, "usage: %s <port>\n", argv[0]);
            exit(1);
        }

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            error("socket");
        }

        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(atoi(argv[1]));

        if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            error("bind");
        }

        if (listen(sockfd, BACKLOG) == -1) {
            error("listen");
        }

        printf("Chat server listening on port %d\n", atoi(argv[1]));

        while (1) {
            new_fd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
            if (new_fd == -1) {
                error("accept");
            }

            printf("Connection from %s\n", inet_ntoa(client_addr.sin_addr));

            while (1) {
                bzero(buffer, MAX_MSG_SIZE);
                n = read(new_fd, buffer, MAX_MSG_SIZE);
                if (n == -1) {
                    error("read");
                } else if (n == 0) {
                    printf("Client disconnected\n");
                    break;
                }

                printf("Received message: %s", buffer);
                fflush(stdout);

                n = write(new_fd, buffer, n);
                if (n == -1) {
                    error("write");
                }
            }

            close(new_fd);
        }

        close(sockfd);
        return 0;
    }