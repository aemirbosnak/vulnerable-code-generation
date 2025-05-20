//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define TIMEOUT 5

int ping(char *hostname) {
    int sockfd, ret;
    struct sockaddr_in serveraddr;
    struct hostent *hostinfo;

    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        printf("Error: Host not found\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Socket creation failed\n");
        return 1;
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(0);
    memcpy(&serveraddr.sin_addr, hostinfo->h_addr, hostinfo->h_length);

    ret = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (ret < 0) {
        printf("Error: Connection failed\n");
        close(sockfd);
        return 1;
    }

    close(sockfd);
    return 0;
}

void *ping_thread(void *param) {
    char *hostname = (char *)param;
    int ret;

    ret = ping(hostname);
    if (ret == 0) {
        printf("%s is reachable\n", hostname);
    } else {
        printf("%s is not reachable\n", hostname);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int i;
    pthread_t threads[argc - 1];

    for (i = 1; i < argc; i++) {
        pthread_create(&threads[i - 1], NULL, ping_thread, argv[i]);
    }

    for (i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}