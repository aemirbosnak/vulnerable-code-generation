//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <net/if.h>
#include <ctype.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define WIFI_INTERFACE "wlan0" // Change this to your Wi-Fi interface name if needed

// Structure to hold the Wi-Fi information
typedef struct {
    char ssid[33];         // SSID of the network
    int signal_strength;   // Signal strength in dBm
} WifiInfo;

// Function declarations
void print_wifi_info(WifiInfo *wifi_info, int count);
void analyze_signal_strength(WifiInfo *wifi_info, int count);
void clear_screen();

// Main function
int main(void) {
    clear_screen();
    printf("🎉 Welcome to the Wi-Fi Signal Strength Analyzer! 🎉\n\n");

    WifiInfo wifi_info[10];  // Buffer to hold information on available networks
    int count = 0;           // Count of available networks

    // Open the command to retrieve wifi signal strength
    FILE *fp = popen("nmcli -t -f ssid,signal dev wifi", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }

    // Read from command output
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer)-1, fp) != NULL) {
        // Clean the buffer
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character
        sscanf(buffer, "%32[^:]:%d", wifi_info[count].ssid, &wifi_info[count].signal_strength);
        count++;

        if (count >= 10) break; // Limit to 10 networks to avoid overflow
    }

    pclose(fp);

    // Analyze and print the gathered Wi-Fi information
    if (count > 0) {
        printf("🎶 Found %d Wi-Fi networks! 🎶\n\n", count);
        analyze_signal_strength(wifi_info, count);
        print_wifi_info(wifi_info, count);
    } else {
        printf("😢 No Wi-Fi networks found! Please ensure your Wi-Fi is enabled.\n");
    }

    return 0;
}

// Function to analyze the signal strength
void analyze_signal_strength(WifiInfo *wifi_info, int count) {
    printf("📊 Analyzing signal strengths...\n");
    for (int i = 0; i < count; i++) {
        if (wifi_info[i].signal_strength >= 75) {
            printf("💪 %s: Excellent Signal! 📶 (+%d dBm)\n", wifi_info[i].ssid, wifi_info[i].signal_strength);
        } else if (wifi_info[i].signal_strength >= 50) {
            printf("👍 %s: Good Signal! 📶 (+%d dBm)\n", wifi_info[i].ssid, wifi_info[i].signal_strength);
        } else if (wifi_info[i].signal_strength >= 25) {
            printf("😐 %s: Fair Signal. 📶 (+%d dBm)\n", wifi_info[i].ssid, wifi_info[i].signal_strength);
        } else {
            printf("👎 %s: Poor Signal. 📶 (+%d dBm)\n", wifi_info[i].ssid, wifi_info[i].signal_strength);
        }
    }
}

// Function to print the Wi-Fi information
void print_wifi_info(WifiInfo *wifi_info, int count) {
    printf("\n🌐 Available Wi-Fi Networks 🌐\n");
    printf("---------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("SSID: %-32s | Signal Strength: %3d dBm\n", wifi_info[i].ssid, wifi_info[i].signal_strength);
    }
    printf("---------------------------------\n");
}

// Function to clear the terminal screen
void clear_screen() {
    printf("\033[H\033[J");  // ANSI escape sequence to clear the screen
    fflush(stdout);
}