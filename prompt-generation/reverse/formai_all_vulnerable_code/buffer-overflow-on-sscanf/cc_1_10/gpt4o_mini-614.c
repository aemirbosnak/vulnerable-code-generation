//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// A noble wizard that delves into the realms of Wi-Fi signal
struct SignalStrength {
    char name[50];
    int strength;
};

// A mighty castle where the wizard surveys the land
#define MAX_SIGNALS 10

// Function prototypes
void fetch_signal_strength(struct SignalStrength signals[], int *count);
void display_signals(const struct SignalStrength signals[], int count);
void sort_signals(struct SignalStrength signals[], int count);

int main() {
    // A gathering of brave knights awaiting their signal fortune
    struct SignalStrength signals[MAX_SIGNALS];
    int count = 0;

    // Fetch the valiant signals
    fetch_signal_strength(signals, &count);
    
    // Banners unfurling with strength
    printf("The Wi-Fi Signal Strength of the Realm:\n");
    display_signals(signals, count);
    
    // Sorting the signals in order of might
    sort_signals(signals, count);
    
    // Displaying the sorted valor
    printf("\nSorted Wi-Fi Signals by Strength:\n");
    display_signals(signals, count);

    return 0;
}

// Function to fetch signals with their strength using a mystical command
void fetch_signal_strength(struct SignalStrength signals[], int *count) {
    FILE *fp;
    char path[1035];
    
    // Command to summon the signals from the dark depths of the system
    fp = popen("nmcli -t -f SSID,SIGNAL dev wifi", "r");
    if (fp == NULL) {
        printf("Alas! The wizards could not summon the signals.\n");
        exit(1);
    }

    // Gathering the whispers of strength one by one
    while (fgets(path, sizeof(path)-1, fp) != NULL && *count < MAX_SIGNALS) {
        sscanf(path, "%[^:]:%d", signals[*count].name, &signals[*count].strength);
        (*count)++;
    }

    pclose(fp);
}

// Function to display the signals in all their glory
void display_signals(const struct SignalStrength signals[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Signal: %s | Strength: %d dBm\n", signals[i].name, signals[i].strength);
    }
    if (count == 0) {
        printf("No signals detected, the land is barren.\n");
    }
}

// Function to sort the signals using a noble bubble sort to see the mightiest
void sort_signals(struct SignalStrength signals[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (signals[j].strength < signals[j + 1].strength) {
                struct SignalStrength temp = signals[j];
                signals[j] = signals[j + 1];
                signals[j + 1] = temp;
            }
        }
    }
}