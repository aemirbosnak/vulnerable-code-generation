//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFSIZE];
    int bytes_sent, bytes_received;

    // Check if IP address and port number are passed as arguments
    if(argc < 3) {
        printf("Usage: %s <IP address> <Port number>\n", argv[0]);
        return 1;
    }

    printf("\nWelcome to the SMTP Client Example Program!\n");
    printf("--------------------------------------------\n\n");
    printf("Are you ready to send some emails? Let's get started!\n");

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket Error");
        return 1;
    }

    // Configure the server address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton Error");
        return 1;
    }

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Connect Error");
        return 1;
    }

    // Wait for the server's welcome message
    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if(bytes_received < 0) {
        perror("Recv Error");
        return 1;
    }
    buffer[bytes_received] = '\0';
    printf("\nServer says: %s\n", buffer);

    // Send the HELO command
    sprintf(buffer, "HELO myhostname\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    printf("\nClient says: %s", buffer);
    if(bytes_sent < 0) {
        perror("Send Error");
        return 1;
    }

    // Wait for the server's response
    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if(bytes_received < 0) {
        perror("Recv Error");
        return 1;
    }
    buffer[bytes_received] = '\0';
    printf("\nServer says: %s\n", buffer);

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <sender@example.com>\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    printf("\nClient says: %s", buffer);
    if(bytes_sent < 0) {
        perror("Send Error");
        return 1;
    }

    // Wait for the server's response
    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if(bytes_received < 0) {
        perror("Recv Error");
        return 1;
    }
    buffer[bytes_received] = '\0';
    printf("\nServer says: %s\n", buffer);

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    printf("\nClient says: %s", buffer);
    if(bytes_sent < 0) {
        perror("Send Error");
        return 1;
    }

    // Wait for the server's response
    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if(bytes_received < 0) {
        perror("Recv Error");
        return 1;
    }
    buffer[bytes_received] = '\0';
    printf("\nServer says: %s\n", buffer);

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    printf("\nClient says: %s", buffer);
    if(bytes_sent < 0) {
        perror("Send Error");
        return 1;
    }

    // Wait for the server's response
    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if(bytes_received < 0) {
        perror("Recv Error");
        return 1;
    }
    buffer[bytes_received] = '\0';
    printf("\nServer says: %s\n", buffer);

    // Send the message data
    sprintf(buffer, "Subject: SMTP Client Example Program\r\n");
    strcat(buffer, "From: <sender@example.com>\r\n");
    strcat(buffer, "To: <recipient@example.com>\r\n");
    strcat(buffer, "This is a test message from the SMTP client example program.\r\n");
    strcat(buffer, ".\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    printf("\nClient says: %s", buffer);
    if(bytes_sent < 0) {
        perror("Send Error");
        return 1;
    }

    // Wait for the server's response
    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if(bytes_received < 0) {
        perror("Recv Error");
        return 1;
    }
    buffer[bytes_received] = '\0';
    printf("\nServer says: %s\n", buffer);

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    printf("\nClient says: %s", buffer);
    if(bytes_sent < 0) {
        perror("Send Error");
        return 1;
    }

    // Wait for the server's response
    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if(bytes_received < 0) {
        perror("Recv Error");
        return 1;
    }
    buffer[bytes_received] = '\0';

    printf("\nServer says: %s\n", buffer);

    printf("\nYour email has been sent successfully! Thanks for using the SMTP Client Example Program!\n");

    // Close the socket
    close(sockfd);

    return 0;
}