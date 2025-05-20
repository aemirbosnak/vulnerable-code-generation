//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_SIGNAL_STRENGTH 100
#define MAX_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Network;

int main() {
    Network networks[MAX_NETWORKS];
    int num_networks = 0;
    
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    printf("Enter the details for up to %d networks.\n", MAX_NETWORKS);
    
    while (num_networks < MAX_NETWORKS) {
        printf("Network %d:\n", num_networks + 1);
        
        char ssid[MAX_SSID_LENGTH];
        int signal_strength;
        printf("Enter the SSID: ");
        scanf("%s", ssid);
        printf("Enter the signal strength (0-%d): ", MAX_SIGNAL_STRENGTH);
        scanf("%d", &signal_strength);
        
        if (signal_strength < 0 || signal_strength > MAX_SIGNAL_STRENGTH) {
            printf("Invalid signal strength! Please try again.\n");
            continue;
        }
        
        Network network;
        strcpy(network.ssid, ssid);
        network.signal_strength = signal_strength;
        networks[num_networks] = network;
        num_networks++;
        
        char response;
        printf("Do you want to enter another network? (y/n): ");
        scanf(" %c", &response);
        
        if (response == 'n' || response == 'N') {
            break;
        }
    }
    
    printf("Results:\n");
    for (int i = 0; i < num_networks; i++) {
        Network network = networks[i];
        printf("Network %d: %s - %d%% signal strength\n", i + 1, network.ssid, network.signal_strength);
    }
    
    printf("Thank you for using the Wi-Fi Signal Strength Analyzer!\n");
    return 0;
}