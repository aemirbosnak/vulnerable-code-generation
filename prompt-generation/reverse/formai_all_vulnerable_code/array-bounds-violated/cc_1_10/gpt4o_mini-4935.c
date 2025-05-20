//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 21
#define DEFAULT_TIMEOUT 5

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void receive_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving response");
    }
    response[bytes_received] = '\0';
    printf("%s", response);
}

void connect_to_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Unable to create socket");
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    receive_response(sockfd);
    
    // Example: User authentication
    send_command(sockfd, "USER anonymous\r\n");
    receive_response(sockfd);
    send_command(sockfd, "PASS guest@\r\n");
    receive_response(sockfd);

    // Enter loop to process FTP commands
    char command[BUFFER_SIZE];
    while (1) {
        printf("ftp> ");
        if (!fgets(command, sizeof(command), stdin)) break;
        
        if (strcmp(command, "quit\r\n") == 0) {
            send_command(sockfd, "QUIT\r\n");
            receive_response(sockfd);
            break;
        }
        
        send_command(sockfd, command);
        receive_response(sockfd);
    }

    // Clean up
    close(sockfd);
}

void download_file(int sockfd, const char *filename) {
    // Set up passive mode
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // Sample implementation - You would have to extract port
    // For simplicity, assuming the FTP server gives us port immediately
    int data_sockfd;
    struct sockaddr_in data_addr;

    // Create data socket (simulated):
    if ((data_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Unable to create data socket");
    }

    // Simulating connection to data port:
    // In real implementation, extract from PASV response
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(2020); // Change to your server port
    inet_pton(AF_INET, "127.0.0.1", &data_addr.sin_addr);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Connection to data port failed");
    }

    // Sending file retrieval command
    char retr_command[BUFFER_SIZE];
    snprintf(retr_command, sizeof(retr_command), "RETR %s\r\n", filename);
    send_command(sockfd, retr_command);
    receive_response(sockfd);

    // Receiving file data
    FILE *file = fopen(filename, "wb");
    if (!file) {
        error("Failed to open file for writing");
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = recv(data_sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, file);
    }

    fclose(file);
    close(data_sockfd);
    printf("File %s downloaded successfully!\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    connect_to_server(argv[1]);
    return EXIT_SUCCESS;
}