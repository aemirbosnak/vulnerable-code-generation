//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct hostent *host;
    struct sockaddr_in servaddr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);

    if ((host = gethostbyname(hostname)) == NULL) {
        printf("Error: %s\n", hstrerror(h_errno));
        return 1;
    }

    if (host->h_addrtype!= AF_INET) {
        printf("Error: %s\n", "Invalid address type");
        return 1;
    }

    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(7);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    if (send(sockfd, "PING", strlen("PING"), 0) < 0) {
        printf("Error: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    ret = recv(sockfd, data, MAX_DATA, 0);

    if (ret < 0) {
        printf("Error: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    } else if (ret == 0) {
        printf("Host is down\n");
    } else {
        data[ret] = '\0';
        printf("Ping response: %s\n", data);
    }

    close(sockfd);
    return 0;
}