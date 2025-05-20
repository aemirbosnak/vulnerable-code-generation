//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024
#define MAX_HOST_NAME_SIZE 256
#define MAX_SERVICE_NAME_SIZE 16

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct addrinfo hints, *result = NULL, *rp = NULL;
    char hostname[MAX_HOST_NAME_SIZE];
    char service[MAX_SERVICE_NAME_SIZE];
    char *data = NULL;
    int datalen = 0;
    int maxdatalen = MAX_DATA_SIZE;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <service>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    strcpy(service, argv[2]);

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    retval = getaddrinfo(hostname, service, &hints, &result);
    if (retval!= 0) {
        fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(retval));
        exit(1);
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        retval = connect(sockfd, rp->ai_addr, rp->ai_addrlen);
        if (retval!= -1 || errno!= EINPROGRESS) {
            fprintf(stderr, "connect failed: %s\n", strerror(errno));
            close(sockfd);
            continue;
        }

        break;
    }

    if (rp == NULL) {
        fprintf(stderr, "Could not connect\n");
        exit(1);
    }

    data = malloc(maxdatalen);
    if (data == NULL) {
        perror("malloc");
        exit(1);
    }

    while (1) {
        retval = recv(sockfd, data, maxdatalen, 0);
        if (retval <= 0) {
            if (retval == 0) {
                fprintf(stdout, "Connection closed\n");
            } else {
                fprintf(stderr, "recv failed: %s\n", strerror(errno));
            }
            break;
        }

        datalen = retval;
        data[datalen] = '\0';
        fprintf(stdout, "Received: %s", data);

        if (datalen >= maxdatalen - 1) {
            maxdatalen += MAX_DATA_SIZE;
            data = realloc(data, maxdatalen);
            if (data == NULL) {
                perror("realloc");
                exit(1);
            }
        }
    }

    close(sockfd);
    free(data);
    freeaddrinfo(result);

    return 0;
}