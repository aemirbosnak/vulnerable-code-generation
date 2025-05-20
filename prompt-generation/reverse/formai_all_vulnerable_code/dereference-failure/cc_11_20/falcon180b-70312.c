//Falcon-180B DATASET v1.0 Category: Networking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT "8080"
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);
    int opt = 1;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(PORT));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %s...\n", PORT);

    while (1)
    {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1)
        {
            bzero(buffer, BUFFER_SIZE);

            if (recv(new_socket, buffer, BUFFER_SIZE, 0) <= 0)
            {
                if (errno!= EAGAIN)
                {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(new_socket, buffer, strlen(buffer), 0) < 0)
            {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        close(new_socket);
    }

    close(server_socket);

    return 0;
}