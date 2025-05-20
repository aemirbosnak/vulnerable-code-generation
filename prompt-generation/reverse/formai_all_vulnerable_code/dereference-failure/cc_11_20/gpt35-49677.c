//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
 
#define SERVER_PORT 25
 
int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
 
    char *server_ip;
    char buffer[1024], response[1024];
 
    if (argc != 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(0);
    }
 
    /* Resolve hostname to IP address */
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("ERROR: Failed to resolve hostname.%s", "\n");
        exit(1);
    }
    server_ip = inet_ntoa(*((struct in_addr *) host->h_addr));
 
    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR: Failed to create socket.%s", "\n");
        exit(1);
    }
 
    /* Configure server address */
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
 
    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("ERROR: Failed to connect to server.%s", "\n");
        exit(1);
    }
 
    /* Receive server's banner */
    if (recv(sockfd, response, 1024, 0) < 0) {
        printf("ERROR: Failed to read server response.%s", "\n");
        exit(1);
    }
    printf("Server banner:\n%s\n", response);
 
    /* Send HELO command */
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("ERROR: Failed to send HELO command.%s", "\n");
        exit(1);
    }
 
    /* Receive server's response */
    if (recv(sockfd, response, 1024, 0) < 0) {
        printf("ERROR: Failed to read server response.%s", "\n");
        exit(1);
    }
    printf("Server response:\n%s\n", response);
 
    /* Send MAIL FROM command */
    sprintf(buffer, "MAIL FROM:<example@mail.com>\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("ERROR: Failed to send MAIL FROM command.%s", "\n");
        exit(1);
    }
 
    /* Receive server's response */
    if (recv(sockfd, response, 1024, 0) < 0) {
        printf("ERROR: Failed to read server response.%s", "\n");
        exit(1);
    }
    printf("Server response:\n%s\n", response);
 
    /* Send RCPT TO command */
    sprintf(buffer, "RCPT TO:<destination@example.com>\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("ERROR: Failed to send RCPT TO command.%s", "\n");
        exit(1);
    }
 
    /* Receive server's response */
    if (recv(sockfd, response, 1024, 0) < 0) {
        printf("ERROR: Failed to read server response.%s", "\n");
        exit(1);
    }
    printf("Server response:\n%s\n", response);
 
    /* Send DATA command */
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("ERROR: Failed to send DATA command.%s", "\n");
        exit(1);
    }
 
    /* Receive server's response */
    if (recv(sockfd, response, 1024, 0) < 0) {
        printf("ERROR: Failed to read server response.%s", "\n");
        exit(1);
    }
    printf("Server response:\n%s\n", response);
 
    /* Send email message */
    sprintf(buffer, "Subject: SMTP Client Test\n\nThis is a test email from SMTP client.\n.\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("ERROR: Failed to send email message.%s", "\n");
        exit(1);
    }
 
    /* Receive server's response */
    if (recv(sockfd, response, 1024, 0) < 0) {
        printf("ERROR: Failed to read server response.%s", "\n");
        exit(1);
    }
    printf("Server response:\n%s\n", response);
 
    /* Send QUIT command */
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("ERROR: Failed to send QUIT command.%s", "\n");
        exit(1);
    }
 
    /* Receive server's response */
    if (recv(sockfd, response, 1024, 0) < 0) {
        printf("ERROR: Failed to read server response.%s", "\n");
        exit(1);
    }
    printf("Server response:\n%s\n", response);
 
    /* Close socket */
    close(sockfd);
 
    return 0;
}