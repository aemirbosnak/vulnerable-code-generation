//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[])
{
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    int addrlen = sizeof(client_addr);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, BACKLOG) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE)
    {
        memset(&client_addr, 0, sizeof(client_addr));
        addrlen = sizeof(client_addr);

        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);

        if (client_socket < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        while (TRUE)
        {
            int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);

            if (bytes_received <= 0)
            {
                break;
            }

            buffer[bytes_received] = '\0';
            printf("%s", buffer);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}