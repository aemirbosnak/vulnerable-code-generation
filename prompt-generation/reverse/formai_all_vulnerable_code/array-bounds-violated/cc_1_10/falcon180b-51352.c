//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<fcntl.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 10

int main(int argc, char *argv[])
{
    int listen_socket, client_socket, bytes_received, bytes_sent, opt = TRUE;
    struct sockaddr_in server_addr, client_addr;
    char request_buffer[BUFFER_SIZE];
    char response_buffer[BUFFER_SIZE];

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(listen_socket == -1)
    {
        perror("socket failed");
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind failed");
        exit(1);
    }

    if(listen(listen_socket, BACKLOG) < 0)
    {
        perror("listen");
        exit(1);
    }

    while(TRUE)
    {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        if(client_socket < 0)
        {
            perror("accept");
            exit(1);
        }

        bytes_received = recv(client_socket, request_buffer, BUFFER_SIZE, 0);

        if(bytes_received <= 0)
        {
            perror("recv");
            exit(1);
        }

        request_buffer[bytes_received] = '\0';

        printf("Received Request : %s\n", request_buffer);

        sprintf(response_buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", strlen("<h1>Welcome to Proxy Server</h1>"));

        send(client_socket, response_buffer, strlen(response_buffer), 0);

        close(client_socket);
    }

    return 0;
}