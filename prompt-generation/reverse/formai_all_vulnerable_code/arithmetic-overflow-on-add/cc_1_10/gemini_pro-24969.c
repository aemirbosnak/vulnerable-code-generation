//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multi-threaded
#include <pcap.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

// Maximum number of packets to capture
#define MAX_PACKETS 10000

// Semaphore to synchronize access to shared data
sem_t semaphore;

// Thread-specific data
typedef struct {
    pcap_t *handle;
    int thread_id;
    int num_packets_captured;
} thread_data;

// Function to capture packets
void *capture_packets(void *arg) {
    thread_data *data = (thread_data *)arg;

    // Start capturing packets
    while (1) {
        // Wait for the semaphore
        sem_wait(&semaphore);

        // Capture a packet
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(data->handle, &header, &packet);

        // Release the semaphore
        sem_post(&semaphore);

        if (res == 0) {
            // No more packets to capture
            break;
        } else if (res == 1) {
            // Packet captured successfully
            data->num_packets_captured++;
        } else {
            // Error
            perror("pcap_next_ex");
            break;
        }
    }

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Open the network interface
    char *device = "en0";
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live");
        return 1;
    }

    // Create a semaphore
    sem_init(&semaphore, 0, 1);

    // Create threads
    int num_threads = 4;
    pthread_t threads[num_threads];
    thread_data data[num_threads];
    for (int i = 0; i < num_threads; i++) {
        data[i].handle = handle;
        data[i].thread_id = i;
        data[i].num_packets_captured = 0;
        pthread_create(&threads[i], NULL, capture_packets, &data[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close the network interface
    pcap_close(handle);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    // Print the number of packets captured by each thread
    for (int i = 0; i < num_threads; i++) {
        printf("Thread %d captured %d packets\n", data[i].thread_id, data[i].num_packets_captured);
    }

    return 0;
}