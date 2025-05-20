//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Define the SMTP port
#define SMTP_PORT 25

// Define the maximum length of the email message
#define MAX_EMAIL_LENGTH 1024

// Define the maximum number of recipients
#define MAX_RECIPIENTS 5

// Function to send an email
int send_email(char *smtp_server, char *sender, char *recipients[], int num_recipients, char *subject, char *message) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Resolve the SMTP server address
    struct hostent *host = gethostbyname(smtp_server);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Read the SMTP server greeting
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Send the HELO command
    sprintf(buffer, "HELO %s\r\n", "localhost");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Read the SMTP server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", sender);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Read the SMTP server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Send the RCPT TO commands
    for (int i = 0; i < num_recipients; i++) {
        sprintf(buffer, "RCPT TO: <%s>\r\n", recipients[i]);
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            close(sockfd);
            return -1;
        }

        // Read the SMTP server response
        if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
            perror("recv");
            close(sockfd);
            return -1;
        }
    }

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Read the SMTP server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Send the email message
    sprintf(buffer, "From: %s\r\n", sender);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    sprintf(buffer, "To: %s\r\n", recipients[0]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    sprintf(buffer, "Subject: %s\r\n", subject);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    sprintf(buffer, "\r\n%s\r\n", message);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Read the SMTP server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main() {
    // Define the SMTP server address
    char *smtp_server = "smtp.example.com";

    // Define the sender email address
    char *sender = "sender@example.com";

    // Define the recipient email addresses
    char *recipients[] = {"recipient1@example.com", "recipient2@example.com"};

    // Define the email subject
    char *subject = "Test email";

    // Define the email message
    char *message = "This is a test email.";

    // Send the email
    if (send_email(smtp_server, sender, recipients, 2, subject, message) == -1) {
        perror("send_email");
        return -1;
    }

    return 0;
}