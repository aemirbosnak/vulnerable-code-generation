//FormAI DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 2048

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_address> <server_port> <email_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    int server_port = atoi(argv[2]);
    char *email_address = argv[3];

    // Resolve server address
    struct hostent *host = gethostbyname(server_address);
    if (host == NULL) {
        printf("Error: Cannot resolve server address.\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Cannot create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Establish connection
    struct sockaddr_in server_address_info;
    server_address_info.sin_family = AF_INET;
    server_address_info.sin_port = htons(server_port);
    server_address_info.sin_addr = *((struct in_addr*)host->h_addr);
    if (connect(sockfd, (struct sockaddr*)&server_address_info, sizeof(server_address_info)) < 0) {
        printf("Error: Cannot establish connection to server.\n");
        exit(EXIT_FAILURE);
    }

    // Send greeting message to server
    char buffer[MAX_BUFFER];
    sprintf(buffer, "EHLO %s\r\n", server_address);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER, 0);

    // Send email address to server
    sprintf(buffer, "MAIL FROM:<%s>\r\n", email_address);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER, 0);

    // Get recipient email address
    char recipient_address[MAX_BUFFER];
    printf("Enter recipient email address: ");
    scanf("%s", recipient_address);

    // Send recipient email address to server
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient_address);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER, 0);

    // Get email message
    char message[MAX_BUFFER];
    printf("Enter email message: ");
    scanf("\n%[^\n]", message);

    // Send email message to server
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER, 0);

    sprintf(buffer, "From: %s\r\n", email_address);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "To: %s\r\n", recipient_address);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "Subject: Email from %s\r\n\r\n", email_address);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "%s\r\n.\r\n", message);
    send(sockfd, buffer, strlen(buffer), 0);

    // Close connection
    close(sockfd);
    return 0;
}