//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strncpy(hostname, argv[1], MAX_HOSTNAME - 1);

    int port = atoi(argv[2]);

    struct hostent *he;
    he = gethostbyname(hostname);
    if (he == NULL) {
        herror("gethostbyname");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, he->h_addr, he->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        die("socket");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        die("connect");
    }

    char send_data[MAX_DATA];
    memset(send_data, 'A', sizeof(send_data));

    if (send(sockfd, send_data, sizeof(send_data), 0)!= sizeof(send_data)) {
        die("send");
    }

    char recv_data[MAX_DATA];
    memset(recv_data, 0, sizeof(recv_data));

    if (recv(sockfd, recv_data, sizeof(recv_data), 0)!= sizeof(recv_data)) {
        die("recv");
    }

    close(sockfd);

    if (memcmp(send_data, recv_data, sizeof(recv_data))!= 0) {
        printf("Echo test failed!\n");
        return 1;
    } else {
        printf("Echo test passed.\n");
        return 0;
    }
}