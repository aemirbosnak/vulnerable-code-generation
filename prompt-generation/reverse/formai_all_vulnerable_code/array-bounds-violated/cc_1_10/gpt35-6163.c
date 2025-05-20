//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

// Function to print response from IMAP server
void print_response(char buffer[])
{
    printf("[IMAP Server] %s", buffer);
}

// Function to authenticate using plain text login
void authenticate(int sock, char username[], char password[])
{
    char buffer[BUFSIZE];
    size_t bytes_read;

    // Send login command with username and password
    char* command = "1 LOGIN %s %s\r\n";
    sprintf(buffer, command, username, password);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response from server
    bytes_read = recv(sock, buffer, BUFSIZE-1, 0);
    buffer[bytes_read] = '\0';

    // Print response from server
    print_response(buffer);
}

int main(int argc, char* argv[])
{
    // Declare variables
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFSIZE];
    int bytes_sent, bytes_received;

    char* server_ip = "imap.gmail.com";
    int server_port = 993;
    char* username = "user@example.com";
    char* password = "password123";

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("[Error] Failed to create socket");
        return EXIT_FAILURE;
    }

    // Prepare socket address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("[Error] Failed to connect to server");
        return EXIT_FAILURE;
    }

    // Receive response from server
    bytes_received = recv(sock, buffer, BUFSIZE-1, 0);
    buffer[bytes_received] = '\0';

    // Print response from server
    print_response(buffer);

    // Authenticate using plain text login
    authenticate(sock, username, password);

    // Close socket
    close(sock);

    return EXIT_SUCCESS;
}