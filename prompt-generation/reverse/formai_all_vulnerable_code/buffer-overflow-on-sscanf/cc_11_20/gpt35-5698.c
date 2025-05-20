//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FTP_PORT 21
#define COMMAND_SIZE 1024
#define RESPONSE_SIZE 8192

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char command[COMMAND_SIZE];
    char response[RESPONSE_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR creating socket");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        error("ERROR invalid server address");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting to server");
    }

    // Receive welcome message from server
    memset(response, 0, RESPONSE_SIZE);
    if (recv(sockfd, response, RESPONSE_SIZE-1, 0) < 0) {
        error("ERROR receiving welcome message from server");
    }
    printf("%s", response);

    // Login
    memset(command, 0, COMMAND_SIZE);
    sprintf(command, "USER %s\r\n", argv[2]);
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("ERROR sending username to server");
    }
    memset(response, 0, RESPONSE_SIZE);
    if (recv(sockfd, response, RESPONSE_SIZE-1, 0) < 0) {
        error("ERROR receiving response from server");
    }
    printf("%s", response);
    
    memset(command, 0, COMMAND_SIZE);
    sprintf(command,"PASS %s\r\n",argv[3]);
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("ERROR sending password to server");
    }
    memset(response, 0, RESPONSE_SIZE);
    if (recv(sockfd, response, RESPONSE_SIZE-1, 0) < 0) {
        error("ERROR receiving response from server");
    }
    printf("%s", response);

    // Change directory to remote folder
    memset(command, 0, COMMAND_SIZE);
    sprintf(command, "CWD %s\r\n", argv[4]);
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("ERROR sending change directory command to server");
    }
    memset(response, 0, RESPONSE_SIZE);
    if (recv(sockfd, response, RESPONSE_SIZE-1, 0) < 0) {
        error("ERROR receiving response from server");
    }
    printf("%s", response);

    // Enable passive mode
    memset(command, 0, COMMAND_SIZE);
    sprintf(command, "PASV\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("ERROR sending passive mode command to server");
    }
    memset(response, 0, RESPONSE_SIZE);
    if (recv(sockfd, response, RESPONSE_SIZE-1, 0) < 0) {
        error("ERROR receiving response from server");
    }
    printf("%s", response);

    // Get file list from server
    int data_sockfd;
    struct sockaddr_in data_server_addr;
    char *ip_str;
    int port, ip[4];
    sscanf(response, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &ip[0], &ip[1], &ip[2], &ip[3], &port, &port);
    ip_str = (char*)malloc(strlen(response));
    sprintf(ip_str, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    memset(&data_server_addr, 0, sizeof(data_server_addr));
    data_server_addr.sin_family = AF_INET;
    data_server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_str, &data_server_addr.sin_addr) <= 0) {
        error("ERROR invalid data server address");
    }
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("ERROR creating data socket");
    }
    if (connect(data_sockfd, (struct sockaddr*)&data_server_addr, sizeof(data_server_addr)) < 0) {
        error("ERROR connecting to data server");
    }
    memset(command, 0, COMMAND_SIZE);
    sprintf(command, "LIST\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("ERROR sending list command to server");
    }
    memset(response, 0, RESPONSE_SIZE);
    if (recv(sockfd, response, RESPONSE_SIZE-1, 0) < 0) {
        error("ERROR receiving response from server");
    }
    printf("%s", response);
    char data_response[RESPONSE_SIZE];
    memset(data_response, 0, RESPONSE_SIZE);
    while (recv(data_sockfd, data_response, RESPONSE_SIZE-1, 0) > 0) {
        printf("%s", data_response);
        memset(data_response, 0, RESPONSE_SIZE);
    }
    close(data_sockfd);

    // Quit
    memset(command, 0, COMMAND_SIZE);
    sprintf(command, "QUIT\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("ERROR sending quit command to server");
    }
    memset(response, 0, RESPONSE_SIZE);
    if (recv(sockfd, response, RESPONSE_SIZE-1, 0) < 0) {
        error("ERROR receiving response from server");
    }
    printf("%s", response);

    close(sockfd);
    return 0;
}