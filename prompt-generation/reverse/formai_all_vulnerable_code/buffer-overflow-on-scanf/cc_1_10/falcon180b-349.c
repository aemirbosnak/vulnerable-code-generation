//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define USERNAME "username"
#define PASSWORD "password"

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket failed\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Error: connect failed\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    while (TRUE) {
        memset(buffer, 0, BUFFER_SIZE);
        retval = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (retval <= 0) {
            printf("Error: recv failed\n");
            exit(1);
        }

        printf("%s", buffer);

        if (strstr(buffer, ".")!= NULL) {
            break;
        }
    }

    close(sockfd);
    return 0;
}