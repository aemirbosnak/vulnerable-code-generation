//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

// Function to connect to the POP3 server
int connect_to_server(const char *server_ip) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send a command to the POP3 server and get response
void send_command(int sock, const char *command) {
    char buffer[BUFFER_SIZE];

    send(sock, command, strlen(command), 0);
    send(sock, "\r\n", 2, 0);

    // Receive the response from the server
    recv(sock, buffer, BUFFER_SIZE - 1, 0);
    printf("Server: %s", buffer);
}

// Function to list emails
void list_emails(int sock) {
    printf("Fetching email list...\n");
    send_command(sock, "LIST");
}

// Function to retrieve an email by its index
void retrieve_email(int sock, int email_index) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d", email_index);
    send_command(sock, command);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server_ip = argv[1];
    char *username = argv[2];
    char password[BUFFER_SIZE];

    int sock = connect_to_server(server_ip);

    // Initial server greeting
    char greeting[BUFFER_SIZE];
    recv(sock, greeting, BUFFER_SIZE - 1, 0);
    printf("Server: %s", greeting);

    // Login
    printf("Enter password for %s: ", username);
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character

    char login_command[BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "USER %s", username);
    send_command(sock, login_command);
    
    snprintf(login_command, sizeof(login_command), "PASS %s", password);
    send_command(sock, login_command);

    // List emails
    list_emails(sock);

    // Prompt user to retrieve a specific email
    int email_index;
    printf("Enter email index to retrieve: ");
    scanf("%d", &email_index);
    retrieve_email(sock, email_index);

    // Quit the session
    send_command(sock, "QUIT");

    close(sock);
    return EXIT_SUCCESS;
}