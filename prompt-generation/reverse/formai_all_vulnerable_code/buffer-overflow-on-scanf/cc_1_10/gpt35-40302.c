//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_SSID_LENGTH 32
#define MAX_NUMBER_OF_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    double signal_strength;
} wifi_network_t;

wifi_network_t networks[MAX_NUMBER_OF_NETWORKS];
int num_networks = 0;

void print_menu() {
    printf("\n---------------------\n");
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("---------------------\n");
    printf("1. Add Network\n");
    printf("2. Remove Network\n");
    printf("3. List Networks\n");
    printf("4. Analyze Signal Strength\n");
    printf("5. Quit\n");
}

void add_network() {
    if(num_networks == MAX_NUMBER_OF_NETWORKS) {
        printf("Maximum number of networks reached\n");
        return;
    }
    
    char ssid[MAX_SSID_LENGTH];
    double signal_strength;
    
    printf("Enter SSID (max %d characters): ", MAX_SSID_LENGTH - 1);
    scanf("%s", ssid);
    
    printf("Enter signal strength (in dBm): ");
    scanf("%lf", &signal_strength);
    
    strcpy(networks[num_networks].ssid, ssid);
    networks[num_networks].signal_strength = signal_strength;
    
    num_networks++;
    
    printf("Network added successfully\n");
}

void remove_network() {
    if(num_networks == 0) {
        printf("No networks to remove\n");
        return;
    }
    
    char ssid[MAX_SSID_LENGTH];
    printf("Enter SSID to remove: ");
    scanf("%s", ssid);
    
    bool found = false;
    for(int i = 0; i < num_networks; i++) {
        if(strcmp(networks[i].ssid, ssid) == 0) {
            for(int j = i; j < num_networks - 1; j++) {
                networks[j] = networks[j+1];
            }
            num_networks--;
            found = true;
            break;
        }
    }
    
    if(found) {
        printf("Network removed successfully\n");
    }
    else {
        printf("Network not found\n");
    }
}

void list_networks() {
    if(num_networks == 0) {
        printf("No networks to list\n");
        return;
    }
    
    printf("SSID\tSignal Strength\n");
    for(int i = 0; i < num_networks; i++) {
        printf("%s\t%.1lf dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

void analyze_signal_strength() {
    if(num_networks == 0) {
        printf("No networks to analyze\n");
        return;
    }
    
    double avg_signal_strength = 0;
    double min_signal_strength = INFINITY;
    double max_signal_strength = -INFINITY;
    
    for(int i = 0; i < num_networks; i++) {
        double signal_strength = networks[i].signal_strength;
        avg_signal_strength += signal_strength;
        if(signal_strength < min_signal_strength) {
            min_signal_strength = signal_strength;
        }
        if(signal_strength > max_signal_strength) {
            max_signal_strength = signal_strength;
        }
    }
    
    avg_signal_strength /= num_networks;
    
    printf("Analysis Results:\n");
    printf("Average Signal Strength: %.1lf dBm\n", avg_signal_strength);
    printf("Minimum Signal Strength: %.1lf dBm\n", min_signal_strength);
    printf("Maximum Signal Strength: %.1lf dBm\n", max_signal_strength);
}

int main() {
    int choice;
    
    do {
        print_menu();
        printf("Enter choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_network();
                break;
            case 2:
                remove_network();
                break;
            case 3:
                list_networks();
                break;
            case 4:
                analyze_signal_strength();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);
    
    return 0;
}