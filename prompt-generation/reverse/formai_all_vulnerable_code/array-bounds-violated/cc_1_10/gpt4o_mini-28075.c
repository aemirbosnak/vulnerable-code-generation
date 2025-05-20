//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

typedef struct {
    char *hostname;
    char *username;
    char *password;
} Config;

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void read_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';  // null terminate
        printf("%s", buffer);
        if (strstr(buffer, "+OK") || strstr(buffer, "-ERR")) {
            break;  // Response complete
        }
    }
}

void fetch_email_list(int sock) {
    send_command(sock, "LIST\r\n");
    read_response(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Config config;
    config.hostname = argv[1];
    config.username = argv[2];
    config.password = argv[3];

    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Server address initialization
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, config.hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    // Read server greeting
    read_response(sock);

    // Login to the server
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", config.username);
    send_command(sock, command);
    read_response(sock);

    snprintf(command, sizeof(command), "PASS %s\r\n", config.password);
    send_command(sock, command);
    read_response(sock);

    // Fetch email list
    fetch_email_list(sock);

    // Logout
    send_command(sock, "QUIT\r\n");
    read_response(sock);

    close(sock);
    return 0;
}