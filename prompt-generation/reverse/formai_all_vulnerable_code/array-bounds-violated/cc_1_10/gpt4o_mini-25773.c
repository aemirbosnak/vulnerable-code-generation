//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 21
#define BUFFER_SIZE 1024

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("socket creation failed");
    }
    return sockfd;
}

void connect_to_server(int sockfd, const char *server_ip) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid server IP address");
    }
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE] = {0};
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        handle_error("Failed to receive response");
    }
    buffer[bytes_received] = '\0';
    printf("Response: %s\n", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    sprintf(command, "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    sprintf(command, "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);
    // Normally we'd need to parse the response to get the data connection details,
    // but for simplicity, let's just send LIST command.
    
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

void terminate_connection(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <FTP_SERVER_IP> <USERNAME> <PASSWORD>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = create_socket();
    connect_to_server(sockfd, server_ip);
    
    receive_response(sockfd);  // Initial server greeting

    login(sockfd, username, password);
    
    list_files(sockfd);
    
    terminate_connection(sockfd);

    return 0;
}