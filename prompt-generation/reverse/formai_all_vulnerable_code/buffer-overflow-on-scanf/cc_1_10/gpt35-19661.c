//FormAI DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Define the structure for the Smart Home device */
struct SmartDevice {
    char name[50];
    bool isOn;
};

/* Define a function to turn on the device */
void turnOn(struct SmartDevice *device) {
    if(!device->isOn) {
        printf("%s is now ON.\n", device->name);
        device->isOn = true;
    }
}

/* Define a function to turn off the device */
void turnOff(struct SmartDevice *device) {
    if(device->isOn) {
        printf("%s is now OFF.\n", device->name);
        device->isOn = false;
    }
}

int main() {
    /* Create some Smart Devices */
    struct SmartDevice smartLights;
    strcpy(smartLights.name, "Smart Lights");
    smartLights.isOn = false;
    
    struct SmartDevice smartThermostat;
    strcpy(smartThermostat.name, "Smart Thermostat");
    smartThermostat.isOn = false;
    
    struct SmartDevice smartLock;
    strcpy(smartLock.name, "Smart Lock");
    smartLock.isOn = false;
    
    /* Prompt the user to select a device */
    printf("Select a device to configure: \n");
    printf("1. Smart Lights\n");
    printf("2. Smart Thermostat\n");
    printf("3. Smart Lock\n");
    
    int choice;
    scanf("%d", &choice);
    
    /* Perform the selected action based on user choice */
    switch(choice) {
        case 1:
            /* Configure Smart Lights */
            printf("Configure Smart Lights:\n");
            printf("1. Turn On\n");
            printf("2. Turn Off\n");
            
            int lightsChoice;
            scanf("%d", &lightsChoice);
            
            switch(lightsChoice) {
                case 1:
                    turnOn(&smartLights);
                    break;
                case 2:
                    turnOff(&smartLights);
                    break;
                default:
                    printf("Invalid selection.\n");
                    break;
            }
            break;
        case 2:
            /* Configure Smart Thermostat */
            printf("Configure Smart Thermostat:\n");
            printf("1. Turn On\n");
            printf("2. Turn Off\n");
            
            int thermostatChoice;
            scanf("%d", &thermostatChoice);
            
            switch(thermostatChoice) {
                case 1:
                    turnOn(&smartThermostat);
                    break;
                case 2:
                    turnOff(&smartThermostat);
                    break;
                default:
                    printf("Invalid selection.\n");
                    break;
            }
            break;
        case 3:
            /* Configure Smart Lock */
            printf("Configure Smart Lock:\n");
            printf("1. Turn On\n");
            printf("2. Turn Off\n");
            
            int lockChoice;
            scanf("%d", &lockChoice);
            
            switch(lockChoice) {
                case 1:
                    turnOn(&smartLock);
                    break;
                case 2:
                    turnOff(&smartLock);
                    break;
                default:
                    printf("Invalid selection.\n");
                    break;
            }
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }
    
    return 0;
}