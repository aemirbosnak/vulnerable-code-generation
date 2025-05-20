//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

int main(int argc, char *argv[])
{
    int listen_socket, client_socket, bytes_received, valread, sd;
    struct sockaddr_in address;
    char buffer[MAX];
    int opt = 1;

    if( (listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if( setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if( bind(listen_socket, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if( listen(listen_socket, 3) < 0 )
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while( TRUE )
    {
        if( (client_socket = accept(listen_socket, (struct sockaddr *)&address, (socklen_t*)&sd)) < 0 )
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected\n");
        send(client_socket, "HELLO SERVER", strlen("HELLO SERVER"), 0 );

        while( (bytes_received = recv(client_socket, buffer, MAX, 0)) > 0 )
        {
            buffer[bytes_received] = '\0';
            printf("Received string is %s\n", buffer);
            send(client_socket, buffer, strlen(buffer), 0 );
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}