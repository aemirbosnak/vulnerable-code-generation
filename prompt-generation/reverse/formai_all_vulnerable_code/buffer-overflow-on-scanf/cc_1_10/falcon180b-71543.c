//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 21
#define MAX_LINE 1024
#define SERVER "localhost"

int main()
{
    int sock;
    struct sockaddr_in server_addr;
    char username[20], password[20];
    char command[MAX_LINE];
    char response[MAX_LINE];
    char *ptr;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Connected to %s\n", SERVER);

    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    while(1)
    {
        memset(command, 0, MAX_LINE);
        memset(response, 0, MAX_LINE);

        printf("ftp> ");
        fgets(command, MAX_LINE, stdin);

        send(sock, command, strlen(command), 0);

        while(1)
        {
            bzero(response, MAX_LINE);
            recv(sock, response, MAX_LINE, 0);

            if(strstr(response, "230")!= NULL)
            {
                printf("%s\n", response);
                break;
            }
            else if(strstr(response, "331")!= NULL)
            {
                ptr = strtok(response, " ");
                printf("Password required for %s\n", ptr);
                break;
            }
            else if(strstr(response, "530")!= NULL)
            {
                printf("Invalid username or password\n");
                exit(1);
            }
        }
    }

    close(sock);

    return 0;
}