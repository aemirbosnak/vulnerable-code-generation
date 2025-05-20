//FormAI DATASET v1.0 Category: Email Client ; Style: portable
// A unique C Email Client example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *email_server_addr = argv[1];
    int email_server_port = atoi(argv[2]);

    // Set up TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Set up server address
    struct hostent *server = gethostbyname(email_server_addr);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(email_server_port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the email server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Get initial greeting from server
    ssize_t nbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send HELO command to server
    char *helo_cmd = "HELO localhost\r\n";
    nbytes = send(sockfd, helo_cmd, strlen(helo_cmd), 0);
    if (nbytes < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Get response from server
    nbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send MAIL FROM command to server
    char *mail_from_cmd = "MAIL FROM:<example@mail.com>\r\n";
    nbytes = send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0);
    if (nbytes < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Get response from server
    nbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send RCPT TO command to server
    char *rcpt_to_cmd = "RCPT TO:<recipient@mail.com>\r\n";
    nbytes = send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0);
    if (nbytes < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Get response from server
    nbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send DATA command to server
    char *data_cmd = "DATA\r\n";
    nbytes = send(sockfd, data_cmd, strlen(data_cmd), 0);
    if (nbytes < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Get response from server
    nbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send email body to server
    char *email_body = "Subject: Test Email\r\n\r\nHello World!\r\n.\r\n";
    nbytes = send(sockfd, email_body, strlen(email_body), 0);
    if (nbytes < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Get response from server
    nbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send QUIT command to server
    char *quit_cmd = "QUIT\r\n";
    nbytes = send(sockfd, quit_cmd, strlen(quit_cmd), 0);
    if (nbytes < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Get response from server
    nbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}