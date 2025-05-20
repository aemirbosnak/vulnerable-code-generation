//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define MAX_EMAILS 100

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        handle_error("send() failed");
    }
    printf(">> %s\n", cmd);
}

void read_response(int sockfd) {
    char buffer[MAX_LINE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        handle_error("recv() failed");
    }
    buffer[bytes_received] = '\0';
    printf("<< %s", buffer);
}

void list_emails(int sockfd) {
    send_command(sockfd, "LIST\r\n");
    read_response(sockfd);
}

void retrieve_email(int sockfd, int email_number) {
    char command[MAX_LINE];
    snprintf(command, sizeof(command), "RETR %d\r\n", email_number);
    send_command(sockfd, command);
    read_response(sockfd);
}

void quit_session(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);
}

int main() {
    const char *pop3_server = "your.pop3.server"; // Replace with your POP3 server
    const char *username = "your_username";        // Replace with your username
    const char *password = "your_password";        // Replace with your password
    int port = 110; // Default POP3 port

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, pop3_server, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    read_response(sockfd); // Read server greeting

    // Authentication
    char cmd[MAX_LINE];
    snprintf(cmd, sizeof(cmd), "USER %s\r\n", username);
    send_command(sockfd, cmd);
    read_response(sockfd);

    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", password);
    send_command(sockfd, cmd);
    read_response(sockfd);

    // List emails
    list_emails(sockfd);
    
    // You can retrieve specific emails
    int email_count = 3; // Change this to the number of emails you want to fetch
    for (int i = 1; i <= email_count; i++) {
        printf("Retrieving email #%d:\n", i);
        retrieve_email(sockfd, i);
    }

    quit_session(sockfd);
    
    close(sockfd);
    return 0;
}