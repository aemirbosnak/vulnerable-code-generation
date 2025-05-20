//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_COMMANDS 10

char imap_host[50] = "localhost";
int imap_port = 143;
int sockfd;
struct sockaddr_in server_addr;

char username[50];
char password[50];

int main() {
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
    server_addr.sin_port = htons(imap_port);
    inet_pton(AF_INET, imap_host, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int n;

    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    close(sockfd);
    return 0;
}