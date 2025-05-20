//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: ./client <smtp-server-ip> <smtp-server-port> <mail-to>\n");
        exit(EXIT_FAILURE);
    }

    char *smtp_server_ip = argv[1];
    int smtp_server_port = atoi(argv[2]);
    char *mail_to = argv[3];

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        perror("Error in creating socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(smtp_server_port),
        .sin_addr.s_addr = inet_addr(smtp_server_ip)
    };

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error in connecting to server\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    char smtp_user_name[] = "user <your-email-address>";
    char smtp_password[] = "your-password";
    char sender_email[] = " <your-email-address>";
    char recipient_email[64];
    sprintf(recipient_email, "<%s>", mail_to);

    char email_subject[] = "Subject: SMTP Client Test\r\n";
    char email_from[] = "From:";
    strcat(email_from, smtp_user_name);
    strcat(email_from, sender_email);
    strcat(email_from, "\r\n");

    char email_to[] = "To:";
    strcat(email_to, recipient_email);
    strcat(email_to, "\r\n");

    char email_text[] = "This is a test message sent using SMTP client\r\n";

    sprintf(buffer, "EHLO localhost\r\n");
    write(socket_fd, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "AUTH LOGIN\r\n");
    write(socket_fd, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "%s\r\n", smtp_user_name);
    write(socket_fd, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "%s\r\n", smtp_password);
    write(socket_fd, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "MAIL FROM:%s\r\n", sender_email);
    write(socket_fd, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "RCPT TO:%s\r\n", recipient_email);
    write(socket_fd, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "DATA\r\n");
    write(socket_fd, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    write(socket_fd, email_subject, strlen(email_subject));
    write(socket_fd, email_from, strlen(email_from));
    write(socket_fd, email_to, strlen(email_to));
    write(socket_fd, email_text, strlen(email_text));
    write(socket_fd, ".\r\n", 3);

    memset(buffer, 0, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "QUIT\r\n");
    write(socket_fd, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) == -1) {
        perror("Error in reading from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    close(socket_fd);

    return 0;
}