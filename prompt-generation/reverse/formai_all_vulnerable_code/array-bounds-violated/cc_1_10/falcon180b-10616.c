//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1)
        error_handling("socket failed");

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        error_handling("setsockopt");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (SA *)&server_addr, sizeof(server_addr)) < 0)
        error_handling("bind failed");

    if (listen(listen_socket, 3) < 0)
        error_handling("listen");

    while (1)
    {
        printf("Waiting for connection...\n");
        client_socket = accept(listen_socket, (SA *)&client_addr, (socklen_t*)&addrlen);

        if (client_socket < 0)
            error_handling("accept");

        char buffer[MAX];
        int bytes_received = 0;

        while ((bytes_received = recv(client_socket, buffer, MAX, 0)) > 0)
        {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);
            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}

void error_handling(char *message)
{
    perror(message);
    exit(1);
}