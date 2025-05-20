//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // Socket setup
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int i;

    // Server IP address and port number
    const char *server_address = "localhost";
    const int server_port = 110;

    // Connecting to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    portno = htons(server_port);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(server_address);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Login
    printf("Username: ");
    scanf("%s", buffer);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);

    // Get all emails
    while (1) {
        printf("Index of email to get: ");
        scanf("%d", &i);
        send(sockfd, &i, sizeof(i), 0);
        recv(sockfd, buffer, 1024, 0);
        printf("%s\n", buffer);
        if (strcmp(buffer, ".") == 0)
            break;
    }

    // Quit
    send(sockfd, "quit\r\n", 6, 0);
    close(sockfd);

    return 0;
}