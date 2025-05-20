//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

void receive_response(int sockfd, char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("Server Response: %s", buffer);
}

void authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd, response);
}

void list_files(int sockfd) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "PASV\r\n");
    send_command(sockfd, command);
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);

    // Extract IP and port for data connection
    int p1, p2, ip1, ip2, ip3, ip4;
    sscanf(response, "%*d %*d %*d %d,%d,%d,%d,%d,%d",
           &ip1, &ip2, &ip3, &ip4, &p1, &p2);
    int data_port = p1 * 256 + p2;

    // Create data socket
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    inet_pton(AF_INET, (char[]){ip1, ip2, ip3, ip4}, &data_addr.sin_addr);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Error connecting to data socket");
    }

    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(sockfd, command);
    receive_response(sockfd, response);

    // Receive file list
    char buffer[BUFFER_SIZE];
    while (recv(data_sockfd, buffer, sizeof(buffer) - 1, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(data_sockfd);
    snprintf(command, sizeof(command), "QUIT\r\n");
    send_command(sockfd, command);
    receive_response(sockfd, response);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_server(hostname);
    
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);
    
    authenticate(sockfd, username, password);
    list_files(sockfd);

    close(sockfd);
    return 0;
}