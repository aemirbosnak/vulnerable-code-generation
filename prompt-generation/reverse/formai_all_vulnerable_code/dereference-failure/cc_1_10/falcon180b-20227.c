//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define MAX_HOSTS 10

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    struct hostent *host;
    struct sockaddr_in server_addr;
    int sockfd, i;
    char buf[BUF_SIZE];

    if ((host = gethostbyname(hostname)) == NULL) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    for (i = 0; host->h_addr_list[i]!= NULL; i++) {
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        memcpy(&server_addr.sin_addr, host->h_addr_list[i], host->h_length);
        server_addr.sin_port = htons(7);

        if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
            printf("Error: %s\n", strerror(errno));
            return 1;
        }

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            printf("Host %s is down\n", hostname);
        } else {
            printf("Host %s is up\n", hostname);
        }

        close(sockfd);
    }

    return 0;
}