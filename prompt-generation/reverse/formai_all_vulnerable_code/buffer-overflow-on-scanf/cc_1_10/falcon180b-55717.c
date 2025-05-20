//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

int sock;
struct sockaddr_in server_addr;
char buffer[BUFFER_SIZE];

void *scan(void *arg) {
    char ip[20];
    strcpy(ip, (char *)arg);

    struct hostent *host = gethostbyname(ip);
    if (host == NULL) {
        printf("Error: %s\n", strerror(errno));
        return NULL;
    }

    struct in_addr **addr_list = (struct in_addr **)host->h_addr_list;
    for (int i = 0; addr_list[i]!= NULL; i++) {
        inet_ntop(AF_INET, addr_list[i], buffer, BUFFER_SIZE);
        printf("%s\n", buffer);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    printf("Enter IP addresses to scan: ");
    char input[20];
    int count = 0;
    while (scanf("%s", input)!= EOF && count < MAX_THREADS) {
        pthread_create(&threads[count], NULL, scan, (void *)input);
        count++;
    }

    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}