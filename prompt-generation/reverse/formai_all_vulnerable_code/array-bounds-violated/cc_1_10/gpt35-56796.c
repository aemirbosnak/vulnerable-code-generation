//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"  // SMTP server IP address
#define SERVER_PORT 25         // SMTP server port number

// Function to send commands to the SMTP server
void sendCommand(int sockfd, char* command, char* expectedResponse) {
    char buffer[1024];
    int numBytes = 0;

    printf("C: %s\n", command);
    send(sockfd, command, strlen(command), 0);

    numBytes = recv(sockfd, buffer, 1024, 0);
    buffer[numBytes] = '\0';
    printf("S: %s", buffer);

    if (expectedResponse != NULL && strcmp(buffer, expectedResponse) != 0) {
        printf("Error: unexpected response from server\n");
        exit(1);
    }
}

int main() {
    int sockfd = 0;
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the server address and port number
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        printf("Error: Invalid IP address\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read the banner
    char buffer[1024];
    int numBytes = recv(sockfd, buffer, 1024, 0);
    buffer[numBytes] = '\0';
    printf("S: %s", buffer);

    // Send HELO command
    sendCommand(sockfd, "HELO example.com\r\n", "250");

    // Send MAIL FROM command
    sendCommand(sockfd, "MAIL FROM: <sender@example.com>\r\n", "250");

    // Send RCPT TO command
    sendCommand(sockfd, "RCPT TO: <recipient@example.com>\r\n", "250");

    // Send DATA command
    sendCommand(sockfd, "DATA\r\n", "354");

    // Send message data
    sendCommand(sockfd, "Subject: Test\r\n\r\nThis is a test message.\r\n.\r\n", "250");

    // Send QUIT command
    sendCommand(sockfd, "QUIT\r\n", "221");

    // Close the socket
    close(sockfd);

    return 0;
}