//FormAI DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
  char* name;
  int status;
} Device;

int count = 0;

void toggleDevice(Device* devices, char* name, int numDevices) {
  int i;
  for (i = 0; i < numDevices; i++) {
    if (strcmp(devices[i].name, name) == 0) {
      if (devices[i].status == 0) {
        printf("%s is now turned on\n", name);
        devices[i].status = 1;
        return;
      } else {
        printf("%s is now turned off\n", name);
        devices[i].status = 0;
        return;
      }
    }
  }
  printf("Device not found\n");
}

void printAllDevices(Device* devices, int numDevices) {
  int i;
  for (i = 0; i < numDevices; i++) {
    printf("%s is currently %s\n", devices[i].name, devices[i].status == 1 ? "on" : "off");
  }
}

void addDevice(Device* devices, char* name, int numDevices) {
  if (count == MAX_DEVICES) {
    printf("Maximum number of devices reached\n");
    return;
  }
  devices[numDevices].name = strdup(name);
  devices[numDevices].status = 0;
  count++;
  printf("%s has been added to the system\n", name);
}

int menu() {
  int option = 0;
  printf("1. Toggle device status\n");
  printf("2. View all devices\n");
  printf("3. Add device\n");
  printf("4. Quit\n");
  printf("Enter option: ");
  scanf("%d", &option);
  return option;
}

int main() {
  Device devices[MAX_DEVICES];
  char name[20];
  int numDevices = 0;
  int option = 0;
  do {
    option = menu();
    switch (option) {
      case 1:
        printf("Enter device name: ");
        scanf("%s", name);
        toggleDevice(devices, name, numDevices);
        break;
      case 2:
        printAllDevices(devices, numDevices);
        break;
      case 3:
        printf("Enter device name: ");
        scanf("%s", name);
        addDevice(devices, name, numDevices);
        numDevices++;
        break;
      case 4:
        printf("Exiting program\n");
        exit(0);
      default:
        printf("Invalid option\n");
        break;
    }
  } while (option != 4);
  return 0;
}