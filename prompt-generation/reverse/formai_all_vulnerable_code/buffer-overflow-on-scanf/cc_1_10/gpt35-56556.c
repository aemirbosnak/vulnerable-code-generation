//FormAI DATASET v1.0 Category: Smart home automation ; Style: protected
#include <stdio.h>

// Function prototypes
void turnOnLight();
void turnOffLight();
void turnOnFan();
void turnOffFan();

int main() {
  int light = 0;
  int fan = 0;
  int choice;

  printf("Welcome to Smart Home Automation!\n");

  while (1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Turn on the light\n");
    printf("2. Turn off the light\n");
    printf("3. Turn on the fan\n");
    printf("4. Turn off the fan\n");
    printf("5. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (light == 0) {
          turnOnLight();
          light = 1;
        }
        else {
          printf("The light is already on.\n");
        }
        break;

      case 2:
        if (light == 1) {
          turnOffLight();
          light = 0;
        }
        else {
          printf("The light is already off.\n");
        }
        break;

      case 3:
        if (fan == 0) {
          turnOnFan();
          fan = 1;
        }
        else {
          printf("The fan is already on.\n");
        }
        break;

      case 4:
        if (fan == 1) {
          turnOffFan();
          fan = 0;
        }
        else {
          printf("The fan is already off.\n");
        }
        break;

      case 5:
        printf("Goodbye!\n");
        return 0;

      default:
        printf("Invalid choice.\n");
    }
  }
}

void turnOnLight() {
  printf("The light is now on.\n");
}

void turnOffLight() {
  printf("The light is now off.\n");
}

void turnOnFan() {
  printf("The fan is now on.\n");
}

void turnOffFan() {
  printf("The fan is now off.\n");
}