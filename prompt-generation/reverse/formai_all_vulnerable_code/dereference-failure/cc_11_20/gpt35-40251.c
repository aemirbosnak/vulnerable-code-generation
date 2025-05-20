//FormAI DATASET v1.0 Category: Email Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 25 // SMTP port
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 4) {
        printf("Usage: %s <from> <to> <message>\n", argv[0]);
        return -1;
    }

    char *from = argv[1];
    char *to = argv[2];
    char *message = argv[3];

    // Get mail server address
    struct hostent *he;
    if ((he = gethostbyname("mail.server.com")) == NULL) {
        perror("Error - Could not resolve mail server address");
        return -1;
    }
    struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;
    char *server_ip = inet_ntoa(*addr_list[0]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error - Could not create socket");
        return -1;
    }

    // Connect to mail server
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(server_ip);
    serveraddr.sin_port = htons(SERVER_PORT);
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error - Could not connect to mail server");
        return -1;
    }

    // Receive greeting message from mail server
    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("Error - Could not receive greeting message from mail server");
        return -1;
    }

    // Send HELO command
    char helo_cmd[BUF_SIZE];
    memset(helo_cmd, 0, sizeof(helo_cmd));
    sprintf(helo_cmd, "HELO %s\r\n", server_ip);
    if (send(sockfd, helo_cmd, strlen(helo_cmd), 0) < 0) {
        perror("Error - Could not send HELO command to mail server");
        return -1;
    }

    // Receive response from mail server
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("Error - Could not receive response from mail server");
        return -1;
    }

    // Send MAIL FROM command
    char mail_from_cmd[BUF_SIZE];
    memset(mail_from_cmd, 0, sizeof(mail_from_cmd));
    sprintf(mail_from_cmd, "MAIL FROM:<%s>\r\n", from);
    if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) < 0) {
        perror("Error - Could not send MAIL FROM command to mail server");
        return -1;
    }

    // Receive response from mail server
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("Error - Could not receive response from mail server");
        return -1;
    }

    // Send RCPT TO command
    char rcpt_to_cmd[BUF_SIZE];
    memset(rcpt_to_cmd, 0, sizeof(rcpt_to_cmd));
    sprintf(rcpt_to_cmd, "RCPT TO:<%s>\r\n", to);
    if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) < 0) {
        perror("Error - Could not send RCPT TO command to mail server");
        return -1;
    }

    // Receive response from mail server
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("Error - Could not receive response from mail server");
        return -1;
    }

    // Send DATA command
    char data_cmd[BUF_SIZE];
    memset(data_cmd, 0, sizeof(data_cmd));
    sprintf(data_cmd, "DATA\r\n");
    if (send(sockfd, data_cmd, strlen(data_cmd), 0) < 0) {
        perror("Error - Could not send DATA command to mail server");
        return -1;
    }

    // Receive response from mail server
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("Error - Could not receive response from mail server");
        return -1;
    }

    // Send message
    char message_line[BUF_SIZE];
    memset(message_line, 0, sizeof(message_line));
    sprintf(message_line, "From: %s\r\nTo: %s\r\nSubject: Test Email\r\n\r\n%s\r\n", from, to, message);
    if (send(sockfd, message_line, strlen(message_line), 0) < 0) {
        perror("Error - Could not send message to mail server");
        return -1;
    }

    // Send QUIT command
    char quit_cmd[BUF_SIZE];
    memset(quit_cmd, 0, sizeof(quit_cmd));
    sprintf(quit_cmd, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0) {
        perror("Error - Could not send QUIT command to mail server");
        return -1;
    }

    // Receive response from mail server
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("Error - Could not receive response from mail server");
        return -1;
    }

    // Close socket
    close(sockfd);

    printf("Email sent successfully!\n");

    return 0;
}