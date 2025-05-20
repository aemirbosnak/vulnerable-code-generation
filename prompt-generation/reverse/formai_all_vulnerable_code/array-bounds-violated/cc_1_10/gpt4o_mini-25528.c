//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 4096

#define CMD_LOGIN "A001 LOGIN "
#define CMD_SELECT "A002 SELECT "
#define CMD_LOGOUT "A003 LOGOUT "
#define CMD_FETCH "A004 FETCH "

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket(char *server_address) {
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error_handling("Failed to create socket");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, server_address, &server.sin_addr) <= 0) {
        error_handling("Invalid address or Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error_handling("Connection failed");
    }

    return sock;
}

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    send(sock, "\r\n", 2, 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);

        // Break on command complete response or error
        if (strstr(buffer, "A001") || strstr(buffer, "A002") || strstr(buffer, "A003")) {
            break;
        }
    }

    if (bytes_received < 0) {
        error_handling("Receive failed");
    }
}

void fetch_email_data(int sock) {
    // Replace "INBOX" with another mailbox if needed
    send_command(sock, CMD_SELECT "INBOX");
    receive_response(sock);

    // Fetch the first email for demonstration
    send_command(sock, CMD_FETCH "1 BODY[]");
    receive_response(sock);
}

void login_to_imap_server(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "%s\"%s\" \"%s\"", CMD_LOGIN, username, password);
    send_command(sock, command);
    receive_response(sock);
}

void logout_from_imap_server(int sock) {
    send_command(sock, CMD_LOGOUT);
    receive_response(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP Server> <Username> <Password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server_address = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    
    int sock = create_socket(server_address);
    
    printf("Connected to the IMAP server.\n");
    
    login_to_imap_server(sock, username, password);
    printf("Logged in as %s\n", username);
    
    fetch_email_data(sock);
    
    logout_from_imap_server(sock);
    close(sock);
    
    printf("Logged out and connection closed.\n");
    
    return EXIT_SUCCESS;
}