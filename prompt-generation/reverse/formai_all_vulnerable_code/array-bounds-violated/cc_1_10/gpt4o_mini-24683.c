//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define COMMAND_BUFFER 256

void connectToFtpServer(int *sockfd, const char *serverIp) {
    struct sockaddr_in serverAddr;
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (*sockfd < 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    
    inet_pton(AF_INET, serverIp, &serverAddr.sin_addr);
    
    if (connect(*sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
}

void communicateWithFtpServer(int sockfd) {
    char buffer[BUFFER_SIZE];
    char command[COMMAND_BUFFER];
    char username[] = "username";  // Replace with the username
    char password[] = "password";  // Replace with the password
    int n;

    // Get server response
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("[Server]: %s\n", buffer);
    
    // Send USER command
    snprintf(command, COMMAND_BUFFER, "USER %s\r\n", username);
    write(sockfd, command, strlen(command));
    
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("[Server]: %s\n", buffer);
    
    // Send PASS command
    snprintf(command, COMMAND_BUFFER, "PASS %s\r\n", password);
    write(sockfd, command, strlen(command));

    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("[Server]: %s\n", buffer);
}

void listFiles(int sockfd) {
    char command[COMMAND_BUFFER];
    char buffer[BUFFER_SIZE];
    int n;

    // Send LIST command
    snprintf(command, COMMAND_BUFFER, "LIST\r\n");
    write(sockfd, command, strlen(command));
    
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    
    printf("[Files]: \n%s\n", buffer);
}

void disconnect(int sockfd) {
    close(sockfd);
    printf("Disconnected from the FTP server. Gritty neon shadows gather.\n");
}

int main() {
    int sockfd;
    char serverIp[30] = "192.168.1.55"; // Add your FTP server IP

    printf("Loading cyberpunk FTP client...\n");
    connectToFtpServer(&sockfd, serverIp);
    communicateWithFtpServer(sockfd);
    listFiles(sockfd);
    disconnect(sockfd);
    
    return 0;
}