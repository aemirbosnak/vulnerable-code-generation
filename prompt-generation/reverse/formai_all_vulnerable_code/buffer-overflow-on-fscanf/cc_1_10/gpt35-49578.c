//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGNAL_THRESHOLD 50

typedef struct wifi {
    char ssid[20];
    int signal_strength;
} wifi;

void read_wifis(FILE *fp, wifi *wifis, int num_wifis) {
    for (int i = 0; i < num_wifis; i++) {
        fscanf(fp, "%s %d", wifis[i].ssid, &wifis[i].signal_strength);
    }
}

void print_wifis(wifi *wifis, int num_wifis) {
    for (int i = 0; i < num_wifis; i++) {
        printf("SSID: %s, Signal Strength: %d\n", wifis[i].ssid, wifis[i].signal_strength);
    }
}

void analyze_signal_strength(wifi *wifis, int num_wifis) {
    printf("Wi-Fi Networks with Signal Strength < %d:\n", SIGNAL_THRESHOLD);
    for (int i = 0; i < num_wifis; i++) {
        if (wifis[i].signal_strength < SIGNAL_THRESHOLD) {
            printf("%s\n", wifis[i].ssid);
        }
    }
}

int main() {
    FILE *fp;
    int num_wifis;

    // open file
    fp = fopen("wifis.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // read number of Wi-Fis
    fscanf(fp, "%d", &num_wifis);

    // allocate memory for Wi-Fis
    wifi *wifis = (wifi *) malloc(num_wifis * sizeof(wifi));
    if (wifis == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    // read Wi-Fi data
    read_wifis(fp, wifis, num_wifis);

    // close file
    fclose(fp);

    // print Wi-Fi data
    print_wifis(wifis, num_wifis);

    // analyze signal strength
    analyze_signal_strength(wifis, num_wifis);

    // free memory
    free(wifis);

    return 0;
}