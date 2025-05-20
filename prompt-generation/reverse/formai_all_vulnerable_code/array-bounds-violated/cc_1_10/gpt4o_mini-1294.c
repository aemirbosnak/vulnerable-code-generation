//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// FTP commands
#define FTP_PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Error sending command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving response");
    }
    buffer[bytes_received] = '\0';
    printf("Server Response: %s\n", buffer);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    sprintf(command, "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    sprintf(command, "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void ftp_list_files(int sockfd) {
    char command[BUFFER_SIZE];
    
    sprintf(command, "LIST\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
}

void ftp_get_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    
    sprintf(command, "RETR %s\r\n", filename);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // Here you can add logic to retrieve and save the file
}

void ftp_quit(int sockfd) {
    char command[] = "QUIT\r\n";
    send_command(sockfd, command);
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        error("Invalid address");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed");
    }

    printf("Connected to FTP server: %s\n", hostname);
    receive_response(sockfd); // Read the server's welcome message

    ftp_login(sockfd, username, password);
    ftp_list_files(sockfd);

    // Uncomment for file retrieval example
    // ftp_get_file(sockfd, "test.txt");

    ftp_quit(sockfd);
    close(sockfd);
    return 0;
}