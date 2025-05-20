//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define IMAP_PORT 143
#define BUFFER_SIZE 1024

// Function prototypes
void connect_to_imap_server(const char *server_ip);
void send_command(int sockfd, const char *command);
void read_response(int sockfd);
void login(int sockfd, const char *username, const char *password);
void fetch_mail(int sockfd);
void disconnect(int sockfd);

int main() {
    char server_ip[20], username[50], password[50];

    printf("Welcome to the Retro IMAP Client!\n");
    printf("Please enter the IMAP server IP: ");
    scanf("%s", server_ip);
    printf("Enter your email username: ");
    scanf("%s", username);
    printf("Enter your email password: ");
    scanf("%s", password);

    connect_to_imap_server(server_ip);

    return 0;
}

void connect_to_imap_server(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Successfully connected to IMAP server at %s\n", server_ip);
    read_response(sockfd);

    // Convert username and password to lowercase for the command
    char username[50], password[50];
    printf("Enter your IMAP username: ");
    scanf("%s", username);
    printf("Enter your IMAP password: ");
    scanf("%s", password);

    login(sockfd, username, password);
    fetch_mail(sockfd);
    disconnect(sockfd);
}

void send_command(int sockfd, const char *command) {
    int sent = send(sockfd, command, strlen(command), 0);
    if (sent < 0) {
        perror("Failed to send command");
        exit(EXIT_FAILURE);
    }
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        perror("Error reading response");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0'; // Null-terminate the buffer
    printf("Response: %s\n", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A1 LOGIN %s %s\r\n", username, password);
    
    send_command(sockfd, command);
    read_response(sockfd);
}

void fetch_mail(int sockfd) {
    send_command(sockfd, "A2 SELECT INBOX\r\n");
    read_response(sockfd);
    
    send_command(sockfd, "A3 FETCH 1:* (UID FLAGS)\r\n");
    read_response(sockfd);
}

void disconnect(int sockfd) {
    send_command(sockfd, "A4 LOGOUT\r\n");
    read_response(sockfd);
    close(sockfd);
    printf("Disconnected from the IMAP server.\n");
}