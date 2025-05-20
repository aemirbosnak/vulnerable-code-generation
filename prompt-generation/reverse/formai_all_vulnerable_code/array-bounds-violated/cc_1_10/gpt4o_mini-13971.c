//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 587
#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr(hostname);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }

    return sock;
}

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE] = {0};
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void smtp_send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sock = create_socket(smtp_server, SMTP_PORT);

    receive_response(sock);
    send_command(sock, "EHLO localhost\r\n");
    receive_response(sock);

    send_command(sock, "MAIL FROM: ");
    send_command(sock, from);
    send_command(sock, "\r\n");
    receive_response(sock);

    send_command(sock, "RCPT TO: ");
    send_command(sock, to);
    send_command(sock, "\r\n");
    receive_response(sock);

    send_command(sock, "DATA\r\n");
    receive_response(sock);
    send_command(sock, "Subject: ");
    send_command(sock, subject);
    send_command(sock, "\r\n\r\n");
    send_command(sock, body);
    send_command(sock, "\r\n.\r\n");
    receive_response(sock);

    send_command(sock, "QUIT\r\n");
    receive_response(sock);
    close(sock);
}

void pop3_receive_email(const char *pop3_server, const char *username, const char *password) {
    int sock = create_socket(pop3_server, POP3_PORT);
    char command[BUFFER_SIZE];

    receive_response(sock);
    sprintf(command, "USER %s\r\n", username);
    send_command(sock, command);
    receive_response(sock);

    sprintf(command, "PASS %s\r\n", password);
    send_command(sock, command);
    receive_response(sock);

    send_command(sock, "LIST\r\n");
    receive_response(sock);
    
    send_command(sock, "RETR 1\r\n"); // Retrieve first email for demonstration
    receive_response(sock);
    
    send_command(sock, "QUIT\r\n");
    receive_response(sock);
    close(sock);
}

int main() {
    const char *smtp_server = "smtp.example.com";
    const char *pop3_server = "pop.example.com";
    const char *from = "you@example.com";
    const char *to = "friend@example.com";
    const char *subject = "Test Email";
    const char *body = "Hello,\nThis is a test email from my C email client!\nBest,\nYou";
    const char *username = "you@example.com";
    const char *password = "yourpassword";

    printf("Sending email...\n");
    smtp_send_email(smtp_server, from, to, subject, body);

    printf("\nReceiving emails...\n");
    pop3_receive_email(pop3_server, username, password);

    return 0;
}