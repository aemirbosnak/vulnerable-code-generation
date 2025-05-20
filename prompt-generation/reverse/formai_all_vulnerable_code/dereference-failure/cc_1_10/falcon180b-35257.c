//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <dirent.h>

#define BUF_SIZE 1024
#define MAX_LINE 100

int main(int argc, char *argv[])
{
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];
    int opt = 1;
    int addrlen = sizeof(client_addr);
    int port = 8080;

    if (argc!= 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Error creating socket.\n");
        exit(1);
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        printf("Error setting socket option.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error binding socket.\n");
        exit(1);
    }

    if (listen(listen_socket, 5) < 0)
    {
        printf("Error listening on socket.\n");
        exit(1);
    }

    printf("Firewall started on port %d.\n", port);

    while (1)
    {
        if ((client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen)) < 0)
        {
            printf("Error accepting connection.\n");
            exit(1);
        }

        char *ip = inet_ntoa(client_addr.sin_addr);
        printf("Connection from %s\n", ip);

        close(client_socket);
    }

    return 0;
}