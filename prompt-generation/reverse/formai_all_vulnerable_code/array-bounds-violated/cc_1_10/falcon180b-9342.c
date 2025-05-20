//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("ERROR: socket creation failed\n");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("ERROR: setsockopt failed\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("ERROR: bind failed\n");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        printf("ERROR: listen failed\n");
        exit(1);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int client_sockfd = accept(sockfd, NULL, NULL);

        if (client_sockfd == -1) {
            printf("ERROR: accept failed\n");
            continue;
        }

        printf("Client connected\n");

        while (1) {
            int bytes_received = recv(client_sockfd, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(client_sockfd);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            send(client_sockfd, buffer, strlen(buffer), 0);
        }
    }

    close(sockfd);
    return 0;
}