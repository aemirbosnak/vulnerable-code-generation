//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Enter IP address of server: ");
    scanf("%s", &server_addr.sin_addr.s_addr);

    printf("Enter port number of server: ");
    scanf("%d", &server_addr.sin_port);

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    // login
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    char login_command[50];
    sprintf(login_command, "USER %s\r\n", username);
    send(sockfd, login_command, strlen(login_command), 0);

    char pass_command[50];
    sprintf(pass_command, "PASS %s\r\n", password);
    send(sockfd, pass_command, strlen(pass_command), 0);

    // receive response
    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);

    if (bytes_received > 0) {
        printf("Response from server: %s", response);
    }

    // send commands
    char command[50];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        send(sockfd, command, strlen(command), 0);

        // receive response
        memset(response, 0, BUFFER_SIZE);
        bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);

        if (bytes_received > 0) {
            printf("Response from server: %s", response);
        }
    }

    // close socket
    close(sockfd);

    return 0;
}