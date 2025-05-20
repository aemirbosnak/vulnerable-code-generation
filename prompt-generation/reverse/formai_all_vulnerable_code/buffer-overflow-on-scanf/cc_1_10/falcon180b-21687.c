//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

typedef struct {
    char hostname[128];
    int port;
    int sockfd;
    int is_connected;
} server_info;

int connect_to_server(server_info *server) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server->port);
    inet_pton(AF_INET, server->hostname, &server_addr.sin_addr);

    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sockfd == -1) {
        printf("Error creating socket\n");
        return FALSE;
    }

    if (connect(server->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(server->sockfd);
        return FALSE;
    }

    server->is_connected = TRUE;
    return TRUE;
}

int send_request(server_info *server, char *request) {
    if (!server->is_connected) {
        printf("Not connected to server\n");
        return FALSE;
    }

    send(server->sockfd, request, strlen(request), 0);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(server->sockfd, buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        printf("Error receiving data from server\n");
        return FALSE;
    }

    printf("%s", buffer);
    return TRUE;
}

int main() {
    server_info server;
    printf("Enter server hostname: ");
    scanf("%s", server.hostname);
    printf("Enter server port: ");
    scanf("%d", &server.port);

    if (!connect_to_server(&server)) {
        return 1;
    }

    char request[128];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", server.hostname);

    if (!send_request(&server, request)) {
        return 1;
    }

    close(server.sockfd);
    return 0;
}