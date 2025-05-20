//FormAI DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

/* Define the maximum number of devices */
#define MAX_DEVICES 10

/* Define the structure for each device */
struct device {
    char name[20];
    int state;
};

/* Function prototypes */
void print_devices(struct device * devices, int num_devices);
void toggle_device(struct device * devices, int device_num);

/* Main program */
int main() {
    /* Initialize devices */
    struct device devices[MAX_DEVICES] = {
        {"Bedroom Light", 0},
        {"Living Room Light", 0},
        {"Kitchen Light", 0},
        {"Bathroom Light", 0}
    };
    int num_devices = 4;
    
    /* Print initial device states */
    printf("Initial device states:\n");
    print_devices(devices, num_devices);
    
    /* Loop until user quits */
    char input[20];
    while (1) {
        printf("Enter device name to toggle (or 'quit' to exit): ");
        fgets(input, 20, stdin);
        input[strlen(input)-1] = '\0';  // Remove newline character
        
        if (strcmp(input, "quit") == 0) {
            break;
        }
        
        /* Find device with matching name */
        int found = 0;
        for (int i = 0; i < num_devices; i++) {
            if (strcmp(input, devices[i].name) == 0) {
                /* Toggle device state */
                toggle_device(devices, i);
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("Device not found.\n");
        } else {
            /* Print updated device states */
            print_devices(devices, num_devices);
        }
    }
    
    return 0;
}

/* Function definitions */

/* Prints the current state of each device */
void print_devices(struct device * devices, int num_devices) {
    printf("Device states:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].state ? "On" : "Off");
    }
}

/* Toggles the state of a device */
void toggle_device(struct device * devices, int device_num) {
    devices[device_num].state = !devices[device_num].state;
}