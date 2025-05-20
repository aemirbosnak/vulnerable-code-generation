//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];
    int port = 80;

    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME);
    port = atoi(argv[2]);

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // set up server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server.sin_addr);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send data
    sprintf(data, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    send(sock, data, strlen(data), 0);

    // receive response
    char response[MAX_DATA];
    memset(response, 0, sizeof(response));
    int bytes_received = 0;
    while ((bytes_received = recv(sock, response + bytes_received, sizeof(response) - bytes_received, 0)) > 0) {
        response[bytes_received] = '\0';
    }

    // print response
    printf("Response:\n%s", response);

    // close socket
    close(sock);

    return 0;
}