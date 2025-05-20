//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];
    char *filename;
    FILE *fp;

    if (argc!= 3) {
        printf("Usage:./ftp_client <IP Address> <Filename>\n");
        exit(0);
    }

    strcpy(buffer, argv[1]); // IP Address
    strcpy(filename, argv[2]); // Filename

    portno = 21; // FTP Port

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, buffer, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(0);
    }

    printf("Connected to server...\n");

    if (send(sockfd, filename, strlen(filename), 0) < 0) {
        printf("Error: Failed to send filename\n");
        exit(0);
    }

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(0);
    }

    while ((n = fread(buffer, sizeof(char), BUF_SIZE, fp)) > 0) {
        if (send(sockfd, buffer, n, 0) < 0) {
            printf("Error: Failed to send data\n");
            exit(0);
        }
    }

    fclose(fp);
    close(sockfd);

    printf("Data sent successfully!\n");

    return 0;
}