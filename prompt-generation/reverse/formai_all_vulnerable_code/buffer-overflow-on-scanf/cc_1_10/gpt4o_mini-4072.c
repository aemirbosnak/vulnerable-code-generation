//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
    send(socket, "\r\n", 2, 0); // Send termination sequence for POP3
}

int receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    
    if (bytes_received < 0) {
        error("Error in receiving response");
    }

    buffer[bytes_received] = '\0'; // Null-terminate the string
    printf("%s", buffer);
    return bytes_received;
}

void list_messages(int socket) {
    send_command(socket, "LIST");
    receive_response(socket);
}

void print_message(int socket, int message_num) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d", message_num);
    send_command(socket, command);
    receive_response(socket);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char hostname[100], username[100], password[100];

    // Input server details
    printf("Enter POP3 server hostname: ");
    scanf("%s", hostname);
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation error");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert hostname to IP address
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    printf("Connected to POP3 server\n");
    receive_response(sock); // Receive server greeting

    // Authenticate
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sock, command);
    receive_response(sock);
    
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sock, command);
    receive_response(sock);
    
    // List message summary
    list_messages(sock);
    
    // Print out messages
    int num_messages;
    printf("Enter number of messages to retrieve: ");
    scanf("%d", &num_messages);
    
    for (int i = 1; i <= num_messages; i++) {
        printf("\nRetrieving message %d:\n", i);
        print_message(sock, i);
    }

    // Disconnect from server
    send_command(sock, "QUIT");
    receive_response(sock);

    // Clean up and exit
    close(sock);
    printf("Disconnected from server.\n");
    return 0;
}