//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define SERVER_PORT 993 // Default IMAP over SSL port
#define MAX_LINE 1024

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *command) {
    if (send(sock, command, strlen(command), 0) == -1) {
        die("send");
    }
}

void receive_response(int sock) {
    char buffer[MAX_LINE];
    int n;

    while ((n = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) {
            break; // Response finished
        }
    }
    if (n < 0) {
        die("recv");
    }
}

void login(int sock, const char *username, const char *password) {
    char command[MAX_LINE];

    sprintf(command, "A001 LOGIN %s %s\r\n", username, password);
    send_command(sock, command);
    receive_response(sock);
}

void list_mailboxes(int sock) {
    char command[] = "A002 LIST \"\" \"*\"\r\n";
    send_command(sock, command);
    receive_response(sock);
}

void fetch_email(int sock, const char *mailbox, int email_number) {
    char command[MAX_LINE];

    sprintf(command, "A003 FETCH %d BODY[]\r\n", email_number);
    send_command(sock, command);
    receive_response(sock);
}

void quit(int sock) {
    char command[] = "A004 LOGOUT\r\n";
    send_command(sock, command);
    receive_response(sock);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    const char *server_ip = "127.0.0.1"; // Assuming the server is localhost
    const char *username = "your_username";
    const char *password = "your_password";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        die("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        die("connect");
    }

    printf("Connected to IMAP server at %s:%d.\n", server_ip, SERVER_PORT);

    login(sock, username, password);
    list_mailboxes(sock);
    fetch_email(sock, "INBOX", 1); // Fetch the first email
    quit(sock);

    close(sock);
    printf("Disconnected from server.\n");
    return 0;
}