//FormAI DATASET v1.0 Category: Smart home automation ; Style: decentralized
// Decentralized Smart Home Automation Example Program

#include <stdio.h>
#include <stdlib.h>

// Define the structure for each device
typedef struct {
    int device_id;
    char device_name[20];
    int device_status;
} Device;

// Define the maximum number of devices 
#define MAX_DEVICES 10

// Define the function to print device details
void print_device_details(Device device) {
    printf("Device ID: %d | Device Name: %s | Device Status: %d\n", device.device_id, device.device_name, device.device_status);
}

// Define the function to print all the devices
void print_all_devices(Device devices[], int num_devices) {
    for (int i = 0; i < num_devices; i++) {
        printf("Device %d: ", i+1);
        print_device_details(devices[i]);
    }
}

int main() {
    // Initialize devices
    Device all_devices[MAX_DEVICES];
    int num_devices = 0;

    // Menu-driven code
    printf("Welcome to Decentralized Smart Home Automation Program!\n");
    printf("1. Add Device\n2. View All Devices\n3. Turn On Device\n4. Turn Off Device\n5. Exit\n");
    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {   // Add Device
                if (num_devices < MAX_DEVICES) {
                    Device new_device;

                    printf("Enter device name: ");
                    scanf("%s", new_device.device_name);

                    new_device.device_id = num_devices + 1;

                    printf("Enter device status (0 for off, 1 for on): ");
                    scanf("%d", &new_device.device_status);

                    all_devices[num_devices] = new_device;
                    num_devices++;

                    printf("Device added successfully!\n");
                } else {
                    printf("Cannot add more devices!\n");
                }
                break;
            }
            case 2: {   // View All Devices
                if (num_devices == 0) {
                    printf("No devices in the system!\n");
                } else {
                    print_all_devices(all_devices, num_devices);
                }
                break;
            }
            case 3: {   // Turn On Device
                if (num_devices == 0) {
                    printf("No devices in the system!\n");
                } else {
                    int device_id;
                    printf("Enter device ID to turn on: ");
                    scanf("%d", &device_id);
                    if (device_id > 0 && device_id <= num_devices) {
                        all_devices[device_id-1].device_status = 1;
                        printf("Device %d turned on!\n", device_id);
                    } else {
                        printf("Invalid device ID!\n");
                    }
                }
                break;
            }
            case 4: {   // Turn Off Device
                if (num_devices == 0) {
                    printf("No devices in the system!\n");
                } else {
                    int device_id;
                    printf("Enter device ID to turn off: ");
                    scanf("%d", &device_id);
                    if (device_id > 0 && device_id <= num_devices) {
                        all_devices[device_id-1].device_status = 0;
                        printf("Device %d turned off!\n", device_id);
                    } else {
                        printf("Invalid device ID!\n");
                    }
                }
                break;
            }
            case 5: {   // Exit
                printf("Exiting program... Thank you for using Smart Home Automation!\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    } while (choice != 5);

    return 0;
}