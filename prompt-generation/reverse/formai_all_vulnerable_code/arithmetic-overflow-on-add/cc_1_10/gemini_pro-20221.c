//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: distributed
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PACKETS 1000
#define PCAP_ERRBUF_SIZE 256

typedef struct {
    pcap_t *handle;
    int num_packets;
    char errbuf[PCAP_ERRBUF_SIZE];
} pcap_thread_data;

void *pcap_thread(void *arg) {
    pcap_thread_data *data = (pcap_thread_data *)arg;
    
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(data->handle, &header, &packet);
        if (res == 1) {
            // Process the packet here
            data->num_packets++;
        } else if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", data->errbuf);
        } else if (res == -2) {
            // End of file
            break;
        }
    }
    
    pcap_close(data->handle);
    return NULL;
}

int main() {
    char *device = "eth0";
    int num_threads = 4;
    pcap_thread_data threads[num_threads];
    
    // Open a pcap handle for each thread
    for (int i = 0; i < num_threads; i++) {
        threads[i].handle = pcap_open_live(device, BUFSIZ, 1, 1000, threads[i].errbuf);
        if (threads[i].handle == NULL) {
            fprintf(stderr, "Error opening pcap handle: %s\n", threads[i].errbuf);
            return EXIT_FAILURE;
        }
    }
    
    // Create a thread for each pcap handle
    pthread_t tid[num_threads];
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&tid[i], NULL, pcap_thread, (void *)&threads[i]) != 0) {
            fprintf(stderr, "Error creating thread\n");
            return EXIT_FAILURE;
        }
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread\n");
            return EXIT_FAILURE;
        }
    }
    
    // Print the number of packets processed by each thread
    for (int i = 0; i < num_threads; i++) {
        printf("Thread %d processed %d packets\n", i, threads[i].num_packets);
    }
    
    return EXIT_SUCCESS;
}