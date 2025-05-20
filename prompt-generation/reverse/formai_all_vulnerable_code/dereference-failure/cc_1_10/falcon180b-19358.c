//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_PKT_SIZE 1024
#define MAX_THREADS 10
#define MAX_EVENTS 100

struct packet_info {
    u_char *packet;
    int len;
    struct timeval ts;
};

struct thread_data {
    int thread_id;
    FILE *log_file;
};

pcap_t *handle;
char *dev;
char errbuf[PCAP_ERRBUF_SIZE];

void *process_packet(void *arg) {
    struct thread_data *data = arg;
    struct packet_info packet;
    while (pcap_next_ex(handle, &packet.packet, &packet.len)!= -1) {
        struct iphdr *ip = (struct iphdr *) packet.packet;
        struct tcphdr *tcp = (struct tcphdr *) (packet.packet + ip->ihl * 4);
        if (tcp->syn == 1 && tcp->ack == 0) {
            fprintf(data->log_file, "SYN packet detected at %ld.%06ld\n", packet.ts.tv_sec, packet.ts.tv_usec);
        }
    }
    return NULL;
}

int main() {
    int i, j;
    pthread_t threads[MAX_THREADS];
    struct thread_data thread_data[MAX_THREADS];

    handle = pcap_open_live(dev, BUFSIZ, 1, 100, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening %s: %s\n", dev, errbuf);
        exit(1);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].log_file = fopen("syn_packets.log", "a");
        pthread_create(&threads[i], NULL, process_packet, &thread_data[i]);
    }

    pcap_loop(handle, -1, process_packet, NULL);

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pcap_close(handle);
    return 0;
}