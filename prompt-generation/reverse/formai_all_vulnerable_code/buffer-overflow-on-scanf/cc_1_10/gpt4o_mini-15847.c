//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

void check_response(int sockfd);
void send_command(int sockfd, const char *cmd, char *response);
void list_messages(int sockfd);
void fetch_message(int sockfd, int message_id);
void connect_to_server(const char *server_ip, int port);

int main() {
    const char *server_ip = "your.pop3.server.ip"; // Change to your POP3 server IP
    char username[50], password[50];

    // Prompt for username and password
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  // Remove newline character

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  // Remove newline character

    connect_to_server(server_ip, SERVER_PORT);

    return 0;
}

void connect_to_server(const char *server_ip, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    check_response(sockfd);

    // Authentication section
    char username[50], password[50];
    printf("Enter Email Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  // Remove newline character
    printf("Enter Email Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  // Remove newline character

    char user_cmd[100], pass_cmd[100];
    snprintf(user_cmd, sizeof(user_cmd), "USER %s\r\n", username);
    snprintf(pass_cmd, sizeof(pass_cmd), "PASS %s\r\n", password);

    send_command(sockfd, user_cmd, response);
    send_command(sockfd, pass_cmd, response);
    list_messages(sockfd);

    // Close the socket
    close(sockfd);
}

void check_response(int sockfd) {
    char response[BUFFER_SIZE];
    recv(sockfd, response, sizeof(response) - 1, 0);
    response[sizeof(response) - 1] = 0; // Ensure null-termination
    printf("Server Response: %s", response);
}

void send_command(int sockfd, const char *cmd, char *response) {
    send(sockfd, cmd, strlen(cmd), 0);
    check_response(sockfd);
}

void list_messages(int sockfd) {
    char response[BUFFER_SIZE];
    send_command(sockfd, "LIST\r\n", response);

    while (1) {
        recv(sockfd, response, sizeof(response) - 1, 0);
        if (strstr(response, "OK")) { // Message termination check
            break;
        }
        printf("%s", response);
    }

    int msg_id;
    printf("Enter the message ID to fetch (or 0 to exit): ");
    scanf("%d", &msg_id);
    if (msg_id > 0) {
        fetch_message(sockfd, msg_id);
    }
}

void fetch_message(int sockfd, int message_id) {
    char fetch_cmd[100];
    char response[BUFFER_SIZE];
    
    snprintf(fetch_cmd, sizeof(fetch_cmd), "RETR %d\r\n", message_id);
    send_command(sockfd, fetch_cmd, response);

    while (1) {
        recv(sockfd, response, sizeof(response) - 1, 0);
        if (strstr(response, ".")) { // Message termination
            break;
        }
        printf("%s", response);
    }
}