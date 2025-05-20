//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER "imap.gmail.com"
#define PORT 993
#define BUFFER_SIZE 1024

// Function to handle errors and print messages
void handle_error(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to create a socket and connect to the email server
int create_connection() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) handle_error("Socket creation failed");

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    return sock;
}

// Function to receive data from the server
void receive_data(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    int bytes_received;
    
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    
    if (bytes_received < 0) handle_error("Error in receiving data");
}

// Function to send commands to the server
void send_command(int sock, const char* command) {
    send(sock, command, strlen(command), 0);
    send(sock, "\r\n", 2, 0); // IMAP commands end with CRLF
}

// Main function, the heart of this puzzling email client
int main() {
    int sock = create_connection();
    printf("Connected to %s on port %d\n", SERVER, PORT);

    // Initial greeting
    receive_data(sock);

    // Send login command (requires valid email and app password)
    printf("Enter your email: ");
    char email[100];
    scanf("%s", email);
    
    printf("Enter your app password: ");
    char password[100]; 
    scanf("%s", password);
    
    char command[200];
    sprintf(command, "a001 LOGIN %s %s", email, password);
    send_command(sock, command);
    receive_data(sock);

    // Send list command
    send_command(sock, "a002 LIST \"\" \"*\"");
    receive_data(sock);

    // Send select command for the inbox
    send_command(sock, "a003 SELECT INBOX");
    receive_data(sock);

    // Get email count
    send_command(sock, "a004 SEARCH ALL");
    receive_data(sock);

    // Send FETCH command for the first email
    send_command(sock, "a005 FETCH 1 BODY[]");
    receive_data(sock);

    // Logout and close socket
    send_command(sock, "a006 LOGOUT");
    receive_data(sock);
    
    close(sock);
    printf("Connection closed. Goodbye!\n");
    return 0;
}