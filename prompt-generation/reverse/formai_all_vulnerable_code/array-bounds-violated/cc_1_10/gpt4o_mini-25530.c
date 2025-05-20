//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024
#define PORT 8888

// Function to create a socket and connect to the server
int create_client_socket(const char *server_ip) {
    int sock;
    struct sockaddr_in server_address;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configuring server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send an email
void send_email(int sock) {
    char subject[MAX_BUFFER];
    char body[MAX_BUFFER];

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove newline character

    printf("Enter message body: ");
    fgets(body, sizeof(body), stdin);
    body[strcspn(body, "\n")] = 0; // Remove newline character

    // Constructing email format
    char email[MAX_BUFFER * 2];
    snprintf(email, sizeof(email), "Subject: %s\n\n%s", subject, body);

    // Sending email
    send(sock, email, strlen(email), 0);
    printf("Email sent successfully!\n");
}

// Function to receive server response
void receive_response(int sock) {
    char buffer[MAX_BUFFER];
    int bytes_received;

    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate buffer
        printf("Server response: %s\n", buffer);
    } else {
        perror("Failed to receive response");
    }
}

// Main function
int main() {
    const char *server_ip = "127.0.0.1"; // Can be changed to target server IP
    int sock;

    // Connecting to the email server
    sock = create_client_socket(server_ip);
    printf("Connected to the mail server at %s:%d\n", server_ip, PORT);

    // Sending email
    send_email(sock);

    // Receiving server response
    receive_response(sock);

    // Clean up and close the socket
    close(sock);
    printf("Disconnected from the mail server. Thank you for using our peaceful email client!\n");

    return 0;
}