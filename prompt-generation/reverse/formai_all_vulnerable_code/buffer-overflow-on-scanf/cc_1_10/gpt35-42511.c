//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>

// Struct for storing device information
typedef struct Device {
    char name[20];
    int state;
} Device;

// Function to turn on/off devices
void changeState(Device *d, int newState) {
    d->state = newState;
    printf("%s is now %s\n", d->name, newState ? "on" : "off");
}

int main() {
    // Create an array of devices
    Device devices[3];
    
    // Configure devices
    strcpy(devices[0].name, "Light 1");
    devices[0].state = 0;
    
    strcpy(devices[1].name, "Light 2");
    devices[1].state = 0;
    
    strcpy(devices[2].name, "Fan");
    devices[2].state = 0;
    
    // Display options to user
    printf("Welcome to Smart Home Automation\n\n");
    printf("Select an option:\n");
    printf("1. Turn on Light 1\n");
    printf("2. Turn off Light 1\n");
    printf("3. Turn on Light 2\n");
    printf("4. Turn off Light 2\n");
    printf("5. Turn on Fan\n");
    printf("6. Turn of Fan\n");
    printf("0. Exit\n\n");
    
    int option = -1;
    
    // Main program loop
    while(option != 0) {
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                changeState(&devices[0], 1);
                break;
            case 2:
                changeState(&devices[0], 0);
                break;
            case 3:
                changeState(&devices[1], 1);
                break;
            case 4:
                changeState(&devices[1], 0);
                break;
            case 5:
                changeState(&devices[2], 1);
                break;
            case 6:
                changeState(&devices[2], 0);
                break;
            default:
                printf("Invalid option\n");
        }
    }
    
    return 0;
}