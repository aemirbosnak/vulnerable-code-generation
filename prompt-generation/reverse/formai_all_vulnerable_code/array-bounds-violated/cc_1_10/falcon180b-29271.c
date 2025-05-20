//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define PORT 8080

int main()
{
    int listening_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1)
    {
        printf("Error creating socket.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listening_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket.\n");
        exit(2);
    }

    if (listen(listening_socket, 5) == -1)
    {
        printf("Error listening on socket.\n");
        exit(3);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        client_socket = accept(listening_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (client_socket == -1)
        {
            printf("Error accepting connection.\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1)
        {
            ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0)
            {
                printf("Connection closed by client.\n");
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            ssize_t bytes_sent = send(client_socket, buffer, strlen(buffer), 0);
            if (bytes_sent <= 0)
            {
                printf("Error sending message.\n");
                break;
            }
        }

        close(client_socket);
    }

    close(listening_socket);

    return 0;
}