//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: interoperable
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>

    #define MAX_MSG_SIZE 1024
    #define MAX_CLIENTS 10

    int main(int argc, char *argv[]) {
        int sockfd, new_sockfd;
        socklen_t clilen;
        char buffer[MAX_MSG_SIZE];
        struct sockaddr_in server_addr, client_addr;

        if (argc != 2) {
            fprintf(stderr, "Usage: %s <port>\n", argv[0]);
            exit(1);
        }

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error opening socket");
            exit(1);
        }

        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(atoi(argv[1]));

        if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            perror("Error binding socket");
            exit(1);
        }

        listen(sockfd, MAX_CLIENTS);

        clilen = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clilen);
        if (new_sockfd < 0) {
            perror("Error accepting socket");
            exit(1);
        }

        while (1) {
            memset(buffer, 0, MAX_MSG_SIZE);
            if (read(new_sockfd, buffer, MAX_MSG_SIZE) < 0) {
                perror("Error reading from socket");
                exit(1);
            }

            printf("Message received: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0) {
                break;
            }

            if (write(new_sockfd, buffer, strlen(buffer)) < 0) {
                perror("Error writing to socket");
                exit(1);
            }
        }

        close(new_sockfd);
        close(sockfd);
        return 0;
    }