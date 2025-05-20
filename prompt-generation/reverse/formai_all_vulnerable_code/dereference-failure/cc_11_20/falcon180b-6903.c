//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define TRUE  1
#define FALSE 0
#define PORT  8888
#define BACKLOG 5
#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int listen_socket, client_socket;
    int opt = TRUE;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[MAX_LINE];

    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, BACKLOG) == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE)
    {
        if ((client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen)) == -1)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE)
        {
            memset(buffer, 0, MAX_LINE);

            if (recv(client_socket, buffer, MAX_LINE, 0) <= 0)
            {
                if (errno!= EAGAIN)
                {
                    printf("Client disconnected\n");
                    break;
                }
            }

            printf("Received message: %s", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0)!= strlen(buffer))
            {
                printf("Send failed\n");
                break;
            }
        }

        close(client_socket);
    }

    close(listen_socket);

    return 0;
}