#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <netdb.h>

void *scan_port(void *arg) {
    char *hostname = (char *)arg;
    int port = 80;
    int sockfd;
    struct sockaddr_in sock_addr;

    while (port <= 1024) {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd == -1) {
            perror("Error creating socket");
            break;
        }

        memset(&sock_addr, 0, sizeof(sock_addr));
        sock_addr.sin_family = AF_INET;
        sock_addr.sin_port = htons(port);
        sock_addr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == 0) {
            printf("%s: UP\n", hostname);
            close(sockfd);
        } else {
            perror("Error connecting to host");
            close(sockfd);
        }

        port++;
    }

    return NULL;
}

int main() {
    FILE *fp = fopen("hosts.txt", "r");
    char line[256];
    pthread_t threads[1024];

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, 256, fp) != NULL) {
        char *hostname = strtok(line, ":");
        int port = atoi(strtok(NULL, ":"));

        pthread_create(&threads[port], NULL, scan_port, hostname);
    }

    for (int i = 0; i < 1024; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp);
    return 0;
}
