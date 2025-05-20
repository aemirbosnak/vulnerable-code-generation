//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_DEVICES 5

typedef struct {
    char name[20];
    bool status;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];

void initializeDevices() {
    for (int i = 0; i < MAX_DEVICES; i++) {
        sprintf(devices[i].name, "Device-%d", i + 1);
        devices[i].status = false;
    }
}

void toggleDevice(int index) {
    if (index < 0 || index >= MAX_DEVICES) {
        printf("Error: Invalid device index!\n");
        return;
    }
    devices[index].status = !devices[index].status;
    printf("%s is now %s.\n", devices[index].name, devices[index].status ? "ON" : "OFF");
}

void listDevices() {
    printf("\n--- List of Smart Devices ---\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].status ? "ON" : "OFF");
    }
    printf("----------------------------\n");
}

void surpriseHomeAutomation() {
    printf("🎉 Welcome to the Smart Home Automation System! 🎉\n");
    printf("Preparing to automate your home... \n");
    
    // Surprise me! Randomly toggling devices
    srand(time(NULL));
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (rand() % 2) {
            toggleDevice(i);
        } else {
            printf("Did you know? %s was left as it is!\n", devices[i].name);
        }
    }

    printf("What about a surprise check on all devices?\n");
    listDevices();
}

void scheduleAutomation() {
    printf("\n--- Scheduling Automation ---\n");
    printf("Every hour, devices will do a random activity!\n");

    while (true) {
        for (int i = 0; i < MAX_DEVICES; i++) {
            int randomAction = rand() % 3;
            switch (randomAction) {
                case 0:
                    toggleDevice(i);
                    break;
                case 1:
                    printf("🌼 %s is lighting up a lovely ambiance!\n", devices[i].name);
                    break;
                case 2:
                    printf("🎵 %s is playing some pleasant tunes!\n", devices[i].name);
                    break;
            }
        }
        listDevices();
        printf("Waiting for the next hour...\n");
        sleep(1); // Simulating waiting; replace with actual time in production
    }
}

int main() {
    initializeDevices();
    surpriseHomeAutomation();
    
    printf("Would you like to schedule automated actions? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        scheduleAutomation();
    } else {
        printf("Thank you for using smart home automation! Goodbye!\n");
    }
    
    return 0;
}