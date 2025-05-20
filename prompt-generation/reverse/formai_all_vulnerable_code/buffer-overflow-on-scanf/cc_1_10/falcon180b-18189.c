//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define PORT_MAX 65535
#define BACKLOG 10

typedef struct {
    int sock;
    struct sockaddr_in server;
    struct sockaddr_in client;
} thread_data;

void * thread_func(void * arg) {
    thread_data * data = (thread_data *) arg;
    char buffer[1024];
    int bytes_recv;

    connect(data->sock, (struct sockaddr *) &data->server, sizeof(data->server));

    while ((bytes_recv = recv(data->sock, buffer, 1024, 0)) > 0) {
        buffer[bytes_recv] = '\0';
        printf("%s\n", buffer);
    }

    close(data->sock);
    return NULL;
}

int main() {
    int port;
    char ip[16];
    int sock, newsock, addrlen;
    struct sockaddr_in server, client;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the starting port number: ");
    scanf("%d", &port);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    bind(sock, (struct sockaddr *) &server, sizeof(server));

    listen(sock, BACKLOG);

    while (TRUE) {
        addrlen = sizeof(client);
        newsock = accept(sock, (struct sockaddr *) &client, &addrlen);

        pthread_t thread_id;
        thread_data * data = (thread_data *) malloc(sizeof(thread_data));

        data->sock = newsock;
        data->server = server;
        data->client = client;

        pthread_create(&thread_id, NULL, thread_func, data);
    }

    return 0;
}