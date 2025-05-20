//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define SERVER "imap.example.com"
#define PORT 993
#define BUFFER_SIZE 1024

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error_handling("Socket creation failed");
    }
    return sock;
}

int connect_to_server(int sock) {
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_address.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error_handling("Connection to server failed");
    }
    return sock;
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error_handling("Failed to receive response");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    sprintf(command, "A001 LOGIN %s %s\r\n", username, password);
    send_command(sock, command);
    receive_response(sock);
}

void list_mailboxes(int sock) {
    const char *command = "A002 LIST \"\" \"*\"\r\n";
    send_command(sock, command);
    receive_response(sock);
}

void fetch_email(int sock, const char *mailbox, const char *email_uid) {
    char command[BUFFER_SIZE];
    
    sprintf(command, "A003 FETCH %s BODY[]\r\n", email_uid);
    send_command(sock, command);
    receive_response(sock);
}

void logout(int sock) {
    const char *command = "A004 LOGOUT\r\n";
    send_command(sock, command);
    receive_response(sock);
}

int main() {
    int sock = create_socket();
    connect_to_server(sock);

    const char *username = "your_email@example.com";
    const char *password = "your_password";

    login(sock, username, password);
    printf("Mailboxes:\n");
    list_mailboxes(sock);
    
    // Adjust based on the mailbox to fetch emails
    fetch_email(sock, "INBOX", "1");

    logout(sock);
    close(sock);
    return 0;
}