//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_SSID_LENGTH 32
#define MAX_NUM_SSID 10
#define SCAN_INTERVAL 5

struct wifi_network {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

struct wifi_network wifi_list[MAX_NUM_SSID];
int num_ssids = 0;

void update_networks() {
    // Simulate scanning for available WiFi networks
    printf("Scanning for WiFi networks...\n");
    sleep(2); // Simulate scanning time

    // Update randomly generated WiFi signal strengths
    srand(time(NULL));
    for (int i = 0; i < num_ssids; i++) {
        int signal = rand() % 100;
        wifi_list[i].signal_strength = signal;
    }
}

void print_networks() {
    printf("Available WiFi networks:\n");
    for (int i = 0; i < num_ssids; i++) {
        printf("%d. SSID: %s\tSignal Strength: %d\n", i+1, wifi_list[i].ssid, wifi_list[i].signal_strength);
    }
}

void signal_handler(int sig) {
    // Update WiFi networks every SCAN_INTERVAL seconds
    update_networks();
    print_networks();
    alarm(SCAN_INTERVAL); // Set alarm to trigger signal_handler again in SCAN_INTERVAL seconds
}

void *async_input(void *args) {
    bool running = true;
    char input[MAX_SSID_LENGTH];
    while (running) {
        printf("Enter an SSID to add (or 'exit' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            running = false;
        } else if (num_ssids >= MAX_NUM_SSID) {
            printf("Error: Maximum number of SSIDs reached.\n");
        } else {
            strcpy(wifi_list[num_ssids].ssid, input);
            wifi_list[num_ssids].signal_strength = 0;
            num_ssids++;
            printf("Added SSID '%s'.\n", input);
        }
    }
    return NULL;
}

int main() {
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("==============================\n");

    // Start asynchronous input thread
    pthread_t input_thread;
    pthread_create(&input_thread, NULL, async_input, NULL);

    // Set signal handler to trigger every SCAN_INTERVAL seconds
    signal(SIGALRM, signal_handler);
    alarm(SCAN_INTERVAL);

    // Wait for input thread to finish
    pthread_join(input_thread, NULL);

    printf("Exiting program.\n");
    return 0;
}