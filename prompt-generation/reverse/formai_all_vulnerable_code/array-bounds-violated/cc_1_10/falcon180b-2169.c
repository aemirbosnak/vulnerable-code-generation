//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024

int main()
{
    int socket_fd;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char username[64];
    char password[64];
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int command_length;
    int response_length;
    int bytes_received;

    printf("Enter POP3 server address: ");
    scanf("%s", server);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr.s_addr = inet_addr(server);

    connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    memset(command, 0, MAX_COMMAND_LENGTH);
    sprintf(command, "USER %s\r\n", username);
    send(socket_fd, command, strlen(command), 0);

    response_length = recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0);
    response[response_length] = '\0';

    if (strstr(response, "+OK"))
    {
        memset(command, 0, MAX_COMMAND_LENGTH);
        sprintf(command, "PASS %s\r\n", password);
        send(socket_fd, command, strlen(command), 0);

        response_length = recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0);
        response[response_length] = '\0';

        if (strstr(response, "+OK"))
        {
            printf("Logged in successfully.\n");
        }
        else
        {
            printf("Login failed.\n");
        }
    }
    else
    {
        printf("Login failed.\n");
    }

    close(socket_fd);

    return 0;
}