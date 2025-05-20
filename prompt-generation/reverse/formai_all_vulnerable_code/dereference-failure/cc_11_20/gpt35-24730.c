//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 25
#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket creation was successful
    if (sockfd < 0) {
        perror("Error in socket opening");
        exit(EXIT_FAILURE);
    }

    // Get server information from hostname
    struct hostent *server = gethostbyname("example.com");

    // Check if server information was obtained successfully
    if (server == NULL) {
        perror("Error in getting server information");
        exit(EXIT_FAILURE);
    }

    // Create a server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receive the server greeting
    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send HELO command
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "HELO example.com\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error in sending data to server");
        exit(EXIT_FAILURE);
    }

    // Receive the server response to HELO command
    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send MAIL FROM command
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "MAIL FROM: <sender@example.com>\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error in sending data to server");
        exit(EXIT_FAILURE);
    }

    // Receive the server response to MAIL FROM command
    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send RCPT TO command
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "RCPT TO: <recipient@example.com>\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error in sending data to server");
        exit(EXIT_FAILURE);
    }

    // Receive the server response to RCPT TO command
    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send DATA command
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error in sending data to server");
        exit(EXIT_FAILURE);
    }

    // Receive the server response to DATA command
    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send email message
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "Subject: Test Email\r\n\r\nThis is a test message\r\n.\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error in sending data to server");
        exit(EXIT_FAILURE);
    }

    // Receive the server response to email message
    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send QUIT command
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error in sending data to server");
        exit(EXIT_FAILURE);
    }

    // Receive the server response to QUIT command
    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}