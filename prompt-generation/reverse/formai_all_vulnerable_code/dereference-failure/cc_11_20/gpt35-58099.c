//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_BUFFER_SIZE 1024
#define USERNAME "myusername"
#define PASSWORD "mypassword"

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char buffer[MESSAGE_BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    if (argc < 3) {
        fprintf(stderr, "ERROR: usage %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: opening socket");
        exit(EXIT_FAILURE);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("ERROR: no such host");
        exit(EXIT_FAILURE);
    }
    
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: connecting");
        exit(EXIT_FAILURE);
    }
    
    // Receive greeting message
    n = recv(sockfd, buffer, MESSAGE_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR: reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);
    
    // Send HELO command
    snprintf(buffer, MESSAGE_BUFFER_SIZE, "HELO %s\r\n", argv[1]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR: writing to socket");
        exit(EXIT_FAILURE);
    }
    
    // Receive response to HELO command
    n = recv(sockfd, buffer, MESSAGE_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR: reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Send LOGIN command
    snprintf(buffer, MESSAGE_BUFFER_SIZE, "LOGIN %s %s\r\n", USERNAME, PASSWORD);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR: writing to socket");
        exit(EXIT_FAILURE);
    }
    
    // Receive response to LOGIN command
    n = recv(sockfd, buffer, MESSAGE_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR: reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);
    
    // Send MAIL FROM command
    snprintf(buffer, MESSAGE_BUFFER_SIZE, "MAIL FROM:<%s>\r\n", USERNAME);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR: writing to socket");
        exit(EXIT_FAILURE);
    }
    
    // Receive response to MAIL FROM command
    n = recv(sockfd, buffer, MESSAGE_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR: reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);
    
    // Send RCPT TO command
    snprintf(buffer, MESSAGE_BUFFER_SIZE, "RCPT TO:<recipient@example.com>\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR: writing to socket");
        exit(EXIT_FAILURE);
    }
    
    // Receive response to RCPT TO command
    n = recv(sockfd, buffer, MESSAGE_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR: reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);
    
    // Send DATA command
    snprintf(buffer, MESSAGE_BUFFER_SIZE, "DATA\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR: writing to socket");
        exit(EXIT_FAILURE);
    }
    
    // Receive response to DATA command
    n = recv(sockfd, buffer, MESSAGE_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR: reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);
    
    // Send email content
    snprintf(buffer, MESSAGE_BUFFER_SIZE, "Subject: Test Email\r\n\r\nThis is a test email from a SMTP client.\r\n.\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR: writing to socket");
        exit(EXIT_FAILURE);
    }
    
    // Receive response to email content
    n = recv(sockfd, buffer, MESSAGE_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR: reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);
    
    // Send QUIT command
    snprintf(buffer, MESSAGE_BUFFER_SIZE, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR: writing to socket");
        exit(EXIT_FAILURE);
    }
    
    // Receive response to QUIT command
    n = recv(sockfd, buffer, MESSAGE_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR: reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);
    
    close(sockfd);
    return 0;
}