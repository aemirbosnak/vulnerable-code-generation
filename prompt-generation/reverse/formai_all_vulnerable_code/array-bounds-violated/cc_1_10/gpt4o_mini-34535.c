//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

typedef struct {
    char *server;
    char *from;
    char *to;
    char *subject;
    char *body;
} Email;

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int smtp_connection(const char *smtp_server) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Socket creation failed!");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to SMTP server failed!");
    }

    return sock;
}

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
}

char* receive_response(int sock) {
    static char response[BUFFER_SIZE];
    int bytes_received = recv(sock, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        handle_error("Receiving response failed!");
    }
    response[bytes_received] = '\0'; // Null-terminate the response
    return response;
}

void send_email(int sock, Email *email) {
    char buffer[BUFFER_SIZE];

    // HELO command
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", email->server);
    send_command(sock, buffer);
    printf("%s", receive_response(sock));

    // MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", email->from);
    send_command(sock, buffer);
    printf("%s", receive_response(sock));

    // RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", email->to);
    send_command(sock, buffer);
    printf("%s", receive_response(sock));

    // DATA command
    send_command(sock, "DATA\r\n");
    printf("%s", receive_response(sock));

    // Email data
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", email->subject, email->body);
    send_command(sock, buffer);
    printf("%s", receive_response(sock));

    // QUIT command
    send_command(sock, "QUIT\r\n");
    printf("%s", receive_response(sock));
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <smtp_server> <from_address> <to_address> <subject> <body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Email email;
    email.server = argv[1];
    email.from = argv[2];
    email.to = argv[3];
    email.subject = argv[4];
    email.body = argv[5];

    int sock = smtp_connection(email.server);
    
    send_email(sock, &email);
    
    close(sock);
    return 0;
}