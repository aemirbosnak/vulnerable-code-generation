//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *message = "Hello, World!";
    int addrlen = sizeof(server_addr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    server_addr.sin_port = htons(8080);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send message
    send(sockfd, message, strlen(message), 0);

    // Receive response
    char response[1024];
    memset(response, 0, sizeof(response));
    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received <= 0) {
        printf("Error receiving response: %s\n", strerror(errno));
        exit(1);
    }

    // Print response
    printf("Response: %s\n", response);

    // Close socket
    close(sockfd);

    return 0;
}