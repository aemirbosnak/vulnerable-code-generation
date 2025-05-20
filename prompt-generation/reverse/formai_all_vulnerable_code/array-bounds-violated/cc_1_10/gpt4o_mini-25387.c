//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *cmd) {
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        die("send_command");
    }
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (received < 0) {
        die("receive_response");
    }
    buffer[received] = '\0'; // Null-terminate the string
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <POP3-server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        die("Socket creation failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110); // Default POP3 port
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to server failed");
    }

    // Receive server greeting
    receive_response(sock);

    // Log in
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sock, command);
    receive_response(sock);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sock, command);
    receive_response(sock);

    // Check number of messages
    send_command(sock, "STAT\r\n");
    printf("Message statistics:\n");
    receive_response(sock);

    // Asking user for a message to retrieve
    int msg_number;
    printf("Enter the message number you want to read: ");
    scanf("%d", &msg_number);

    snprintf(command, sizeof(command), "RETR %d\r\n", msg_number);
    send_command(sock, command);
    printf("Fetching message %d:\n", msg_number);
    receive_response(sock);

    // Send QUIT command
    send_command(sock, "QUIT\r\n");
    receive_response(sock);

    close(sock);
    return EXIT_SUCCESS;
}