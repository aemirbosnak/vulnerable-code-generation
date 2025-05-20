//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define SERVICE_NAME "SmartHomeService"
#define CONFIG_FILE "config.txt"

typedef struct {
    char name[50];
    bool isActive;
    int sensitivity; // 1 to 5
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

// Function prototypes
void loadConfig();
void saveConfig();
void addDevice(const char* name, int sensitivity);
void toggleDevice(const char* name);
void listDevices();
void paranoidCheck();

int main() {
    loadConfig();
    while (true) {
        printf("\nParanoid Smart Home Automation\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. List Devices\n");
        printf("4. Paranoid Check\n");
        printf("5. Save and Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            char name[50];
            int sensitivity;
            printf("Enter device name: ");
            scanf("%s", name);
            printf("Enter sensitivity (1-5): ");
            scanf("%d", &sensitivity);
            addDevice(name, sensitivity);
        } else if (choice == 2) {
            char name[50];
            printf("Enter device name to toggle: ");
            scanf("%s", name);
            toggleDevice(name);
        } else if (choice == 3) {
            listDevices();
        } else if (choice == 4) {
            paranoidCheck();
        } else if (choice == 5) {
            saveConfig();
            break;
        } else {
            printf("Invalid choice! Trust no one.\n");
        }
    }
    return 0;
}

void loadConfig() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        printf("Config file not found! Initializing defaults...\n");
        return;
    }

    while (fscanf(file, "%s %d %d", devices[deviceCount].name, &devices[deviceCount].isActive, &devices[deviceCount].sensitivity) != EOF) {
        deviceCount++;
    }
    fclose(file);
}

void saveConfig() {
    FILE *file = fopen(CONFIG_FILE, "w");
    for (int i = 0; i < deviceCount; i++) {
        fprintf(file, "%s %d %d\n", devices[i].name, devices[i].isActive, devices[i].sensitivity);
    }
    fclose(file);
}

void addDevice(const char* name, int sensitivity) {
    if (deviceCount >= MAX_DEVICES) {
        printf("Maximum device limit reached! Monitor the situation closely.\n");
        return;
    }
    strcpy(devices[deviceCount].name, name);
    devices[deviceCount].isActive = false;
    devices[deviceCount].sensitivity = sensitivity;
    deviceCount++;
    printf("Device '%s' added successfully. Remain alert!\n", name);
}

void toggleDevice(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].isActive = !devices[i].isActive;
            printf("Device '%s' turned %s. Keep your eyes peeled!\n", name, devices[i].isActive ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found! Could it be a ruse?\n", name);
}

void listDevices() {
    printf("Listing devices...\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("Device: %s, Status: %s, Sensitivity: %d\n", 
               devices[i].name, 
               devices[i].isActive ? "Active" : "Inactive", 
               devices[i].sensitivity);
    }
}

void paranoidCheck() {
    printf("Performing paranoid check...\n");
    for (int i = 0; i < deviceCount; i++) {
        if (devices[i].isActive && devices[i].sensitivity > 3) {
            printf("Warning! Device '%s' is active with high sensitivity!\n", devices[i].name);
        }
    }
    printf("All devices have been scrutinized. Stay vigilant!\n");
}