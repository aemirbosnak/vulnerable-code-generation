//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110
#define MAX_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char buffer[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];

    if (argc < 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[1]);
    strcpy(password, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr("localhost");

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Username: ");
    fgets(buffer, MAX_LEN, stdin);
    printf("Password: ");
    fgets(buffer, MAX_LEN, stdin);

    if (write(sockfd, username, strlen(username)) < 0 || write(sockfd, "\r\n", 2) < 0 || write(sockfd, password, strlen(password)) < 0) {
        perror("write");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buffer, MAX_LEN);
        if (n < 0) {
            perror("read");
            exit(1);
        }

        if (strstr(buffer, "USER OK")!= NULL) {
            printf("Authentication successful!\n");
            break;
        }

        if (strstr(buffer, "ERROR")!= NULL) {
            printf("Error: %s\n", buffer);
            break;
        }

        if (strstr(buffer, "QUIT")!= NULL) {
            printf("Connection closed.\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}