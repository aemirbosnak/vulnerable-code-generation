//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21

int main(int argc, char *argv[]) {
    int sock, bytes;
    char buffer[1024] = {0};
    struct sockaddr_in server_address = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from server
    if ((bytes = recv(sock, buffer, 1024, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("%s\n", buffer);
    }

    // Send user credentials
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    send(sock, username, strlen(username), 0);
    if ((bytes = recv(sock, buffer, 1024, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("%s\n", buffer);
    }
    printf("Enter password: ");
    scanf("%s", password);
    send(sock, password, strlen(password), 0);
    if ((bytes = recv(sock, buffer, 1024, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("%s\n", buffer);
    }

    // Send command to change directory
    char dir[100];
    printf("Enter directory: ");
    scanf("%s", dir);
    char cwd[100] = {0};
    sprintf(buffer, "CWD %s\r\n", dir);
    send(sock, buffer, strlen(buffer), 0);
    if ((bytes = recv(sock, buffer, 1024, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("%s\n", buffer);
    }

    // Send command to list directory contents
    sprintf(buffer, "LIST\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive directory listing from server
    while ((bytes = recv(sock, buffer, 1024, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(sock);

    return 0;
}