//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOST_LEN];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(hostname, NULL, &hints, &result);
    if(status!= 0) {
        printf("Error: %s\n", gai_strerror(status));
        return 1;
    }

    int sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(sock == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    char data[MAX_DATA_LEN];
    memset(data, 0, sizeof(data));
    strcat(data, "PING");

    int sent = send(sock, data, strlen(data), 0);
    if(sent == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char buffer[MAX_DATA_LEN];
    memset(buffer, 0, sizeof(buffer));

    int received = recv(sock, buffer, sizeof(buffer), 0);
    if(received == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    printf("Received: %s\n", buffer);
    close(sock);

    return 0;
}