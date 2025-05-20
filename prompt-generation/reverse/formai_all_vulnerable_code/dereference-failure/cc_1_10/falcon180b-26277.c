//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define MAX 1000
#define PORT "80"
#define TIMEOUT 5

typedef struct {
    char *ip;
    char *domain;
} host_t;

void *thread(void *arg) {
    char *ip = (char *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *host;
    struct sockaddr_in server;

    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(PORT));

    if (inet_pton(AF_INET, ip, &server.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        close(sock);
        perror("connect");
        exit(EXIT_FAILURE);
    }

    host = gethostbyaddr((char *) &server.sin_addr, sizeof(server.sin_addr), AF_INET);

    if (host == NULL) {
        fprintf(stdout, "No reverse lookup for %s\n", ip);
    } else {
        fprintf(stdout, "Reverse lookup for %s: %s\n", ip, host->h_name);
    }

    close(sock);
    return NULL;
}

int main(int argc, char **argv) {
    int i, max;
    char input[MAX];
    char *ip;
    pthread_t threads[MAX];

    printf("Enter IP range (e.g. 192.168.0.1-192.168.0.255): ");
    fgets(input, MAX, stdin);

    max = atoi(strtok(input, "-"));

    for (i = 1; i <= max; i++) {
        ip = malloc(16);
        sprintf(ip, "192.168.0.%d", i);

        pthread_create(&threads[i-1], NULL, thread, ip);
    }

    for (i = 0; i < max; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}