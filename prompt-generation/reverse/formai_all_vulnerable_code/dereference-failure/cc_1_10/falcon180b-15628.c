//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define MAX_LINE 1024

// Function to establish a connection to the server
int connect_to_server(char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }
    return sockfd;
}

// Function to login to the server
int login(int sockfd) {
    char buf[MAX_LINE];
    sprintf(buf, "USER anonymous\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_LINE, 0);
    sprintf(buf, "PASS ftp@example.com\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_LINE, 0);
    if (strstr(buf, "230")) {
        return 1;
    } else {
        return 0;
    }
}

// Function to download a file from the server
void download_file(int sockfd, char *filename) {
    char buf[MAX_LINE];
    sprintf(buf, "RETR %s\r\n", filename);
    send(sockfd, buf, strlen(buf), 0);
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }
    int bytes_read;
    char *buffer = malloc(MAX_LINE);
    while ((bytes_read = recv(sockfd, buffer, MAX_LINE, 0)) > 0) {
        fwrite(buffer, 1, bytes_read, fp);
    }
    fclose(fp);
}

// Main function to run the FTP client
int main(int argc, char *argv[]) {
    char hostname[MAX_LINE];
    int port = PORT;
    if (argc > 1) {
        strcpy(hostname, argv[1]);
    } else {
        strcpy(hostname, "localhost");
    }
    int sockfd = connect_to_server(hostname, port);
    if (login(sockfd) == 0) {
        printf("Login failed\n");
        exit(1);
    }
    char filename[MAX_LINE];
    printf("Enter the filename to download: ");
    scanf("%s", filename);
    download_file(sockfd, filename);
    close(sockfd);
    return 0;
}