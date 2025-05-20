//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 8192

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server_addr;
    char host[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];
    int port;
    int opt = 1;
    int addrlen;
    int n;

    printf("Enter the IP address of the server: ");
    scanf("%s", host);

    printf("Enter the port number: ");
    scanf("%d", &port);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    addrlen = sizeof(server_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", host, port);

    while (1) {
        memset(data, 0, MAX_DATA_LEN);
        n = recv(sock, data, MAX_DATA_LEN, 0);
        if (n <= 0) {
            break;
        }
        printf("Received %d bytes of data:\n%s", n, data);
    }

    close(sock);
    return 0;
}