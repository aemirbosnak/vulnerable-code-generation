//FormAI DATASET v1.0 Category: Client Server Application ; Style: detailed
#include <stdio.h>          // Standard I/O Library
#include <stdlib.h>         // Standard Library
#include <unistd.h>         // UNIX Standard Library (read, write)
#include <errno.h>          // Error Number Library
#include <string.h>         // String Handling Functions
#include <sys/socket.h>     // Socket Library
#include <netinet/in.h>     // Internet Protocol Library

#define PORT 8080          // Port Number
#define MAXLINE 1024        // Maximum line size

int main(int argc, char *argv[]) {

    int sockfd;                 // File descriptor for the socket
    char buffer[MAXLINE];       // Receive buffer
    struct sockaddr_in servaddr, cliaddr;     // Server and client address structures

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;
    len = sizeof(cliaddr);

    // Wait for client connection
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';

    // Open file based on received file path
    FILE *fp = fopen(buffer, "rb");
    if (fp == NULL) {
        printf("File open failed.\n");
        exit(EXIT_FAILURE);
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Send file size to client
    printf("File size: %ld\n", file_size);
    sendto(sockfd, &file_size, sizeof(long int), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);

    // Send file in chunks of 1024 bytes
    while (1) {
        char file_buffer[MAXLINE] = {0};
        int read = fread(file_buffer, 1, MAXLINE, fp);
        if (read == 0) {
            break;
        }
        sendto(sockfd, file_buffer, read, MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
    }

    // Close file and socket
    fclose(fp);
    close(sockfd);

    return 0;
}