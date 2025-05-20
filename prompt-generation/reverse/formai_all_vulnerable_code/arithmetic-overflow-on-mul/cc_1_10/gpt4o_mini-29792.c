//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define PORT 21

void ftp_login(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];
    
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
}

void ftp_list_files(int sockfd) {
    char buffer[BUFFER_SIZE];
    
    send(sockfd, "PASV\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Extract IP and port for data connection
    int p1, p2;
    char ip[16];
    sscanf(buffer, "227 Entering Passive Mode (%[^)])", ip);
    sscanf(buffer, "227 Entering Passive Mode (%*[^,],%*[^,],%d,%d)", &p1, &p2);
    int data_port = p1 * 256 + p2;

    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    inet_pton(AF_INET, ip, &data_addr.sin_addr);
    
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Data connection failed");
        return;
    }

    send(sockfd, "LIST\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    
    while (recv(data_sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
    }

    close(data_sockfd);
    printf("Files listed successfully!\n\n");
}

void ftp_download_file(int sockfd, const char *filename) {
    char buffer[BUFFER_SIZE];
    
    send(sockfd, "PASV\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    int p1, p2;
    char ip[16];
    sscanf(buffer, "227 Entering Passive Mode (%[^)])", ip);
    sscanf(buffer, "227 Entering Passive Mode (%*[^,],%*[^,],%d,%d)", &p1, &p2);
    int data_port = p1 * 256 + p2;

    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    inet_pton(AF_INET, ip, &data_addr.sin_addr);
    
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Data connection failed");
        return;
    }

    sprintf(buffer, "RETR %s\r\n", filename);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        close(data_sockfd);
        return;
    }

    while (1) {
        int bytes_received = recv(data_sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break; // End of file
        }
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);
    close(data_sockfd);
    printf("File downloaded successfully!\n\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ftp_server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to FTP server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer); // Welcome message

    ftp_login(sockfd, username, password);
    ftp_list_files(sockfd);
    ftp_download_file(sockfd, "example.txt");

    close(sockfd);
    return 0;
}