//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define PORT "80"
#define BUFFER_SIZE 1024

struct hostent *server;
int sock;

void *scanner(void *arg) {
    char *ip = (char *) arg;
    int ret;
    struct sockaddr_in sin;

    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(PORT));
    inet_pton(AF_INET, ip, &sin.sin_addr);

    ret = connect(sock, (struct sockaddr *) &sin, sizeof(sin));

    if (ret == 0) {
        printf("%s is online\n", ip);
    } else if (errno == ECONNREFUSED) {
        printf("%s is offline\n", ip);
    } else {
        printf("%s error: %s\n", ip, strerror(errno));
    }

    close(sock);
    return NULL;
}

int main() {
    int i, ret;
    pthread_t threads[MAX_THREADS];
    char *ips[MAX_THREADS];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server = gethostbyname("www.example.com");

    if (server == NULL) {
        printf("Error resolving host\n");
        return 1;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        ips[i] = malloc(16);
        sprintf(ips[i], "192.168.%d.%d", i / 256, i % 256);
        pthread_create(&threads[i], NULL, scanner, ips[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);
    return 0;
}