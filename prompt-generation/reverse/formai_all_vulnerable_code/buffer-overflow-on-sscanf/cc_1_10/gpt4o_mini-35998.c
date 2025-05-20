//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define NETWORK_BUFFER_SIZE 100

typedef struct {
    char ssid[32];      // SSID of the network
    int signal_level;   // Signal level in dBm
    char encryption[32]; // Encryption type
} NetworkInfo;

// Function declarations
void scanNetworks(NetworkInfo networks[], int *count);
void parseNetworkLine(char *line, NetworkInfo *network);
void displayNetworkInfo(NetworkInfo networks[], int count);

int main() {
    NetworkInfo networks[NETWORK_BUFFER_SIZE];
    int networkCount = 0;

    printf("Scanning for available Wi-Fi networks...\n");

    scanNetworks(networks, &networkCount);

    if (networkCount > 0) {
        displayNetworkInfo(networks, networkCount);
    } else {
        printf("No Wi-Fi networks found.\n");
    }

    return 0;
}

void scanNetworks(NetworkInfo networks[], int *count) {
    FILE *fp;
    char command[] = "sudo iwlist wlan0 scan | grep -E 'ESSID|Signal|Encryption'";
    char line[MAX_LINE_LENGTH];
    int index = 0;

    // Open a pipe to the command
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    NetworkInfo currentNetwork;
    char encryptionType[32] = "None";

    // Read the output a line at a time
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse relevant information and store it
        if (strstr(line, "ESSID")) {
            if (index > 0) {
                strcpy(currentNetwork.encryption, encryptionType);
                networks[index - 1] = currentNetwork; // Save previous network
            }
            parseNetworkLine(line, &currentNetwork);
            index++;
        } else if (strstr(line, "Signal")) {
            sscanf(line, " Signal level=%ddBm", &currentNetwork.signal_level);
        } else if (strstr(line, "Encryption")) {
            sscanf(line, " Encryption key:%s", encryptionType);
            strcpy(currentNetwork.encryption, (strcmp(encryptionType, "on") == 0) ? "Enabled" : "Disabled");
            encryptionType[0] = '\0'; // Reset for the next network
        }
    }

    // Save the last network
    if (index > 0) {
        networks[index - 1] = currentNetwork;
    }

    *count = index;

    pclose(fp);
}

void parseNetworkLine(char *line, NetworkInfo *network) {
    char ssid[32];
    sscanf(line, " ESSID:\"%[^\"]\"", ssid);
    strcpy(network->ssid, ssid);
    network->signal_level = -1; // Default value
    strcpy(network->encryption, "None"); // Default value
}

void displayNetworkInfo(NetworkInfo networks[], int count) {
    printf("\nAvailable Wi-Fi Networks:\n");
    printf("%-30s %-15s %-15s\n", "SSID", "Signal Level", "Encryption");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-30s %-15d %-15s\n", 
            networks[i].ssid, 
            networks[i].signal_level, 
            networks[i].encryption);
    }
}