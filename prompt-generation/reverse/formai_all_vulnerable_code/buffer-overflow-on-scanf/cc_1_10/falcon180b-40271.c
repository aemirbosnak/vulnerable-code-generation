//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_SSIDS 20

struct thread_data {
    int thread_id;
    char ssid[32];
};

void *scan_thread(void *data) {
    struct thread_data *tdata = (struct thread_data *)data;
    int thread_id = tdata->thread_id;
    char ssid[32] = {0};

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error: Cannot create socket\n");
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1);
    inet_pton(AF_INET, "255.255.255.255", &server_addr.sin_addr);

    while (1) {
        char buffer[1024];
        int len = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (len <= 0) {
            printf("Error: Cannot receive data\n");
            break;
        }

        char *pos = strstr(buffer, "SSID:");
        if (pos!= NULL) {
            pos += 6;
            strncpy(ssid, pos, sizeof(ssid));
            printf("Thread %d found SSID: %s\n", thread_id, ssid);
            break;
        }
    }

    close(sock);
    return NULL;
}

int main() {
    int num_threads = 0;
    int i;

    printf("Enter the number of threads to use (1-10): ");
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Error: Invalid number of threads\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    struct thread_data tdata[MAX_THREADS];

    printf("Enter the SSIDs to scan for (up to %d):\n", MAX_SSIDS);
    for (i = 0; i < num_threads; i++) {
        scanf("%s", tdata[i].ssid);
    }

    for (i = 0; i < num_threads; i++) {
        tdata[i].thread_id = i + 1;
        pthread_create(&threads[i], NULL, scan_thread, &tdata[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}