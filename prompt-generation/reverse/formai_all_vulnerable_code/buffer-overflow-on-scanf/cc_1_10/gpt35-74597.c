//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define MAX_USERNAME 50
#define MAX_PASSWORD 50

int main(int argc, char *argv[]) {
    char *server_address = "imap.gmail.com";
    int server_port = 993;
    int client_socket;
    struct sockaddr_in server_addr;
    
    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Error: Could not create socket");
        return 1;
    }
    
    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    
    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to server");
        return 1;
    }
    
    // Send login credentials
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    char login_command[MAX_BUFFER];
    sprintf(login_command, "LOGIN %s %s\r\n", username, password);
    send(client_socket, login_command, strlen(login_command), 0);
    
    // Receive response from server
    char server_response[MAX_BUFFER];
    recv(client_socket, server_response, MAX_BUFFER, 0);
    printf("%s", server_response);
    
    // Send command to select mailbox
    char select_command[MAX_BUFFER];
    sprintf(select_command, "SELECT INBOX\r\n");
    send(client_socket, select_command, strlen(select_command), 0);
    
    return 0;
}