//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVER_PORT 993
#define BUFFER_SIZE 2048

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void connect_to_server(int *socket_fd, const char *server_ip) {
    struct sockaddr_in server_address;

    *socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*socket_fd < 0) {
        handle_error("Socket creation failed");
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    if (connect(*socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        handle_error("Connection to server failed");
    }
}

void send_command(int socket_fd, const char *command) {
    send(socket_fd, command, strlen(command), 0);
}

void receive_response(int socket_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(socket_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK")) break; // Exit on success response
    }
}

void login(int socket_fd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "a LOGIN %s %s\r\n", username, password);
    send_command(socket_fd, command);
    receive_response(socket_fd);
}

void fetch_emails(int socket_fd) {
    const char *command = "a SELECT INBOX\r\n";
    send_command(socket_fd, command);
    receive_response(socket_fd);

    command = "a FETCH 1:* (ENVELOPE)\r\n";
    send_command(socket_fd, command);
    receive_response(socket_fd);
}

void logout(int socket_fd) {
    const char *command = "a LOGOUT\r\n";
    send_command(socket_fd, command);
    receive_response(socket_fd);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int socket_fd;
    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    printf("In the desolate wasteland of code, an IMAP client rises!\n");
    connect_to_server(&socket_fd, server_ip);
    printf("Connected to the IMAP server hidden in the ruins of civilization.\n");

    login(socket_fd, username, password);
    printf("The brave user has logged into the abyss of emails.\n");

    fetch_emails(socket_fd);
    printf("Emails retrieved from the ether. Gathering information...\n");

    logout(socket_fd);
    printf("Logged out of the digital realm. The disconnecting echoes haunt the desolate silence.\n");

    close(socket_fd);
    printf("Connection to the server severed. The wasteland awaits for another day.\n");

    return EXIT_SUCCESS;
}