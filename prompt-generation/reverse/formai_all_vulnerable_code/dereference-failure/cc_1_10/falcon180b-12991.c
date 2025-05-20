//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

void err(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock, port;
    struct sockaddr_in serv_addr;
    char *ip;
    int opt = 1;
    int addrlen = sizeof(serv_addr);
    char buffer[1024];

    if (argc < 3)
    {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 0;
    }

    ip = argv[1];
    port = atoi(argv[2]);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        err("socket failed");
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        err("setsockopt");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    while (port <= 65535)
    {
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0)
        {
            printf("Port %d is open.\n", port);
        }
        else
        {
            printf("Port %d is closed.\n", port);
        }

        close(sock);
        port++;
    }

    return 0;
}