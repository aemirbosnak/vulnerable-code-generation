//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "mail.cyberworld.com"
#define PORT 110
#define BUFFER_SIZE 4096
#define MAX_EMAILS 100

typedef struct {
    char sender[50];
    char subject[100];
    char date[30];
} Email;

void connectToServer(int *sock, struct sockaddr_in *server_addr);
void sendCommand(int sock, const char *cmd);
void receiveResponse(int sock);
void listEmails(int sock);
void getEmail(int sock, int emailIndex);
void parseEmail(char *response);

int main() {
    int sock;
    struct sockaddr_in server_addr;

    connectToServer(&sock, &server_addr);

    // Authenticate with the server
    sendCommand(sock, "USER hacker");
    receiveResponse(sock);
    sendCommand(sock, "PASS supersecretpassword");
    receiveResponse(sock);

    // List emails in the inbox
    listEmails(sock);
    
    // Get a specific email
    getEmail(sock, 1);  // Grab the first email for demonstration purposes

    // Logout and clean up
    sendCommand(sock, "QUIT");
    receiveResponse(sock);
    close(sock);

    return 0;
}

void connectToServer(int *sock, struct sockaddr_in *server_addr) {
    *sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (*sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(PORT);
    server_addr->sin_addr.s_addr = inet_addr(SERVER);

    if (connect(*sock, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        perror("Connection to the server failed");
        exit(EXIT_FAILURE);
    }
}

void sendCommand(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    send(sock, "\r\n", 2, 0);
}

void receiveResponse(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate the response
        printf("Server: %s", buffer);
    } else {
        perror("Failed to receive data");
    }
}

void listEmails(int sock) {
    sendCommand(sock, "LIST");
    receiveResponse(sock);
}

void getEmail(int sock, int emailIndex) {
    char cmd[20];
    sprintf(cmd, "RETR %d", emailIndex);
    sendCommand(sock, cmd);
    receiveResponse(sock);
}

void parseEmail(char *response) {
    // In a real POP3 response, this would parse the message.
    printf("Email Content: \n%s\n", response);
}