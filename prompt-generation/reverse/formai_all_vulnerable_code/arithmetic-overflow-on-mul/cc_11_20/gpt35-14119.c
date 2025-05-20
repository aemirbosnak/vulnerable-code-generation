//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    // Define server address and port number
    char* server_ip = "127.0.0.1";
    int server_port = 21;

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    // Receive greeting message from server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive error");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", buffer);

    // Send login credentials to server
    char* username = "ftpuser";
    char* password = "ftppasswd";
    char login_buffer[BUFFER_SIZE];
    memset(login_buffer, 0, BUFFER_SIZE);
    sprintf(login_buffer, "USER %s\r\nPASS %s\r\n", username, password);
    if (send(sock, login_buffer, strlen(login_buffer), 0) < 0) {
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    // Receive login response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive error");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", buffer);

    // Send PASV command to server
    char pasv_buffer[BUFFER_SIZE];
    memset(pasv_buffer, 0, BUFFER_SIZE);
    sprintf(pasv_buffer, "PASV\r\n");
    if (send(sock, pasv_buffer, strlen(pasv_buffer), 0) < 0) {
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    // Receive PASV response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive error");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", buffer);

    // Parse PASV response to obtain data port number
    int data_port;
    int a,b,c,d,p1,p2;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\r\n", &a,&b,&c,&d,&p1,&p2);
    data_port = p1 * 256 + p2;

    // Connect to data port
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    if (inet_pton(AF_INET, server_ip, &data_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(data_sock, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    // Send LIST command to server
    char list_buffer[BUFFER_SIZE];
    memset(list_buffer, 0, BUFFER_SIZE);
    sprintf(list_buffer, "LIST\r\n");
    if (send(sock, list_buffer, strlen(list_buffer), 0) < 0) {
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    // Receive directory listing from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(data_sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive error");
        exit(EXIT_FAILURE);
    }
    printf("Directory Listing:\n%s", buffer);

    // Cleanup and exit
    close(data_sock);
    close(sock);
    return 0;
}