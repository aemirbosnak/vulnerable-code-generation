//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_NETWORKS 100

typedef struct {
    char ssid[32];
    char signal_strength[16];
    char encryption[16];
} Network;

void printWelcomeMessage() {
    printf("🌈✨ Welcome to the Happy Wireless Network Scanner! ✨🌈\n");
    printf("🚀 Let's find the networks around you with sparkling joy! 🚀\n");
}

void printNetwork(Network network, int index) {
    printf("📡 Network %d: \n", index + 1);
    printf("   SSID: %s\n", network.ssid);
    printf("   Signal Strength: %s\n", network.signal_strength);
    printf("   Encryption: %s\n\n", network.encryption);
}

void parseNetworkData(char *line, Network *network) {
    sscanf(line, "    ESSID:\"%[^\"]\"", network->ssid);
    sscanf(line, "    Signal level=%s", network->signal_strength);
    sscanf(line, "    Encryption key:%s", network->encryption);
}

void scanNetworks() {
    FILE *fp;
    char path[BUFFER_SIZE];
    Network networks[MAX_NETWORKS];
    int network_count = 0;

    // Execute the command to scan for networks
    fp = popen("sudo iwlist wlan0 scan", "r");
    if (fp == NULL) {
        printf("😢 Oh no! Failed to run the command. Please check if you have the right permissions!\n");
        return;
    }

    // Read the output a line at a time - output it.
    while (fgets(path, BUFFER_SIZE, fp) != NULL) {
        if (strstr(path, "ESSID:")) {
            if (network_count < MAX_NETWORKS) {
                parseNetworkData(path, &networks[network_count]);
                network_count++;
            }
        }
    }

    // Close the command stream
    pclose(fp);

    // Print the scanned networks
    printf("🎉 We found %d wireless networks! 🎉\n\n", network_count);
    for (int i = 0; i < network_count; i++) {
        printNetwork(networks[i], i);
    }
}

int main() {
    printWelcomeMessage();
    scanNetworks();
    printf("💫 Hope you found your favorite network! Have a marvelous day! 💫\n");
    return 0;
}