//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define BUF_SIZE 1024

struct hostent *gethostbyname(const char *name);

void *scan_thread(void *arg);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    sscanf(port_range, "%d-%d", &start_port, &end_port);

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int i = start_port; i <= end_port; i++) {
        if (thread_count >= MAX_THREADS) {
            printf("Maximum number of threads reached\n");
            break;
        }

        pthread_t thread;
        if (pthread_create(&thread, NULL, scan_thread, (void *)i)!= 0) {
            printf("Error creating thread: %d\n", i);
            break;
        }

        threads[thread_count++] = thread;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *scan_thread(void *arg) {
    int port = (int)arg;

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    char *ip = gethostbyname("");
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %d\n", port);
        return NULL;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }

    close(sock);
    return NULL;
}