//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
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

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n > 0) {
        buffer[n] = '\0';  // Null-terminate the string
        printf("Received: %s", buffer);
    } else {
        error("Failed to receive response from server");
    }
}

int main() {
    const char *ftp_server = "ftp.dlptest.com";
    const char *username = "dlpuser";
    const char *password = "rNrKYTX9g7z3RgJRmxWuGHbeu";
    
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("Error opening socket");

    // Configure server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, ftp_server, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or Address not supported\n");
        return -1;
    }

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        error("Connection failed");

    // Receive initial response
    receive_response(sockfd);
    
    // Send USER command
    char user_cmd[BUFFER_SIZE];
    snprintf(user_cmd, sizeof(user_cmd), "USER %s\r\n", username);
    send_command(sockfd, user_cmd);
    receive_response(sockfd);

    // Send PASS command
    char pass_cmd[BUFFER_SIZE];
    snprintf(pass_cmd, sizeof(pass_cmd), "PASS %s\r\n", password);
    send_command(sockfd, pass_cmd);
    receive_response(sockfd);

    // Send CWD command to change directory
    send_command(sockfd, "CWD /testdir\r\n");
    receive_response(sockfd);

    // Send LIST command to list files
    send_command(sockfd, "PASV\r\n");
     receive_response(sockfd); 
    printf("Initiated Passive Mode\n");
    
    // Establish a data connection
    struct sockaddr_in data_serv_addr;
    bzero((char *) &data_serv_addr, sizeof(data_serv_addr));
    data_serv_addr.sin_family = AF_INET;
    data_serv_addr.sin_port = htons(2021);  // The port should match server response
    
    // Create new socket for data connection
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) 
        error("Error opening data socket");
    
    // Bind to the new port
    if (bind(data_sockfd, (struct sockaddr *)&data_serv_addr, sizeof(data_serv_addr)) < 0) {
        error("Binding failed");
    }
    
    // Listen and accept incoming connection
    listen(data_sockfd, 5);
    
    // Send LIST command
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    // Accept connection from FTP server
    int new_sockfd = accept(data_sockfd, NULL, NULL);
    if (new_sockfd < 0) 
        error("Error on accept");

    // Receive file list
    char file_buffer[BUFFER_SIZE];
    while (recv(new_sockfd, file_buffer, sizeof(file_buffer) - 1, 0) > 0) {
        printf("%s", file_buffer);
    }

    // Cleanup sockets
    close(new_sockfd);
    close(data_sockfd);
    close(sockfd);

    printf("FTP operation completed, client shutting down.\n");
    return 0;
}