//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_LINE 1024
#define USER "anonymous"
#define PASS "anonymous@example.com"

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE];
    char filename[MAX_LINE];
    char command[MAX_LINE];
    char *ptr;
    FILE *fp;
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "ftp.example.com", &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Login to server
    send(sockfd, USER, strlen(USER), 0);
    send(sockfd, PASS, strlen(PASS), 0);

    // Get directory listing
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
    while ((n = recv(sockfd, buffer, MAX_LINE, 0)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
    }

    // Download file
    printf("Enter filename to download: ");
    scanf("%s", filename);
    sprintf(command, "RETR %s\r\n", filename);
    send(sockfd, command, strlen(command), 0);
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while ((n = recv(sockfd, buffer, MAX_LINE, 0)) > 0) {
        fwrite(buffer, 1, n, fp);
    }
    fclose(fp);

    // Close connection
    close(sockfd);

    return 0;
}