//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 80

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> [<port>]\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = DEFAULT_PORT;

    if (argc > 2) {
        port = atoi(argv[2]);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct hostent *server = gethostbyname(host);

    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", host);
        close(sock);
        return 1;
    }

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("connect");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);

    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sock);
        return 1;
    }

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    int bytes_received = 0;

    while ((bytes_received = recv(sock, response + bytes_received, BUFFER_SIZE - bytes_received, 0)) > 0) {
        response[bytes_received] = '\0';

        if (strstr(response, "200 OK")!= NULL) {
            printf("Ping successful.\n");
        } else {
            printf("Ping failed.\n");
        }

        break;
    }

    close(sock);

    return 0;
}