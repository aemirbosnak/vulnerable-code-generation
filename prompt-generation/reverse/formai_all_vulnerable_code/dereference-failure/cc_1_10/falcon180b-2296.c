//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define SERVER "smtp.gmail.com"
#define PORT 587
#define USER "your_username"
#define PASS "your_password"
#define FROM "your_email@gmail.com"
#define TO "recipient_email@gmail.com"
#define SUBJECT "Hello World!"
#define BODY "This is a test email sent from a C program!"

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[1024];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *username = USER;
    char *password = PASS;
    char *auth_string = username;

    strcat(auth_string, "\0");
    strcat(auth_string, username);
    strcat(auth_string, "\0");
    strcat(auth_string, password);

    write(sock, auth_string, strlen(auth_string));
    read(sock, buffer, sizeof(buffer));

    char *mail_from = FROM;
    char *rcpt_to = TO;

    sprintf(buffer, "MAIL FROM:<%s>\r\n", mail_from);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));

    sprintf(buffer, "RCPT TO:<%s>\r\n", rcpt_to);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));

    sprintf(buffer, "DATA\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));

    sprintf(buffer, "Subject: %s\r\n", SUBJECT);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));

    sprintf(buffer, "\r\n%s\r\n.\r\n", BODY);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));

    close(sock);

    printf("Email sent successfully!\n");

    return 0;
}