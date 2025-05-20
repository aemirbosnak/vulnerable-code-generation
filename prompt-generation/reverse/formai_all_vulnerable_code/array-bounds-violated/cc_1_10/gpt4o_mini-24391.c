//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_EMAILS 100
#define BUFFER_SIZE 4096
#define IMAP_PORT 993

// Function prototypes
void connect_to_imap(const char *server);
void fetch_email_list();
void print_email(const char *message);
void safe_send(int socket, const char *message);
char *safe_receive(int socket);
void handle_error(const char *msg);

int main() {
    char *server = "imap.gmail.com";  // Replace with your IMAP server
    connect_to_imap(server);
    return 0;
}

void connect_to_imap(const char *server) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Unable to create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    
    // Convert server IP to binary
    if(inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    printf("Connected to IMAP server %s\n", server);
    
    // Receive welcome message
    printf("%s", safe_receive(sock));
    
    // Authenticate and retrieve email list
    fetch_email_list(sock);
    
    close(sock);
}

void fetch_email_list(int sock) {
    char command[BUFFER_SIZE];
    
    // Send login command
    sprintf(command, "A001 LOGIN your-email@gmail.com your-password\r\n");
    safe_send(sock, command);

    // Process response
    printf("%s", safe_receive(sock));
    
    // Select mailbox
    sprintf(command, "A002 SELECT INBOX\r\n");
    safe_send(sock, command);
    
    // Process response
    printf("%s", safe_receive(sock));

    // Fetch email list
    sprintf(command, "A003 SEARCH ALL\r\n");
    safe_send(sock, command);
    
    // Process response and print emails
    char *response = safe_receive(sock);
    printf("%s", response);

    // Fetch individual emails if needed
    // Here you can parse the response and retrieve specific email messages.
    
    // Logout
    sprintf(command, "A004 LOGOUT\r\n");
    safe_send(sock, command);
    
    // Process logout response
    printf("%s", safe_receive(sock));
}

void print_email(const char *message) {
    // You can implement email parsing and formatting here
    printf("Email:\n%s\n", message);
}

void safe_send(int socket, const char *message) {
    if (send(socket, message, strlen(message), 0) < 0) {
        handle_error("Send failed");
    }
}

char *safe_receive(int socket) {
    static char buffer[BUFFER_SIZE];
    ssize_t bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    
    if (bytes_received < 0) {
        handle_error("Receive failed");
    }
    buffer[bytes_received] = '\0';
    return buffer;
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}