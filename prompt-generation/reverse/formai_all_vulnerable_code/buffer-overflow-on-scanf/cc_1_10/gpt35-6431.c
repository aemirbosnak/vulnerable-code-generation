//FormAI DATASET v1.0 Category: Smart home automation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

#define MAX_DEVICES 5

typedef struct Device {
    char name[50];
    int status;
} Device;

Device devices[MAX_DEVICES];
int num_devices = 0;

void addDevice() {
    if(num_devices >= MAX_DEVICES) {
        printf("Maximum number of devices exceeded.\n");
        return;
    }
    Device newDevice;
    printf("Enter device name: ");
    scanf("%s", newDevice.name);
    newDevice.status = 0;
    devices[num_devices++] = newDevice;
    printf("Device added successfully.\n");
}

void changeDeviceStatus() {
    char deviceName[50];
    printf("Enter device name: ");
    scanf("%s", deviceName);
    for(int i=0; i<num_devices; i++) {
        if(strcmp(devices[i].name, deviceName) == 0) {
            devices[i].status = (devices[i].status == 0 ? 1 : 0);
            printf("Device status changed successfully.\n");
            return;
        }
    }
    printf("Device not found.\n");
}

void displayDevices() {
    printf("Device name\t\tStatus\n");
    for(int i=0; i<num_devices; i++) {
        printf("%s\t\t", devices[i].name);
        printf("%s\n", (devices[i].status == 0 ? "OFF" : "ON"));
    }
}

int main() {
    int option;
    do {
        printf("\nSMART HOME\n");
        printf("1. Add Device\n");
        printf("2. Change Device Status\n");
        printf("3. Display Devices\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addDevice();
                break;
            case 2:
                changeDeviceStatus();
                break;
            case 3:
                displayDevices();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    } while(option != 4);
    return 0;
}