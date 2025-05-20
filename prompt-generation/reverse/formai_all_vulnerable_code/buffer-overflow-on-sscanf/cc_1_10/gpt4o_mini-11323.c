//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "pop.example.com" // Change this to your POP3 server
#define PORT 110
#define BUFFER_SIZE 1024

void send_command(int sock, const char *cmd, char *response) {
    send(sock, cmd, strlen(cmd), 0);
    send(sock, "\r\n", 2, 0); // POP3 protocol requires CRLF at the end
    recv(sock, response, BUFFER_SIZE, 0);
}

void pop3_client(const char *username, const char *password) {
    int sock;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("YOUR_SERVER_IP"); // Change this to your server IP

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server: %s", response);

    // User authentication
    char command[BUFFER_SIZE];

    sprintf(command, "USER %s", username);
    send_command(sock, command, response);
    printf("Server: %s", response);

    sprintf(command, "PASS %s", password);
    send_command(sock, command, response);
    printf("Server: %s", response);

    // List emails
    send_command(sock, "LIST", response);
    printf("Server: %s", response);

    // Fetch and display emails
    int email_count;
    sscanf(response, "+OK %d", &email_count);
    printf("You have %d emails!\n", email_count);

    for (int i = 1; i <= email_count; i++) {
        sprintf(command, "RETR %d", i);
        send_command(sock, command, response);
        printf("Email %d:\n%s\n", i, response);
    }

    // Logout
    send_command(sock, "QUIT", response);
    printf("Server: %s", response);

    // Close socket
    close(sock);
    printf("Goodbye!\n");
}

int main() {
    char username[100], password[100];
    printf("Welcome to the POP3 Email Client!\n");
    printf("Please enter your username: ");
    scanf("%99s", username);
    printf("Please enter your password: ");
    scanf("%99s", password); // Warning: In a real app, use secure password methods!

    pop3_client(username, password);

    return 0;
}