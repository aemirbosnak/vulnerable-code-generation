//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LEFT_TURN        1
#define RIGHT_TURN       2
#define FORWARD          3
#define BACKWARD         4
#define STOP             5
#define EXIT             6

void clear_input_buffer() {
  while (getchar() != '\n');
}

void display_menu() {
  printf("\nAvailable Commands:\n");
  printf("  1. Left Turn\n");
  printf("  2. Right Turn\n");
  printf("  3. Forward\n");
  printf("  4. Backward\n");
  printf("  5. Stop\n");
  printf("  6. Exit\n");
}

int main() {
  int running = 1;
  char command[2];

  printf("Welcome to the Remote Control Vehicle Simulator!\n");
  display_menu();

  while (running) {
    printf("> ");
    scanf("%s", command);
    clear_input_buffer();

    switch (atoi(command)) {
      case LEFT_TURN:
        printf("Turning Left...\n");
        break;
      case RIGHT_TURN:
        printf("Turning Right...\n");
        break;
      case FORWARD:
        printf("Moving Forward...\n");
        break;
      case BACKWARD:
        printf("Moving Backward...\n");
        break;
      case STOP:
        printf("Stopping...\n");
        break;
      case EXIT:
        printf("Exiting...\n");
        running = 0;
        break;
      default:
        printf("Invalid command!\n");
        break;
    }
  }

  return 0;
}