//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080

void handle_client(int sockfd) {
    char buf[1024];
    int recv_len = recv(sockfd, buf, 1024, 0);
    if (recv_len > 0) {
        buf[recv_len] = '\0';
        printf("Client: %s\n", buf);
        send(sockfd, buf, recv_len, 0);
    } else {
        perror("Error receiving data");
    }
    close(sockfd);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, client_addr;
    int sin_size;

    // Bind to port
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections
    listen(sockfd, 10);

    // Handle clients
    while (1) {
        // Get client connection
        sin_size = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (int *)&sin_size);

        // Handle client
        if (newsockfd > 0) {
            handle_client(newsockfd);
        } else {
            perror("Error accepting connection");
        }
    }

    return 0;
}