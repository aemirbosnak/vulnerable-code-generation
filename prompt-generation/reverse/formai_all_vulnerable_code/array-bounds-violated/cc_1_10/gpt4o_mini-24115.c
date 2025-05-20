//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define FTP_PORT 21
#define BUFFER_SIZE 4096

void error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("Failed to send command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (buffer[bytes_received-1] == '\n') {
            break;
        }
    }

    if (bytes_received < 0) {
        error("Failed to receive response");
    }
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void ftp_retrieve_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        error("Failed to open file for writing");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, fp);
    }
    
    if (bytes_received < 0) {
        error("Failed to receive file");
    }

    fclose(fp);
    printf("File retrieved: %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Could not create socket");
    }
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Could not connect to FTP server");
    }

    receive_response(sockfd);
    ftp_login(sockfd, username, password);
    ftp_retrieve_file(sockfd, "example.txt");
    
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}