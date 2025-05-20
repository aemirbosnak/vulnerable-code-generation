//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 64

int main(int argc, char *argv[])
{
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char hostname[MAX_HOST_NAME];
    char data[MAX_DATA_SIZE];
    int datalen;
    struct timeval timeout;
    int ret;

    if (argc!= 3)
    {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    if ((host = gethostbyname(hostname)) == NULL)
    {
        printf("Error: could not resolve hostname '%s'\n", hostname);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error: could not create socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(7);
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("Error: could not connect to host '%s'\n", hostname);
        exit(1);
    }

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    ret = send(sock, data, strlen(data), 0);
    if (ret == -1)
    {
        printf("Error: could not send data\n");
        exit(1);
    }

    datalen = recv(sock, data, MAX_DATA_SIZE, 0);
    if (datalen <= 0)
    {
        printf("Error: could not receive data\n");
        exit(1);
    }

    printf("Received data: %s\n", data);

    close(sock);

    return 0;
}