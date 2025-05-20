//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 993  // IMAP over SSL port
#define BUFFER_SIZE 1024

void print_help() {
    printf("Simple C Email Client\n");
    printf("Commands:\n");
    printf("  'login <username> <password>' - Login to your email\n");
    printf("  'list' - List emails\n");
    printf("  'read <id>' - Read the email\n");
    printf("  'quit' - Logout and exit\n");
    printf("  'help' - Show this help text\n");
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    char username[50], password[50];
    
    // Establish connection
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        handle_error("Socket creation failed");

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        handle_error("Connection to server failed");

    printf("Welcome to the Mind-Bending C Email Client...\n");
    print_help();

    while (1) {
        printf("Type your command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline

        if (strncmp(buffer, "login", 5) == 0) {
            sscanf(buffer, "login %s %s", username, password);
            printf("Logging in as: %s\n", username);
            // Implement login logic here (stub)
        } else if (strcmp(buffer, "list") == 0) {
            printf("Fetching emails...\n");
            // Implement email list fetching logic (stub)
        } else if (strncmp(buffer, "read", 4) == 0) {
            int email_id;
            sscanf(buffer, "read %d", &email_id);
            printf("Reading email with ID: %d\n", email_id);
            // Implement email reading logic (stub)
        } else if (strcmp(buffer, "quit") == 0) {
            printf("Logging out... Goodbye!\n");
            break;  // Exit the loop
        } else if (strcmp(buffer, "help") == 0) {
            print_help();
        } else {
            printf("Unknown command. Type 'help' to see options.\n");
        }

        // Mimicking server processing delay
        sleep(1);
    }

    close(sock);
    return 0;
}