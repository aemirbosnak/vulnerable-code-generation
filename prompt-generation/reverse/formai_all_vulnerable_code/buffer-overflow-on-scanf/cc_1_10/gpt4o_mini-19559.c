//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

// Structure to represent a device in the network
typedef struct Device {
    char name[MAX_NAME_LEN];
    struct Device* next;
} Device;

// Function to create a new device
Device* createDevice(const char* name) {
    Device* newDevice = (Device*)malloc(sizeof(Device));
    if (newDevice) {
        strncpy(newDevice->name, name, MAX_NAME_LEN);
        newDevice->name[MAX_NAME_LEN - 1] = '\0'; // Ensure null termination
        newDevice->next = NULL;
    }
    return newDevice;
}

// Function to add a device to the network
void addDevice(Device** head, const char* name) {
    Device* newDevice = createDevice(name);
    if (!newDevice) {
        printf("Failed to allocate memory for new device\n");
        return;
    }
    newDevice->next = *head;
    *head = newDevice;
    printf("Device '%s' added to the network.\n", name);
}

// Function to display the network topology
void displayTopology(Device* head) {
    if (!head) {
        printf("Network is empty.\n");
        return;
    }
    printf("Current Network Topology:\n");
    Device* temp = head;
    while (temp) {
        printf("- %s\n", temp->name);
        temp = temp->next;
    }
}

// Function to free the allocated memory for devices
void freeDevices(Device* head) {
    Device* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Device* networkTopology = NULL;
    char command[50];
    char deviceName[MAX_NAME_LEN];

    printf("Welcome to the Network Topology Mapper!\n");
    printf("You can add devices to the network by typing their names.\n");
    printf("Type 'show' to display the current topology.\n");
    printf("Type 'exit' to quit the program.\n");

    while (1) {
        printf("Enter device name (or command): ");
        scanf("%s", command);

        if (strcmp(command, "show") == 0) {
            displayTopology(networkTopology);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            // Assume the user provides a device name
            addDevice(&networkTopology, command);
        }
    }

    printf("Cleaning up allocated memory...\n");
    freeDevices(networkTopology);
    printf("Goodbye!\n");
    return 0;
}