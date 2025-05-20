//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[64];
    char password[64];
    char command[MAX_COMMAND_LENGTH];
    char buffer[BUFFER_SIZE];
    int n;

    // Prompt user for server IP address
    printf("Enter server IP address: ");
    scanf("%s", inet_ntoa(server_addr.sin_addr));

    // Prompt user for username and password
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Connect to FTP server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    inet_pton(AF_INET, inet_ntoa(server_addr.sin_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Authenticate with server
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0 || strncmp(buffer, "331", 3)!= 0) {
        printf("Error authenticating with server\n");
        exit(1);
    }

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0 || strncmp(buffer, "230", 3)!= 0) {
        printf("Error authenticating with server\n");
        exit(1);
    }

    // Send commands to server
    printf("Enter FTP commands:\n");
    while (fgets(command, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        send(sockfd, command, strlen(command), 0);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    // Close connection to server
    close(sockfd);

    return 0;
}