//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: %s [hostname] [port] [from email address]\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *from = argv[3];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Read server greeting
    char buffer[MAX_BUFFER_SIZE];
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        perror("Error reading from server");
        return 1;
    }
    printf("%s\n", buffer);

    // Send HELO command
    char helo[MAX_BUFFER_SIZE];
    snprintf(helo, MAX_BUFFER_SIZE, "HELO %s\r\n", hostname);
    if (send(sockfd, helo, strlen(helo), 0) < 0) {
        perror("Error sending HELO command");
        return 1;
    }

    // Read server response
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        perror("Error reading HELO response");
        return 1;
    }
    printf("%s\n", buffer);

    // Send MAIL FROM command
    char mail_from[MAX_BUFFER_SIZE];
    snprintf(mail_from, MAX_BUFFER_SIZE, "MAIL FROM: <%s>\r\n", from);
    if (send(sockfd, mail_from, strlen(mail_from), 0) < 0) {
        perror("Error sending MAIL FROM command");
        return 1;
    }

    // Read server response
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        perror("Error reading MAIL FROM response");
        return 1;
    }
    printf("%s\n", buffer);

    // Send QUIT command
    char quit[MAX_BUFFER_SIZE];
    snprintf(quit, MAX_BUFFER_SIZE, "QUIT\r\n");
    if (send(sockfd, quit, strlen(quit), 0) < 0) {
        perror("Error sending QUIT command");
        return 1;
    }

    // Read server response
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        perror("Error reading QUIT response");
        return 1;
    }
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}