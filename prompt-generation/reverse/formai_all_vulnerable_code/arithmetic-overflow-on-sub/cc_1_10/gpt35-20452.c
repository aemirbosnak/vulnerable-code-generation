//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ssid[20];
    int signal_strength; 
} wifi;

void display_wifi_networks(wifi *wifi_networks, int num_networks) {
    printf("WiFi Network List:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%d. %s - %d dBm\n", i+1, wifi_networks[i].ssid, wifi_networks[i].signal_strength);
    }
}

void sort_wifi_networks(wifi *wifi_networks, int num_networks) {
    for (int i = 0; i < num_networks-1; i++) {
        for (int j = 0; j < num_networks-i-1; j++) {
            if (wifi_networks[j].signal_strength < wifi_networks[j+1].signal_strength) {
                wifi temp = wifi_networks[j];
                wifi_networks[j] = wifi_networks[j+1];
                wifi_networks[j+1] = temp;
            }
        }
    }
}

int main() {
    int num_networks;
    printf("Enter the number of WiFi networks: ");
    scanf("%d", &num_networks);
    
    wifi *wifi_networks = (wifi*)malloc(num_networks * sizeof(wifi));
    for (int i = 0; i < num_networks; i++) {
        printf("\nWiFi network %d details:\n", i+1);
        printf("Enter the SSID: ");
        scanf("%s", wifi_networks[i].ssid);
        printf("Enter the signal strength (in dBm): ");
        scanf("%d", &wifi_networks[i].signal_strength);
    }
    
    display_wifi_networks(wifi_networks, num_networks);
    
    sort_wifi_networks(wifi_networks, num_networks);
    
    printf("\nWiFi Networks sorted in descending order of signal strength:\n");
    
    display_wifi_networks(wifi_networks, num_networks);
    
    free(wifi_networks);
    
    return 0;
}