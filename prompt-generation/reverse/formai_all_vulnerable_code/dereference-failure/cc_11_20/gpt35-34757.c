//FormAI DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024 // Maximum size of message

int main() {
    int sockfd; // Socket descriptor
    struct sockaddr_in serv_addr; // Server address
    struct hostent *server; // Host entity
    char buffer[MAX_SIZE]; // Buffer for messages
    char username[50]; // Username for login
    char password[50]; // Password for login
    char recipient[50]; // Recipient email address
    char message[MAX_SIZE]; // Message to send
    int port = 25; // Default port for SMTP

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Get server address
    server = gethostbyname("mail.example.com");
    if (server == NULL) {
        perror("Error getting server address");
        exit(1);
    }

    // Clear server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Set server address family, address, and port
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive initial greeting from server
    bzero(buffer, MAX_SIZE);
    if (recv(sockfd, buffer, MAX_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send username for login
    printf("Enter username: ");
    fgets(username, 50, stdin);
    sprintf(buffer, "EHLO %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Receive response from server
    bzero(buffer, MAX_SIZE);
    if (recv(sockfd, buffer, MAX_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send password for login
    printf("Enter password: ");
    fgets(password, 50, stdin);
    sprintf(buffer, "AUTH %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Receive response from server
    bzero(buffer, MAX_SIZE);
    if (recv(sockfd, buffer, MAX_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send recipient email address
    printf("Enter recipient email address: ");
    fgets(recipient, 50, stdin);
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Receive response from server
    bzero(buffer, MAX_SIZE);
    if (recv(sockfd, buffer, MAX_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send message
    printf("Enter message: ");
    fgets(message, MAX_SIZE, stdin);
    sprintf(buffer, "DATA\r\n%s\r\n.\r\n", message);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Receive response from server
    bzero(buffer, MAX_SIZE);
    if (recv(sockfd, buffer, MAX_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}