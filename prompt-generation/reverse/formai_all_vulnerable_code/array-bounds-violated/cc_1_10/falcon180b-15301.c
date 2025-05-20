//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 4096

int main(int argc, char *argv[])
{
    int listening_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char request_buffer[MAX_REQUEST_SIZE], response_buffer[MAX_RESPONSE_SIZE];
    int request_size, response_size;

    listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(listening_socket == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listening_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        exit(1);
    }

    if(listen(listening_socket, BACKLOG) == -1)
    {
        printf("Error listening on socket\n");
        exit(1);
    }

    while(TRUE)
    {
        bytes_received = 0;
        client_socket = accept(listening_socket, (struct sockaddr*)&client_addr, sizeof(client_addr));
        if(client_socket == -1)
        {
            printf("Error accepting connection\n");
            continue;
        }

        while(TRUE)
        {
            request_size = recv(client_socket, request_buffer + bytes_received, MAX_REQUEST_SIZE - bytes_received, 0);
            if(request_size == 0)
            {
                printf("Client disconnected\n");
                break;
            }
            else if(request_size == -1)
            {
                printf("Error receiving request\n");
                break;
            }

            bytes_received += request_size;
            request_buffer[bytes_received] = '\0';

            response_size = send(client_socket, response_buffer, strlen(response_buffer), 0);
            if(response_size == -1)
            {
                printf("Error sending response\n");
                break;
            }
        }

        close(client_socket);
    }

    close(listening_socket);
    return 0;
}