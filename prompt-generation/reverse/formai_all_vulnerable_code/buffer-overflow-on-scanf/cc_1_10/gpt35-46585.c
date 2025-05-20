//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 20
#define SCAN_DELAY 3

int num_networks = 0;

struct network {
    char ssid[MAX_SSID_LENGTH];
    int strength;
};

struct network networks[MAX_NETWORKS];

void scan_networks() {
    printf("Scanning for wireless networks...\n");
    sleep(SCAN_DELAY);
    printf("Found %d networks:\n", MAX_NETWORKS);
    for(int i=0; i<MAX_NETWORKS; i++) {
        strcpy(networks[i].ssid, "MedievalWifi");
        networks[i].strength = rand() % 100;
        printf("%d. %s (strength: %d)\n", i+1, networks[i].ssid, networks[i].strength);
    }
    num_networks = MAX_NETWORKS;
}

void connect_to_network(int n) {
    if(n < 1 || n > num_networks) {
        printf("Invalid network number\n");
        return;
    }
    printf("Connecting to network %d...\n", n);
    sleep(2);
    printf("Connected to network %s\n", networks[n-1].ssid);
}

int main() {
    int option;
    do {
        printf("\nWireless Network Scanner - Medieval Style\n");
        printf("1. Scan for networks\n");
        printf("2. Connect to a network\n");
        printf("3. Quit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                scan_networks();
                break;
            case 2:
                if(num_networks == 0) {
                    printf("No networks found. Please scan for networks first.\n");
                } else {
                    int network_number;
                    printf("Enter network number to connect (1 to %d): ", num_networks);
                    scanf("%d", &network_number);
                    connect_to_network(network_number);
                }
                break;
            case 3:
                printf("Farewell traveler!\n");
                break;
            default:
                printf("Invalid option. Please select a valid option.\n");
                break;
        }
    } while(option != 3);
    return 0;
}