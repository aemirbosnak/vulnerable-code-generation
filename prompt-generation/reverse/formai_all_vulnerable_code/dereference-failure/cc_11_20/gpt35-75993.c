//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE], command[BUFFER_SIZE];
    struct sockaddr_in servaddr;
    struct hostent *server;

    // Check for arguments
    if (argc < 2) {
        fprintf(stderr,"Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    // Get server IP from hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        exit(1);
    }
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize server address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    memcpy(&servaddr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive greeting message from server
    memset(buffer, 0, BUFFER_SIZE);
    if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", buffer);

    // Login with username
    printf("Username: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    sprintf(command, "USER %s", buffer);
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", buffer);

    // Login with password
    printf("Password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    sprintf(command, "PASS %s", buffer);
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", buffer);

    // Enter passive mode
    send(sockfd, "PASV\r\n", 6, 0);
    memset(buffer, 0, BUFFER_SIZE);
    if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("Error receiving from server");
        exit(1);
    }

    // Extract port from passive mode response
    char *port_str = strtok(buffer, "(),");
    int port_num = 0;
    for (int i = 0; i < 4; i++) {
        port_num = port_num * 256 + atoi(port_str);
        port_str = strtok(NULL, "(),");
    }
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port_num);
    memcpy(&data_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Send list command to server and receive response
    send(sockfd, "LIST\r\n", 6, 0);
    memset(buffer, 0, BUFFER_SIZE);
    if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", buffer);

    // Connect to data port and receive response
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    char data[BUFFER_SIZE];
    memset(data, 0, BUFFER_SIZE);
    while ((n = recv(data_sockfd, data, BUFFER_SIZE, 0)) > 0) {
        printf("%s", data);
        memset(data, 0, BUFFER_SIZE);
    }
    if (n < 0) {
        perror("Error receiving from server");
        exit(1);
    }

    // Close sockets
    close(sockfd);
    close(data_sockfd);
    return 0;
}