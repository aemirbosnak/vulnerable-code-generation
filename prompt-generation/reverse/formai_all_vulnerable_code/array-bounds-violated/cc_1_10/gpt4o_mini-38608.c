//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error_handler(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Command Sent: %s", command);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Response Received: %s", buffer);
        if (buffer[0] == '2' || buffer[0] == '3')  // Response code starts with 2 or 3
            break;
    }
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    // Send USER command
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char command[BUFFER_SIZE];
    int data_sock;

    // Send PASV command to switch to passive mode
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // Assuming the server responds with the IP and port in PASV response
    // Parse this response to extract the IP and port for the data connection
    // Here we will use static values; in production, parse the actual response
    char *ip = "127,0,0,1";  // Dummy IP; you typically parse from response
    int port = 20;           // Dummy port; you typically parse from response

    // Establish data connection
    data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        error_handler("Data Socket Creation Failed");
    }

    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &data_addr.sin_addr);

    if (connect(data_sock, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0) {
        error_handler("Data Connection Failed");
    }

    // Send LIST command to the server
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    // Receive and print directory listing
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(data_sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("File List: %s", buffer);
    }

    close(data_sock);
}

void download_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    int data_sock;

    // Send PASV command to switch to passive mode
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // Use static values for IP and port; in production, parse the actual response
    char *ip = "127,0,0,1";  // Dummy IP
    int port = 20;           // Dummy port

    // Establish data connection
    data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        error_handler("Data Socket Creation Failed");
    }

    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &data_addr.sin_addr);

    if (connect(data_sock, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0) {
        error_handler("Data Connection Failed");
    }

    // Send RETR command to download the file
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Receive the file and save it locally
    FILE *file = fopen(filename, "wb");
    if (!file) {
        error_handler("File Creation Failed");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(data_sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);
    close(data_sock);
    printf("File downloaded: %s\n", filename);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handler("Socket Creation Failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Connect to localhost for testing

    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error_handler("Connection to FTP Server Failed");
    }

    receive_response(sockfd);

    // Sample login credentials
    login(sockfd, "username", "password");
    
    // List files in the current directory
    list_files(sockfd);

    // Download a specific file
    download_file(sockfd, "example.txt");

    // Close the socket
    close(sockfd);
    return 0;
}