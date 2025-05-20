//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE   1
#define FALSE  0
#define PORT 8888
#define MAX 1024

int main(int argc, char *argv[])
{
    int listen_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX];

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        exit(2);
    }

    if (listen(listen_socket, 5) == -1)
    {
        printf("Error listening on socket\n");
        exit(3);
    }

    while(TRUE)
    {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        if (client_socket == -1)
        {
            printf("Error accepting connection\n");
            exit(4);
        }

        bytes_received = recv(client_socket, buffer, MAX, 0);

        if (bytes_received <= 0)
        {
            printf("Error receiving data\n");
            exit(5);
        }

        buffer[bytes_received] = '\0';

        printf("Received message: %s\n", buffer);

        send(client_socket, buffer, strlen(buffer), 0);

        close(client_socket);
    }

    return 0;
}