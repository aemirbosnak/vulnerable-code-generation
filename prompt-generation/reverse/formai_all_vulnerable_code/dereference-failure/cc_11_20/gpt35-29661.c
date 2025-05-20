//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

#define HTTP_PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int proxy_sockfd, client_sockfd, server_sockfd;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    socklen_t sin_size;

    if(argc != 3) {
        perror("Usage: ./proxy <ip_address> <port>\n");
        exit(1);
    }

    /* Create the proxy listening socket */
    if((proxy_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(1);
    }

    /* Fill the proxy address struct */
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(atoi(argv[2]));
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    memset(proxy_addr.sin_zero, '\0', sizeof proxy_addr.sin_zero);

    /* Bind to the proxy listening socket */
    if(bind(proxy_sockfd, (struct sockaddr *) &proxy_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind error");
        exit(1);
    }

    /* Listen for incoming connections */
    if(listen(proxy_sockfd, 10) == -1) {
        perror("listen error");
        exit(1);
    }

    printf("Proxy Server started on port %s\n", argv[2]);

    while(1) {
        sin_size = sizeof(struct sockaddr_in);

        /* Accept a client connection */
        if((client_sockfd = accept(proxy_sockfd, (struct sockaddr *) &client_addr, &sin_size)) == -1) {
            perror("accept error");
            continue;
        }

        printf("Accepted connection from %s\n", inet_ntoa(client_addr.sin_addr));

        /* Create the server socket */
        if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket error");
            exit(1);
        }

        /* Fill the address struct for the server */
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(HTTP_PORT);
        memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);

        /* Get the destination IP address */
        struct hostent *he = gethostbyname(argv[1]);
        if (he == NULL) {
            perror("gethostbyname error");
            exit(1);
        }
        server_addr.sin_addr = *((struct in_addr *)he->h_addr);

        /* Connect to the destination server */
        if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
            perror("connect error");
            exit(1);
        }

        /* Relay the information between client and server */
        int total_bytes_written = 0;
        char buffer[BUFFER_SIZE];

        while(1) {
            /* Receive data from the client */
            int num_bytes = recv(client_sockfd, buffer, BUFFER_SIZE - 1, 0);
            if(num_bytes == -1) {
                perror("recv error");
                exit(1);
            }
            else if(num_bytes == 0) {
                break;
            }

            buffer[num_bytes] = '\0';

            /* Relay the data to the server */
            int bytes_written = send(server_sockfd, buffer, num_bytes, 0);
            if(bytes_written == -1) {
                perror("send error");
                exit(1);
            }
            total_bytes_written += bytes_written;

            /* Receive data from the server */
            num_bytes = recv(server_sockfd, buffer, BUFFER_SIZE - 1, 0);
            if(num_bytes == -1) {
                perror("recv error");
                exit(1);
            }
            else if(num_bytes == 0) {
                break;
            }

            buffer[num_bytes] = '\0';

            /* Relay the data to the client */
            bytes_written = send(client_sockfd, buffer, num_bytes, 0);
            if(bytes_written == -1) {
                perror("send error");
                exit(1);
            }
        }

        printf("Relayed data between client and server - Total Bytes Written %d\n", total_bytes_written);

        /* Close the sockets */
        close(client_sockfd);
        close(server_sockfd);
    }

    return 0;
}