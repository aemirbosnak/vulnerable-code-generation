//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000  // Maximum number of networks that can be scanned

typedef struct wifi {
    char ssid[50];
    int signal_strength;
} wifi;

int main() {
    wifi network_list[MAX];
    int n;
    printf("Enter the number of networks you want to scan: ");
    scanf("%d", &n);

    if(n > MAX) {
        printf("Error: Maximum number of networks to scan exceeded");
        exit(1);
    }

    for(int i = 0; i < n; i++) {
        printf("Enter the SSID of network %d: ", i+1);
        scanf("%s", network_list[i].ssid);

        printf("Enter the signal strength of network %d (out of 100): ", i+1);
        scanf("%d", &network_list[i].signal_strength);

        if(network_list[i].signal_strength > 100 || network_list[i].signal_strength < 0) {
            printf("Error: Signal strength must be between 0 and 100");
            exit(1);
        }
    }

    // sort network_list in descending order of signal_strength
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(network_list[j].signal_strength < network_list[j+1].signal_strength) {
                wifi temp = network_list[j];
                network_list[j] = network_list[j+1];
                network_list[j+1] = temp;
            }
        }
    }

    // print the list of networks in descending order of signal_strength
    printf("\n================================\n");
    printf("Wi-Fi Networks, sorted by strength\n");
    printf("================================\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s : %d\n", i+1, network_list[i].ssid, network_list[i].signal_strength);
    }

    return 0;
}