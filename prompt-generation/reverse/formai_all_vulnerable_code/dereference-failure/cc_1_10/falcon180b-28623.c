//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA_SIZE 64
#define TRUE 1
#define FALSE 0
#define PORT 7

struct hostent *gethostbyname(char *name);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA_SIZE];
    int datalen;
    int status;
    struct timeval timeout;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        return 1;
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME);
    strncpy(data, argv[2], MAX_DATA_SIZE);

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    status = inet_pton(AF_INET, hostname, &server.sin_addr);
    if (status <= 0) {
        close(sock);
        printf("Invalid hostname\n");
        return 1;
    }

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    datalen = sendto(sock, data, strlen(data), 0, (struct sockaddr *)&server, sizeof(server));
    if (datalen == -1) {
        perror("sendto");
        close(sock);
        return 1;
    }

    memset(data, 0, MAX_DATA_SIZE);
    datalen = recvfrom(sock, data, MAX_DATA_SIZE, 0, NULL, NULL);
    if (datalen == -1) {
        perror("recvfrom");
        close(sock);
        return 1;
    }

    printf("Ping response: %s\n", data);

    close(sock);

    return 0;
}

struct hostent *gethostbyname(char *name)
{
    struct hostent *host;
    int status;

    status = gethostbyname_r(name, &host, NULL, 0, NULL);
    if (status!= 0) {
        herror("gethostbyname");
        return NULL;
    }

    return host;
}