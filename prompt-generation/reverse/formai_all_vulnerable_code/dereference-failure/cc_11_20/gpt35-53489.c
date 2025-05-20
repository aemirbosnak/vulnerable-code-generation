//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int proxy_sock, client_sock, server_sock;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char buffer[MAX_BUFFER_SIZE];
    char *proxy_ip, *server_ip, *client_ip;
    int proxy_port, server_port, client_port;
    ssize_t read_size;

    /* Parse command line arguments */
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <proxy_ip> <proxy_port> <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    proxy_ip = argv[1];
    proxy_port = atoi(argv[2]);
    server_ip = argv[3];
    server_port = atoi(argv[4]);

    /* Create a socket for the proxy */
    proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    /* Bind the proxy to a specific IP and port */
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(proxy_ip);
    proxy_addr.sin_port = htons(proxy_port);
    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    /* Listen for incoming connections */
    if (listen(proxy_sock, 1) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on %s:%d\n", proxy_ip, proxy_port);

    while (1) {
        /* Accept an incoming connection */
        memset(&client_addr, 0, sizeof(client_addr));
        socklen_t client_len = sizeof(client_addr);
        client_sock = accept(proxy_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept() failed");
            continue;
        }

        /* Get the client's IP address */
        client_ip = inet_ntoa(client_addr.sin_addr);
        client_port = ntohs(client_addr.sin_port);
        printf("New client connected from %s:%d\n", client_ip, client_port);

        /* Connect to the server */
        server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock < 0) {
            perror("socket() failed");
            close(client_sock);
            continue;
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(server_ip);
        server_addr.sin_port = htons(server_port);

        if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect() failed");
            close(client_sock);
            continue;
        }

        /* Forward data between the client and server */
        while ((read_size = read(client_sock, buffer, MAX_BUFFER_SIZE)) > 0) {
            if (write(server_sock, buffer, read_size) != read_size) {
                perror("write() failed");
                break;
            }

            read_size = read(server_sock, buffer, MAX_BUFFER_SIZE);
            if (read_size < 0) {
                perror("read() failed");
                break;
            }

            if (write(client_sock, buffer, read_size) != read_size) {
                perror("write() failed");
                break;
            }
        }

        /* Close the client and server sockets */
        close(client_sock);
        close(server_sock);
    }

    close(proxy_sock);
    return 0;
}