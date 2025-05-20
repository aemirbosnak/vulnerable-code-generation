//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>

int main() {
  int light[3] = {0}; // initializes the light array to all off
  int room, command;

  printf("Hello! Welcome to your smart home light control system.\n\n");

  while (1) {
    printf("Which room would you like to control? Enter 1 for living room, 2 for bedroom, or 3 for kitchen: ");
    scanf("%d", &room);
    
    if (room > 3 || room < 1) {
      printf("That room does not exist! Try again.\n\n");
      continue; // goes back to the start of the loop
    }

    printf("Enter 1 to turn the light on, or 2 to turn it off: ");
    scanf("%d", &command);

    if (command != 1 && command != 2) {
      printf("That is an invalid command! Try again.\n\n");
      continue; // goes back to the start of the loop
    }

    // update the light array
    if (command == 1) {
      light[room - 1] = 1;
    } else {
      light[room - 1] = 0;
    }

    // display the current status of the lights
    printf("Current light statuses: {");

    for (int i = 0; i < 3; i++) {
      if (light[i]) {
        printf("on");
      } else {
        printf("off");
      }

      if (i == 2) {
        printf("}\n\n"); // end of line, so add a curly brace before newline
      } else {
        printf(", "); // not end of line, so add a comma and space
      }
    }
  }

  return 0; // the program should never reach here
}