//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_COMMAND_LENGTH 1024
#define MAX_DATA_LENGTH 4096

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char command[MAX_COMMAND_LENGTH];
    char data[MAX_DATA_LENGTH];
    int n;
    FILE* fp;

    if (argc!= 3) {
        printf("Usage:./ftp_client <hostname> <filename>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    sprintf(command, "STOR %s\r\n", argv[2]);
    send(sockfd, command, strlen(command), 0);

    while ((n = recv(sockfd, data, MAX_DATA_LENGTH, 0)) > 0) {
        data[n] = 0;
        printf("%s", data);
    }

    close(sockfd);
    exit(0);
}