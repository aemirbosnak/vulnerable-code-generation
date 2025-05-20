//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEVICES 10
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char* name;
    int signal_strength;
} WiFidevice;

void initializeDevices(WiFidevice devices[]) {
    devices[0].name = "Router";
    devices[0].signal_strength = 70;

    devices[1].name = "Smartphone";
    devices[1].signal_strength = 80;

    devices[2].name = "Laptop";
    devices[2].signal_strength = 90;

    devices[3].name = "Tablet";
    devices[3].signal_strength = 60;

    devices[4].name = "Smart TV";
    devices[4].signal_strength = 50;

    devices[5].name = "PlayStation";
    devices[5].signal_strength = 75;
}

void displayDevices(WiFidevice devices[], int num_devices) {
    printf("\nList of Devices:\n");

    for (int i = 0; i < num_devices; i++) {
        printf("%d. %s - Signal Strength: %d\n", i + 1, devices[i].name, devices[i].signal_strength);
    }
}

int getMaxSignalStrength(WiFidevice devices[], int num_devices) {
    int max = devices[0].signal_strength;

    for (int i = 1; i < num_devices; i++) {
        if (devices[i].signal_strength > max) {
            max = devices[i].signal_strength;
        }
    }

    return max;
}

void displaySignalStrength(WiFidevice devices[], int num_devices) {
    int max_signal_strength = getMaxSignalStrength(devices, num_devices);

    printf("\nSignal Strength:\n");

    for (int i = 0; i < num_devices; i++) {
        printf("%s: ", devices[i].name);

        for (int j = 0; j < ((devices[i].signal_strength * 30) / max_signal_strength); j++) {
            printf("#");
        }

        printf("\n");
    }
}

void updateSignalStrength(WiFidevice devices[], int num_devices) {
    printf("\nEnter the device number to update signal strength: ");
    int device_num;
    scanf("%d", &device_num);

    if (device_num < 1 || device_num > num_devices) {
        printf("\nInvalid device number.\n");
        return;
    }

    printf("Enter the new signal strength: ");
    int signal_strength;
    scanf("%d", &signal_strength);

    if (signal_strength < 0 || signal_strength > MAX_SIGNAL_STRENGTH) {
        printf("\nInvalid signal strength.\n");
        return;
    }

    devices[device_num - 1].signal_strength = signal_strength;

    printf("\nSignal strength updated successfully.\n");
}

int main() {
    WiFidevice devices[MAX_DEVICES];
    int num_devices = 6;

    initializeDevices(devices);

    printf("Welcome to Wi-Fi Signal Strength Analyzer game!\n");

    while (1) {
        printf("\n1. Display Devices\n");
        printf("2. Display Signal Strength\n");
        printf("3. Update Signal Strength\n");
        printf("4. Quit\n");

        printf("\nEnter your choice (1-4): ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayDevices(devices, num_devices);
                break;
            case 2:
                displaySignalStrength(devices, num_devices);
                break;
            case 3:
                updateSignalStrength(devices, num_devices);
                break;
            case 4:
                printf("\nThank you for playing Wi-Fi Signal Strength Analyzer game!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}