//Falcon2-11B DATASET v1.0 Category: Networking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct SockAddr {
    int sockfd;
    int port;
    char host[16];
};

int main() {
    struct SockAddr client, server;
    char buf[1024];
    int n;

    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.port = 8080;
    server.host[0] = '\0';
    server.host[1] = '\0';
    server.host[2] = '\0';
    server.host[3] = '\0';
    server.host[4] = '\0';
    server.host[5] = '\0';
    server.host[6] = '\0';
    server.host[7] = '\0';
    server.host[8] = '\0';
    server.host[9] = '\0';
    server.host[10] = '\0';
    server.host[11] = '\0';
    server.host[12] = '\0';
    server.host[13] = '\0';
    server.host[14] = '\0';
    server.host[15] = '\0';
    bzero(buf, sizeof(buf));
    printf("Enter the hostname of the server: ");
    scanf("%s", server.host);
    bzero(buf, sizeof(buf));
    printf("Enter the port number: ");
    scanf("%d", &server.port);
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(server.sockfd, (struct sockaddr *)&server, sizeof(server));
    listen(server.sockfd, 5);

    client.sockfd = accept(server.sockfd, (struct sockaddr *)&client, (socklen_t *)&n);
    printf("Client connected with host %s and port %d\n", client.host, client.port);
    read(client.sockfd, buf, sizeof(buf));
    write(client.sockfd, buf, sizeof(buf));
    close(client.sockfd);
    close(server.sockfd);
    return 0;
}