//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[1025];
    char username[50];
    char password[50];
    char command[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("socket failed");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);
    serv_addr.sin_addr.s_addr = inet_addr("localhost");

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server\n");

    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));

        if (recv(sock, buffer, sizeof(buffer), 0) < 0)
        {
            perror("recv failed");
            exit(1);
        }

        printf("%s", buffer);

        if (strcmp(buffer, "+OK") == 0)
        {
            printf("Enter command: ");
            scanf("%s", command);

            if (strcmp(command, "LIST") == 0)
            {
                send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
            }
            else if (strcmp(command, "RETR") == 0)
            {
                send(sock, "RETR 1\r\n", strlen("RETR 1\r\n"), 0);
            }
            else if (strcmp(command, "DELE") == 0)
            {
                send(sock, "DELE 1\r\n", strlen("DELE 1\r\n"), 0);
            }
            else if (strcmp(command, "QUIT") == 0)
            {
                send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
                break;
            }
        }
    }

    close(sock);

    return 0;
}