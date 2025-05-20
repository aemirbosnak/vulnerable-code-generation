//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to send an email
int sendEmail(char *sender, char *receiver, char *subject, char *message) {
    int socket_fd, n;
    struct sockaddr_in server_addr;
    char buf[1024];

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    server_addr.sin_addr.s_addr = inet_addr("smtp.example.com");

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    // Send HELO command
    sprintf(buf, "HELO client\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending HELO command");
        exit(1);
    }

    // Send EHLO command
    sprintf(buf, "EHLO client\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending EHLO command");
        exit(1);
    }

    // Send MAIL FROM command
    sprintf(buf, "MAIL FROM:<%s>\r\n", sender);
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }

    // Send RCPT TO command
    sprintf(buf, "RCPT TO:<%s>\r\n", receiver);
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }

    // Send DATA command
    sprintf(buf, "DATA\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending DATA command");
        exit(1);
    }

    // Send message
    sprintf(buf, "%s\r\n", message);
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Send QUIT command
    sprintf(buf, "QUIT\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }

    // Close socket
    close(socket_fd);

    return 0;
}

int main() {
    char sender[100], receiver[100], subject[100], message[100];

    // Get user input
    printf("Enter sender email: ");
    scanf("%s", sender);
    printf("Enter receiver email: ");
    scanf("%s", receiver);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    scanf("%s", message);

    // Send email
    sendEmail(sender, receiver, subject, message);

    return 0;
}