//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void receive_email(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s", buffer);
    }
}

void pop3_command(int sock, const char *cmd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    send(sock, cmd, strlen(cmd), 0);
  
    printf("Sent command: %s", cmd);
    
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        die("Receive failed");
    }
    buffer[bytes_received] = '\0';
    printf("Response: %s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <pop3_server> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *pop3_server = argv[1];
    const char *username = argv[2];
    const char *password = "your_password"; // Replace with actual password for testing

    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        die("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
  
    if (inet_pton(AF_INET, pop3_server, &server_addr.sin_addr) <= 0) {
        die("Invalid address/ Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection failed");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        die("Receive failed");
    }
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);
  
    // Authenticate with USER and PASS commands.
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    pop3_command(sock, command);
  
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    pop3_command(sock, command);
  
    // List emails
    pop3_command(sock, "LIST\r\n");

    // Retrieve the first email for demonstration
    pop3_command(sock, "RETR 1\r\n");

    // Quit the connection
    pop3_command(sock, "QUIT\r\n");
  
    close(sock);
    return EXIT_SUCCESS;
}