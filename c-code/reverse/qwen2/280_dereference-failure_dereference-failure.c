#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Fill server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    inet_pton(AF_INET, "smtp.example.com", &servaddr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connection with the server failed");
        return -1;
    }

    // Send SMTP commands
    char *hello_cmd = "HELO example\r\n";
    send(sockfd, hello_cmd, strlen(hello_cmd), 0);

    char *mail_from_cmd = "MAIL FROM:<sender@example.com>\r\n";
    send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0);

    char *rcpt_to_cmd = "RCPT TO:<recipient@example.com>\r\n";
    send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0);

    char *data_cmd = "DATA\r\n";
    send(sockfd, data_cmd, strlen(data_cmd), 0);

    char *email_body = "Subject: Test Email\r\n\r\nThis is a test email.\r\n.";
    send(sockfd, email_body, strlen(email_body), 0);

    char *quit_cmd = "QUIT\r\n";
    send(sockfd, quit_cmd, strlen(quit_cmd), 0);

    close(sockfd);
    return 0;
}
