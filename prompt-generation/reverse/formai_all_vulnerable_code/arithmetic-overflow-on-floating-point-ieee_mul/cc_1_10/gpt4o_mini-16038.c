//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define MAX_SIG_STR_LEN 256
#define RSSI_FILE "/proc/net/wireless"

void analyze_signal_strength() {
    FILE *fp = fopen(RSSI_FILE, "r");
    if (!fp) {
        perror("Could not open RSSI file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_SIG_STR_LEN];

    // Skip the first two lines as they contain headers
    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);
    
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("----------------------------------\n");
    printf("%-15s %-10s %-10s\n", "Interface", "Quality", "Signal");

    while (fgets(line, sizeof(line), fp) != NULL) {
        char interface[16];
        int quality;
        float signal;

        // Parse the line
        if (sscanf(line, "%15s %f %*s %s", interface, &signal) == 2) {
            // Convert signal to quality
            quality = (int)(signal * 100 / 70); // Assuming max signal corresponds to 70
            quality = (quality > 100) ? 100 : quality;

            printf("%-15s %-10d %-10.2f dBm\n", interface, quality, signal);
        }
    }

    fclose(fp);
}

void display_help() {
    printf("Usage: wifi_signal_analyzer\n");
    printf("This program analyzes and displays the Wi-Fi signal strength.\n");
    printf("Run the program without any parameters.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        display_help();
        exit(EXIT_FAILURE);
    }

    while (1) {
        analyze_signal_strength();
        sleep(5);  // Analyze every 5 seconds
        printf("\n");
    }

    return EXIT_SUCCESS;
}