//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "USER %s\r\n", username);
    send_command(sockfd, cmd);
    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", password);
    send_command(sockfd, cmd);
}

void ftp_download(int control_sockfd, const char *remote_file, const char *local_file) {
    int data_sockfd;
    struct sockaddr_in data_addr;
    char cmd[BUFFER_SIZE];

    // Prepare for data connection
    // Use passive mode to get IP and port
    send_command(control_sockfd, "PASV\r\n");

    // Here we parse the response to extract the data port
    char buffer[BUFFER_SIZE];
    recv(control_sockfd, buffer, BUFFER_SIZE, 0);
    int p1, p2;
    sscanf(buffer, "%*d %*d %*d %*d %*d %d,%d", &p1, &p2);
    int data_port = (p1 << 8) + p2;

    // Create data socket
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("Failed to create data socket");
    }
    
    // Bind and connect data socket
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Failed to connect data socket");
    }

    // Send RETR command
    snprintf(cmd, sizeof(cmd), "RETR %s\r\n", remote_file);
    send_command(control_sockfd, cmd);

    // Receive the file
    int file_fd = open(local_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file_fd < 0) {
        error("Failed to open local file");
    }

    ssize_t bytes;
    while ((bytes = recv(data_sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        write(file_fd, buffer, bytes);
    }

    close(file_fd);
    close(data_sockfd);
    printf("Download complete: %s to %s\n", remote_file, local_file);
}

void ftp_close(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Create control socket
    int control_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (control_sockfd < 0) {
        error("Failed to create control socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to FTP server
    if (connect(control_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Failed to connect to FTP server");
    }

    // Read the welcome message
    char buffer[BUFFER_SIZE];
    recv(control_sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Log in to the FTP server
    ftp_login(control_sockfd, username, password);

    // Download a file
    ftp_download(control_sockfd, "remote_file.txt", "local_file.txt");

    // Close the FTP connection
    ftp_close(control_sockfd);

    return EXIT_SUCCESS;
}