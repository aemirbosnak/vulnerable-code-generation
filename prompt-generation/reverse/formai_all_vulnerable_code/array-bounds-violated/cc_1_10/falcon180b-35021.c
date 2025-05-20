//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main()
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 5) == -1)
    {
        perror("listen");
        exit(1);
    }

    while (1)
    {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1)
        {
            perror("accept");
            continue;
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1)
        {
            perror("recv");
            close(client_socket);
            continue;
        }

        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);

        send(client_socket, buffer, strlen(buffer), 0);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}