//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

// Function to scan wireless networks
void *scan_networks(void *arg) {
    char *network_name = (char *) arg;
    FILE *fp;
    char line[BUFFER_SIZE];

    // Open the network interface file
    fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/net/wireless\n");
        exit(1);
    }

    // Search for the specified network
    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        if (strstr(line, network_name)!= NULL) {
            // Network found, print details
            printf("Network %s found\n", network_name);
            printf("Signal strength: ");
            fgets(line, BUFFER_SIZE, fp);
            printf("%s\n", line);
            break;
        }
    }

    fclose(fp);
    return NULL;
}

// Function to create and manage threads
void scan_networks_thread(char *network_name) {
    pthread_t thread_id;

    // Create a new thread
    pthread_create(&thread_id, NULL, scan_networks, (void *) network_name);

    // Wait for the thread to finish
    pthread_join(thread_id, NULL);
}

// Main function
int main() {
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];

    // Get the number of wireless networks to scan
    printf("Enter the number of wireless networks to scan: ");
    scanf("%d", &num_threads);

    // Create and start the threads
    for (int i = 0; i < num_threads; i++) {
        char network_name[20];
        printf("Enter the name of the %dth network to scan: ", i+1);
        scanf("%s", network_name);

        // Start a new thread for each network
        scan_networks_thread(network_name);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}