//Falcon-180B DATASET v1.0 Category: Networking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define MAX_RECV_SIZE 1024

int main(int argc, char *argv[])
{
    int server_socket, new_socket, addrlen, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char recv_buffer[MAX_RECV_SIZE];
    int opt = 1;
    int max_clients = 0;

    // create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // fill server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    while (1)
    {
        // accept a new connection
        addrlen = sizeof(client_addr[max_clients]);
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], &addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // add new socket to array
        client_socket[max_clients] = new_socket;
        max_clients++;

        printf("New client connected, socket fd is %d\n", new_socket);
    }

    return 0;
}