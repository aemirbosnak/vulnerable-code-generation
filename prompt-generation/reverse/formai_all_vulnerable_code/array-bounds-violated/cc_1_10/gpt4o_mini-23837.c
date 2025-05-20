//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "pop.example.com"
#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving message");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void pop3_authenticate(int sock, const char *user, const char *pass) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", user);
    send_command(sock, command);
    receive_response(sock);

    snprintf(command, sizeof(command), "PASS %s\r\n", pass);
    send_command(sock, command);
    receive_response(sock);
}

void list_emails(int sock) {
    send_command(sock, "LIST\r\n");
    receive_response(sock);
}

void retrieve_email(int sock, int msg_num) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %d\r\n", msg_num);
    send_command(sock, command);
    receive_response(sock);
}

void disconnect(int sock) {
    send_command(sock, "QUIT\r\n");
    receive_response(sock);
    close(sock);
}

int main() {
    int sock;
    struct sockaddr_in server;
    const char *username = "your_username";  // Change to your POP3 username
    const char *password = "your_password";  // Change to your POP3 password

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("Could not create socket");
    }
    printf("Socket created.\n");

    // Define server details
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }
    printf("Connected to POP3 server.\n");

    // Receive server greeting
    receive_response(sock);
    
    // Authenticate user
    pop3_authenticate(sock, username, password);

    // List emails
    printf("Listing Emails:\n");
    list_emails(sock);

    // Retrieve first email (for demonstration)
    printf("Retrieving Email 1:\n");
    retrieve_email(sock, 1);

    // Disconnect
    disconnect(sock);

    printf("Disconnected from server.\n");
    return 0;
}