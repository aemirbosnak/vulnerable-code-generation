//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Donald Knuth
// Weave a tapestry of automated bliss in thy abode with this cunning C program, crafted in the eloquent prose of Donald Knuth.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Enumerations are epiphanies from the realm of clarity.
enum device_type {
  LIGHT,
  FAN,
  SENSOR
};

// Structures are a veritable tapestry of interlaced data, each thread woven with precision.
typedef struct device {
  enum device_type type;
  uint8_t id;
  char* name;
} device;

// An array, like a celestial tapestry, holds countless stars.
device devices[] = {
  { LIGHT, 1, "Living Room Light" },
  { FAN, 2, "Bedroom Fan" },
  { SENSOR, 3, "Front Door Sensor" }
};

// Functions, like skilled weavers, transform mere threads into intricate patterns.
void turn_on_device(device* dev) {
  printf("Activating device '%s' with ID %u.\n", dev->name, dev->id);
}

void turn_off_device(device* dev) {
  printf("Deactivating device '%s' with ID %u.\n", dev->name, dev->id);
}

void toggle_device(device* dev) {
  if (dev->type == LIGHT) {
    if (dev->id & 1) {
      turn_off_device(dev);
    } else {
      turn_on_device(dev);
    }
  } else if (dev->type == FAN) {
    if (dev->id % 2 == 0) {
      turn_off_device(dev);
    } else {
      turn_on_device(dev);
    }
  }
}

// The main function, like the master weaver, orchestrates the symphony of automation.
int main(void) {
  int choice;
  do {
    printf("1. Turn on a device\n2. Turn off a device\n3. Toggle a device\n4. Exit\nChoice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter device ID: ");
        scanf("%u", &choice);
        turn_on_device(&devices[choice - 1]);
        break;
      case 2:
        printf("Enter device ID: ");
        scanf("%u", &choice);
        turn_off_device(&devices[choice - 1]);
        break;
      case 3:
        printf("Enter device ID: ");
        scanf("%u", &choice);
        toggle_device(&devices[choice - 1]);
        break;
      default:
        break;
    }
  } while (choice != 4);

  return 0;
}