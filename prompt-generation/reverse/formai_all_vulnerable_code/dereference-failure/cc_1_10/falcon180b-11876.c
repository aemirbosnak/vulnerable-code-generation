//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define IMAP_PORT 143

void imap_client_send_command(int sock, const char* command) {
    ssize_t bytes_sent;
    bytes_sent = send(sock, command, strlen(command), 0);
    if (bytes_sent < 0) {
        printf("Error sending command\n");
        exit(1);
    }
}

void imap_client_recv_response(int sock, char* response, size_t max_len) {
    char buffer[MAX_COMMAND_LENGTH];
    ssize_t bytes_recv;
    size_t response_len = 0;

    do {
        bytes_recv = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_recv <= 0) {
            printf("Error receiving response\n");
            exit(1);
        }

        strncat(response, buffer, bytes_recv);
        response_len += bytes_recv;
    } while (response_len < max_len && buffer[bytes_recv - 1]!= '\r');

    response[response_len] = '\0';
}

int main() {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char username[64];
    char password[64];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    char login_command[MAX_COMMAND_LENGTH];
    snprintf(login_command, sizeof(login_command), "LOGIN %s %s\r\n", username, password);

    imap_client_send_command(sock, login_command);

    char response[MAX_COMMAND_LENGTH];
    imap_client_recv_response(sock, response, sizeof(response));

    printf("Response: %s\n", response);

    close(sock);
    return 0;
}