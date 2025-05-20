//FormAI DATASET v1.0 Category: Smart home light control ; Style: lively
#include <stdio.h>

// function to turn on the lights based on user input
void turnOnLights(char room[]) {
  printf("Turning on the lights in the %s...\n", room);
  // code to turn on the lights
}

// function to turn off the lights based on user input
void turnOffLights(char room[]) {
  printf("Turning off the lights in the %s...\n", room);
  // code to turn off the lights
}

int main() {
  printf("Welcome to Smart Home Light Control!\n");
  char input = ' ';
  while (input != 'x') {
    printf("\nWhich room would you like to control the lights for?\n");
    printf("a. Living Room\n");
    printf("b. Bedroom\n");
    printf("c. Kitchen\n");
    printf("d. Bathroom\n");
    printf("x. Exit\n");
    scanf(" %c", &input);

    switch(input) {
      case 'a': 
        turnOnLights("Living Room");
        break;
      case 'b': 
        turnOnLights("Bedroom");
        break;
      case 'c': 
        turnOnLights("Kitchen");
        break;
      case 'd': 
        turnOnLights("Bathroom");
        break;
      case 'x':
        printf("Exiting the program...\n");
        break;
      default:
        printf("Invalid input, please try again.\n");
        break;
    }

    // wait for a moment before turning the lights off
    if (input != 'x') {
      printf("\nDo you want to turn the lights off? (y/n)\n");
      char choice = ' ';
      scanf(" %c", &choice);
      if (choice == 'y') {
        switch(input) {
          case 'a': 
            turnOffLights("Living Room");
            break;
          case 'b': 
            turnOffLights("Bedroom");
            break;
          case 'c': 
            turnOffLights("Kitchen");
            break;
          case 'd': 
            turnOffLights("Bathroom");
            break;
        }
      }
    }
  }

  return 0;
}