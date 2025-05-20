//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[50], password[50], command[100];
    int n;
    char buffer[1024];

    printf("Enter POP3 Server IP Address: ");
    scanf("%s", &serveraddr.sin_addr.s_addr);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(110);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Connection Failed\n");
        exit(0);
    }

    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    char *auth = "USER ";
    strcat(auth, username);
    strcat(auth, "\r\n");
    send(sockfd, auth, strlen(auth), 0);

    char *pass = "PASS ";
    strcat(pass, password);
    strcat(pass, "\r\n");
    send(sockfd, pass, strlen(pass), 0);

    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    while (1) {
        printf("Enter Command: ");
        fgets(command, sizeof(command), stdin);
        send(sockfd, command, strlen(command), 0);
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}