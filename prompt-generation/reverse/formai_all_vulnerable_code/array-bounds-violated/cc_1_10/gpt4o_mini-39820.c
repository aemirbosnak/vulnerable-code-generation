//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define PORT 21

void error_handling(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("Socket creation failed");
    }
    return sockfd;
}

void connect_to_server(int sockfd, const char *server_ip) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Connection to server failed");
    }
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);  // FTP commands end with CRLF
}

void receive_response(int sockfd) {
    char buffer[BUF_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error_handling("Failed to receive response from server");
    }
    buffer[bytes_received] = '\0';  // Null-terminate the received data
    printf("Server: %s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUF_SIZE];

    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char command[BUF_SIZE];
    snprintf(command, sizeof(command), "PASV");  // Enter passive mode
    send_command(sockfd, command);
    receive_response(sockfd);

    // Assume the response contains the necessary info to establish a data connection
    // Here, we would split the response string to obtain the address and port

    snprintf(command, sizeof(command), "LIST");  // Request file list
    send_command(sockfd, command);
    receive_response(sockfd);
}

void close_connection(int sockfd) {
    char *command = "QUIT";
    send_command(sockfd, command);
    receive_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = create_socket();
    connect_to_server(sockfd, server_ip);
    receive_response(sockfd);  // Expect initial server greeting

    login(sockfd, username, password);

    list_files(sockfd);

    close_connection(sockfd);
    return 0;
}