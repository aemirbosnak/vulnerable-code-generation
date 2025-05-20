//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[4096];
    char username[50];
    char password[50];
    char command[50];
    FILE *fp;
    int count;

    printf("Enter POP3 Server Address: ");
    scanf("%s", &serv_addr.sin_addr.s_addr);

    printf("Enter POP3 Server Port: ");
    scanf("%d", &serv_addr.sin_port);

    printf("Enter POP3 Username: ");
    scanf("%s", &username);

    printf("Enter POP3 Password: ");
    scanf("%s", &password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(serv_addr.sin_addr.s_addr);
    serv_addr.sin_port = htons(serv_addr.sin_port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection failed\n");
        return 0;
    }

    printf("Connected to POP3 Server\n");

    memset(buffer, 0, sizeof(buffer));

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0)
        {
            printf("Disconnected from POP3 Server\n");
            break;
        }
        buffer[n] = 0;
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}