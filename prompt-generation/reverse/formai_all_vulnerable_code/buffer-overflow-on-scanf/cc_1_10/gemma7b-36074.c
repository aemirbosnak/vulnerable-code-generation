//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char host[256];
    char username[256];
    char password[256];
    char filepath[256];
    int port;

    printf("Enter host: ");
    scanf("%s", host);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter port: ");
    scanf("%d", &port);

    printf("Enter filepath: ");
    scanf("%s", filepath);

    // Connect to FTP server
    int sockfd = ftp_connect(host, port, username, password);

    // Transfer file
    ftp_transfer(sockfd, filepath);

    // Close connection
    ftp_close(sockfd);

    return 0;
}

int ftp_connect(char *host, int port, char *username, char *password) {
    int sockfd;
    struct sockaddr_in sock_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    inet_aton(host, &sock_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        exit(1);
    }

    return sockfd;
}

int ftp_transfer(int sockfd, char *filepath) {
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    int read_size, write_size;

    fp = fopen(filepath, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        close(sockfd);
        exit(1);
    }

    while ((read_size = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0) {
        write_size = write(sockfd, buffer, read_size);
        if (write_size < 0) {
            perror("Error writing to socket");
            close(sockfd);
            exit(1);
        }
    }

    fclose(fp);

    return 0;
}

int ftp_close(int sockfd) {
    close(sockfd);
    return 0;
}