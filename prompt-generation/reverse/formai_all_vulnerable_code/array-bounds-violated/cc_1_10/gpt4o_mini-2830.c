//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 993
#define BUFFER_SIZE 1024

void error_handling(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char* cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK")) break; // Break at server's OK response
    }
}

int main() {
    char* server_ip = "imap.example.com"; // Change to your IMAP server
    char email[100], password[100];
    
    printf("Welcome to the IMAP Client\n");
    printf("Please enter your email address: ");
    scanf("%99s", email);
    printf("Please enter your password: ");
    scanf("%99s", password);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("Socket creation failed");
    }

    // Setup server address struct
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    // Convert IP address from text to binary
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error_handling("Invalid address/ Address not supported");
    }

    // Connect to IMAP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Connection to the server failed");
    }

    printf("Connected to the IMAP server!\n");

    // Receive initial greeting from server
    receive_response(sockfd);

    // LOGIN command
    char login_cmd[200];
    snprintf(login_cmd, sizeof(login_cmd), "a001 LOGIN %s %s\r\n", email, password);
    send_command(sockfd, login_cmd);
    receive_response(sockfd);

    // SELECT command to open inbox
    send_command(sockfd, "a002 SELECT INBOX\r\n");
    receive_response(sockfd);

    // Fetch email subjects
    send_command(sockfd, "a003 SEARCH ALL\r\n");
    receive_response(sockfd);

    // Let's assume we get a response with email IDs
    // (In a real-world scenario, we'd split this to fetch each email)
    // For demonstration, we will just simulate fetching subjects
    send_command(sockfd, "a004 FETCH 1 BODY[HEADER.FIELDS (SUBJECT)]\r\n");
    receive_response(sockfd);

    send_command(sockfd, "a005 LOGOUT\r\n");
    receive_response(sockfd);

    close(sockfd);
    printf("Disconnected from the IMAP server. Thank you for using the IMAP Client!\n");

    return 0;
}