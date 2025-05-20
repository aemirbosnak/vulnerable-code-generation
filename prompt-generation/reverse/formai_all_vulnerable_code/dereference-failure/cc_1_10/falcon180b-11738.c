//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    char message[BUF_SIZE];
    int n;

    if (argc!= 3) {
        printf("Usage:./smtp_client <server_address> <message>\n");
        exit(1);
    }

    // Convert server address to IP address
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: Invalid server address\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    // Send HELO command
    send(sockfd, "HELO ", 5, 0);

    // Send MAIL FROM command
    sprintf(message, "MAIL FROM:<%s> ", argv[2]);
    send(sockfd, message, strlen(message), 0);

    // Send RCPT TO command
    sprintf(message, "RCPT TO:<%s> ", argv[2]);
    send(sockfd, message, strlen(message), 0);

    // Send DATA command
    send(sockfd, "DATA ", 5, 0);

    // Send message body
    sprintf(message, "Subject: Message from SMTP client\n\n%s", argv[2]);
    send(sockfd, message, strlen(message), 0);

    // Send quit command
    send(sockfd, "QUIT ", 5, 0);

    // Close socket
    close(sockfd);

    return 0;
}