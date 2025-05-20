//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21
#define BUFFER_SIZE 1024

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error_handling("Sending failed");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error_handling("Receiving failed");
    }
    buffer[bytes_received] = '\0'; // Null-terminate the string
    printf("Server Response: %s", buffer);
}

void connect_to_ftp_server(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        error_handling("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Connection failed");
    }

    printf("Connected to FTP server at %s:%d\n", ip, port);
    receive_response(sockfd);

    // Implement login
    send_command(sockfd, "USER anonymous\r\n");
    receive_response(sockfd);
    
    send_command(sockfd, "PASS guest@example.com\r\n");
    receive_response(sockfd);

    // Change to passive mode
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // Upload a file
    int data_sockfd;
    struct sockaddr_in data_addr;
    int data_port;

    // Extract Data Port from PASV response
    // Response example: 227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).
    // A better implementation would use regex or string parsing.
    // For simplicity, let's assume p1 and p2 are set manually.
    data_port = 12345; // Dummy value for testing
    if ((data_sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        error_handling("Data socket creation failed");
    }
    
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr(ip);
    data_addr.sin_port = htons(data_port);

    if (bind(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error_handling("Binding failed");
    }

    if (listen(data_sockfd, 1) < 0) {
        error_handling("Listening failed");
    }

    // This simulates a file upload
    // In practice, you would open a file and read its contents
    send_command(sockfd, "STOR test_file.txt\r\n");
    receive_response(sockfd);

    // Open the file and copy it over data socket after connecting to it
    int client_data_sockfd;
    socklen_t addr_len = sizeof(data_addr);
    if ((client_data_sockfd = accept(data_sockfd, (struct sockaddr *)&data_addr, &addr_len)) < 0) {
        error_handling("Accepting data connection failed");
    }

    int file_fd = open("test_file.txt", O_RDONLY);
    if (file_fd < 0) {
        error_handling("File open failed");
    }

    char file_buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = read(file_fd, file_buffer, BUFFER_SIZE)) > 0) {
        send(client_data_sockfd, file_buffer, bytes_read, 0);
    }

    close(file_fd);
    close(client_data_sockfd);
    close(data_sockfd);
    close(sockfd);
    printf("File uploaded successfully.\n");
}

int main() {
    connect_to_ftp_server(SERVER_IP, SERVER_PORT);
    return 0;
}