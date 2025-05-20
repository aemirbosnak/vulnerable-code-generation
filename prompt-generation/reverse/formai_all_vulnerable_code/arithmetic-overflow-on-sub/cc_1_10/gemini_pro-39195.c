//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <net/if.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pcap.h>

#define MAX_IFACE_LEN 16

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <filter>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *iface = argv[1];
    char *filter = argv[2];

    // Open the network interface
    pcap_t *handle = pcap_open_live(iface, BUFSIZ, 0, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface %s: %s\n", iface, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Compile the filter
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 0, NULL) != 0) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) != 0) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Initialize the statistics
    struct timeval start_time;
    struct timeval end_time;
    int total_packets = 0;
    int total_bytes = 0;
    int max_delay = 0;
    int min_delay = 1000000;
    int avg_delay = 0;

    // Capture packets
    while (1) {
        // Get the current time
        gettimeofday(&start_time, NULL);

        // Capture a packet
        struct pcap_pkthdr *header;
        const u_char *data;
        int res = pcap_next_ex(handle, &header, &data);

        // Update the statistics
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        }

        total_packets++;
        total_bytes += header->len;

        // Get the timestamp of the packet
        struct timeval timestamp;
        timestamp.tv_sec = header->ts.tv_sec;
        timestamp.tv_usec = header->ts.tv_usec;

        // Calculate the delay between the current time and the timestamp
        int delay = (end_time.tv_sec - timestamp.tv_sec) * 1000000 + (end_time.tv_usec - timestamp.tv_usec);

        // Update the maximum, minimum, and average delay
        if (delay > max_delay) {
            max_delay = delay;
        }
        if (delay < min_delay) {
            min_delay = delay;
        }
        avg_delay = (avg_delay + delay) / 2;

        // Get the end time
        gettimeofday(&end_time, NULL);
    }

    // Print the statistics
    printf("Total packets: %d\n", total_packets);
    printf("Total bytes: %d\n", total_bytes);
    printf("Maximum delay: %d\n", max_delay);
    printf("Minimum delay: %d\n", min_delay);
    printf("Average delay: %d\n", avg_delay);

    // Close the network interface
    pcap_close(handle);

    return EXIT_SUCCESS;
}