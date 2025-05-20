//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_SIZE 256
#define BUFFER_SIZE 1024
#define MAX_SSID 32

void analyze_signal_strength(const char* interface) {
    char cmd[CMD_SIZE];
    snprintf(cmd, CMD_SIZE, "nmcli -f SSID,SIGNAL device wifi list ifname %s", interface);

    FILE* fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen failed");
        return;
    }

    char buffer[BUFFER_SIZE];

    // Displaying Header
    printf("========== Wi-Fi Signal Strengths ==========\n");
    printf("SSID\t\tSignal\n");
    printf("--------------------------------------------\n");

    // Reading the output and parsing the signal strengths
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        char ssid[MAX_SSID];
        int signal;
        if (sscanf(buffer, "%31[^\t]\t%d", ssid, &signal) == 2) {
            // Print SSID and Signal strength
            printf("%-15s\t%d dBm\n", ssid, signal);
        }
    }

    printf("============================================\n");
    pclose(fp);
}

void print_help() {
    printf("Usage: wifi_analyzer <interface>\n");
    printf("Example: wifi_analyzer wlan0\n");
    printf("============================================\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_help();
        return EXIT_FAILURE;
    }

    const char* interface = argv[1];
    analyze_signal_strength(interface);

    return EXIT_SUCCESS;
}