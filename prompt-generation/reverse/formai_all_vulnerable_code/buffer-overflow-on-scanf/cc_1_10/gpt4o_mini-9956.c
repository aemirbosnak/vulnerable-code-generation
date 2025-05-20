//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

// Device structure for smart home appliances
typedef struct {
    char name[NAME_LENGTH];
    int status; // 0 = off, 1 = on
} Device;

Device devices[MAX_DEVICES];
int deviceCount = 0;

// Function prototypes
void initializeDevices();
void displayMenu();
void toggleDevice(int index);
void showDevices();
void setDeviceStatus(int index, int status);
void waitUser();

int main() {
    initializeDevices();

    // Infinite loop for home automation control
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the Cyberpunk Control Center...\n");
            break;
        } else if (choice > 0 && choice <= deviceCount) {
            toggleDevice(choice - 1);
        } else {
            printf("Invalid choice. Please select again.\n\n");
        }
        waitUser();
    }

    return 0;
}

void initializeDevices() {
    // Sample devices initialize
    strcpy(devices[deviceCount].name, "Neon Light");
    devices[deviceCount++].status = 0;

    strcpy(devices[deviceCount].name, "Holo Projector");
    devices[deviceCount++].status = 0;

    strcpy(devices[deviceCount].name, "Smart Thermostat");
    devices[deviceCount++].status = 0;

    strcpy(devices[deviceCount].name, "AI Coffee Maker");
    devices[deviceCount++].status = 0;

    strcpy(devices[deviceCount].name, "Security Drone");
    devices[deviceCount++].status = 0;

    // More devices can be initialized
    printf("The Cyberpunk Smart Home is ready.\n");
}

void displayMenu() {
    printf("====================================\n");
    printf("=== Cyberpunk Smart Home Control ===\n");
    printf("====================================\n");
    showDevices();
    printf("Select a device to toggle (1 - %d) or 0 to exit: ", deviceCount);
}

void toggleDevice(int index) {
    if (devices[index].status == 0) {
        setDeviceStatus(index, 1);
        printf("[ACTION] %s is now ON.\n", devices[index].name);
    } else {
        setDeviceStatus(index, 0);
        printf("[ACTION] %s is now OFF.\n", devices[index].name);
    }
}

void showDevices() {
    for (int i = 0; i < deviceCount; i++) {
        printf("%d. %s [%s]\n", i + 1, devices[i].name, devices[i].status == 1 ? "ON" : "OFF");
    }
}

void setDeviceStatus(int index, int status) {
    devices[index].status = status;

    // Simulate some action for devices
    if (status == 1) {
        printf("Activating the neon glow for %s...\n", devices[index].name);
        usleep(500000); // Simulates a delay for activation
    } else {
        printf("Deactivating the systems for %s...\n", devices[index].name);
        usleep(500000); // Simulates a delay for deactivation
    }
}

void waitUser() {
    printf("[INFO] Press ENTER to continue...\n");
    while(getchar() != '\n'); // Clear input buffer
    getchar(); // Wait for user to press ENTER
}