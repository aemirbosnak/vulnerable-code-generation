//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110

int main() {
    int sockfd, valread;
    struct sockaddr_in serveraddr;
    char buffer[256];
    char *mailFrom = "sender@example.com";
    char *rcptTo = "receiver@example.com";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in socket");
        return 1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error in connecting");
        return 1;
    }

    printf("POP3 Client\n");
    printf("Username: ");
    scanf("%s", buffer);
    if (strcmp(buffer, mailFrom)!= 0) {
        printf("Username is incorrect\n");
        return 1;
    }

    printf("Enter the password: ");
    scanf("%s", buffer);
    if (strcmp(buffer, mailFrom)!= 0) {
        printf("Password is incorrect\n");
        return 1;
    }

    printf("Authenticated\n");
    printf("Enter 'QUIT' to exit\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        valread = read(sockfd, buffer, sizeof(buffer));
        if (valread < 0) {
            perror("Error in reading from socket");
            return 1;
        }
        if (strstr(buffer, "QUIT")) {
            printf("Exiting POP3 Client\n");
            break;
        } else {
            printf("%s\n", buffer);
        }
    }

    return 0;
}