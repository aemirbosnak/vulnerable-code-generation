//FormAI DATASET v1.0 Category: Smart home light control ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>

/* Enum to represent the status of the light */
typedef enum {
  OFF,
  ON
} LightStatus;

/* Function to turn the light on */
void turnOn(LightStatus *status) {
  *status = ON;
  printf("The light is ON\n");
}

/* Function to turn the light off */
void turnOff(LightStatus *status) {
  *status = OFF;
  printf("The light is OFF\n");
}

int main() {
  /* Create variables for status of the light and user input */
  LightStatus status = OFF;
  char userInput;

  /* Loop to continuously ask user for input */
  while (true) {
    /* Print current status of the light and ask user for input */
    printf("The light is currently %s. Type 'o' to turn it on or 'f' to turn it off.\n", status == ON ? "ON" : "OFF");
    scanf(" %c", &userInput);

    /* Use switch statement to execute appropriate function based on user input */
    switch (userInput) {
      case 'o':
        if (status == OFF) {
          turnOn(&status);
        } else {
          printf("The light is already ON. Please choose another option.\n");
        }
        break;
      case 'f':
        if (status == ON) {
          turnOff(&status);
        } else {
          printf("The light is already OFF. Please choose another option.\n");
        }
        break;
      default:
        printf("Invalid input. Please choose 'o' to turn the light on or 'f' to turn it off.\n");
        break;
    }
  }

  return 0;
}