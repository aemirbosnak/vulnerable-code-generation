//FormAI DATASET v1.0 Category: Smart home automation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for devices
#define LIGHTS 0
#define FAN 1
#define AC 2

// Define constants for commands
#define ON 1
#define OFF 0

// Define struct for device information
typedef struct device {
   int id;
   bool status;
} Device;

// Define function to update device status
void update_device_status(Device* d, bool status) {
   d->status = status;
   printf("Device %d is now ", d->id);
   if (d->status) printf("on\n");
   else printf("off\n");
}

// Define function to toggle device status
void toggle_device_status(Device* d) {
   if (d->status) {
      update_device_status(d, OFF);
   }
   else {
      update_device_status(d, ON);
   }
}

int main() {
   // Create array of devices for the home automation system
   Device devices[3];
   devices[LIGHTS] = (Device){LIGHTS, OFF};
   devices[FAN] = (Device){FAN, OFF};
   devices[AC] = (Device){AC, OFF};
   
   // Print welcome message and instructions
   printf("Welcome to Smart Home Automation System\n");
   printf("---------------------------------------\n");
   printf("Available commands:\n");
   printf("  - Type 0 to exit.\n");
   printf("  - Type 1 to toggle lights.\n");
   printf("  - Type 2 to toggle fan.\n");
   printf("  - Type 3 to toggle AC.\n");
   
   // Loop to read and execute user commands
   int user_input = -1;
   while (user_input != 0) {
      scanf("%d", &user_input);
      switch (user_input) {
         case 0:
            printf("Goodbye!\n");
            exit(0);
         case 1:
            toggle_device_status(&devices[LIGHTS]);
            break;
         case 2:
            toggle_device_status(&devices[FAN]);
            break;
         case 3:
            toggle_device_status(&devices[AC]);
            break;
         default:
            printf("Invalid command. Try again.\n");
            break;
      }
   }
   
   return 0;
}