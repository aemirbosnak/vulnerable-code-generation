//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50], password[50];
    char buffer[BUFFER_SIZE];
    int n;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(buffer, "USER %s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE);
    printf("Server response: %s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE);
    printf("Server response: %s", buffer);

    close(sockfd);
    return 0;
}