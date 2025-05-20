//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);
        if (strncmp(buffer, "226", 3) == 0 || strncmp(buffer, "221", 3) == 0) {
            break; // Command completed
        }
    }
}

void ftp_connect(int sockfd) {
    receive_response(sockfd);
    send_command(sockfd, "USER anonymous\r\n");
    receive_response(sockfd);
    send_command(sockfd, "PASS anonymous\r\n");
    receive_response(sockfd);
}

void ftp_list(int sockfd) {
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // Simulating PASV response parsing
    // In practice, this should parse the response to get the IP and port
    char *ip = "127.0.0.1"; // Dummy IP
    int port = 2121; // Dummy port

    // Establish data connection
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &data_addr.sin_addr);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        handle_error("Data connection failed");
    }

    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    char buffer[BUFFER_SIZE];
    int bytes_received;
    printf("Directory Listing:\n");
    while ((bytes_received = recv(data_sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(data_sockfd);
}

void ftp_get(int sockfd, const char *filename) {
    send_command(sockfd, "RETR ");
    send(sockfd, filename, strlen(filename), 0);
    send(sockfd, "\r\n", 2, 0);
    receive_response(sockfd);
    
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // Dummy values for demo purposes
    char *ip = "127.0.0.1"; // Dummy IP
    int port = 2121; // Dummy port

    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &data_addr.sin_addr);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        handle_error("Data connection failed for RETR");
    }

    FILE *file = fopen(filename, "wb");
    if (!file) {
        handle_error("Failed to open file");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    printf("Receiving file: %s\n", filename);
    while ((bytes_received = recv(data_sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);
    close(data_sockfd);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        handle_error("Socket creation failed");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    inet_pton(AF_INET, "your.ftp.server.ip", &server_addr.sin_addr); // Replace with actual server IP

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to FTP server failed");
    }

    ftp_connect(sockfd);
    ftp_list(sockfd);

    const char *filename = "example.txt"; // Specify the file you want to retrieve
    ftp_get(sockfd, filename);

    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
    close(sockfd);

    printf("FTP session ended. Goodbye!\n");
    return 0;
}