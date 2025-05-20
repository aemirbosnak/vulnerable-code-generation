//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define IMAP_PORT 993
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

void connect_to_imap(int sock, const char *server_ip) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);

    if(inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error_handling("Invalid address / Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Connection to IMAP server failed");
    }
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
    send(sock, "\r\n", 2, 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int nbytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (nbytes < 0) {
        error_handling("Receiving response failed");
    }
    buffer[nbytes] = '\0';
    printf("Server response: %s\n", buffer);
}

void login_to_imap(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"", username, password);
    send_command(sock, command);
    receive_response(sock);
}

void list_mailboxes(int sock) {
    send_command(sock, "A002 LIST \"\" \"*\"");
    receive_response(sock);
}

void select_mailbox(int sock, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 SELECT \"%s\"", mailbox);
    send_command(sock, command);
    receive_response(sock);
}

void fetch_email(int sock, const char *email_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A004 FETCH %s (RFC822)", email_number);
    send_command(sock, command);
    receive_response(sock);
}

void logout_from_imap(int sock) {
    send_command(sock, "A005 LOGOUT");
    receive_response(sock);
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock = create_socket();
    connect_to_imap(sock, server_ip);
    
    receive_response(sock); // Initial greeting from the server
    login_to_imap(sock, username, password);
    
    list_mailboxes(sock);
    select_mailbox(sock, "INBOX");
    
    fetch_email(sock, "1"); // Fetch the first email
    logout_from_imap(sock);

    return 0;
}