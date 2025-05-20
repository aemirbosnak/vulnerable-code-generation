//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "127.0.0.1"
#define PORT 25

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(SERVER);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Could not connect to SMTP server");
        exit(1);
    }

    char username[50], password[50], email[100];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Enter the recipient email address: ");
    scanf("%s", email);

    char message[1024];
    memset(message, 0, sizeof(message));
    sprintf(message, "EHLO %s\r\n", username);
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "AUTH LOGIN\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "%s\r\n", username);
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "%s\r\n", password);
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "MAIL FROM: <%s>\r\n", username);
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "RCPT TO: <%s>\r\n", email);
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "DATA\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "From: <%s>\r\n", username);
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "To: <%s>\r\n", email);
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "Subject: This is a Cyberpunk SMTP message\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "Greetings from the cybernetic underground!\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, ".\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
    sprintf(message, "QUIT\r\n");
    send(sock, message, strlen(message), 0);

    close(sock);
    return 0;
}