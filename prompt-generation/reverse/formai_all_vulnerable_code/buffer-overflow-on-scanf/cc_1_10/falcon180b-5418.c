//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_HOST_NAME_LENGTH 256
#define MAX_DATA_SIZE 1024

int main() {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char host[MAX_HOST_NAME_LENGTH];
    char port[6];
    int rv;
    int numbytes;

    printf("Enter host name: ");
    scanf("%s", host);

    printf("Enter port number: ");
    scanf("%s", port);

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        printf("getaddrinfo() failed: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket()");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect()");
            close(sock);
            continue;
        }

        break;
    }

    if (p == NULL) {
        printf("Failed to connect.\n");
        exit(1);
    }

    printf("Connected to %s:%s\n", host, port);

    while(1) {
        char buffer[MAX_DATA_SIZE];
        int bytes_received = 0;
        struct timeval timeout;

        timeout.tv_sec = 0;
        timeout.tv_usec = 100000; // 100ms

        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        numbytes = recv(sock, buffer, MAX_DATA_SIZE, 0);

        if (numbytes <= 0) {
            if (numbytes == 0) {
                printf("Connection closed by server\n");
            } else {
                printf("recv() failed: %s\n", strerror(errno));
            }
            break;
        }

        printf("Received %d bytes: %s", numbytes, buffer);
    }

    close(sock);
    freeaddrinfo(servinfo);

    return 0;
}