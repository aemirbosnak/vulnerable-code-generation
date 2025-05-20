//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "ftp.dlptest.com"
#define PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("ERROR sending command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("ERROR receiving response");
    }
    buffer[n] = '\0'; // null-terminate the buffer
    printf("%s", buffer);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // USER command
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    // PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char command[BUFFER_SIZE];
    
    // PASV command to enter passive mode
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);
    
    // Creating a new connection to fetch the files
    int data_sockfd, port1, port2;
    struct sockaddr_in data_addr;
    
    // Parsing port from response
    // Assuming the response format is "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2)."
    char response[BUFFER_SIZE];
    int n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0'; // null-terminate
    sscanf(strstr(response, "(") + 1, "%*[^,],%*[^,],%*[^,],%*[^,],%d,%d", &port1, &port2);
    
    // Calculate port number
    int port = (port1 << 8) + port2;

    // Create data socket
    if ((data_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("ERROR opening data socket");
    }
    
    // Set up the sockaddr_in struct for data connection
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    struct hostent *server = gethostbyname(SERVER);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    memcpy(&data_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    
    // Connect to data port
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("ERROR connecting to data socket");
    }
    
    // LIST command
    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // Receive file list from data socket
    char file_buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(data_sockfd, file_buffer, sizeof(file_buffer) - 1, 0)) > 0) {
        file_buffer[bytes_received] = '\0'; // null-terminate
        printf("%s", file_buffer);
    }
    
    // Close data socket
    close(data_sockfd);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("ERROR opening socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Resolve hostname
    struct hostent *server = gethostbyname(SERVER);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    
    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    
    // Receive welcome message
    receive_response(sockfd);
    
    // Login to server
    ftp_login(sockfd, "dlpuser", "rNrKYTX9g7z3RgJRMXeiw");
    
    // List files in directory
    list_files(sockfd);
    
    // Close main socket
    close(sockfd);
    return 0;
}