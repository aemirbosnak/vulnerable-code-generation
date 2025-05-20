//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char** argv) {
    
    char* server_address = "mail.example.com";
    char* username = "john.doe";
    char* password = "password";

    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Get server address details
    struct hostent* server_host = gethostbyname(server_address);
    if (server_host == NULL) {
        perror("Could not resolve server address");
        exit(1);
    }

    // Set server address information
    struct sockaddr_in server_address_info;
    memset(&server_address_info, 0, sizeof(server_address_info));
    server_address_info.sin_family = AF_INET;
    server_address_info.sin_port = htons(110);
    memcpy(&server_address_info.sin_addr.s_addr, server_host->h_addr, server_host->h_length);

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_address_info, sizeof(server_address_info)) < 0) {
        perror("Connection to server failed");
        exit(1);
    }

    // Receive server greeting
    char buffer[MAX_BUFFER_SIZE];
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive greeting from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send user credentials
    sprintf(buffer, "USER %s\r\n", username);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send user credentials");
        exit(1);
    }
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send password
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send password");
        exit(1);
    }
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send QUIT command");
        exit(1);
    }
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(client_socket);

    return 0;
}