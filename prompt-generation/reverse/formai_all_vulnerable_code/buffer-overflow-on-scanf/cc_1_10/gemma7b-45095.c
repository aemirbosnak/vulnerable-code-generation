//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void goto_location(int location) {
  switch (location) {
    case 1:
      printf("You are in the forest.\n");
      break;
    case 2:
      printf("You are in the castle.\n");
      break;
    case 3:
      printf("You are in the city.\n");
      break;
  }
}

int main() {
  int location = 1;
  char input;

  printf("Welcome to the adventure!\n");

  while (1) {
    goto_location(location);

    printf("What do you want to do? (north, south, east, west)\n");
    scanf("%c", &input);

    switch (input) {
      case 'n':
        location = 2;
        break;
      case 's':
        location = 3;
        break;
      case 'e':
        location = 1;
        break;
      case 'w':
        location = 3;
        break;
    }

    if (location == 3) {
      printf("You have reached the end of the adventure!\n");
      break;
    }
  }

  return 0;
}