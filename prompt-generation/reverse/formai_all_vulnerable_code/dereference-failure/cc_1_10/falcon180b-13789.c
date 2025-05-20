//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <host> <port> <mode>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);
    char *mode = argv[3];

    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    if (strcmp(mode, "download") == 0) {
        char filename[BUFFER_SIZE];
        printf("Enter filename to download: ");
        fgets(filename, BUFFER_SIZE, stdin);
        filename[strcspn(filename, "\n")] = '\0';

        char command[BUFFER_SIZE];
        sprintf(command, "RETR %s\r\n", filename);
        send(sockfd, command, strlen(command), 0);

        char buffer[BUFFER_SIZE];
        while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
            printf("%s", buffer);
        }
    } else if (strcmp(mode, "upload") == 0) {
        char filename[BUFFER_SIZE];
        printf("Enter filename to upload: ");
        fgets(filename, BUFFER_SIZE, stdin);
        filename[strcspn(filename, "\n")] = '\0';

        char command[BUFFER_SIZE];
        sprintf(command, "STOR %s\r\n", filename);
        send(sockfd, command, strlen(command), 0);

        FILE *fp = fopen(filename, "rb");
        if (fp == NULL) {
            printf("Error opening file\n");
            return 1;
        }

        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
            send(sockfd, buffer, strlen(buffer), 0);
        }

        fclose(fp);
    } else {
        printf("Invalid mode\n");
        return 1;
    }

    close(sockfd);
    return 0;
}