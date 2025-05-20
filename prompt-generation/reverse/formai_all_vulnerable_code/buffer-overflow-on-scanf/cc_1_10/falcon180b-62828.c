//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define USERNAME "anonymous"
#define PASSWORD "anonymous@"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char command[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    int n;
    FILE *fp;

    printf("Enter the filename to download: ");
    scanf("%s", filename);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.100"); // replace with your server IP address

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(command, "USER %s\r\n", USERNAME);
    send(sockfd, command, strlen(command), 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    sprintf(command, "PASS %s\r\n", PASSWORD);
    send(sockfd, command, strlen(command), 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    sprintf(command, "RETR %s\r\n", filename);
    send(sockfd, command, strlen(command), 0);

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }

    fclose(fp);
    close(sockfd);

    printf("File downloaded successfully\n");

    return 0;
}