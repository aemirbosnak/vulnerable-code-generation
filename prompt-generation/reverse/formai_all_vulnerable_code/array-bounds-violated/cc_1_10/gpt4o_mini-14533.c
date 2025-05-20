//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    printf(" > %s", cmd);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("recv failed");
    }
    buffer[bytes_received] = '\0';
    printf(" < %s", buffer);
}

void login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sock, command);
    receive_response(sock);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sock, command);
    receive_response(sock);
}

void list_messages(int sock) {
    send_command(sock, "LIST\r\n");
    receive_response(sock);
}

void retrieve_message(int sock, int msg_num) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", msg_num);
    send_command(sock, command);
    receive_response(sock);
}

int main() {
    int sock;
    struct sockaddr_in server;
    const char *server_ip = "127.0.0.1"; // Change to your POP3 server's IP
    const char *username = "your_username"; // Change to your POP3 username
    const char *password = "your_password"; // Change to your POP3 password

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("Could not create socket");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }

    printf("Connected to POP3 server\n");
    receive_response(sock);

    // Login to server
    login(sock, username, password);

    // List messages
    list_messages(sock);

    // Retrieve first message as an example
    retrieve_message(sock, 1);

    // Send quit command
    send_command(sock, "QUIT\r\n");
    receive_response(sock);

    // Close the socket
    close(sock);
    return 0;
}