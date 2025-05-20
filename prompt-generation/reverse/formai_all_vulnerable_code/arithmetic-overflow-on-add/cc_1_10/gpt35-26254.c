//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_SIGNAL_STRENGTH 0
#define MAX_SIGNAL_STRENGTH 100
#define MAX_SSID_LENGTH 32

struct wifi_network {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

void delay(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) < start_time + seconds);
}

void print_signal_strength(int signal_strength) {
    printf("Signal strength: %d%%\n", signal_strength);
}

void analyze_signal_strength(struct wifi_network network) {
    printf("Analyzing signal strength for network: %s...\n", network.ssid);
    delay(3);
    int signal_strength = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;
    network.signal_strength = signal_strength;
    printf("Signal strength analysis completed.\n");
    print_signal_strength(signal_strength);
}

void print_network_info(struct wifi_network network) {
    printf("Network: %s\n", network.ssid);
    print_signal_strength(network.signal_strength);
}

int main() {
    srand(time(NULL));
    struct wifi_network network1 = {"MyNetwork", 0};
    struct wifi_network network2 = {"CoffeeShop", 0};
    analyze_signal_strength(network1);
    printf("\n");
    analyze_signal_strength(network2);
    printf("\n");
    print_network_info(network1);
    printf("\n");
    print_network_info(network2);
    return 0;
}