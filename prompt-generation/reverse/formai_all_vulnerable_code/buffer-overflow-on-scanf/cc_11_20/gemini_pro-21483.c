//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int rooms[10] = {0};
  int current_room = 0;
  int steps = 0;

  printf("Welcome to the Haunted House Simulator!\n");
  printf("You are standing in the entrance hall.\n");

  while (current_room != 9) {
    int choice = 0;
    printf("Which room do you want to enter?\n");
    printf("1. Living room\n");
    printf("2. Dining room\n");
    printf("3. Kitchen\n");
    printf("4. Study\n");
    printf("5. Master bedroom\n");
    printf("6. Guest bedroom\n");
    printf("7. Attic\n");
    printf("8. Basement\n");
    printf("9. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        current_room = 1;
        break;
      case 2:
        current_room = 2;
        break;
      case 3:
        current_room = 3;
        break;
      case 4:
        current_room = 4;
        break;
      case 5:
        current_room = 5;
        break;
      case 6:
        current_room = 6;
        break;
      case 7:
        current_room = 7;
        break;
      case 8:
        current_room = 8;
        break;
      case 9:
        current_room = 9;
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 9.\n");
        break;
    }

    if (current_room != 9) {
      int event = rand() % 10;

      if (event == 0) {
        printf("You hear a creaking sound.\n");
      } else if (event == 1) {
        printf("You see a shadow moving in the corner of your eye.\n");
      } else if (event == 2) {
        printf("You feel a cold breeze on your neck.\n");
      } else if (event == 3) {
        printf("You hear a faint whisper.\n");
      } else if (event == 4) {
        printf("You see a door slowly opening.\n");
      } else if (event == 5) {
        printf("You feel a hand on your shoulder.\n");
      } else if (event == 6) {
        printf("You see a ghost!\n");
      }

      steps++;
    }
  }

  printf("You have escaped the haunted house! You took %d steps.\n", steps);

  return 0;
}