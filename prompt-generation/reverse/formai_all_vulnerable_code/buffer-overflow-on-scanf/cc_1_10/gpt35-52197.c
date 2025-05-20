//FormAI DATASET v1.0 Category: Smart home automation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char deviceName[MAX_NAME_LENGTH];
    int connected;
} device;

void connectToDevice(device* devices, int index) {
    devices[index].connected = 1;
    printf("\nConnected to device %s\n", devices[index].deviceName);
}

void disconnectFromDevice(device* devices, int index) {
    devices[index].connected = 0;
    printf("\nDisconnected from device %s\n", devices[index].deviceName);
}

int getRandomDeviceIndex() {
    srand(time(NULL));
    return rand() % MAX_DEVICES;
}

int main() {
    device devices[MAX_DEVICES];
    int connectedDevices = 0;
    int i, x;
    char name[MAX_NAME_LENGTH];

    for(i = 0; i < MAX_DEVICES; i++) {
        printf("Enter device #%d name: ", i+1);
        scanf("%s", name);
        devices[i].connected = 0;
        strcpy(devices[i].deviceName, name);
    }

    while(1) {
        printf("----------------------------\n");
        printf("           MENU\n");
        printf("----------------------------\n");
        printf("1. Connect to device\n");
        printf("2. Disconnect from device\n");
        printf("3. Check connected devices\n");
        printf("4. Exit\n");
        printf("----------------------------\n");
        printf("Enter option: ");
        scanf("%d", &x);

        switch(x) {
            case 1:
                if(connectedDevices == MAX_DEVICES) {
                    printf("\nCannot connect to more devices. All devices are connected!\n");
                } else {
                    int deviceIndex = getRandomDeviceIndex();
                    while(devices[deviceIndex].connected) {
                        deviceIndex = getRandomDeviceIndex();
                    }
                    connectToDevice(devices, deviceIndex);
                    connectedDevices++;
                }
                break;

            case 2:
                if(connectedDevices == 0) {
                    printf("\nNo devices are connected!\n");
                } else {
                    int deviceIndex = getRandomDeviceIndex();
                    while(!devices[deviceIndex].connected) {
                        deviceIndex = getRandomDeviceIndex();
                    }
                    disconnectFromDevice(devices, deviceIndex);
                    connectedDevices--;
                }
                break;

            case 3:
                printf("\nNumber of connected devices: %d\n", connectedDevices);
                printf("Connected devices:\n");
                for(i = 0; i < MAX_DEVICES; i++) {
                    if(devices[i].connected) {
                        printf("%s\n", devices[i].deviceName);
                    }
                }
                break;

            case 4:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}