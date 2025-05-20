//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SSID_LEN 32
#define MAX_NETWORKS 10

typedef struct network {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} Network;

void sort_networks(Network networks[], int num_networks) {
    int i, j;
    Network temp;
    
    for (i = 0; i < num_networks; i++) {
        for (j = 0; j < num_networks - 1; j++) {
            if (networks[j].signal_strength < networks[j+1].signal_strength) {
                temp = networks[j];
                networks[j] = networks[j+1];
                networks[j+1] = temp;
            }
        }
    }
}

void print_networks(Network networks[], int num_networks) {
    int i;
    
    printf("\nSSID\tSignal Strength\n");
    for (i = 0; i < num_networks; i++) {
        printf("%s\t%d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    int i, num_networks;
    Network networks[MAX_NETWORKS];
    
    printf("Enter the number of networks to analyze: ");
    scanf("%d", &num_networks);
    
    for (i = 0; i < num_networks; i++) {
        printf("Enter the SSID of network %d: ", i+1);
        scanf("%s", networks[i].ssid);
        
        printf("Enter the signal strength of network %d (out of 100): ", i+1);
        scanf("%d", &networks[i].signal_strength);
    }
    
    sort_networks(networks, num_networks);
    
    printf("\nNetworks sorted by signal strength (strongest first):\n");
    print_networks(networks, num_networks);
    
    return 0;
}