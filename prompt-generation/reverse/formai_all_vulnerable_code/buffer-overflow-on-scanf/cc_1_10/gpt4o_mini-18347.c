//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_NETWORKS 50
#define SSID_LENGTH 33
#define BUFFER_SIZE 1024

typedef struct {
    char ssid[SSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

void display_menu() {
    printf("===================================\n");
    printf("      Wi-Fi Signal Strength Analyzer\n");
    printf("===================================\n");
    printf("1. Scan for networks\n");
    printf("2. Exit\n");
    printf("===================================\n");
}

void scan_wifi_networks(WiFiNetwork *networks, int *network_count) {
    char buffer[BUFFER_SIZE];
    FILE *fp;

    // Execute the command to scan Wi-Fi networks
    fp = popen("nmcli -t -f SSID,SIGNAL dev wifi", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }

    int count = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL && count < MAX_NETWORKS) {
        char *token = strtok(buffer, ":");
        if (token != NULL) {
            strncpy(networks[count].ssid, token, SSID_LENGTH - 1);
            networks[count].ssid[SSID_LENGTH - 1] = '\0';  // Ensure null termination
            
            token = strtok(NULL, ":");
            if (token != NULL) {
                networks[count].signal_strength = atoi(token);
            }

            count++;
        }
    }

    *network_count = count;
    pclose(fp);
}

void print_networks(WiFiNetwork *networks, int count) {
    printf("Available Wi-Fi Networks:\n");
    printf("SSID                               Signal Strength\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-32s %d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    WiFiNetwork networks[MAX_NETWORKS];
    int network_count = 0;
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            // Clear invalid input from buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                scan_wifi_networks(networks, &network_count);
                print_networks(networks, network_count);
                break;
            case 2:
                printf("Exiting...\n");
                return 0;
            default:
                fprintf(stderr, "Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}