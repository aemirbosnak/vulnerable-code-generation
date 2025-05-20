//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

// Function to send commands to the FTP server
int send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    return 0;
}

// Function to receive a response from the FTP server
void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("%s\n", buffer);
    }
}

// Function to log in to the FTP server
void ftp_login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sock, command);
    receive_response(sock);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sock, command);
    receive_response(sock);
}

// Function to list files in the current directory
void ftp_list(int sock) {
    send_command(sock, "PASV\r\n");
    receive_response(sock);
    
    // You need to parse the response to get the IP and Port for data transfer
    // Here, we stub in values for demonstration
    char *data_ip = "127,0,0,1"; // This should be parsed from the PASV response
    char *data_port = "12345"; // This should also be parsed just like above
    
    struct sockaddr_in data_addr;
    int data_sock;
    
    // Prepare to connect to the data socket
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(atoi(data_port)); 
    inet_pton(AF_INET, data_ip, &data_addr.sin_addr);
    
    // Create the data socket
    data_sock = socket(AF_INET, SOCK_STREAM, 0);
    connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr));
    
    send_command(sock, "LIST\r\n");
    receive_response(sock);
    
    // Receive the list of files
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(data_sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(data_sock);
    receive_response(sock);
}

// Main function for the FTP client
int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }
    
    // Setup the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    // Receive server response
    receive_response(sock);
    
    // Log in
    ftp_login(sock, username, password);
    
    // List files
    ftp_list(sock);

    // Close the socket
    close(sock);
    
    return EXIT_SUCCESS;
}