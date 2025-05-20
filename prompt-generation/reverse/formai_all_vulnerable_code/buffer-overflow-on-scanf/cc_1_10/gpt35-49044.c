//FormAI DATASET v1.0 Category: Smart home automation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

//function to control the devices
void deviceControl(char device[], int status) {
  if (status == 1) {
    printf("Turning on %s...\n", device);
  } else {
    printf("Turning off %s...\n", device);
  }
}

int main() {
  //array of devices
  char devices[5][15] = {"light", "fan", "television", "camera", "alarm"};

  //initial status of devices
  int status[5] = {0, 0, 0, 0, 0};

  char choice;
  int deviceIndex;
  int newStatus;

  do {
    //list of devices and their status
    printf("List of Devices:\n");
    for (int i=0; i<5; i++) {
      printf("%d. %s - %s\n", i+1, devices[i], status[i]==1 ? "On" : "Off");
    }
    printf("Enter the device index (1-5) to control or 0 to exit: ");
    scanf("%d", &deviceIndex);

    //exit if user enters 0
    if (deviceIndex == 0) {
      break;
    }

    //ask for new status and change device status
    printf("Enter new status (1 for On, 0 for Off): ");
    scanf("%d", &newStatus);
    status[deviceIndex-1] = newStatus;

    //control the device
    deviceControl(devices[deviceIndex-1], newStatus);

    //ask if user wants to control another device
    printf("Do you want to control another device? (y/n): ");
    scanf(" %c", &choice);

  } while (choice == 'y');

  printf("Goodbye! Thank you for using Smart Home Automation.");

  return 0;
}