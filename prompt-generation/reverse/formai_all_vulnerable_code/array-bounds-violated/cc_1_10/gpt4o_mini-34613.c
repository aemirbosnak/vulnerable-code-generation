//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110 // Default port for POP3
#define MAX_EMAILS 100
#define BUFFER_SIZE 1024

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void connect_to_server(int *sock, const char *server) {
    struct sockaddr_in server_addr;
    
    // Creating socket
    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock < 0) {
        handle_error("Could not create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    if (connect(*sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE] = {0};
    int bytes_received;

    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        handle_error("Failed to receive response");
    }
    buffer[bytes_received] = '\0';
    printf("Server Response: %s", buffer);
}

void list_emails(int sock) {
    send_command(sock, "LIST\r\n");
    receive_response(sock);
}

void retrieve_email(int sock, int email_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", email_number);
    send_command(sock, command);
    receive_response(sock);
}

void delete_email(int sock, int email_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "DELE %d\r\n", email_number);
    send_command(sock, command);
    receive_response(sock);
}

void quit_session(int sock) {
    send_command(sock, "QUIT\r\n");
    receive_response(sock);
}

void print_menu() {
    printf("\n=== Simple Email Client ===\n");
    printf("1. List Emails\n");
    printf("2. Retrieve Email\n");
    printf("3. Delete Email\n");
    printf("4. Quit\n");
    printf("Choose an option: ");
}

int main() {
    int sock;
    char server[100];
    int choice, email_number;

    printf("Enter the email server IP address: ");
    scanf("%s", server);

    connect_to_server(&sock, server);
    receive_response(sock); // Get server greeting

    printf("Enter your username: ");
    char username[50];
    scanf("%s", username);
    send_command(sock, "USER ");
    send_command(sock, username);
    send_command(sock, "\r\n");
    receive_response(sock);

    printf("Enter your password: ");
    char password[50];
    scanf("%s", password);
    send_command(sock, "PASS ");
    send_command(sock, password);
    send_command(sock, "\r\n");
    receive_response(sock);

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_emails(sock);
                break;
            case 2:
                printf("Enter email number to retrieve: ");
                scanf("%d", &email_number);
                retrieve_email(sock, email_number);
                break;
            case 3:
                printf("Enter email number to delete: ");
                scanf("%d", &email_number);
                delete_email(sock, email_number);
                break;
            case 4:
                quit_session(sock);
                close(sock);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    close(sock);
    return 0;
}