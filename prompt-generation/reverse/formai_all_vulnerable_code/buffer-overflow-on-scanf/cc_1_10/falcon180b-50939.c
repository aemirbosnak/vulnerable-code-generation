//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[50];
    char password[50];
    char response[BUFFER_SIZE];
    int response_len;
    int auth_state = 0;
    int stat = 0;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(response, 0, BUFFER_SIZE);
        response_len = recv(sockfd, response, BUFFER_SIZE, 0);

        if (response_len <= 0) {
            printf("Error: Could not receive data from server\n");
            exit(1);
        }

        printf("Server response: %s\n", response);

        if (auth_state == 0) {
            if (strstr(response, "+OK")!= NULL) {
                auth_state = 1;
            }
        } else {
            if (strstr(response, "+OK")!= NULL) {
                printf("Authentication successful\n");
                stat = 1;
            } else if (strstr(response, "-ERR")!= NULL) {
                printf("Authentication failed\n");
                stat = 0;
            }
        }

        if (stat == 1) {
            break;
        }
    }

    close(sockfd);
    return 0;
}