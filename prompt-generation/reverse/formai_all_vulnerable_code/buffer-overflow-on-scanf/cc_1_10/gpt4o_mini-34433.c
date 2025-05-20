//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

void recursive_ftp_put(int sockfd, const char *filename, const char *path);
void send_file(int sockfd, const char *filename);
void handle_ftp_response(int sockfd);
void change_directory(int sockfd, const char *path);
void user_login(int sockfd, const char *username, const char *password);
void ftp_put(int sockfd, const char *path, const char *filename);
void ftp_get(int sockfd, const char *filename);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1"; // Replace with actual server IP
    char username[50], password[50];
    char filename[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21); // Default FTP port
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to FTP server failed");
        exit(EXIT_FAILURE);
    }

    handle_ftp_response(sockfd);

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    user_login(sockfd, username, password);

    printf("Enter file name to upload: ");
    scanf("%s", filename);
    recursive_ftp_put(sockfd, filename, "/uploaded/");

    close(sockfd);
    return 0;
}

void user_login(int sockfd, const char *username, const char *password) {
    char command[512];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    handle_ftp_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    handle_ftp_response(sockfd);
}

void handle_ftp_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Server: %s", buffer);
    }
}

void ftp_put(int sockfd, const char *path, const char *filename) {
    char command[512];
    snprintf(command, sizeof(command), "CWD %s\r\n", path);
    send(sockfd, command, strlen(command), 0);
    handle_ftp_response(sockfd);

    send_file(sockfd, filename);
}

void send_file(int sockfd, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("File opening failed");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
        if (bytes_read > 0) {
            send(sockfd, buffer, bytes_read, 0);
        }
        if (bytes_read < sizeof(buffer)) {
            if (feof(file))
                break;
            if (ferror(file)) {
                perror("Error reading from file");
                break;
            }
        }
    }
    fclose(file);
}

void recursive_ftp_put(int sockfd, const char *filename, const char *path) {
    char command[512];
    snprintf(command, sizeof(command), "TYPE I\r\n"); // Set binary mode
    send(sockfd, command, strlen(command), 0);
    handle_ftp_response(sockfd);

    ftp_put(sockfd, path, filename);

    // For demo purposes, we're assuming a hierarchy; implement recursion here
    if (strstr(filename, ".txt")) { // Dummy check for demonstration
        printf("Recursively processing %s... \n", filename);
        // Call recursive_ftp_put for child files/folders here
    }
}