//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFF_SIZE 1024

// SMTP commands
#define HELO "HELO %s\r\n"
#define EHLO "EHLO %s\r\n"
#define MAIL_FROM "MAIL FROM: <%s>\r\n"
#define RCPT_TO "RCPT TO: <%s>\r\n"
#define DATA "DATA\r\n"
#define QUIT "\r\n.\r\nQUIT\r\n"

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <server> <port> <sender> <recipient>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse command line arguments
    char *server = argv[1];
    int port = atoi(argv[2]);
    char *sender = argv[3];
    char *recipient = argv[4];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive the welcome message from the server
    char recv_buff[BUFF_SIZE];
    int recv_len = recv(sockfd, recv_buff, BUFF_SIZE, 0);
    if (recv_len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buff);

    // Send the HELO command
    char send_buff[BUFF_SIZE];
    snprintf(send_buff, BUFF_SIZE, HELO, "example.com");
    if (send(sockfd, send_buff, strlen(send_buff), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    recv_len = recv(sockfd, recv_buff, BUFF_SIZE, 0);
    if (recv_len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buff);

    // Send the MAIL FROM command
    snprintf(send_buff, BUFF_SIZE, MAIL_FROM, sender);
    if (send(sockfd, send_buff, strlen(send_buff), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    recv_len = recv(sockfd, recv_buff, BUFF_SIZE, 0);
    if (recv_len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buff);

    // Send the RCPT TO command
    snprintf(send_buff, BUFF_SIZE, RCPT_TO, recipient);
    if (send(sockfd, send_buff, strlen(send_buff), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    recv_len = recv(sockfd, recv_buff, BUFF_SIZE, 0);
    if (recv_len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buff);

    // Send the DATA command
    if (send(sockfd, DATA, strlen(DATA), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    recv_len = recv(sockfd, recv_buff, BUFF_SIZE, 0);
    if (recv_len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buff);

    // Send the email message
    char message[] = "This is a test email message.\n";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Send the QUIT command
    if (send(sockfd, QUIT, strlen(QUIT), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    recv_len = recv(sockfd, recv_buff, BUFF_SIZE, 0);
    if (recv_len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buff);

    // Close the socket
    close(sockfd);

    return 0;
}