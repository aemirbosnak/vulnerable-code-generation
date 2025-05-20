//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0';
    printf("%s", buffer);
}

void login(int sockfd) {
    char username[256], password[256];
    printf("Enter FTP Username: ");
    scanf("%s", username);
    printf("Enter FTP Password: ");
    scanf("%s", password);
    
    send_command(sockfd, "USER ");
    send_command(sockfd, username);
    
    send_command(sockfd, "PASS ");
    send_command(sockfd, password);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV");
    // In a complete implementation, you would open a data connection here
    send_command(sockfd, "LIST");
}

void download_file(int sockfd) {
    char filename[256];
    printf("Enter the filename to download: ");
    scanf("%s", filename);
    
    send_command(sockfd, "RETR ");
    send_command(sockfd, filename);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to your FTP server IP
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
    
    char welcome_message[BUFFER_SIZE];
    recv(sockfd, welcome_message, BUFFER_SIZE - 1, 0);
    printf("%s", welcome_message);
    
    login(sockfd);
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. List Files\n");
        printf("2. Download File\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                list_files(sockfd);
                break;
            case 2:
                download_file(sockfd);
                break;
            case 3:
                printf("Goodbye! 😊\n");
                close(sockfd);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    close(sockfd);
    return 0;
}