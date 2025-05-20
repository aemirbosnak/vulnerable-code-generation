//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Robot movement functions
void move_forward(int steps) {
  printf("Beep boop! I'm taking %d steps forward!\n", steps);
  // Simulate walking forward
  sleep(steps);
}

void turn_left(int degrees) {
  printf("Whizz! I'm turning %d degrees to the left!\n", degrees);
  // Simulate turning left
  sleep(degrees / 10);
}

void turn_right(int degrees) {
  printf("Honk! I'm turning %d degrees to the right!\n", degrees);
  // Simulate turning right
  sleep(degrees / 10);
}

void dance() {
  printf("I'm feeling groovy! Let's dance!\n");
  // Simulate dancing
  for (int i = 0; i < 10; i++) {
    move_forward(1);
    turn_left(90);
    move_forward(1);
    turn_right(90);
  }
}

int main() {
  // Introduce the robot
  printf("Hello, I'm Robby the Robot!\n");

  // Ask the user for instructions
  printf("What should I do today?\n");
  printf("(Options: forward, left, right, dance)\n");

  // Get the user's input
  char input[100];
  scanf("%s", input);

  // Execute the user's instructions
  if (strcmp(input, "forward") == 0) {
    printf("How many steps forward should I take?\n");
    int steps;
    scanf("%d", &steps);
    move_forward(steps);
  } else if (strcmp(input, "left") == 0) {
    printf("How many degrees should I turn left?\n");
    int degrees;
    scanf("%d", &degrees);
    turn_left(degrees);
  } else if (strcmp(input, "right") == 0) {
    printf("How many degrees should I turn right?\n");
    int degrees;
    scanf("%d", &degrees);
    turn_right(degrees);
  } else if (strcmp(input, "dance") == 0) {
    dance();
  } else {
    printf("I don't understand that command. Please try again.\n");
  }

  // Say goodbye
  printf("Thanks for playing with me! See you later!\n");

  return 0;
}