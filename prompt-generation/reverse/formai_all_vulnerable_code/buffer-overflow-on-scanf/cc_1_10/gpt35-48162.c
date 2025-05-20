//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNALS 10
#define MAX_NAME_LENGTH 20

typedef struct wifi_signal {
    char name[MAX_NAME_LENGTH];
    int strength;
} wifi_signal;

void print_signal(wifi_signal signal) {
    printf("Signal name: %s / Strength: %d dBm\n", signal.name, signal.strength);
}

int compare_signal_strength(const void* a, const void* b) {
    const wifi_signal* signal_a = (const wifi_signal*) a;
    const wifi_signal* signal_b = (const wifi_signal*) b;
    return signal_a->strength - signal_b->strength;
}

int main() {
    wifi_signal signals[MAX_SIGNALS];
    int num_signals = 0;

    printf("Wi-Fi Signal Strength Analyzer\n");

    while (num_signals < MAX_SIGNALS) {
        wifi_signal signal;
        printf("Enter signal name (or 'q' to quit): ");
        scanf("%s", signal.name);
        if (strcmp(signal.name, "q") == 0) {
            break;
        }
        printf("Enter signal strength (dBm): ");
        scanf("%d", &signal.strength);
        signals[num_signals++] = signal;
    }

    qsort(signals, num_signals, sizeof(wifi_signal), compare_signal_strength);

    printf("Signal strength sorted list:\n");
    for (int i = 0; i < num_signals; i++) {
        wifi_signal signal = signals[i];
        print_signal(signal);
    }

    return 0;
}