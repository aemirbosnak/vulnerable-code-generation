//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int listen_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    int addrlen = sizeof(client_addr);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == 0)
    {
        error_handling("socket failed");
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error_handling("bind failed");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) < 0)
    {
        error_handling("listen");
        exit(1);
    }

    while(TRUE)
    {
        new_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);

        if(new_socket < 0)
        {
            error_handling("accept");
        }
        else
        {
            char buffer[1024];
            int bytes_received;

            while((bytes_received = recv(new_socket, buffer, sizeof(buffer), 0)) > 0)
            {
                buffer[bytes_received] = '\0';
                printf("Received message: %s\n", buffer);
            }

            close(new_socket);
        }
    }

    return 0;
}

void error_handling(char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}