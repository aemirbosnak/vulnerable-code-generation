//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "pop.your-email-provider.com" // Change to your POP3 server
#define PORT 110                            // Default POP3 port
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sock, const char *cmd) {
    write(sock, cmd, strlen(cmd));
    write(sock, "\r\n", 2); // Send the CRLF termination
}

char *receive_response(int sock) {
    static char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    read(sock, buffer, BUFFER_SIZE - 1);
    return buffer;
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[50], password[50];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) 
        error("ERROR opening socket");

    // Setup the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to server IP

    // Connect to POP3 server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    // Receive server greeting
    printf("%s", receive_response(sock));
    
    // Get user credentials
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Authenticate with the POP3 server
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "USER %s", username);
    send_command(sock, cmd);
    printf("%s", receive_response(sock));
    
    snprintf(cmd, sizeof(cmd), "PASS %s", password);
    send_command(sock, cmd);
    printf("%s", receive_response(sock));

    // List messages
    send_command(sock, "LIST");
    printf("%s", receive_response(sock));

    // Get the number of messages
    printf("Enter the message number to read: ");
    int msg_number;
    scanf("%d", &msg_number);

    // Retrieve the specified message
    snprintf(cmd, sizeof(cmd), "RETR %d", msg_number);
    send_command(sock, cmd);
    
    // Print the message content
    printf("%s", receive_response(sock));

    // Terminate session
    send_command(sock, "QUIT");
    printf("%s", receive_response(sock));

    // Close the socket
    close(sock);
    return 0;
}