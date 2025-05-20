//FormAI DATASET v1.0 Category: Smart home automation ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Creating structure to store device details */
struct Device {
    char deviceName[50];
    int deviceID;
    int deviceStatus;
};

/* Helper function to turn on/off device */
void turnDevice(struct Device *device, int status) {
    device->deviceStatus = status;
    printf("%s has been turned %s\n", device->deviceName, status ? "on" : "off");
}

/* Main function */
int main() {
    /* Initializing device struct */
    struct Device devices[3] = {
        {"Living Room Light", 1, 0},
        {"Bedroom Light", 2, 0},
        {"Ceiling Fan", 3, 0}
    };

    /* Displaying initial devices status */
    printf("*** Initial Devices Status ***\n");
    for(int i=0; i<3; i++) {
        printf("Device %d - %s is turned %s\n", devices[i].deviceID, devices[i].deviceName, devices[i].deviceStatus ? "on" : "off");
    }

    /* Get user input to turn on/off device */
    char inputDevice[50];
    int inputStatus;
    printf("\nWhich device would you like to turn on/off? (eg. Living Room Light): ");
    scanf("%[^\n]%*c", inputDevice);

    printf("What would you like to do? (0 -> off, 1 -> on): ");
    scanf("%d", &inputStatus);

    /* Loop through devices and find the requested one */
    for(int i=0; i<3; i++) {
        if(strcmp(devices[i].deviceName, inputDevice) == 0) {
            /* Turn device on/off */
            turnDevice(&devices[i], inputStatus);
            break;
        }
    }

    /* Displaying updated devices status */
    printf("\n*** Updated Devices Status ***\n");
    for(int i=0; i<3; i++) {
        printf("Device %d - %s is turned %s\n", devices[i].deviceID, devices[i].deviceName, devices[i].deviceStatus ? "on" : "off");
    }

    return 0;
}