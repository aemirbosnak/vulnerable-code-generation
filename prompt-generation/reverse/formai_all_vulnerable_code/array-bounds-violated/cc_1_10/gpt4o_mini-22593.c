//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Failed to send command");
    }
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "226") || strstr(buffer, "250")) break; // End of successful command
    }
    if (bytes_read < 0) {
        error("Failed to read response");
    }
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    read_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    read_response(sockfd);
}

void ftp_get_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);
    read_response(sockfd);

    // Receive the file data
    int data_sock, bytes_read;
    struct sockaddr_in data_addr;
    socklen_t addr_len = sizeof(data_addr);
    char buffer[BUFFER_SIZE];

    data_sock = accept(sockfd, (struct sockaddr*)&data_addr, &addr_len);
    if (data_sock < 0) {
        error("Could not create data socket");
    }

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("Could not open file for writing");
    }

    while ((bytes_read = recv(data_sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, fp);
    }
    fclose(fp);
    close(data_sock);
    read_response(sockfd);
}

void ftp_quit(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);
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

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address/Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    read_response(sockfd);
    ftp_login(sockfd, username, password);

    char filename[BUFFER_SIZE];
    printf("Enter the name of the file to download: ");
    scanf("%s", filename);
    ftp_get_file(sockfd, filename);
    ftp_quit(sockfd);

    close(sockfd);
    return 0;
}