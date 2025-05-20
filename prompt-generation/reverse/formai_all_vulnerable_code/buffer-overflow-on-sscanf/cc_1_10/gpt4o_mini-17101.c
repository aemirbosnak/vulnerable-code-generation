//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_quality;
} WifiNetwork;

WifiNetwork wifi_networks[MAX_NETWORKS];
int network_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *scan_networks(void *arg) {
    FILE *fp;
    char command[256];
    
    // Crafting command to scan Wi-Fi networks
    sprintf(command, "iwlist %s scan | grep 'ESSID:\\|Signal level' > temp_scan.txt", (char *)arg);
    
    // Execute the command
    system(command);

    // Read the results
    fp = fopen("temp_scan.txt", "r");
    if (fp == NULL) {
        perror("Failed to open scan file");
        return NULL;
    }
    
    char line[128];
    char ssid[MAX_SSID_LENGTH];
    int signal_quality;

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, " ESSID:\"%[^\"]\"", ssid) == 1) {
            // Found an SSID, now we will read the next line for signal quality
            if (fgets(line, sizeof(line), fp)) {
                if (sscanf(line, " Signal level=%d", &signal_quality) == 1) {
                    pthread_mutex_lock(&mutex);
                    if (network_count < MAX_NETWORKS) {
                        strcpy(wifi_networks[network_count].ssid, ssid);
                        wifi_networks[network_count].signal_quality = signal_quality;
                        network_count++;
                    }
                    pthread_mutex_unlock(&mutex);
                }
            }
        }
    }
    
    fclose(fp);
    return NULL;
}

void display_networks() {
    printf("Available Wi-Fi Networks:\n");
    printf("%-32s %-15s\n", "SSID", "Signal Quality (dBm)");
    for (int i = 0; i < network_count; i++) {
        printf("%-32s %-15d\n", wifi_networks[i].ssid, wifi_networks[i].signal_quality);
    }
}

int main() {
    pthread_t threads[2];
    
    // Create threads for scanning
    printf("Starting Wi-Fi network scans...\n");
    
    char *interface1 = "wlan0"; // Change to your Wi-Fi interface
    char *interface2 = "wlan1"; // Change to another Wi-Fi interface if available

    pthread_create(&threads[0], NULL, scan_networks, interface1);
    pthread_create(&threads[1], NULL, scan_networks, interface2);

    // Wait for threads to complete
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    display_networks();

    // Clean up
    remove("temp_scan.txt");
    pthread_mutex_destroy(&mutex);

    return 0;
}