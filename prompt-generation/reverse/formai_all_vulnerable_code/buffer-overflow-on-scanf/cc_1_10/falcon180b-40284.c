//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n, ret;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    char username[50];
    char password[50];
    char response[50];
    char command[50];
    int user_authenticated = FALSE;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    portno = 110;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        printf("\n Socket creation failed \n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (ret < 0)
        printf("\n Connection Failed \n");

    printf("Connected\n");

    while (1) {
        memset(buffer, '\0', BUF_SIZE);
        ret = read(sockfd, buffer, BUF_SIZE);

        if (ret <= 0) {
            printf("\n Disconnected \n");
            break;
        }

        printf("\n %s \n", buffer);

        if (user_authenticated == FALSE) {
            if (strstr(buffer, "+OK")!= NULL) {
                printf("\n Server ready for authentication \n");
                sprintf(command, "USER %s", username);
                send(sockfd, command, strlen(command), 0);
                user_authenticated = TRUE;
            }
        } else {
            if (strstr(buffer, "+OK")!= NULL) {
                printf("\n Authentication successful \n");
            } else if (strstr(buffer, "-ERR")!= NULL) {
                printf("\n Authentication failed \n");
                break;
            }
        }
    }

    close(sockfd);

    return 0;
}