//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: standalone
#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <pthread.h>

volatile int running;          // Global variable to control the loop

// Callback function for pcap_loop
void packet_handler(u_char *arg, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received packet with length: %d\n", header->len);
    printf("Capture time: %s\n", ctime((const time_t *)&header->ts.tv_sec));

    // Print the first 16 bytes of the packet
    for (int i = 0; i < 16; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n");
}

void *input_handler(void *arg) {
    char input;
    while (running) {
        scanf(" %c", &input);
        if (input == 'q' || input == 'Q') {
            running = 0;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    // Check if the user provided an interface name
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the network interface for packet capture
    char *interface = argv[1];
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Create a thread to handle user input
    pthread_t input_thread;
    if (pthread_create(&input_thread, NULL, input_handler, NULL)) {
        fprintf(stderr, "pthread_create() failed\n");
        return EXIT_FAILURE;
    }

    // Set the running flag to true
    running = 1;

    // Start the packet capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // Wait for the input thread to finish
    pthread_join(input_thread, NULL);

    // Close the network interface
    pcap_close(handle);

    return EXIT_SUCCESS;
}