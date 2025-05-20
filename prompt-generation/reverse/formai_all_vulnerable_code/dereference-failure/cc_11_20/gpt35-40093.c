//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
/* Post-Apocalyptic SMTP Client */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024
#define SERVER_ADDR "mailserver.com"
#define SERVER_PORT 25

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAX_BUFF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Failed to create socket");
        exit(1);
    }

    // Get the mail server
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr,"Error: Failed to get mail server\n");
        exit(1);
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Failed to connect to server");
        exit(1);
    }

    // Wait for the server's greeting
    memset(buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) {
        perror("Error: Failed to read server's greeting");
        exit(1);
    }
    printf("Server says: %s\n", buffer);

    // Send HELO command
    char helo[] = "HELO client\r\n";
    n = write(sockfd, helo, strlen(helo));
    if (n < 0) {
        perror("Error: Failed to send HELO command");
        exit(1);
    }

    // Wait for server's response to HELO command
    memset(buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) {
        perror("Error: Failed to read server's response to HELO command");
        exit(1);
    }
    printf("Server says: %s\n", buffer);

    // Send MAIL FROM command
    char mail_from[] = "MAIL FROM:<sender@example.com>\r\n";
    n = write(sockfd, mail_from, strlen(mail_from));
    if (n < 0) {
        perror("Error: Failed to send MAIL FROM command");
        exit(1);
    }

    // Wait for server's response to MAIL FROM command
    memset(buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) { 
        perror("Error: Failed to read server's response to MAIL FROM command");
        exit(1);
    }
    printf("Server says: %s\n", buffer);

    // Send RCPT TO command
    char rcpt_to[] = "RCPT TO:<recipient@example.com>\r\n";
    n = write(sockfd, rcpt_to, strlen(rcpt_to));
    if (n < 0) {
        perror("Error: Failed to send RCPT TO command");
        exit(1);
    }

    // Wait for server's response to RCPT TO command
    memset(buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) { 
        perror("Error: Failed to read server's response to RCPT TO command");
        exit(1);
    }
    printf("Server says: %s\n", buffer);

    // Send DATA command
    char data[] = "DATA\r\n";
    n = write(sockfd, data, strlen(data));
    if (n < 0) {
        perror("Error: Failed to send DATA command");
        exit(1);
    }

    // Wait for server's response to DATA command
    memset(buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) { 
        perror("Error: Failed to read server's response to DATA command");
        exit(1);
    }
    printf("Server says: %s\n", buffer);

    // Send message body
    char body[] = "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test\r\n\r\nHello,\r\nThis is a test message\r\n.\r\n";
    n = write(sockfd, body, strlen(body));
    if (n < 0) {
        perror("Error: Failed to send message body");
        exit(1);
    }

    // Wait for server's response to message body
    memset(buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) { 
        perror("Error: Failed to read server's response to message body");
        exit(1);
    }
    printf("Server says: %s\n", buffer);

    // Send QUIT command
    char quit[] = "QUIT\r\n";
    n = write(sockfd, quit, strlen(quit));
    if (n < 0) {
        perror("Error: Failed to send QUIT command");
        exit(1);
    }

    // Wait for server's response to QUIT command
    memset(buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) { 
        perror("Error: Failed to read server's response to QUIT command");
        exit(1);
    }
    printf("Server says: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}