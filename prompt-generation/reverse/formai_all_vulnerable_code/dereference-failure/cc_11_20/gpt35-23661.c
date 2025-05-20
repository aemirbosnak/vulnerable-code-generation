//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    // Step 1: Create a socket
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Step 2: Connect to the server
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Error converting server IP address");
        exit(1);
    }
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Step 3: Send HELO command to server
    
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "HELO %s\n", argv[1]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending HELO command to server");
        exit(1);
    }
    
    // Step 4: Receive server's reply to HELO command
    
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server reply to HELO command");
        exit(1);
    }
    printf("Server reply to HELO command: %s", buffer);

    // Step 5: Enter email address and recipient address
    
    char email_from[BUFFER_SIZE];
    printf("Enter your email address: ");
    fgets(email_from, BUFFER_SIZE, stdin);
    email_from[strlen(email_from)-1] = '\0';

    char email_to[BUFFER_SIZE];
    printf("Enter recipient email address: ");
    fgets(email_to, BUFFER_SIZE, stdin);
    email_to[strlen(email_to)-1] = '\0';
    
    // Step 6: Send MAIL FROM command to server
    
    sprintf(buffer, "MAIL FROM: <%s>\n", email_from);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending MAIL FROM command to server");
        exit(1);
    }
    
    // Step 7: Receive server's reply to MAIL FROM command
    
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server reply to MAIL FROM command");
        exit(1);
    }
    printf("Server reply to MAIL FROM command: %s", buffer);

    // Step 8: Send RCPT TO command to server
    
    sprintf(buffer, "RCPT TO: <%s>\n", email_to);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending RCPT TO command to server");
        exit(1);
    }
    
    // Step 9: Receive server's reply to RCPT TO command
    
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server reply to RCPT TO command");
        exit(1);
    }
    printf("Server reply to RCPT TO command: %s", buffer);

    // Step 10: Send DATA command to server

    sprintf(buffer, "DATA\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending DATA command to server");
        exit(1);
    }

    // Step 11: Receive server's reply to DATA command
    
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server reply to DATA command");
        exit(1);
    }
    printf("Server reply to DATA command: %s", buffer);

    // Step 12: Enter email subject and message
    
    char email_subject[BUFFER_SIZE];
    printf("Enter email subject: ");
    fgets(email_subject, BUFFER_SIZE, stdin);
    email_subject[strlen(email_subject)-1] = '\0';

    char email_message[BUFFER_SIZE];
    printf("Enter email message:\n");
    fgets(email_message, BUFFER_SIZE, stdin);
    email_message[strlen(email_message)-1] = '\0';

    // Step 13: Send email message headers and body to server

    sprintf(buffer, "Subject: %s\n", email_subject);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending email subject to server");
        exit(1);
    }

    sprintf(buffer, "From: <%s>\n", email_from);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending email from address to server");
        exit(1);
    }

    sprintf(buffer, "To: <%s>\n", email_to);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending email to address to server");
        exit(1);
    }

    sprintf(buffer, "\n%s\n", email_message);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending email message to server");
        exit(1);
    }

    // Step 14: Send QUIT command to server
    
    sprintf(buffer, "QUIT\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending QUIT command to server");
        exit(1);
    }
    
    // Step 15: Receive server's reply to QUIT command
    
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server reply to QUIT command");
        exit(1);
    }
    printf("Server reply to QUIT command: %s", buffer);

    // Step 16: Close the socket
    
    close(sockfd);

    return 0;
}