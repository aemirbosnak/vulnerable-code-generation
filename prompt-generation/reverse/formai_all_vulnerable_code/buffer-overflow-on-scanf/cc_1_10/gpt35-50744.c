//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(char* message) {
    printf("%s\n", message);
    exit(1);
}

void read_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(socket, buffer, BUFFER_SIZE, 0);
    if (bytes_read <= 0) {
        error("Error reading response from server.");
    }
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
}

void send_command(int socket, char* command) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s\r\n", command);
    if (send(socket, buffer, strlen(buffer), 0) < 0) {
        error("Error sending command to server.");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        error("Usage: ./imap_client [server] [username]\n");
    }

    char* server_name = argv[1];
    char* username = argv[2];
    char* password;
    printf("Password: ");
    scanf("%ms", &password);

    struct hostent* server = gethostbyname(server_name);
    if (!server) {
        error("Error resolving server name.");
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("Error creating socket.");
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993);
    server_address.sin_addr = *((struct in_addr*) server->h_addr);

    if (connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        error("Error connecting to server.");
    }

    read_response(socket_fd);
    send_command(socket_fd, "a1 LOGIN ");
    send_command(socket_fd, username);
    send_command(socket_fd, password);
    read_response(socket_fd);

    send_command(socket_fd, "a2 SELECT INBOX");
    read_response(socket_fd);

    send_command(socket_fd, "a3 SEARCH ALL");
    read_response(socket_fd);

    send_command(socket_fd, "a4 LOGOUT");
    read_response(socket_fd);

    close(socket_fd);
    free(password);

    return 0;
}