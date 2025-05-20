//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[20] = "anonymous";
    char password[20] = "anonymous@example.com";
    char buffer[BUFFER_SIZE];
    char command[50] = "USER anonymous\r\n";
    char data_mode[] = "TYPE I\r\n";
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "ftp.example.com", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to FTP server\n");

    send(sockfd, command, strlen(command), 0);

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}