//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024
#define MAX_HOST_NAME_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOST_NAME_SIZE];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        printf("Error: %s\n", gai_strerror(errno));
        return 1;
    }

    int sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sock, result->ai_addr, result->ai_addrlen) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char send_data[MAX_DATA_SIZE];
    memset(send_data, 'A', MAX_DATA_SIZE);

    if (send(sock, send_data, MAX_DATA_SIZE, 0) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char recv_data[MAX_DATA_SIZE];
    memset(recv_data, 0, MAX_DATA_SIZE);

    int bytes_received = recv(sock, recv_data, MAX_DATA_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    printf("Received %d bytes of data:\n%s\n", bytes_received, recv_data);

    close(sock);
    return 0;
}