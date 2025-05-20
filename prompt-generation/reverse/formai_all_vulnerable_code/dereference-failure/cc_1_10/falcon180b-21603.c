//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    if (argc!= 4) {
        printf("Usage:./smtp_client <server_ip> <server_port> <email_address>\n");
        return -1;
    }

    // Convert server IP and port from string to integer
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return -1;
    }

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Send email body
    sprintf(buffer, "Subject: Test email\r\n\r\nHello, World!\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Close socket
    close(sockfd);

    return 0;
}