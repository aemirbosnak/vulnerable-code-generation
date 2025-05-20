//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

// Function to check server response
void server_response(int sock_fd) {
    char buffer[MAXSIZE];
    int code;
    read(sock_fd, buffer, sizeof(buffer));
    sscanf(buffer, "%d", &code);
    printf("%s", buffer + 4);  // print response message
    if (code != 220) {  // check if not connected
        exit(EXIT_FAILURE);
    }
}

// Function to download file
void download_file(int sock_fd, char *filename) {
    FILE *file = fopen(filename, "wb");  // open file in write binary mode
    if (file == NULL) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    int nbytes;
    char buffer[MAXSIZE];

    while ((nbytes = recv(sock_fd, buffer, MAXSIZE, 0)) > 0) {  // read file contents from server
        fwrite(buffer, sizeof(char), nbytes, file);  // write file contents to local file
    }

    fclose(file);
    printf("File %s downloaded successfully.\n", filename);
}

int main(int argc, char *argv[]) {
    // Validate user input
    if (argc != 4) {
        printf("Usage: %s <server_ip> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Create socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(21);  // FTP port

    // Convert IP address to binary form
    if (inet_pton(AF_INET, ip, &(server.sin_addr)) != 1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    server_response(sock_fd);  // check server response

    // Send username to server
    char buffer[MAXSIZE];
    sprintf(buffer, "USER %s\r\n", username);
    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    server_response(sock_fd);  // check server response

    // Send password to server
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    server_response(sock_fd);  // check server response

    // Send PASV command to server
    sprintf(buffer, "PASV\r\n");
    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    server_response(sock_fd);  // check server response

    // Parse file size from server response
    char *p = strchr(buffer, '(');
    p = p + 1;
    int nums[6];
    sscanf(p, "%d,%d,%d,%d,%d,%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5]);
    int file_size = nums[4] * 256 + nums[5];
    printf("File size: %d bytes\n", file_size);

    // Send RETR command to server
    sprintf(buffer, "RETR %s\r\n", "index.html");
    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    server_response(sock_fd);  // check server response

    download_file(sock_fd, "index.html");  // download file
    close(sock_fd);  // close socket

    return 0;
}