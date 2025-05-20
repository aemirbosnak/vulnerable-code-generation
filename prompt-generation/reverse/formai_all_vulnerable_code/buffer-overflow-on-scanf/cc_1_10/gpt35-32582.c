//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int command;
  char instructions[50];

  printf("Welcome to the C Drone Remote Control\n");

  printf("Please enter the drone's current coordinates (x, y, z): ");
  scanf("%s", instructions);
  printf("\n");

  char *token = strtok(instructions, ", ");
  int x = atoi(token);
  token = strtok(NULL, ", ");
  int y = atoi(token);
  token = strtok(NULL, ", ");
  int z = atoi(token);

  printf("Current drone coordinates: (%d, %d, %d)\n", x, y, z);
  printf("Please enter the drone's next command:\n");
  printf("1. Move up\n");
  printf("2. Move down\n");
  printf("3. Move left\n");
  printf("4. Move right\n");
  printf("5. Move forward\n");
  printf("6. Move backward\n");
  
  scanf("%d", &command);

  switch (command) {
    case 1:
      z++;
      printf("Moving up\n");
      break;
    case 2:
      z--;
      printf("Moving down\n");
      break;
    case 3:
      x--;
      printf("Moving left\n");
      break;
    case 4:
      x++;
      printf("Moving right\n");
      break;
    case 5:
      y++;
      printf("Moving forward\n");
      break;
    case 6:
      y--;
      printf("Moving backward\n");
      break;
    default:
      printf("Invalid command\n");
  }

  printf("New drone coordinates: (%d, %d, %d)\n", x, y, z);

  return 0;
}