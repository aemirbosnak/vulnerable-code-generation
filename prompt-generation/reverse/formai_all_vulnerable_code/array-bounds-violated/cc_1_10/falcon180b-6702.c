//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define MAX_LINE_LENGTH 80

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char command[MAX_LINE_LENGTH];
    char response[BUFFER_SIZE];
    int n, len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    printf("Enter the IP address of the FTP server: ");
    scanf("%s", &buffer);

    // Get server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, buffer, &serv_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    // Send USER command
    sprintf(command, "USER %s\r\n", argv[1]);
    send(sockfd, command, strlen(command), 0);

    // Receive response
    memset(response, 0, BUFFER_SIZE);
    len = recv(sockfd, response, BUFFER_SIZE, 0);
    response[len] = '\0';
    printf("Server response: %s\n", response);

    // Send PASS command
    sprintf(command, "PASS %s\r\n", argv[2]);
    send(sockfd, command, strlen(command), 0);

    // Receive response
    memset(response, 0, BUFFER_SIZE);
    len = recv(sockfd, response, BUFFER_SIZE, 0);
    response[len] = '\0';
    printf("Server response: %s\n", response);

    // Send LIST command
    sprintf(command, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);

    // Receive response
    memset(response, 0, BUFFER_SIZE);
    len = recv(sockfd, response, BUFFER_SIZE, 0);
    response[len] = '\0';
    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}