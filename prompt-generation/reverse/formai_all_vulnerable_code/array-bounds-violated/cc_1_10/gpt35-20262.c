//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define variables
#define MIN_FREQ 2.4     // in GHz
#define MAX_FREQ 5.2     // in GHz
#define MAX_NUM_DEVICES 10
#define RSSI_THRESH -80   // in dBm

// Define device struct
struct device {
    char name[20];
    float freq;
    int rssi;
};

// Define function to generate random frequency within defined range
float generateFrequency() {
    srand(time(NULL));
    float freq = (float) rand() / RAND_MAX;   // generate a random float between 0 and 1
    freq = freq * (MAX_FREQ - MIN_FREQ) + MIN_FREQ; // scale to the desired range
    return freq;
}

// Define function to scan for wireless devices
void scanNetwork() {
    struct device devices[MAX_NUM_DEVICES];
    int num_devices = 0;

    // Simulate scanning for devices
    for (int i = 0; i < 1000; i++) { // loop over all possible devices within frequency range
        // Check if device is present (randomly)
        if ((float) rand() / RAND_MAX > 0.9) { // 10% chance of device being present
            // Add device to list
            struct device new_device;
            snprintf(new_device.name, sizeof(new_device.name), "Device%d", i+1);
            new_device.freq = generateFrequency();
            new_device.rssi = rand() % 101 - 100; // generate random RSSI between -100dBm and 0dBm

            devices[num_devices] = new_device;
            num_devices++;
        }
    }

    // Print results
    printf("Wireless devices found:\n");
    for (int i = 0; i < num_devices; i++) {
        if (devices[i].rssi > RSSI_THRESH) { // only print devices with sufficient signal strength
            printf("%s (%.1f GHz) - RSSI: %d dBm\n", devices[i].name, devices[i].freq, devices[i].rssi);
        }
    }
}

int main() {
    // Initialize program
    printf("Starting wireless network scanner...\n");
    srand(time(NULL)); // seed random number generator
    
    // Scan for wireless devices
    scanNetwork();

    // End program
    printf("Scan complete.\n");
    return 0;
}