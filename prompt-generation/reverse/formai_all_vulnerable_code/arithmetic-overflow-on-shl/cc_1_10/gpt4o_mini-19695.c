//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define FTP_COMMAND_SIZE 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void ftp_authenticate(int sockfd, const char *username, const char *password) {
    char command[FTP_COMMAND_SIZE];
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, command, sizeof(command), 0); // receive response

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, command, sizeof(command), 0); // receive response
}

void ftp_list_files(int sockfd) {
    char command[FTP_COMMAND_SIZE];
    sprintf(command, "PASV\r\n");
    send(sockfd, command, strlen(command), 0);
    
    char response[BUFFER_SIZE];
    recv(sockfd, response, sizeof(response), 0); // receive response
    printf("Response: %s", response); // display server response

    // Extract IP address and port from PASV response
    int p1, p2, port;
    char *ptr = strchr(response, '(') + 1;
    sscanf(ptr, "%*d,%*d,%*d,%*d,%d,%d", &p1, &p2);
    port = (p1 << 8) + p2;

    // Connect to data port
    int data_sockfd;
    struct sockaddr_in data_addr;
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("Failed to create data socket");
    }

    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    data_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // assume localhost for this example

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Failed to connect to data socket");
    }

    // Request file listing
    sprintf(command, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, sizeof(response), 0); // receive response

    // Receive file list
    while (1) {
        int bytes_received = recv(data_sockfd, response, sizeof(response) - 1, 0);
        if (bytes_received <= 0) break; // check for termination
        response[bytes_received] = '\0'; // null-terminate string
        printf("%s", response); // print file list
    }

    close(data_sockfd); // close data socket
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Failed to open socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21); // standard FTP port
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed");
    }

    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer), 0); // get server greeting
    printf("Server: %s", buffer); // print the server greeting

    ftp_authenticate(sockfd, username, password);
    
    ftp_list_files(sockfd); // list files in FTP

    // Close the main control socket
    close(sockfd);

    return 0;
}