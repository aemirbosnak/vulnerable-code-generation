//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9000
#define MAX_NAME_LEN 50
#define MAX_BUF_SIZE 1024

void clear_buffer(char *buf) {
    memset(buf, 0, MAX_BUF_SIZE);
}

void get_user_email(char *email) {
    printf("Enter your email address: ");
    fgets(email, MAX_NAME_LEN, stdin);
    email[strcspn(email, "\n")] = 0;  // Remove newline character
}

void connect_to_server(int *sock, struct sockaddr_in *server_addr) {
    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr->sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }
    
    if (connect(*sock, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        perror("Connection to the server failed");
        exit(EXIT_FAILURE);
    }
}

void send_email(int sock) {
    char subject[MAX_BUF_SIZE], body[MAX_BUF_SIZE], email[MAX_NAME_LEN];

    // Get user email address
    get_user_email(email);

    // Clear buffer
    clear_buffer(subject);
    clear_buffer(body);

    // Subject and Body
    printf("Enter subject: ");
    fgets(subject, MAX_BUF_SIZE, stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove newline character

    printf("Enter body: ");
    fgets(body, MAX_BUF_SIZE, stdin);
    body[strcspn(body, "\n")] = 0; // Remove newline character

    // Send Email
    char to_send[MAX_BUF_SIZE];
    snprintf(to_send, sizeof(to_send), "Email from: %s\nSubject: %s\nBody: %s", email, subject, body);
    
    send(sock, to_send, strlen(to_send), 0);
    printf("Email sent successfully!\n");
}

void read_emails(int sock) {
    char buffer[MAX_BUF_SIZE];
    int bytes_received;

    printf("Reading emails...\n");
    bytes_received = recv(sock, buffer, MAX_BUF_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to read emails");
    } else {
        buffer[bytes_received] = '\0';
        printf("Received Emails:\n%s\n", buffer);
    }
}

void close_connection(int sock) {
    close(sock);
    printf("Disconnected from email server.\n");
}

int main() {
    int sock;
    struct sockaddr_in server_addr;

    printf("Welcome to C Email Client!\n");

    connect_to_server(&sock, &server_addr);
    
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Send Email\n");
        printf("2. Read Emails\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                send_email(sock);
                break;
            case 2:
                read_emails(sock);
                break;
            case 3:
                close_connection(sock);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}