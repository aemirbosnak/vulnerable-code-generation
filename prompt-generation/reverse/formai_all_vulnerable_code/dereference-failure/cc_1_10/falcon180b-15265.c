//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX 65535
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sock, port, opt = 1;
    struct sockaddr_in dest;
    char *ip;
    int ret, sd;
    struct hostent *he;
    char buffer[BUFSIZE];

    if (argc < 3)
    {
        printf("Usage: %s <IP> <Port>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1)
    {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    inet_pton(AF_INET, ip, &dest.sin_addr);

    ret = connect(sock, (struct sockaddr *)&dest, sizeof(dest));

    if (ret == -1)
    {
        printf("Connection failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Port %d is open\n", port);

    close(sock);
    exit(0);
}