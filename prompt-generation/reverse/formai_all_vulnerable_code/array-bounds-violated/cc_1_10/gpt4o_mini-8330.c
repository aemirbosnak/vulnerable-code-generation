//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void print_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
    printf(">> %s", command);
    print_response(sock);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char hostname[100];
    char username[100];
    char password[100];
    char command[255];

    printf("Enter POP3 server hostname or IP: ");
    fgets(hostname, sizeof(hostname), stdin);
    hostname[strcspn(hostname, "\n")] = 0;

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        return 1;
    }

    print_response(sock); // Print server greeting

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sock, command);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sock, command);

    send_command(sock, "LIST\r\n"); // List emails

    // To retrieve individual emails, we can further implement a loop to LIST and RETR commands
    send_command(sock, "QUIT\r\n"); // Properly close connection

    close(sock);
    return 0;
}