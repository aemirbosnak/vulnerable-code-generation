//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 32
#define BUFFER_SIZE 256

// Structure to hold Wi-Fi network information
typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

// Function to generate random signal strengths (for comedic effect)
int generate_random_signal_strength() {
    // Simulate signal strength: -100 (bad) to 0 (excellent)
    return rand() % 101 - 100;
}

// Function to simulate scanning for networks (returns count of found networks)
int scan_wifi_networks(WiFiNetwork networks[]) {
    int count = rand() % MAX_NETWORKS + 1; // Random number of networks found
    for (int i = 0; i < count; i++) {
        snprintf(networks[i].ssid, MAX_SSID_LENGTH, "Network_%d", i + 1);
        networks[i].signal_strength = generate_random_signal_strength();
    }
    return count;
}

// Function to display networks
void display_networks(WiFiNetwork networks[], int count) {
    printf("Scanning for Wi-Fi networks... 🛰️\n");
    sleep(2); // Simulate delay for scanning
    printf("Found %d networks:\n", count);
    printf("SSID\t\tSignal Strength\n");
    printf("-------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

// Function to analyze and provide humorous commentary on the signal strength
void analyze_signal_strength(WiFiNetwork networks[], int count) {
    printf("\nAnalyzing the Wi-Fi situation...\n");
    sleep(2); // Dramatic pause
    for (int i = 0; i < count; i++) {
        if (networks[i].signal_strength > -50) {
            printf("🏆 Signal strength of %s is absolutely fabulous! You're practically surfing on sunshine!\n", networks[i].ssid);
        } else if (networks[i].signal_strength > -70) {
            printf("😎 %s has a decent signal. Time to show your Wi-Fi some love! Maybe add a cookie?\n", networks[i].ssid);
        } else if (networks[i].signal_strength > -90) {
            printf("😱 Oh no! %s has a weak signal. Caution: Proceed with buffering!\n", networks[i].ssid);
        } else {
            printf("🚨 Danger! The signal for %s is worse than dial-up! Time to call for backup!\n", networks[i].ssid);
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    WiFiNetwork networks[MAX_NETWORKS];
    
    printf("Welcome to the Wi-Fi Signal Strength Analyzer! 🎉\n");
    
    while (1) {
        int count = scan_wifi_networks(networks);
        display_networks(networks, count);
        analyze_signal_strength(networks, count);

        printf("\nWould you like to scan again? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y') {
            printf("Goodbye! May your signal be strong and your buffering short! 🖖\n");
            break;
        }
    }
    
    return 0;
}