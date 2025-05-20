//FormAI DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdbool.h>

bool checkStatus(char light1, char light2, char light3, char light4) {
  // function to check the status of all the lights
  if (light1 == '1' && light2 == '1' && light3 == '1' && light4 == '1') {
    return true;
  } else {
    return false;
  }
}

int main() {
  char light1 = '0';
  char light2 = '0';
  char light3 = '0';
  char light4 = '0';

  printf("Welcome to Smart Home Light Control Program!\n");
  printf("Enter 1 to turn on Light 1.\n");
  printf("Enter 2 to turn on Light 2.\n");
  printf("Enter 3 to turn on Light 3.\n");
  printf("Enter 4 to turn on Light 4.\n");
  printf("Enter 0 to turn off all lights.\n");

  int input;
  while (true) {
    printf("Enter your choice: ");
    scanf("%d", &input);

    switch (input) {
      case 0: // turn off all lights
        light1 = '0';
        light2 = '0';
        light3 = '0';
        light4 = '0';
        printf("All lights turned off.\n");
        break;

      case 1: // turn on Light 1
        light1 = '1';
        printf("Light 1 turned on.\n");
        break;

      case 2: // turn on Light 2
        light2 = '1';
        printf("Light 2 turned on.\n");
        break;

      case 3: // turn on Light 3
        light3 = '1';
        printf("Light 3 turned on.\n");
        break;

      case 4: // turn on Light 4
        light4 = '1';
        printf("Light 4 turned on.\n");
        break;

      default: // invalid input
        printf("Invalid input. Please try again.\n");
        continue;
    }

    // check the status of all the lights
    bool status = checkStatus(light1, light2, light3, light4);
    if (status) {
      printf("All lights are on!\n");
    }
  }

  return 0;
}