//FormAI DATASET v1.0 Category: Robot movement control ; Style: surrealist
#include <stdio.h>

void moveForward() {
  printf("The C Robot stepped into a tunnel made entirely of mirrors.\n");
  printf("As it moved forward, its reflection in the mirrors distorted and multiplied infinitely.\n");
  printf("The Robot felt like it was traversing through a kaleidoscope.\n");
}

void moveBackward() {
  printf("The C Robot stumbled backwards, but it didn't stop walking.\n");
  printf("The ground beneath it was made of thick, woolly grass, and it cushioned the Robot's fall.\n");
  printf("The Robot got up, looked up at the sky, and saw that it was raining pine needles.\n");
}

void turnLeft() {
  printf("The C Robot made a sharp left turn and found itself in the middle of a vast, monochrome desert.\n");
  printf("The sand dunes that surrounded it shifted and swirled as if they were alive.\n");
  printf("The Robot blinked, and when it opened its eyes, it saw that it was standing in front of a towering, obsidian gateway.\n");
}

void turnRight() {
  printf("The C Robot turned right and saw a great wall of ice in front of it.\n");
  printf("The Robot approached the wall and placed its hand on the ice.\n");
  printf("To its surprise, the ice melted under its touch and revealed a secret chamber hidden inside the wall.\n");
}

void dance() {
  printf("The C Robot jumped up and down, spun around, and shook its mechanical hips.\n");
  printf("The ground beneath it trembled and split open, revealing a swirling vortex of lights and colors.\n");
  printf("The Robot kept on dancing and leapt into the vortex.\n");
}

int main() {
  printf("The C Robot woke up in a field of tall, golden wheat.\n");
  printf("It stretched its limbs and stood up, feeling the warmth of the sun on its metal skin.\n");

  int input;
  do {
    printf("\nWhat would you like the C Robot to do?\n");
    printf("1. Move forward.\n");
    printf("2. Move backward.\n");
    printf("3. Turn left.\n");
    printf("4. Turn right.\n");
    printf("5. Dance.\n");
    printf("6. Exit.\n");
    
    scanf("%d", &input);

    switch(input) {
      case 1:
        moveForward();
        break;
      case 2:
        moveBackward();
        break;
      case 3:
        turnLeft();
        break;
      case 4:
        turnRight();
        break;
      case 5:
        dance();
        break;
      case 6:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid option! Please choose a valid option.\n");
    }
  } while(input != 6);

  return 0;
}