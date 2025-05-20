//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

int main(int argc, char **argv)
{
    int sockfd, new_socket, n, portno, clilen, i;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[100];
    char *hostname = argv[1];

    // Creating a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Getting server's address and port number
    server = gethostbyname(hostname);
    if (server == NULL)
    {
        fprintf(stderr,"Hostname could not be resolved.\n");
        exit(EXIT_FAILURE);
    }
    memcpy((char *)&serv_addr, (char *)server->h_addr, server->h_length);
    portno = ntohs(serv_addr.sin_port);

    // Binding socket to port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    listen(sockfd, 5);

    while (1)
    {
        // Accepting connection
        if ((new_socket = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen)) < 0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        printf("Connected with %s\n", inet_ntoa(cli_addr.sin_addr));

        // Spawning a new thread for each client
        for (i = 0; i < 5; i++)
        {
            if ((n = fork()) < 0)
            {
                perror("fork failed");
                exit(EXIT_FAILURE);
            }
            else if (n == 0)
            {
                // Child process
                close(new_socket);
                close(sockfd);
                printf("Client %d connected.\n", getpid());
                while (1)
                {
                    if ((n = read(new_socket, buffer, 100)) < 0)
                    {
                        perror("read failed");
                        exit(EXIT_FAILURE);
                    }
                    printf("Client %d: %s\n", getpid(), buffer);
                    write(new_socket, buffer, n);
                }
            }
            else
            {
                close(new_socket);
                close(sockfd);
                printf("Parent process\n");
            }
        }
    }

    close(new_socket);
    close(sockfd);
    exit(EXIT_SUCCESS);
}