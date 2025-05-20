//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT_LIST "22,80,443"
#define MAX_PORTS 3

int scan_port(char *ip_address, char *port)
{
    int sockfd, retval;
    struct sockaddr_in target;
    int opt = 1;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return -1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(atoi(port));
    inet_pton(AF_INET, ip_address, &target.sin_addr);

    retval = connect(sockfd, (struct sockaddr *)&target, sizeof(target));

    if (retval < 0)
    {
        printf("Connection failed\n");
        close(sockfd);
        return -1;
    }

    printf("Connection established\n");
    close(sockfd);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    char *ports = PORT_LIST;
    char *port;

    printf("Scanning ports: %s\n", ports);

    while ((port = strsep(&ports, ","))!= NULL)
    {
        scan_port(ip_address, port);
    }

    return 0;
}