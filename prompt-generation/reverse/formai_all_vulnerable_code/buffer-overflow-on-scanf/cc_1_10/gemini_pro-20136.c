//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIFI_MAX_SSID 32

struct wifi_signal {
    char ssid[WIFI_MAX_SSID + 1];
    int strength;
};

int compare_wifi_signals(const void *a, const void *b) {
    return ((struct wifi_signal *)a)->strength - ((struct wifi_signal *)b)->strength;
}

int main(void) {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of Wi-Fi signals to generate
    int num_signals;
    printf("How many Wi-Fi signals wouldst thou like to generate? ");
    scanf("%d", &num_signals);

    // Generate the Wi-Fi signals
    struct wifi_signal signals[num_signals];
    for (int i = 0; i < num_signals; i++) {
        // Generate a random SSID
        int ssid_len = rand() % (WIFI_MAX_SSID - 1) + 1;
        for (int j = 0; j < ssid_len; j++) {
            signals[i].ssid[j] = 'a' + (rand() % 26);
        }
        signals[i].ssid[ssid_len] = '\0';

        // Generate a random strength
        signals[i].strength = rand() % 100;
    }

    // Sort the Wi-Fi signals by strength
    qsort(signals, num_signals, sizeof(struct wifi_signal), compare_wifi_signals);

    // Print the Wi-Fi signals
    printf("\nHere be the Wi-Fi signals thou hast requested:\n");
    for (int i = 0; i < num_signals; i++) {
        printf("%s: %d\n", signals[i].ssid, signals[i].strength);
    }

    return 0;
}