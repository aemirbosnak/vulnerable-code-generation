//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: surrealist
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>

    int main(int argc, char **argv) {
        int sockfd, new_fd;
        struct sockaddr_in server_addr, client_addr;
        socklen_t addrlen = sizeof(client_addr);
        char buffer[1024];

        if (argc < 2) {
            printf("Usage: %s <port>\n", argv[0]);
            return 1;
        }

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Error creating socket!\n");
            return 1;
        }

        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(atoi(argv[1]));

        if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            printf("Error binding!\n");
            return 1;
        }

        if (listen(sockfd, 5) < 0) {
            printf("Error listening!\n");
            return 1;
        }

        printf("Server listening on port %d...\n", ntohs(server_addr.sin_port));

        while (1) {
            new_fd = accept(sockfd, (struct sockaddr *) &client_addr, &addrlen);
            if (new_fd < 0) {
                printf("Error accepting!\n");
                return 1;
            }

            printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            read(new_fd, buffer, 1024);
            printf("Received: %s\n", buffer);

            write(new_fd, buffer, strlen(buffer));

            close(new_fd);
        }

        close(sockfd);

        return 0;
    }