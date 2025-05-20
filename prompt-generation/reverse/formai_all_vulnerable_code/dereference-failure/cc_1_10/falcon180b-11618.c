//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a smart home device
typedef struct {
    char name[50];
    int status;
    struct smart_home_device *next;
} smart_home_device;

// Function to add a new device to the list
void add_device(smart_home_device **head, char *name) {
    smart_home_device *new_device = (smart_home_device *)malloc(sizeof(smart_home_device));
    strcpy(new_device->name, name);
    new_device->status = 0;
    new_device->next = NULL;

    if (*head == NULL) {
        *head = new_device;
        return;
    }

    smart_home_device *current = *head;

    while (current->next!= NULL) {
        current = current->next;
    }

    current->next = new_device;
}

// Function to print the list of devices
void print_devices(smart_home_device *head) {
    if (head == NULL) {
        printf("No devices found.\n");
        return;
    }

    printf("List of Smart Home Devices:\n");
    while (head!= NULL) {
        printf("%s - Status: %d\n", head->name, head->status);
        head = head->next;
    }
}

// Function to turn on/off all devices
void control_devices(smart_home_device *head, int status) {
    if (head == NULL) {
        printf("No devices found.\n");
        return;
    }

    while (head!= NULL) {
        head->status = status;
        head = head->next;
    }
}

// Function to recursively turn on/off devices based on their status
void toggle_devices(smart_home_device *head) {
    if (head == NULL) {
        return;
    }

    if (head->status == 0) {
        head->status = 1;
    } else {
        head->status = 0;
    }

    toggle_devices(head->next);
}

// Main function to demonstrate the usage of the above functions
int main() {
    smart_home_device *devices = NULL;

    add_device(&devices, "Living Room Light");
    add_device(&devices, "Bedroom Light");
    add_device(&devices, "Kitchen Light");

    print_devices(devices);

    control_devices(devices, 1);
    print_devices(devices);

    toggle_devices(devices);
    print_devices(devices);

    return 0;
}