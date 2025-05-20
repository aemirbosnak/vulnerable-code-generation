//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 4096
#define TRUE 1
#define FALSE 0

typedef struct {
    char ip[16];
    int port;
} server_info;

void send_request(int sock, char *request) {
    send(sock, request, strlen(request), 0);
}

char *receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    return strdup(buffer);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char *response;
    char request[100];

    printf("Enter server IP address: ");
    scanf("%s", request);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, request, &server_addr.sin_addr);

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    send_request(sock, "GET /speedtest.txt HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");

    response = receive_response(sock);
    printf("%s", response);

    close(sock);
    exit(0);
}