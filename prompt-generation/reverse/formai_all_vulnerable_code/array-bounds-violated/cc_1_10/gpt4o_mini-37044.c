//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "pop.mailserver.com" // Replace with your POP3 server
#define USER "your_email@example.com" // Replace with your email
#define PASS "your_password" // Replace with your password
#define PORT 110

void send_command(int sock, const char *cmd) {
    // Send command to the server
    send(sock, cmd, strlen(cmd), 0);
}

void read_response(int sock) {
    char buffer[1024];
    int bytes_received;

    // Read the response from the server
    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
        if (strstr(buffer, "+OK") || strstr(buffer, "-ERR")) {
            break;
        }
    }
}

int main() {
    struct sockaddr_in server_addr;
    int sock;
    
    // Open a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.0.2.1"); // Replace with actual server IP address

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return 1;
    }

    // Read the server welcome message
    read_response(sock);

    // Send USER command
    char command[256];
    sprintf(command, "USER %s\r\n", USER);
    send_command(sock, command);
    read_response(sock);

    // Send PASS command
    sprintf(command, "PASS %s\r\n", PASS);
    send_command(sock, command);
    read_response(sock);

    // Send STAT command to get the number of messages
    send_command(sock, "STAT\r\n");
    read_response(sock);

    // Send LIST command to list messages
    send_command(sock, "LIST\r\n");
    read_response(sock);

    // Fetch the first email message
    sprintf(command, "RETR 1\r\n");
    send_command(sock, command);
    read_response(sock);

    // Send QUIT command to logout
    send_command(sock, "QUIT\r\n");
    read_response(sock);

    // Close the socket
    close(sock);
    printf("\nAdventurer, you've completed your quest!\n");

    return 0;
}