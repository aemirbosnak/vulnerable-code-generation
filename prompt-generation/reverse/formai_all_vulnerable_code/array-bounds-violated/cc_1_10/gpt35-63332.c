//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_DEVICES 10

struct device {
   char name[20];
   bool status;
   int power_consumption;
};

void turnOn(struct device *d) {
   printf("%s turned on.\n", d->name);
   d->status = true;
}

void turnOff(struct device *d) {
   printf("%s turned off.\n", d->name);
   d->status = false;
}

void displayStatus(struct device *d) {
   printf("%s is currently %s.\n", d->name, d->status ? "on" : "off");
}

int getTotalPowerConsumption(struct device *devices[]) {
   int total = 0;
   for (int i = 0; i < MAX_DEVICES; i++) {
      if (devices[i] != NULL && devices[i]->status) {
         total += devices[i]->power_consumption;
      }
   }
   return total;
}

int main() {
   struct device *devices[MAX_DEVICES];
   int numDevices = 0;

   // Add devices
   devices[numDevices] = (struct device*) malloc(sizeof(struct device));
   strcpy(devices[numDevices]->name, "Living Room Light");
   devices[numDevices]->power_consumption = 40;
   numDevices++;

   devices[numDevices] = (struct device*) malloc(sizeof(struct device));
   strcpy(devices[numDevices]->name, "Bedroom Light");
   devices[numDevices]->power_consumption = 35;
   numDevices++;

   devices[numDevices] = (struct device*) malloc(sizeof(struct device));
   strcpy(devices[numDevices]->name, "Smart TV");
   devices[numDevices]->power_consumption = 120;
   numDevices++;

   devices[numDevices] = (struct device*) malloc(sizeof(struct device));
   strcpy(devices[numDevices]->name, "Washing Machine");
   devices[numDevices]->power_consumption = 450;
   numDevices++;

   devices[numDevices] = (struct device*) malloc(sizeof(struct device));
   strcpy(devices[numDevices]->name, "Air Conditioner");
   devices[numDevices]->power_consumption = 700;
   numDevices++;

   printf("Welcome to Smart Home Automation!\n\n");

   char choice;
   do {
      printf("Enter your choice:\n");
      printf("a - Turn on a device\n");
      printf("b - Turn off a device\n");
      printf("c - Display device status\n");
      printf("d - Display total power consumption\n");
      printf("e - Exit\n");

      scanf(" %c", &choice);

      switch (choice) {
         case 'a': {
            printf("Enter device number to turn on: ");
            int num;
            scanf("%d", &num);

            if (num >= numDevices || devices[num] == NULL) {
               printf("Invalid device number.\n");
            } else {
               turnOn(devices[num]);
            }
            break;
         }

         case 'b': {
            printf("Enter device number to turn off: ");
            int num;
            scanf("%d", &num);

            if (num >= numDevices || devices[num] == NULL) {
               printf("Invalid device number.\n");
            } else {
               turnOff(devices[num]);
            }
            break;
         }

         case 'c': {
            printf("Enter device number to display status: ");
            int num;
            scanf("%d", &num);

            if (num >= numDevices || devices[num] == NULL) {
               printf("Invalid device number.\n");
            } else {
               displayStatus(devices[num]);
            }
            break;
         }

         case 'd': {
            int total = getTotalPowerConsumption(devices);
            printf("Total power consumption: %d watts\n", total);
            break;
         }

         case 'e': {
            printf("Goodbye!\n");
            break;
         }

         default: {
            printf("Invalid choice.\n");
            break;
         }
      }
   } while (choice != 'e');

   return 0;
}