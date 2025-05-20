//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SNAPLEN 65535
#define MAX_PKTS 1000
#define MAX_THREADS 10
#define SOCK_TIMEOUT 10

typedef struct {
    pcap_t *pcap;
    pthread_t thread_id;
    int is_running;
} thread_data_t;

void *packet_handler(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    pcap_t *pcap = data->pcap;
    const u_char *packet;
    int len;

    while (data->is_running) {
        packet = pcap_next(pcap, &len);

        if (packet == NULL) {
            continue;
        }

        // Process packet here
        printf("Packet received with length %d\n", len);

        if (data->is_running == 0) {
            break;
        }
    }

    return NULL;
}

int start_capture(pcap_t *pcap, int num_threads) {
    int i;
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];

    for (i = 0; i < num_threads; i++) {
        data[i].pcap = pcap;
        data[i].is_running = 1;

        if (pthread_create(&threads[i], NULL, packet_handler, &data[i])!= 0) {
            printf("Error creating thread %d\n", i);
            return -1;
        }
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap;
    char *dev;
    int ret;
    int num_threads = MAX_THREADS;

    printf("Enter capture device name: ");
    scanf("%s", dev);

    pcap = pcap_open_live(dev, MAX_SNAPLEN, 1, SOCK_TIMEOUT, errbuf);

    if (pcap == NULL) {
        printf("Error opening capture device: %s\n", errbuf);
        return -1;
    }

    ret = pcap_activate(pcap);

    if (ret!= 0) {
        printf("Error activating capture device: %s\n", pcap_geterr(pcap));
        return -1;
    }

    start_capture(pcap, num_threads);

    pcap_close(pcap);

    return 0;
}