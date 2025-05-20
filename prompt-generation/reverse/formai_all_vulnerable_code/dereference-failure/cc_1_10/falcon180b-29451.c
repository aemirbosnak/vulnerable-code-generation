//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    char hostname[20];
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[MAX_LINE];
    int n;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port number: ");
    scanf("%d", &portno);

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: could not resolve hostname\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(buffer, MAX_LINE, stdin);
        n = strlen(buffer);
        if (n == 0)
            continue;
        buffer[n-1] = '\0';
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, MAX_LINE, 0);
        if (n <= 0)
            break;
        buffer[n] = '\0';
        printf("Server response: %s", buffer);
    }

    close(sockfd);
    return 0;
}