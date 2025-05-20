//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: introspective
/* Wi-Fi Signal Strength Analyzer */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME 100

struct device {
    char name[MAX_NAME];
    int signal_strength;
};

int main() {
    struct device devices[MAX_DEVICES];
    int num_devices = 0;

    // Input devices and signal strengths from user
    printf("Enter \"done\" to finish entering devices.\n");
    while (1) {
        char input[MAX_NAME];
        int signal_strength;

        printf("Enter device name (max %d characters): ", MAX_NAME-1);
        fgets(input, MAX_NAME, stdin);
        input[strcspn(input, "\n")] = '\0'; // Strip newline character

        if (strcmp(input, "done") == 0) {
            break; // Exit the input loop
        }
        else if (strlen(input) >= MAX_NAME) {
            printf("Error: device name too long.\n");
            continue; // Start loop again
        }

        printf("Enter signal strength (0-10): ");
        scanf("%d", &signal_strength);
        getchar(); // Clear input buffer

        if (signal_strength < 0 || signal_strength > 10) {
            printf("Error: invalid signal strength.\n");
            continue; // Start loop again
        }

        // Add device and signal strength to array
        struct device new_device;
        strcpy(new_device.name, input);
        new_device.signal_strength = signal_strength;

        devices[num_devices] = new_device;
        num_devices++;
    }

    // Sort devices by signal strength (descending)
    for (int i = 0; i < num_devices; i++) {
        for (int j = i+1; j < num_devices; j++) {
            if (devices[i].signal_strength < devices[j].signal_strength) {
                // Swap devices
                struct device temp = devices[i];
                devices[i] = devices[j];
                devices[j] = temp;
            }
        }
    }

    // Print devices and signal strengths
    printf("\nDevices sorted by signal strength (strongest to weakest):\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s: %d/10\n", devices[i].name, devices[i].signal_strength);
    }

    return 0;
}