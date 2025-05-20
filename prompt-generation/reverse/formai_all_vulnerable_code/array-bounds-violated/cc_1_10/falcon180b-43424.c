//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define SERVER_PORT 25
#define SERVER_ADDRESS "localhost"

int main()
{
    int sock;
    struct sockaddr_in server_addr;
    int opt = 1;
    char buffer[BUF_SIZE];
    int len;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        printf("Error setting socket option\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1)
    {
        memset(buffer, 0, BUF_SIZE);
        printf("Enter message: ");
        fgets(buffer, BUF_SIZE, stdin);

        len = strlen(buffer);
        send(sock, buffer, len, 0);

        memset(buffer, 0, BUF_SIZE);
        len = recv(sock, buffer, BUF_SIZE, 0);
        buffer[len] = '\0';
        printf("Server response: %s\n", buffer);

        if (strcmp(buffer, "bye") == 0)
        {
            break;
        }
    }

    close(sock);
    return 0;
}