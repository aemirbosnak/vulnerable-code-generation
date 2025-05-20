//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_BUFFER 1024

void send_command(int sockfd, const char* cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("C: %s", cmd);
}

void receive_response(int sockfd) {
    char buffer[MAX_BUFFER];
    int len = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[len] = '\0';
    printf("S: %s", buffer);
}

void smtp_client(const char* server_ip, const char* sender, const char* recipient, const char* subject, const char* body) {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    receive_response(sockfd);
    send_command(sockfd, "HELO localhost\r\n");
    receive_response(sockfd);
    
    char mail_from[256];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM: <%s>\r\n", sender);
    send_command(sockfd, mail_from);
    receive_response(sockfd);

    char rcpt_to[256];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO: <%s>\r\n", recipient);
    send_command(sockfd, rcpt_to);
    receive_response(sockfd);

    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    char data[512];
    snprintf(data, sizeof(data), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, data);
    receive_response(sockfd);
    
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <server_ip> <sender> <recipient> <subject>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    const char *sender = argv[2];
    const char *recipient = argv[3];
    const char *subject = argv[4];
    const char *body = "This is a test email body.";

    smtp_client(server_ip, sender, recipient, subject, body);

    return EXIT_SUCCESS;
}