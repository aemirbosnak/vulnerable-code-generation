//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_NETWORKS 128
#define BUFFER_SIZE 256

typedef struct {
    char ssid[BUFFER_SIZE];
    char signal[BUFFER_SIZE];
} WiFiNetwork;

WiFiNetwork networks[MAX_NETWORKS];
int network_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* scan_networks(void* arg) {
    char buffer[BUFFER_SIZE];
    FILE* fp;

    // Use iwlist to scan for networks
    fp = popen("iwlist wlan0 scan | grep 'ESSID\\|Quality'", "r");
    if (fp == NULL) {
        perror("popen");
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char essid[BUFFER_SIZE];
        char signal[BUFFER_SIZE];

        // Parse ESSID
        if (sscanf(buffer, " ESSID:\"%[^\"]\"", essid)) {
            pthread_mutex_lock(&mutex);
            if (network_count < MAX_NETWORKS) {
                strcpy(networks[network_count].ssid, essid);
            }
            pthread_mutex_unlock(&mutex);
        }

        // Parse Quality
        if (sscanf(buffer, " Quality=%[0-9]/", signal)) {
            pthread_mutex_lock(&mutex);
            if (network_count < MAX_NETWORKS) {
                snprintf(networks[network_count].signal, BUFFER_SIZE, "%s%%", signal);
                network_count++;
            }
            pthread_mutex_unlock(&mutex);
        }
    }
    
    pclose(fp);
    return NULL;
}

void* print_networks(void* arg) {
    // Continuously print the network information
    while (1) {
        sleep(2);
        pthread_mutex_lock(&mutex);
        printf("\nDetected WiFi Networks (%d total):\n", network_count);
        for (int i = 0; i < network_count; i++) {
            printf("SSID: %-30s Signal: %s\n", networks[i].ssid, networks[i].signal);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t scanner_thread, printer_thread;

    // Create threads for scanning and printing
    pthread_create(&scanner_thread, NULL, scan_networks, NULL);
    pthread_create(&printer_thread, NULL, print_networks, NULL);

    // Join threads (this will block indefinitely in this case)
    pthread_join(scanner_thread, NULL);
    pthread_join(printer_thread, NULL);

    return 0;
}