//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define MAX_SIGNALS 10

typedef struct {
    char ssid[100];
    int signal_strength;
} WiFiNetwork;

void parseSignalStrength(char *line, WiFiNetwork *network) {
    // Logic to parse signal strength from the line
    sscanf(line, "%s %d", network->ssid, &network->signal_strength);
}

void displayNetworks(WiFiNetwork networks[], int count) {
    printf("\n🚀 Wi-Fi Networks Found! 🚀\n");
    printf("========================================\n");
    for (int i = 0; i < count; i++) {
        printf("📶 SSID: %s | Signal Strength: %d dBm \n",
               networks[i].ssid, networks[i].signal_strength);
    }
    printf("========================================\n");
}

int main() {
    printf("🌟 Welcome to the Exciting Wi-Fi Signal Strength Analyzer! 🌟\n");
    printf("Scanning your surroundings for Wi-Fi networks...\n");

    FILE *fp;
    char buffer[BUF_SIZE];
    WiFiNetwork networks[MAX_SIGNALS];
    int network_count = 0;

    // Launching the command to scan for Wi-Fi networks
    fp = popen("nmcli -f SSID,SIGNAL device wifi list", "r");
    if (fp == NULL) {
        printf("🤖 Error! Unable to scan Wi-Fi networks. 😱\n");
        return 1;
    }

    // Reading from command output
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Skip the header line
        if (strncmp(buffer, "SSID:", 5) == 0) continue;

        parseSignalStrength(buffer, &networks[network_count]);
        network_count++;
        if (network_count >= MAX_SIGNALS) break;
    }

    pclose(fp);

    // Displaying the results
    if (network_count > 0) {
        displayNetworks(networks, network_count);
    } else {
        printf("🔍 No Wi-Fi networks were found. Go find a better spot! 💨\n");
    }

    printf("💡 Pro Tip: A signal strength above -70 dBm is usually good! 🎉\n");
    return 0;
}