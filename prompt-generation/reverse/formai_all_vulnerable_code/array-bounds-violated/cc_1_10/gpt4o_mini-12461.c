//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) == -1) {
        error("send command failed");
    }
    send(sockfd, "\r\n", 2, 0); // FTP commands are followed by CRLF
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int nbytes;

    do {
        nbytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (nbytes < 0) {
            error("recv failed");
        }
        buffer[nbytes] = '\0';  // Null terminate the string
        printf("%s", buffer);
    } while (nbytes > 0 && buffer[nbytes - 1] != '\n');
}

void login(int sockfd, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];

    // Send USER command
    snprintf(cmd, sizeof(cmd), "USER %s", username);
    send_command(sockfd, cmd);
    receive_response(sockfd);

    // Send PASS command
    snprintf(cmd, sizeof(cmd), "PASS %s", password);
    send_command(sockfd, cmd);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char cmd[BUFFER_SIZE];
    int data_sockfd;
    struct sockaddr_in data_addr;
    socklen_t addr_len = sizeof(data_addr);

    // Set up the data connection
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("Could not create data socket");
    }

    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(0);  // Use any available port
    data_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Could not bind data socket");
    }

    listen(data_sockfd, 5);
    
    // Get the port number
    socklen_t len = sizeof(data_addr);
    getsockname(data_sockfd, (struct sockaddr *)&data_addr, &len);
    int port = ntohs(data_addr.sin_port);

    // Send PASV command to the server
    snprintf(cmd, sizeof(cmd), "PASV");
    send_command(sockfd, cmd);
    receive_response(sockfd);

    // Establish data connection
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Data connection failed");
    }

    // Send LIST command
    snprintf(cmd, sizeof(cmd), "LIST");
    send_command(sockfd, cmd);
    receive_response(sockfd);

    // Now receive the file list (output will be received on data_sockfd)
    char buffer[BUFFER_SIZE];
    int nbytes;
    while ((nbytes = recv(data_sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[nbytes] = '\0';
        printf("%s", buffer);
    }

    close(data_sockfd);
    receive_response(sockfd);  // Final response after LIST
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Could not create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Could not connect to FTP server");
    }

    receive_response(sockfd); // response after connection

    // Perform FTP login
    login(sockfd, username, password);

    // List files in the current directory
    list_files(sockfd);
    
    // Close the socket
    close(sockfd);

    return 0;
}