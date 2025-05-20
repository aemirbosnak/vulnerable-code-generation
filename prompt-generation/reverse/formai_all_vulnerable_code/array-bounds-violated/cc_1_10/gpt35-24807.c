//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char request[MAX_BUF_SIZE];
    char response[MAX_BUF_SIZE];
    struct hostent *he;
    struct sockaddr_in server_addr;
    int sock;

    if ((he = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Error: unable to resolve hostname: %s\n", hostname);
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: failed to create socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr*)he->h_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: failed to connect to server");
        return 1;
    }

    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("Error: failed to send request");
        return 1;
    }

    int recv_len = 0;
    while ((recv_len = recv(sock, response, MAX_BUF_SIZE - 1, 0)) > 0) {
        response[recv_len] = '\0';
        printf("%s", response);
    }

    close(sock);
    return 0;
}