//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_EMAIL_SIZE 1024
#define BUFFER_SIZE 2048

// Function prototypes
void get_email_details(char *email, char *server, int *port);
void connect_to_server(int *socket_desc, struct sockaddr_in *server_addr, char *server, int port);
void retrieve_email(int socket_desc);
void parse_email(char *response);
void cleanup(int socket_desc);

int main() {
    char email[MAX_EMAIL_SIZE];
    char server[MAX_EMAIL_SIZE];
    int port = 0;
    int socket_desc;
    struct sockaddr_in server_addr;

    // Gather information from the user
    get_email_details(email, server, &port);
    
    // Attempting connection to the server
    connect_to_server(&socket_desc, &server_addr, server, port);
    
    // Retrieve and display the email
    retrieve_email(socket_desc);
    
    // Clean up and close connections
    cleanup(socket_desc);

    return 0;
}

void get_email_details(char *email, char *server, int *port) {
    printf("Enter your email: ");
    fgets(email, MAX_EMAIL_SIZE, stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove trailing new line

    printf("Enter the server address: ");
    fgets(server, MAX_EMAIL_SIZE, stdin);
    server[strcspn(server, "\n")] = '\0'; // Remove trailing new line

    printf("Enter the server port (e.g., 110): ");
    scanf("%d", port);
    getchar(); // Clear the newline character from the input buffer
}

void connect_to_server(int *socket_desc, struct sockaddr_in *server_addr, char *server, int port) {
    *socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (*socket_desc == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(port);
    if (inet_pton(AF_INET, server, &server_addr->sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(*socket_desc, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the email server %s:%d\n", server, port);
}

void retrieve_email(int socket_desc) {
    char buffer[BUFFER_SIZE];
    char command[100];

    // Simple email retrieval command (for POP3)
    strcpy(command, "USER user@example.com\r\n");
    send(socket_desc, command, strlen(command), 0);
    recv(socket_desc, buffer, sizeof(buffer), 0);
    parse_email(buffer);
    
    strcpy(command, "PASS password\r\n");
    send(socket_desc, command, strlen(command), 0);
    recv(socket_desc, buffer, sizeof(buffer), 0);
    parse_email(buffer);
    
    strcpy(command, "LIST\r\n");
    send(socket_desc, command, strlen(command), 0);
    recv(socket_desc, buffer, sizeof(buffer), 0);
    parse_email(buffer);

    strcpy(command, "RETR 1\r\n"); // Retrieve the first email
    send(socket_desc, command, strlen(command), 0);
    recv(socket_desc, buffer, sizeof(buffer), 0);
    parse_email(buffer);
    
    strcpy(command, "QUIT\r\n");
    send(socket_desc, command, strlen(command), 0);
}

void parse_email(char *response) {
    printf("Response from server:\n%s\n", response);
}

void cleanup(int socket_desc) {
    close(socket_desc);
    printf("Connection closed.\n");
}