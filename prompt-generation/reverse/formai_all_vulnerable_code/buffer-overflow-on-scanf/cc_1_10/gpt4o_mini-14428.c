//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function declarations
void show_menu();
int connect_to_server(const char *hostname, int port);
void login(int sockfd);
void get_file(int sockfd);
void put_file(int sockfd);
void close_connection(int sockfd);

int main() {
    const char *hostname = "ftp.example.com"; // Replace with your FTP server
    int port = 21; // Standard FTP port
    int sockfd;

    sockfd = connect_to_server(hostname, port);
    if (sockfd < 0) {
        return 1; // Connection failed
    }

    login(sockfd);

    int choice;
    do {
        show_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                get_file(sockfd);
                break;
            case 2:
                put_file(sockfd);
                break;
            case 3:
                close_connection(sockfd);
                break;
            default:
                printf("Exiting...\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void show_menu() {
    printf("Menu:\n");
    printf("1. Get file from server\n");
    printf("2. Put file to server\n");
    printf("3. Close connection\n");
    printf("0. Exit\n");
}

int connect_to_server(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        return -1;
    }

    printf("Connected to FTP server at %s:%d\n", hostname, port);
    return sockfd;
}

void login(int sockfd) {
    char buffer[BUFFER_SIZE];
    char username[50], password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s\n", buffer);

    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s\n", buffer);
}

void get_file(int sockfd) {
    char buffer[BUFFER_SIZE];
    char filename[50];

    printf("Enter filename to get: ");
    scanf("%s", filename);
    
    snprintf(buffer, sizeof(buffer), "RETR %s\r\n", filename);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s\n", buffer);

    // Logic to download file should be implemented here

    printf("File retrieval implemented here.\n");
}

void put_file(int sockfd) {
    char buffer[BUFFER_SIZE];
    char filename[50];

    printf("Enter filename to put: ");
    scanf("%s", filename);

    snprintf(buffer, sizeof(buffer), "STOR %s\r\n", filename);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s\n", buffer);

    // Logic to upload file should be implemented here

    printf("File upload implemented here.\n");
}

void close_connection(int sockfd) {
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s\n", buffer);

    close(sockfd);
    printf("Connection closed.\n");
}