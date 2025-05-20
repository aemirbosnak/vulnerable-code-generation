//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110 // Default POP3 port
#define BUFFER_SIZE 1024

// Function prototypes
void connect_to_server(int *sockfd, const char *server_ip);
void login(int sockfd, const char *username, const char *password);
void list_emails(int sockfd);
void retrieve_email(int sockfd, int email_number);
void close_connection(int sockfd);

int main() {
    int sockfd;
    char server_ip[100], username[100], password[100];

    // Get server IP, username, and password from the user
    printf("Enter the POP3 server IP address: ");
    scanf("%s", server_ip);
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Connect to the server
    connect_to_server(&sockfd, server_ip);
    
    // Login to the server
    login(sockfd, username, password);
    
    // List emails
    list_emails(sockfd);
    
    // Get user's choice for email retrieval
    int email_number;
    printf("Enter the email number you want to retrieve: ");
    scanf("%d", &email_number);
    retrieve_email(sockfd, email_number);
    
    // Close the connection
    close_connection(sockfd);
    return 0;
}

void connect_to_server(int *sockfd, const char *server_ip) {
    struct sockaddr_in server_addr;
    
    // Create socket
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to the server
    if (connect(*sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(*sockfd);
        exit(EXIT_FAILURE);
    }

    // Read server greeting
    char buffer[BUFFER_SIZE];
    read(*sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    // Send USER command
    sprintf(buffer, "USER %s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send PASS command
    sprintf(buffer, "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
}

void list_emails(int sockfd) {
    char buffer[BUFFER_SIZE];

    // Send LIST command
    write(sockfd, "LIST\r\n", 7);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    // Continue reading until the end of the LIST response
    while (strstr(buffer, ".") == NULL) {
        read(sockfd, buffer, sizeof(buffer));
        printf("Server: %s", buffer);
    }
}

void retrieve_email(int sockfd, int email_number) {
    char buffer[BUFFER_SIZE];

    // Send RETR command
    sprintf(buffer, "RETR %d\r\n", email_number);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Read the email content until the end
    if (strstr(buffer, "OK") != NULL) {
        while (strstr(buffer, ".") == NULL) {
            read(sockfd, buffer, sizeof(buffer));
            printf("Email Content: %s", buffer);
        }
    } else {
        printf("Failed to retrieve the email.\n");
    }
}

void close_connection(int sockfd) {
    write(sockfd, "QUIT\r\n", 7);
    close(sockfd);
    printf("Connection closed. Goodbye!\n");
}