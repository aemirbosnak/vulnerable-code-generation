//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_ftp_server(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Failed to create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
}

void read_response(int sockfd, char *response, size_t size) {
    memset(response, 0, size);
    recv(sockfd, response, size - 1, 0);
    printf("Server: %s", response);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    read_response(sockfd, response, sizeof(response));
    printf("Server replied to connection: %s", response);
    
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    read_response(sockfd, response, sizeof(response));

    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    read_response(sockfd, response, sizeof(response));
}

void ftp_list_files(int sockfd) {
    char response[BUFFER_SIZE];

    send_command(sockfd, "PASV");
    read_response(sockfd, response, sizeof(response));

    // Assume the response will provide us with a Data Connection IP and port
    int data_sockfd = connect_to_data_connection(response);
    
    send_command(sockfd, "LIST");
    read_response(sockfd, response, sizeof(response));
    
    // Read all data from data connection
    char data_response[BUFFER_SIZE];
    read(data_sockfd, data_response, sizeof(data_response));
    printf("File Listing:\n%s", data_response);

    close(data_sockfd);
}

int connect_to_data_connection(const char *response) {
    // Parsing the IP and port from the PASV response
    int p1, p2, port;
    char ip[16];
    sscanf(response, "227 Entering Passive Mode (%[^)])", ip);
    
    // Here we would extract the port from the IP response
    sscanf(response, "227 Entering Passive Mode (%[^,]),%d,%d", ip, &p1, &p2);
    port = p1 * 256 + p2;

    int data_sockfd;
    struct sockaddr_in data_addr;

    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("Failed to create data socket");
    }

    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &data_addr.sin_addr);
    data_addr.sin_port = htons(port);
    
    // Connect to data channel
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Failed to connect to data connection");
    }

    return data_sockfd;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ftp_server_ip> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ftp_server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_ftp_server(ftp_server_ip);

    // Log into FTP server
    ftp_login(sockfd, username, password);

    // List files in current directory
    ftp_list_files(sockfd);
    
    // Close the control connection
    close(sockfd);
    return EXIT_SUCCESS;
}