//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 50

typedef enum {
    DEVICE_ON,
    DEVICE_OFF
} DeviceStatus;

typedef struct {
    char name[NAME_LENGTH];
    DeviceStatus status;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;
pthread_mutex_t deviceMutex;

void initializeDevice(SmartDevice* device, const char* name) {
    strncpy(device->name, name, NAME_LENGTH - 1);
    device->name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
    device->status = DEVICE_OFF;
}

void printDeviceStatus(SmartDevice device) {
    printf("Device: %s is %s\n", device.name, device.status == DEVICE_ON ? "ON" : "OFF");
}

void* monitorDevices(void* arg) {
    while (true) {
        pthread_mutex_lock(&deviceMutex);
        for (int i = 0; i < deviceCount; i++) {
            printDeviceStatus(devices[i]);
        }
        pthread_mutex_unlock(&deviceMutex);
        sleep(5);
    }
    return NULL;
}

void toggleDevice(const char* deviceName) {
    pthread_mutex_lock(&deviceMutex);
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, deviceName) == 0) {
            devices[i].status = devices[i].status == DEVICE_ON ? DEVICE_OFF : DEVICE_ON;
            printf("%s toggled to %s\n", devices[i].name, devices[i].status == DEVICE_ON ? "ON" : "OFF");
            pthread_mutex_unlock(&deviceMutex);
            return;
        }
    }
    pthread_mutex_unlock(&deviceMutex);
    printf("Device %s not found!\n", deviceName);
}

void addDevice(const char* name) {
    if (deviceCount >= MAX_DEVICES) {
        printf("Device limit reached!\n");
        return;
    }
    initializeDevice(&devices[deviceCount++], name);
    printf("Device %s added.\n", name);
}

void removeDevice(const char* name) {
    pthread_mutex_lock(&deviceMutex);
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i] = devices[--deviceCount];
            printf("Device %s removed.\n", name);
            pthread_mutex_unlock(&deviceMutex);
            return;
        }
    }
    pthread_mutex_unlock(&deviceMutex);
    printf("Device %s not found!\n", name);
}

void showMenu() {
    printf("\nSmart Home Automation System\n");
    printf("1. Add Device\n");
    printf("2. Remove Device\n");
    printf("3. Toggle Device\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    pthread_mutex_init(&deviceMutex, NULL);
    pthread_t monitorThread;

    if (pthread_create(&monitorThread, NULL, monitorDevices, NULL) != 0) {
        fprintf(stderr, "Failed to create monitoring thread\n");
        return EXIT_FAILURE;
    }

    while (true) {
        showMenu();
        int choice;
        scanf("%d", &choice);
        char deviceName[NAME_LENGTH];

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", deviceName);
                addDevice(deviceName);
                break;
            case 2:
                printf("Enter device name: ");
                scanf("%s", deviceName);
                removeDevice(deviceName);
                break;
            case 3:
                printf("Enter device name: ");
                scanf("%s", deviceName);
                toggleDevice(deviceName);
                break;
            case 4:
                printf("Exiting...\n");
                pthread_cancel(monitorThread);
                pthread_join(monitorThread, NULL);
                pthread_mutex_destroy(&deviceMutex);
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}