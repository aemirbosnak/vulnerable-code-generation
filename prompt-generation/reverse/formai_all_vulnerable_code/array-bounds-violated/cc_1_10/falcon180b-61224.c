//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOST 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;

    char hostname[MAX_HOST];
    char data[MAX_DATA];

    strcpy(hostname, "www.example.com");
    strcpy(data, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if ((host = gethostbyname(hostname)) == NULL) {
        printf("Error getting host information\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    send(sock, data, strlen(data), 0);

    char buffer[MAX_DATA];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, MAX_DATA, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sock);

    return 0;
}