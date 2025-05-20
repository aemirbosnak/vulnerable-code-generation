//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[20];
    int signal_strength;
} Device;

int main() {
    Device devices[MAX_DEVICES];
    int num_devices = 0;
    int i;

    // Prompt user to input devices
    printf("Enter the names of up to %d devices (one per line):\n", MAX_DEVICES);
    for (i = 0; i < MAX_DEVICES; i++) {
        char device_name[20];
        printf("[%d/%d] Device name: ", i+1, MAX_DEVICES);
        fgets(device_name, 20, stdin);
        device_name[strlen(device_name)-1] = '\0'; // remove newline character
        if (strlen(device_name) == 0) {
            break; // no more devices to add
        }
        strncpy(devices[i].name, device_name, 20);
        devices[i].signal_strength = rand() % 101; // generate random signal strength (0-100)
        num_devices++;
    }

    // Print out the devices and their signal strengths
    printf("\nWi-Fi Devices:\n");
    for (i = 0; i < num_devices; i++) {
        printf("%s: %d%% signal strength\n", devices[i].name, devices[i].signal_strength);
    }

    // Find the device with the strongest signal
    int strongest_signal = -1;
    int strongest_device = -1;
    for (i = 0; i < num_devices; i++) {
        if (devices[i].signal_strength > strongest_signal) {
            strongest_signal = devices[i].signal_strength;
            strongest_device = i;
        }
    }
    printf("\nThe device with the strongest signal is: %s\n\n", devices[strongest_device].name);

    // Allow other players to guess the strongest device
    int guesser_num = 1;
    while (1) {
        int guess;
        printf("Player %d, enter your guess (0-%d): ", guesser_num, num_devices-1);
        scanf("%d", &guess);
        if (guess < 0 || guess >= num_devices) {
            printf("Invalid guess.\n");
            continue;
        }
        if (guess == strongest_device) {
            printf("Player %d wins! The device with the strongest signal was %s.\n", guesser_num, devices[guess].name);
            break;
        } else {
            printf("Player %d's guess was incorrect.\n", guesser_num);
            guesser_num = (guesser_num % 2) + 1; // switch to other player
        }
    }

    return 0;
}