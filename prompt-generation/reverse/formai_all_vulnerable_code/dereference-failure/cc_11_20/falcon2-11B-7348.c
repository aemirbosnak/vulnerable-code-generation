//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize socket address
    struct sockaddr_in servaddr;
    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT);

    // Create a buffer to store incoming data
    char buffer[1024];

    // Accept incoming connections
    while (1) {
        int clientfd = accept(sockfd, NULL, NULL);
        if (clientfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Get the remote server address
        struct sockaddr_in clientaddr;
        socklen_t clientlen = sizeof(clientaddr);
        if (getsockname(clientfd, (struct sockaddr *) &clientaddr, &clientlen) < 0) {
            perror("getsockname failed");
            exit(EXIT_FAILURE);
        }

        // Connect to the remote server
        int remote_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_fd < 0) {
            perror("socket creation failed");
            exit(EXIT_FAILURE);
        }

        struct hostent *remote_host = gethostbyname(clientaddr.sin_addr.s_addr);
        if (remote_host == NULL) {
            perror("gethostbyname failed");
            exit(EXIT_FAILURE);
        }

        struct sockaddr_in remote_addr;
        bcopy((char *) remote_host->h_addr, (char *) &remote_addr.sin_addr.s_addr, remote_host->h_length);
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(clientaddr.sin_port);

        // Connect to the remote server
        if (connect(remote_fd, (struct sockaddr *) &remote_addr, sizeof(remote_addr)) < 0) {
            perror("connect failed");
            exit(EXIT_FAILURE);
        }

        // Read the incoming data from the client
        while (1) {
            int bytes_read = recv(clientfd, buffer, sizeof(buffer), 0);
            if (bytes_read < 0) {
                perror("recv failed");
                exit(EXIT_FAILURE);
            }
            if (bytes_read == 0) {
                break;
            }

            // Send the data to the remote server
            send(remote_fd, buffer, bytes_read, 0);
        }

        // Close the client socket
        close(clientfd);
    }

    // Close the listening socket
    close(sockfd);
    return 0;
}