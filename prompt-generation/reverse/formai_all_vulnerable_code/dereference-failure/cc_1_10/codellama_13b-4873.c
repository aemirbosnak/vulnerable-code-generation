//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
/*
 * QoS Monitor Program in a Cheerful Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define BUFSIZE 1024
#define TIMEOUT 10

int main(int argc, char *argv[]) {
    int sockfd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen = sizeof(client_addr);
    char buffer[BUFSIZE];
    int n, i;
    int count = 0;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
    if (new_fd < 0) {
        perror("accept");
        exit(1);
    }

    // Set timeout for recv function
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(new_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    while (1) {
        // Receive data from client
        n = recv(new_fd, buffer, BUFSIZE, 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }

        // Print received data
        printf("Received: %s\n", buffer);

        // Send response to client
        char response[] = "Hello, client!";
        send(new_fd, response, strlen(response), 0);

        // Check if client closed connection
        if (n == 0) {
            break;
        }

        count++;
    }

    // Close socket
    close(sockfd);

    // Print number of connections made
    printf("Made %d connections\n", count);

    return 0;
}