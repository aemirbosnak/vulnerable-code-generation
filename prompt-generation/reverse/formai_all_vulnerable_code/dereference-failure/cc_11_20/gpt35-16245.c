//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: safe
/* SMTP client program in C */

#include <stdio.h>  // For standard input/output functions
#include <stdlib.h>  // For memory allocation and program exit function
#include <string.h>  // For string functions
#include <netdb.h>  // For network database functions
#include <sys/socket.h>  // For socket functions
#include <arpa/inet.h>  // For internet operations

#define BUF_SIZE 1024  // Define buffer size for communications

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];

    /* Set up server address */
    portno = 25;  // Use default SMTP port number
    server = gethostbyname("mail.example.com");  // SMTP server name
    if (server == NULL) {
        fprintf(stderr, "Error: No such host.\n");
        exit(0);
    }

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket.");
        exit(0);
    }

    /* Set up server address structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server.");
        exit(0);
    }

    /* Read greeting message from server */
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(0);
    }
    printf("%s", buffer);

    /* Send HELO command */
    char helo_cmd[BUF_SIZE] = "HELO client.example.com\r\n";
    n = write(sockfd, helo_cmd, strlen(helo_cmd));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(0);
    }

    /* Read response from server */
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(0);
    }
    printf("%s", buffer);

    /* Send MAIL FROM command */
    char mailfrom_cmd[BUF_SIZE] = "MAIL FROM:<sender@example.com>\r\n";
    n = write(sockfd, mailfrom_cmd, strlen(mailfrom_cmd));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(0);
    }

    /* Read response from server */
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(0);
    }
    printf("%s", buffer);

    /* Send RCPT TO command */
    char rcptto_cmd[BUF_SIZE] = "RCPT TO:<recipient@example.com>\r\n";
    n = write(sockfd, rcptto_cmd, strlen(rcptto_cmd));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(0);
    }

    /* Read response from server */
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(0);
    }
    printf("%s", buffer);

    /* Send DATA command */
    char data_cmd[BUF_SIZE] = "DATA\r\n";
    n = write(sockfd, data_cmd, strlen(data_cmd));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(0);
    }

    /* Read response from server */
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(0);
    }
    printf("%s", buffer);

    /* Send message body */
    char message_body[BUF_SIZE] = "From: sender@example.com\r\n"
                                   "To: recipient@example.com\r\n"
                                   "Subject: Test email\r\n\r\n"
                                   "This is a test email.\r\n";
    n = write(sockfd, message_body, strlen(message_body));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(0);
    }

    /* Send "." to end message */
    char end_cmd[BUF_SIZE] = "\r\n.\r\n";
    n = write(sockfd, end_cmd, strlen(end_cmd));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(0);
    }

    /* Read response from server */
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(0);
    }
    printf("%s", buffer);

    /* Send QUIT command */
    char quit_cmd[BUF_SIZE] = "QUIT\r\n";
    n = write(sockfd, quit_cmd, strlen(quit_cmd));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(0);
    }

    /* Read response from server */
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(0);
    }
    printf("%s", buffer);

    /* Close socket */
    close(sockfd);

    return 0;
}