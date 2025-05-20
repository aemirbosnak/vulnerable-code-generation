//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER "imap.example.com"
#define PORT 993
#define BUFFER_SIZE 1024

// Function prototypes
int connect_to_server(const char* server, int port);
void imap_login(int sock, const char* username, const char* password);
void fetch_email_list(int sock);
void logout(int sock);
void send_command(int sock, const char* command);
void read_response(int sock);

int main() {
    const char* username = "your_username@example.com"; // replace with your username
    const char* password = "your_password"; // replace with your password

    int sock = connect_to_server(SERVER, PORT);
    if (sock < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    imap_login(sock, username, password);
    fetch_email_list(sock);
    logout(sock);

    close(sock);
    return EXIT_SUCCESS;
}

int connect_to_server(const char* server, int port) {
    struct sockaddr_in server_addr;
    struct hostent* host;

    host = gethostbyname(server);
    if (host == NULL) {
        herror("gethostbyname failed");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
    server_addr.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        return -1;
    }
    
    return sock;
}

void imap_login(int sock, const char* username, const char* password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"\r\n", username, password);
    send_command(sock, command);
    read_response(sock);
}

void fetch_email_list(int sock) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A002 SELECT INBOX\r\n");
    send_command(sock, command);
    read_response(sock);

    snprintf(command, sizeof(command), "A003 SEARCH ALL\r\n");
    send_command(sock, command);
    read_response(sock);
}

void logout(int sock) {
    send_command(sock, "A004 LOGOUT\r\n");
    read_response(sock);
}

void send_command(int sock, const char* command) {
    ssize_t num_bytes = send(sock, command, strlen(command), 0);
    if (num_bytes < 0) {
        perror("Failed to send command");
        exit(EXIT_FAILURE);
    }
}

void read_response(int sock) {
    char buffer[BUFFER_SIZE];
    ssize_t num_bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (num_bytes < 0) {
        perror("Failed to read response");
        exit(EXIT_FAILURE);
    }
    buffer[num_bytes] = '\0';
    printf("%s", buffer);
}