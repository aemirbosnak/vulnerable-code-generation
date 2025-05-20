//Falcon-180B DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int master_socket, client_socket, valread, sd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE];

    if (argc < 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    master_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (master_socket == -1)
    {
        printf("socket failed\n");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        printf("setsockopt failed\n");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("bind failed\n");
        exit(EXIT_FAILURE);
    }

    if (listen(master_socket, 5) < 0)
    {
        printf("listen failed\n");
        exit(EXIT_FAILURE);
    }

    while (TRUE)
    {
        printf("Waiting for connections...\n");
        valread = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        if (valread < 0)
        {
            printf("accept failed\n");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted\n");

        if (fork() == 0)
        {
            close(master_socket);

            while (TRUE)
            {
                memset(buffer, 0, BUF_SIZE);
                valread = recv(client_socket, buffer, BUF_SIZE, 0);

                if (valread <= 0) break;

                send(client_socket, buffer, strlen(buffer), 0);
            }

            exit(EXIT_SUCCESS);
        }
        else
        {
            close(client_socket);
        }
    }

    return 0;
}