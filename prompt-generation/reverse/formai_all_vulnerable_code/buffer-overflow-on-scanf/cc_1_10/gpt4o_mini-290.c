//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void ftp_send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0';  // Null-terminate for safe string handling
    printf("%s", buffer);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    ftp_send_command(sockfd, command);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    ftp_send_command(sockfd, command);
}

void ftp_list_files(int sockfd) {
    ftp_send_command(sockfd, "PASV\r\n");
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0';
    
    int p1, p2, port1, port2;
    sscanf(buffer, "227 Entering Passive Mode (%*[^,],%d,%d)", &port1, &port2);

    int pasv_port = port1 * 256 + port2;
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    data_addr.sin_port = htons(pasv_port);
    
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Data socket connection failed");
    }

    ftp_send_command(sockfd, "LIST\r\n");
    
    while (1) {
        int bytes_received = recv(data_sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) break;
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(data_sockfd);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0); // Receive the response after LIST
    printf("%s", buffer);
}

void ftp_download_file(int sockfd, const char *filename) {
    ftp_send_command(sockfd, "PASV\r\n");
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0';
    
    int p1, p2;
    sscanf(buffer, "227 Entering Passive Mode (%*[^,],%d,%d)", &p1, &p2);
    
    int data_port = p1 * 256 + p2;
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    data_addr.sin_port = htons(data_port);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Data socket connection failed");
    }

    snprintf(buffer, sizeof(buffer), "RETR %s\r\n", filename);
    ftp_send_command(sockfd, buffer);

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("Could not open file for writing");
    }

    while (1) {
        int bytes_received = recv(data_sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) break;
        fwrite(buffer, 1, bytes_received, fp);
    }

    fclose(fp);
    close(data_sockfd);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0); // Receive the response after RETR
    printf("%s", buffer);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Failed to open socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Could not connect to FTP server");
    }

    char username[100], password[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    ftp_login(sockfd, username, password);
    ftp_list_files(sockfd);

    char filename[100];
    printf("Enter filename to download: ");
    scanf("%s", filename);
    ftp_download_file(sockfd, filename);

    close(sockfd);
    return 0;
}