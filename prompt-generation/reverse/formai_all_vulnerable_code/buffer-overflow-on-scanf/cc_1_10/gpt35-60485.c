//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LEN 32

struct network {
    char ssid[MAX_SSID_LEN];
    int strength;
};

void print_networks(struct network networks[], int num_networks) {
    printf("SSID\t\tSignal Strength\n");
    for(int i=0; i<num_networks; i++) {
        printf("%s\t\t%d%%\n", networks[i].ssid, networks[i].strength);
    }
    printf("\n");
}

void clear_buffer() {
    while(getchar() != '\n');
}

int main() {
    struct network networks[MAX_NETWORKS];
    int num_networks = 0;

    while(1) {
        int option;
        printf("Select an option:\n1. Scan for Wi-Fi networks\n2. Print current networks\n3. Check for suspicious activity\n4. Exit\n");
        scanf("%d", &option);
        clear_buffer();

        switch(option) {
            case 1: // Scan for Wi-Fi networks
                printf("Scanning...\n");
                // Code to scan for Wi-Fi networks goes here
                // For this example, we'll just randomly generate some networks
                for(int i=0; i<MAX_NETWORKS; i++) {
                    memset(networks[i].ssid, 0, sizeof(networks[i].ssid));
                    char random_chars[MAX_SSID_LEN] = "";
                    for(int j=0; j<5; j++) {
                        char random_char = 'a' + rand() % 26;
                        strncat(random_chars, &random_char, 1);
                    }
                    sprintf(networks[i].ssid, "Network-%d-%s", i+1, random_chars);
                    networks[i].strength = rand() % 101;
                }
                num_networks = MAX_NETWORKS;
                printf("Scan complete.\n\n");
                break;
            case 2: // Print current networks
                if(num_networks == 0) {
                    printf("No networks found.\n\n");
                }
                else {
                    print_networks(networks, num_networks);
                }
                break;
            case 3: // Check for suspicious activity
                printf("Checking for suspicious activity...\n");
                // Code to check for suspicious activity goes here
                // For this example, we'll just check if any network has a signal strength above 75%
                for(int i=0; i<num_networks; i++) {
                    if(networks[i].strength > 75) {
                        printf("Detected suspicious activity on network %s.\n", networks[i].ssid);
                    }
                }
                printf("Suspicious activity check complete.\n\n");
                break;
            case 4: // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    }
}