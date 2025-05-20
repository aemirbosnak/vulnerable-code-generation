//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 993
#define SERVER "imap.example.com" // Replace with the actual IMAP server
#define BUFFER_SIZE 1024

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
}

void receive_response(int socket, char *buffer) {
    memset(buffer, 0, BUFFER_SIZE); // Cleans the buffer anew
    recv(socket, buffer, BUFFER_SIZE - 1, 0);
}

void connect_to_imap_server(const char *username, const char *password) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // The canvas on which we'll paint our connection
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Socket creation failed.\n");
        exit(1);
    }
    
    // Creating a beautiful memory of a server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    // A romantic journey to the IMAP server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Connection to server failed.\n");
        close(sock);
        exit(1);
    }
    
    // Whispering "LOGIN" in the soft hum of bytes
    receive_response(sock, buffer);
    printf("Server: %s\n", buffer);

    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(sock, command);
    receive_response(sock, buffer);
    printf("Login Response: %s\n", buffer);

    // The tender act of selecting the inbox
    send_command(sock, "A002 SELECT INBOX\r\n");
    receive_response(sock, buffer);
    printf("Select Inbox Response: %s\n", buffer);

    // Reading the sweet contents of the inbox
    send_command(sock, "A003 FETCH 1:* (FLAGS SUBJECT)\r\n");
    receive_response(sock, buffer);
    printf("Fetch Response: %s\n", buffer);

    // The art of disconnecting from the server, slowly and lovingly
    send_command(sock, "A004 LOGOUT\r\n");
    receive_response(sock, buffer);
    printf("Logout Response: %s\n", buffer);

    // The final farewell, when the connection fades into the void
    close(sock);
}

int main() {
    char username[100];
    char password[100];

    printf("Enter your IMAP username: ");
    scanf("%s", username);
    printf("Enter your IMAP password: ");
    scanf("%s", password); 

    // A flame ignites as we connect to the IMAP server
    connect_to_imap_server(username, password);
    
    return 0;
}