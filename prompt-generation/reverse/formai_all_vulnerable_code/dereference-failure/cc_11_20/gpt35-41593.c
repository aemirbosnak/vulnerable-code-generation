//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE], server_reply[BUFFER_SIZE];
    struct sockaddr_in serv_addr;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: failed to create socket");
        exit(1);
    }

    // setup server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "smtp.gmail.com", &serv_addr.sin_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: failed to connect to server");
        exit(1);
    }

    // receive server greeting
    n = recv(sockfd, server_reply, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Error: failed to receive server greeting");
        exit(1);
    }
    printf("%s\n", server_reply);

    // send HELO command
    sprintf(buffer, "HELO %s\r\n", argv[1]); // argv[1]: client domain
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: failed to send HELO command");
        exit(1);
    }

    // receive HELO reply
    n = recv(sockfd, server_reply, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Error: failed to receive HELO reply");
        exit(1);
    }
    printf("%s\n", server_reply);

    // send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[2]); // argv[2]: sender email
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: failed to send MAIL FROM command");
        exit(1);
    }

    // receive MAIL FROM reply
    n = recv(sockfd, server_reply, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Error: failed to receive MAIL FROM reply");
        exit(1);
    }
    printf("%s\n", server_reply);

    // send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[3]); // argv[3]: recipient email
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: failed to send RCPT TO command");
        exit(1);
    }

    // receive RCPT TO reply
    n = recv(sockfd, server_reply, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Error: failed to receive RCPT TO reply");
        exit(1);
    }
    printf("%s\n", server_reply);

    // send DATA command
    sprintf(buffer, "DATA\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: failed to send DATA command");
        exit(1);
    }

    // receive DATA reply
    n = recv(sockfd, server_reply, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Error: failed to receive DATA reply");
        exit(1);
    }
    printf("%s\n", server_reply);

    // send email header and body
    sprintf(buffer, "From:<%s>\r\nTo:<%s>\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n.\r\n", argv[2], argv[3]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: failed to send email");
        exit(1);
    }

    // receive email reply
    n = recv(sockfd, server_reply, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Error: failed to receive email reply");
        exit(1);
    }
    printf("%s\n", server_reply);

    // send QUIT command
    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: failed to send QUIT command");
        exit(1);
    }

    // receive QUIT reply
    n = recv(sockfd, server_reply, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Error: failed to receive QUIT reply");
        exit(1);
    }
    printf("%s\n", server_reply);

    // close socket
    close(sockfd);

    return 0;
}