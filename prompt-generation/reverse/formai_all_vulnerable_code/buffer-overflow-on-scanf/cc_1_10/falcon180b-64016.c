//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[1025];
    char username[50];
    char password[50];
    char command[100];
    int n;
    int flag = 0;

    printf("Enter POP3 Server IP Address: ");
    scanf("%s", &serv_addr.sin_addr.s_addr);

    printf("Enter POP3 Server Port Number: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to POP3 Server\n");

    while (1) {
        printf("Enter Username: ");
        scanf("%s", username);

        printf("Enter Password: ");
        scanf("%s", password);

        sprintf(command, "USER %s\r\n", username);
        send(sockfd, command, strlen(command), 0);

        sprintf(command, "PASS %s\r\n", password);
        send(sockfd, command, strlen(command), 0);

        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n > 0) {
            printf("Server Response: %s", buffer);
        }

        flag = 1;
        break;
    }

    close(sockfd);
    return 0;
}