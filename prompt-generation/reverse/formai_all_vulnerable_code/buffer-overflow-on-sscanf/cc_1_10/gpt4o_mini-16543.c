//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LEN 32
#define MAX_LINE_LEN 256

typedef enum {
    EXCELLENT,
    GOOD,
    FAIR,
    POOR,
    NO_SIGNAL
} WiFiSignalStrength;

const char *getSignalDescription(WiFiSignalStrength strength) {
    switch (strength) {
        case EXCELLENT:
            return "Superb! You're living the Wi-Fi dream!";
        case GOOD:
            return "Nice! Your connection is doing a happy dance!";
        case FAIR:
            return "Hmm... It's like a Wi-Fi diet: not the best.";
        case POOR:
            return "Dude! Your Wi-Fi needs a pep talk!";
        case NO_SIGNAL:
            return "Houston, we have a problem! No signal detected!";
        default:
            return "Unknown signal strength!";
    }
}

WiFiSignalStrength analyzeSignal(int dBm) {
    if (dBm >= -50) {
        return EXCELLENT;
    } else if (dBm >= -60) {
        return GOOD;
    } else if (dBm >= -70) {
        return FAIR;
    } else if (dBm >= -80) {
        return POOR;
    } else {
        return NO_SIGNAL;
    }
}

void parseSignalStrength(char *line, char *ssid) {
    int qualityIndex = 0;
    char *qualityString = strchr(line, ' ');
    if (qualityString) {
        qualityString++; // Skip the space
        sscanf(qualityString, "Quality=%d", &qualityIndex);
        int signalStrength = -100 + qualityIndex; // Convert quality to dBm
        WiFiSignalStrength strength = analyzeSignal(signalStrength);
        printf("SSID: %s | Signal Strength: %d dBm | %s\n",
               ssid, signalStrength, getSignalDescription(strength));
    }
}

void scanWiFiNetworks() {
    FILE *fp;
    char path[MAX_LINE_LEN];
    char ssid[MAX_SSID_LEN];
    
    // Open the command to find Wi-Fi networks!
    fp = popen("iwlist scan | grep -E 'ESSID|Quality'", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run iwlist command. Looks like your Wi-Fi is on strike!\n");
        exit(1);
    }

    while (fgets(path, sizeof(path), fp) != NULL) {
        if (strstr(path, "ESSID") != NULL) {
            sscanf(path, " ESSID:\"%[^\"]\"", ssid); // Extract SSID
        } else {
            parseSignalStrength(path, ssid);
        }
    }

    pclose(fp);
}

int main() {
    printf("=== Wi-Fi Signal Strength Analyzer ===\n");
    printf("Greetings, intrepid Wi-Fi warrior! Let's analyze your signal strength.\n");

    scanWiFiNetworks();

    printf("=== End of Analysis ===\n");
    printf("May your Wi-Fi be ever strong and your buffering times be short!\n");
    return 0;
}