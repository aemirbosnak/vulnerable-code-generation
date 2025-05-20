//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global variables
int brightness = 50; // Default brightness level
bool lightOn = false; // Default light status

// Function prototypes
void turnLightOn();
void turnLightOff();
void setBrightness(int level);

int main() {
  char input;
  printf("Welcome to Smart Home Light Control!\n");
  while (true) {
    printf("\nEnter a command (o for on, f for off, b to set brightness): ");
    scanf(" %c", &input);
    switch(input) {
      case 'o':
        turnLightOn();
        break;
      case 'f':
        turnLightOff();
        break;
      case 'b':
        setBrightness(brightness);
        break;
      default:
        printf("Invalid command. Try again.\n");
        break;
    }
  }
  return 0;
}

// Turn the light on
void turnLightOn() {
  if (lightOn) {
    printf("The light is already on.\n");
  } else {
    lightOn = true;
    printf("The light is now on.\n");
  }
}

// Turn the light off
void turnLightOff() {
  if (!lightOn) {
    printf("The light is already off.\n");
  } else {
    lightOn = false;
    printf("The light is now off.\n");
  }
}

// Set the brightness level
void setBrightness(int level) {
  printf("Enter brightness level (0-100): ");
  scanf("%d", &level);
  if (level < 0 || level > 100) {
    printf("Invalid brightness level. Try again.\n");
  } else {
    brightness = level;
    printf("Brightness level set to %d.\n", brightness);
  }
}