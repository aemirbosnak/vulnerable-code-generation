//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define SERVER_IP "192.168.1.1" // Replace with your FTP server IP

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Failed to read response");
    }
    buffer[bytes_received] = '\0';
    printf("Server Response: %s", buffer);
}

void upload_file(int sock, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return;
    }
    
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(sock, buffer, bytes_read, 0);
    }
    fclose(file);
}

void download_file(int sock, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("File opening failed");
        return;
    }
    
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }
    fclose(file);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char command[BUFFER_SIZE];

    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Socket creation failed");
    }

    // Setting up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connecting to the FTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to FTP server failed");
    }

    receive_response(sock); // Receive server's welcome message

    // User authentication (replace with your credentials)
    send_command(sock, "USER anonymous\r\n");
    receive_response(sock);
    send_command(sock, "PASS anonymous\r\n");
    receive_response(sock);

    // File upload
    printf("Uploading 'test.txt'...\n");
    send_command(sock, "STOR test.txt\r\n");
    receive_response(sock);
    upload_file(sock, "test.txt");
    printf("File uploaded successfully.\n");

    // File download
    printf("Downloading 'downloaded.txt'...\n");
    send_command(sock, "RETR test.txt\r\n");
    receive_response(sock);
    download_file(sock, "downloaded.txt");
    printf("File downloaded successfully.\n");

    // Ending the session
    send_command(sock, "QUIT\r\n");
    receive_response(sock);

    // Closing the socket
    close(sock);
    return 0;
}