//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 80

int main(int argc, char *argv[]) {
    int sockfd, clientfd, serverfd;
    struct sockaddr_in server_addr, client_addr, server_sockaddr;
    int addrlen = sizeof(struct sockaddr_in);
    char buffer[1024];

    // Creating a socket for the proxy server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket()");
        exit(1);
    }

    // Setting the server address
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    // Binding the socket to the server address
    if(bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind()");
        exit(1);
    }

    // Listening for incoming connections
    if(listen(sockfd, 10) < 0) {
        perror("listen()");
        exit(1);
    }
    printf("HTTP Proxy server started and listening on port %d\n", SERVER_PORT);

    while(1) {
        // Accepting a client connection
        bzero(&client_addr, sizeof(client_addr));
        clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
        if(clientfd < 0) {
            perror("accept()");
            continue;
        }

        printf("Received incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receiving the client request
        int n = recv(clientfd, buffer, sizeof(buffer) - 1, 0);
        if(n <= 0) {
            perror("recv()");
            close(clientfd);
            continue;
        }
        buffer[n] = '\0';

        printf("Received client request:\n%s\n", buffer);

        // Parsing the client request to extract the desired server address and port
        char *pos = strstr(buffer, "Host: ");
        if(pos == NULL) {
            printf("Invalid client request, could not find host\n");
            close(clientfd);
            continue;
        }
        pos += 6;
        char *pos2 = strchr(pos, '\r');
        if(pos2 == NULL) {
            printf("Invalid client request, could not find end of host\n");
            close(clientfd);
            continue;
        }
        *pos2 = '\0';
        char *hostname = pos;
        int port = 80; // Default port is 80
        pos = strchr(hostname, ':');
        if(pos != NULL) {
            *pos = '\0';
            port = atoi(pos + 1);
        }

        printf("Connecting to server %s:%d...\n", hostname, port);

        // Creating a socket for the server
        serverfd = socket(AF_INET, SOCK_STREAM, 0);
        if(serverfd < 0) {
            perror("socket()");
            close(clientfd);
            continue;
        }

        // Setting the server address
        bzero(&server_sockaddr, sizeof(server_sockaddr));
        server_sockaddr.sin_family = AF_INET;
        server_sockaddr.sin_addr.s_addr = inet_addr(hostname);
        server_sockaddr.sin_port = htons(port);

        // Connecting to the server
        if(connect(serverfd, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr)) < 0) {
            perror("connect()");
            close(clientfd);
            close(serverfd);
            continue;
        }

        // Sending the client request to the server
        if(send(serverfd, buffer, n, 0) < 0) {
            perror("send()");
            close(clientfd);
            close(serverfd);
            continue;
        }

        // Receiving the server response
        n = recv(serverfd, buffer, sizeof(buffer) - 1, 0);
        if(n <= 0) {
            perror("recv()");
            close(clientfd);
            close(serverfd);
            continue;
        }
        buffer[n] = '\0';

        printf("Received server response:\n%s\n", buffer);

        // Forwarding the server response to the client
        if(send(clientfd, buffer, n, 0) < 0) {
            perror("send()");
            close(clientfd);
            close(serverfd);
            continue;
        }

        // Closing the client and server connections
        close(clientfd);
        close(serverfd);

        printf("Connection closed\n");
    }

    return 0;
}