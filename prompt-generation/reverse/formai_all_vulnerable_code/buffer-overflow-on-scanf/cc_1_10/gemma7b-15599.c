//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define HOST "localhost"
#define PORT 8080

int main() {
    int sockfd, n, i;
    char buf[1024];
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(HOST);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a message
    printf("Enter a message: ");
    scanf("%s", buf);
    n = send(sockfd, buf, strlen(buf) + 1, 0);
    if (n < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Receive a message
    n = recv(sockfd, buf, 1024, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(1);
    }

    // Print the message
    printf("Received message: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}