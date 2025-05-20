//Code Llama-13B DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
/*
 * A C Smart Home Light Control Example Program
 *
 * This program allows the user to control a smart light using a simple CLI.
 * The user can turn the light on and off, change the brightness, and change
 * the color of the light.
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1

// Structure to represent a smart light
typedef struct {
  int brightness;
  int color;
  int status;
} smart_light_t;

// Function to turn the light on
void turn_light_on(smart_light_t* light) {
  light->status = LIGHT_ON;
}

// Function to turn the light off
void turn_light_off(smart_light_t* light) {
  light->status = LIGHT_OFF;
}

// Function to change the brightness of the light
void change_brightness(smart_light_t* light, int brightness) {
  light->brightness = brightness;
}

// Function to change the color of the light
void change_color(smart_light_t* light, int color) {
  light->color = color;
}

int main() {
  // Initialize the smart light
  smart_light_t light;
  light.brightness = 50;
  light.color = 0;
  light.status = LIGHT_OFF;

  // Prompt the user for input
  char input[100];
  while (1) {
    printf("Enter a command (on/off/brightness/color): ");
    fgets(input, sizeof(input), stdin);

    // Turn the light on
    if (strcmp(input, "on") == 0) {
      turn_light_on(&light);
      printf("Light is now on\n");
    }

    // Turn the light off
    else if (strcmp(input, "off") == 0) {
      turn_light_off(&light);
      printf("Light is now off\n");
    }

    // Change the brightness of the light
    else if (strcmp(input, "brightness") == 0) {
      int brightness;
      printf("Enter new brightness (0-100): ");
      scanf("%d", &brightness);
      change_brightness(&light, brightness);
      printf("Brightness is now %d\n", light.brightness);
    }

    // Change the color of the light
    else if (strcmp(input, "color") == 0) {
      int color;
      printf("Enter new color (0-255): ");
      scanf("%d", &color);
      change_color(&light, color);
      printf("Color is now %d\n", light.color);
    }

    // Exit the program
    else if (strcmp(input, "exit") == 0) {
      break;
    }

    // Invalid input
    else {
      printf("Invalid input\n");
    }
  }

  return 0;
}