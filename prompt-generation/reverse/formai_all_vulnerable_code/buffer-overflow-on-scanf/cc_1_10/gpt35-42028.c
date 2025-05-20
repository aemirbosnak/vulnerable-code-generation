//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50

typedef struct device {
    char name[50];
    char mac_address[18];
    int signal_strength;
} device;

void swap_devices(device* a, device* b) {
    device temp = *a;
    *a = *b;
    *b = temp;
}

void sort_devices(device* devices, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (devices[j].signal_strength < devices[j + 1].signal_strength) {
                swap_devices(&devices[j], &devices[j + 1]);
            }
        }
    }
}

int main() {
    printf("You awaken in a world of wireless signals and waves,\n");
    printf("Where everything is connected yet nothing is certain.\n");
    printf("As you traverse through this endless sea of information,\n");
    printf("You realize that you need a tool to help you find your way.\n");
    printf("\n");

    device devices[MAX_DEVICES];
    int num_devices = 0;

    printf("You pull out your scanner from your pocket, and turn it on.\n");
    printf("As the green light starts to blink, it starts to scan for signals.\n");
    printf("You wait for a few seconds, as the scanner beeps with each new device it finds.\n");
    printf("\n");

    char response[10];
    do {
        printf("The scanner has found a device. Enter its name: ");
        scanf("%s", devices[num_devices].name);
        printf("Enter its MAC address: ");
        scanf("%s", devices[num_devices].mac_address);
        printf("Enter its signal strength: ");
        scanf("%d", &devices[num_devices].signal_strength);
        num_devices++;

        printf("Do you want to scan for more devices? (y/n): ");
        scanf("%s", response);
        printf("\n");
    } while (strcmp(response, "y") == 0 && num_devices < MAX_DEVICES);

    sort_devices(devices, num_devices);

    printf("You look at the scanner, and it displays the following information:\n");
    printf("\n");

    printf("---------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-10s |\n", "Device Name", "MAC Address", "Signal");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < num_devices; i++) {
        printf("| %-20s | %-20s | %-10d |\n", devices[i].name, devices[i].mac_address, devices[i].signal_strength);
    }
    printf("---------------------------------------------------------------\n");

    printf("\n");
    printf("As you turn off your scanner, you realize that even in a surreal world of wireless signals and waves,\n");
    printf("You have a tool to help you find your way.\n");

    return 0;
}