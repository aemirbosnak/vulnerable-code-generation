//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <linux/wireless.h>
#include <ifaddrs.h>
#include <fcntl.h>

#define MAX_NETWORKS 100
#define BUFFER_SIZE 1024

typedef struct {
    char ssid[32];
    int signal_strength;
} Network;

void scan_networks(Network networks[], int *count) {
    FILE *fp;
    char path[BUFFER_SIZE];

    fp = popen("iwlist scan 2>/dev/null | grep 'ESSID\\|Quality'", "r");
    if (fp == NULL) {
        perror("Failed to run iwlist command");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fgets(path, sizeof(path), fp) != NULL) {
        if (strstr(path, "ESSID:")) {
            sscanf(path, " ESSID:\"%[^\"]\"", networks[*count].ssid);
        } else if (strstr(path, "Quality")) {
            int quality;
            sscanf(path, " Quality=%d", &quality);
            networks[*count].signal_strength = quality;
            (*count)++;
        }
    }
    pclose(fp);
}

void print_networks(Network networks[], int count) {
    printf("Survivor, Here is a glimpse of the frequencies left in this fractured world:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-32s | Signal Strength\n", "SSID");
    printf("-------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-32s | %3d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
    printf("-------------------------------------------------------------\n");
}

int main(void) {
    printf("Initializing the Scanner... Please wait...\n");
    sleep(2);  // Simulate some delay for dramatic effect

    Network networks[MAX_NETWORKS];
    int count = 0;

    scan_networks(networks, &count);
    if (count == 0) {
        printf("No networks found! The silence is haunting...\n");
        return EXIT_FAILURE;
    }

    print_networks(networks, count);
    printf("Survey complete. May your next steps echo in the void...\n");
    
    return EXIT_SUCCESS;
}