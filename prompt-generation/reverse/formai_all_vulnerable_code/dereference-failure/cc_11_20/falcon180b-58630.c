//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: detailed
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

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    int opt = 1;
    int addrlen;
    char buffer[BUFFER_SIZE];
    int max_fd;
    fd_set master_fds, read_fds;

    if (argc!= 2)
    {
        printf("Usage:./server <port>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1)
    {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %s\n", argv[1]);

    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    FD_SET(server_socket, &master_fds);
    max_fd = server_socket;

    while (1)
    {
        read_fds = master_fds;
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1)
        {
            printf("Error selecting\n");
            exit(1);
        }

        for (int i = 0; i <= max_fd; i++)
        {
            if (FD_ISSET(i, &read_fds))
            {
                if (i == server_socket)
                {
                    addrlen = sizeof(client_addr[MAX_CLIENTS - 1]);
                    client_socket[MAX_CLIENTS - 1] = accept(server_socket, (struct sockaddr *)&client_addr[MAX_CLIENTS - 1], &addrlen);

                    if (client_socket[MAX_CLIENTS - 1]!= -1)
                    {
                        printf("Client connected\n");
                    }
                    else
                    {
                        printf("Error accepting connection\n");
                    }
                }
                else
                {
                    memset(buffer, 0, BUFFER_SIZE);
                    if (recv(i, buffer, BUFFER_SIZE, 0) == -1)
                    {
                        printf("Error receiving data\n");
                        close(i);
                        FD_CLR(i, &master_fds);
                    }
                    else
                    {
                        printf("Received: %s\n", buffer);
                    }
                }
            }
        }
    }

    return 0;
}