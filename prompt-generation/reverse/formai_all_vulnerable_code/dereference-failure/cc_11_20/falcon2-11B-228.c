//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int server_fd, new_socket, listen_socket, portno;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(client_address);
    char buffer[1024];

    if (argc!= 2)
    {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket");
        exit(1);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
    {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    while (1)
    {
        listen_socket = accept(server_fd, (struct sockaddr *) &client_address, (socklen_t *) &addrlen);
        if (listen_socket < 0)
        {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        if (connect(listen_socket, (struct sockaddr *) &client_address, sizeof(client_address)) < 0)
        {
            perror("connect");
            exit(1);
        }

        while (1)
        {
            new_socket = accept(listen_socket, (struct sockaddr *) &client_address, (socklen_t *) &addrlen);
            if (new_socket < 0)
            {
                perror("accept");
                exit(1);
            }

            printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

            while (1)
            {
                memset(buffer, 0, sizeof(buffer));
                bzero((char *) &client_address, sizeof(client_address));

                new_socket = accept(listen_socket, (struct sockaddr *) &client_address, (socklen_t *) &addrlen);
                if (new_socket < 0)
                {
                    perror("accept");
                    exit(1);
                }

                printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

                while (1)
                {
                    read(new_socket, buffer, sizeof(buffer));
                    printf("Received: %s\n", buffer);

                    send(new_socket, buffer, sizeof(buffer), 0);
                    printf("Sent: %s\n", buffer);
                }
            }
        }
    }

    close(server_fd);
    close(listen_socket);
    return 0;
}