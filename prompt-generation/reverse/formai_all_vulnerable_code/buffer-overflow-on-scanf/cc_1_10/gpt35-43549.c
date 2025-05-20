//FormAI DATASET v1.0 Category: Client Server Application ; Style: satisfied
/* A simple C client-server program that accepts string from client and returns its length to the client */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send data to server
    char buffer[1024] = {0};
    printf("Enter a string: ");
    scanf("%[^\n]", buffer);
    getchar();
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response from server
    int len;
    while ((len = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("Length of string: %d\n", len);
    }

    // Close socket
    close(sockfd);

    return 0;
}