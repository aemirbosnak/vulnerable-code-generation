//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 21

void error_handler(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void ftp_send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error_handler("Failed to send command");
    }
}

void ftp_receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error_handler("Failed to receive response");
    }

    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    ftp_send_command(sockfd, command);
    ftp_receive_response(sockfd);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    ftp_send_command(sockfd, command);
    ftp_receive_response(sockfd);
}

void ftp_retrieve_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    ftp_send_command(sockfd, command);
    ftp_receive_response(sockfd);
}

void ftp_download_file(int sockfd, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        error_handler("Cannot open file for writing");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, file);
    }

    fclose(file);
    printf("File downloaded successfully: %s\n", filename);
}

void ftp_command_mode(int sockfd) {
    char command[BUFFER_SIZE];
    
    while (1) {
        printf("Enter FTP command (or 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);
        
        if (strncmp(command, "exit", 4) == 0) {
            break;
        }
        
        ftp_send_command(sockfd, command);
        ftp_receive_response(sockfd);
    }
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
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handler("Failed to open socket");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        error_handler("No such host");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handler("Failed to connect to server");
    }

    ftp_receive_response(sockfd);
    ftp_login(sockfd, username, password);
    
    ftp_command_mode(sockfd);

    close(sockfd);
    return 0;
}