//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SSIDS 10
#define MAX_SSID_LEN 32

// Struct to hold SSID info
typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} SSID_INFO;

// Function to compare two SSIDs
int compare_ssids(const void *a, const void *b) {
    SSID_INFO *ssid_a = (SSID_INFO *)a;
    SSID_INFO *ssid_b = (SSID_INFO *)b;

    if (ssid_a->signal_strength > ssid_b->signal_strength) {
        return -1;
    } else if (ssid_a->signal_strength < ssid_b->signal_strength) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get Wi-Fi signal strength
int get_signal_strength(const char *iface) {
    FILE *fp;
    char cmd[64];
    int strength = 0;

    sprintf(cmd, "iw dev %s link", iface);
    fp = popen(cmd, "r");

    if (fp!= NULL) {
        fscanf(fp, "signal: %d", &strength);
        pclose(fp);
    }

    return strength;
}

// Function to scan for Wi-Fi networks
void scan_for_networks(char *iface) {
    FILE *fp;
    char cmd[64];

    sprintf(cmd, "iw dev %s scan", iface);

    fp = popen(cmd, "r");

    if (fp!= NULL) {
        SSID_INFO ssids[MAX_SSIDS];
        int num_ssids = 0;

        while (fscanf(fp, "SSID: %31s", ssids[num_ssids].ssid)!= EOF) {
            ssids[num_ssids].signal_strength = get_signal_strength(iface);
            num_ssids++;
        }

        qsort(ssids, num_ssids, sizeof(SSID_INFO), compare_ssids);

        for (int i = 0; i < num_ssids; i++) {
            printf("SSID: %s Signal Strength: %d\n", ssids[i].ssid, ssids[i].signal_strength);
        }

        pclose(fp);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <Wi-Fi interface>\n", argv[0]);
        return 1;
    }

    scan_for_networks(argv[1]);

    return 0;
}