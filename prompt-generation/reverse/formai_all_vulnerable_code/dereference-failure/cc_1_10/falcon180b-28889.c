//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

void *scan_port(void *arg) {
    char *ip = (char *) arg;
    int port = *(int *) (ip + strlen(ip) + 1);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    int ret = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (ret == 0) {
        printf("Port %d is open on %s\n", port, ip);
    } else {
        printf("Port %d is closed on %s\n", port, ip);
    }
    close(sock);
    return NULL;
}

int main() {
    char *ip = "127.0.0.1";
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];
    while (num_threads < MAX_THREADS) {
        int port = 0;
        while (port <= 65535) {
            char *port_str = malloc(6);
            sprintf(port_str, "%d", port);
            char *thread_arg = malloc(strlen(ip) + 6);
            strcpy(thread_arg, ip);
            strcat(thread_arg, " ");
            strcat(thread_arg, port_str);
            pthread_create(&threads[num_threads], NULL, scan_port, thread_arg);
            free(port_str);
            free(thread_arg);
            port++;
            num_threads++;
        }
        sleep(1);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}