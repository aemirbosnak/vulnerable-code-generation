//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (received < 0) error("Error receiving data");
    buffer[received] = '\0';
    printf("%s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    // Specify server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Use your POP3 server IP

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) error("Error connecting to server");

    // Read the greeting message
    receive_response(sockfd);

    // Login to the server
    char username[50], password[50];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    char login_command[BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "USER %s\r\n", username);
    send_command(sockfd, login_command);
    receive_response(sockfd);

    snprintf(login_command, sizeof(login_command), "PASS %s\r\n", password);
    send_command(sockfd, login_command);
    receive_response(sockfd);

    // List messages
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    // Retrieving a specific message
    printf("Enter the message number to retrieve: ");
    int message_number;
    scanf("%d", &message_number);
    
    char retr_command[BUFFER_SIZE];
    snprintf(retr_command, sizeof(retr_command), "RETR %d\r\n", message_number);
    send_command(sockfd, retr_command);
    receive_response(sockfd);

    // Quit the session
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Close the socket
    close(sockfd);
    return 0;
}