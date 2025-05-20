//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

bool send_command(int socket_fd, const char *command);
bool receive_response(int socket_fd);
bool parse_response(const char *response, const char *expected_response);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [server] [username]\n", argv[0]);
        return 1;
    }

    const char *server_address = argv[1];
    const char *username = argv[2];

    // Connect to the server
    struct hostent *server = gethostbyname(server_address);
    if (!server) {
        printf("Error: Could not resolve server address\n");
        return 1;
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    struct sockaddr_in server_address_info;
    memset(&server_address_info, 0, sizeof(server_address_info));
    server_address_info.sin_family = AF_INET;
    server_address_info.sin_port = htons(993);
    memcpy(&server_address_info.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    if (connect(socket_fd, (struct sockaddr *)&server_address_info, sizeof(server_address_info)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    // Send login command
    char login_command[BUFFER_SIZE];
    snprintf(login_command, BUFFER_SIZE, "LOGIN %s *", username);
    if (!send_command(socket_fd, login_command) || !receive_response(socket_fd)) {
        printf("Error: Could not login to server\n");
        return 1;
    }

    // Send list command
    if (!send_command(socket_fd, "LIST \"\" *") || !receive_response(socket_fd)) {
        printf("Error: Could not retrieve mailbox list\n");
        return 1;
    }

    // Send select command
    if (!send_command(socket_fd, "SELECT INBOX") || !receive_response(socket_fd)) {
        printf("Error: Could not select mailbox\n");
        return 1;
    }

    // Send fetch command
    if (!send_command(socket_fd, "FETCH 1 BODY[]") || !receive_response(socket_fd)) {
        printf("Error: Could not retrieve message\n");
        return 1;
    }

    // Disconnect from server
    send_command(socket_fd, "LOGOUT");
    close(socket_fd);

    return 0;
}

bool send_command(int socket_fd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "%s\r\n", command);

    ssize_t bytes_sent = send(socket_fd, buffer, strlen(buffer), 0);

    return bytes_sent == strlen(buffer);
}

bool receive_response(int socket_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received = 0;

    do {
        bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);

        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("%s", buffer);
        }
    } while (bytes_received > 0 && strstr(buffer, "\r\n") == NULL);

    return parse_response(buffer, "OK");
}

bool parse_response(const char *response, const char *expected_response) {
    char *response_copy = strdup(response);
    char *token = strtok(response_copy, " \r\n");

    while (token != NULL) {
        if (strcmp(token, expected_response) == 0) {
            free(response_copy);
            return true;
        }
        token = strtok(NULL, " \r\n");
    }
    free(response_copy);
    return false;
}