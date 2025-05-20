//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GOATS 10

typedef struct Goat {
  char name[20];
  int health;
  int happiness;
  int location;
} Goat;

int main() {
  srand(time(NULL));
  Goat goats[MAX_GOATS];

  for (int i = 0; i < MAX_GOATS; i++) {
    goats[i].name[0] = 'G' + i;
    goats[i].health = rand() % 100;
    goats[i].happiness = rand() % 100;
    goats[i].location = rand() % 10;
  }

  int current_goat = 0;
  char command[20];

  printf("Welcome to the Goat Simulator!\n");
  printf("Current goat: %s\n", goats[current_goat].name);
  printf("Health: %d, Happiness: %d\n", goats[current_goat].health, goats[current_goat].happiness);

  while (1) {
    printf("Enter command: ");
    scanf("%s", command);

    if (strcmp(command, "quit") == 0) {
      break;
    } else if (strcmp(command, "feed") == 0) {
      goats[current_goat].health++;
      printf("Yum! Goat is happy!\n");
    } else if (strcmp(command, "make_sad") == 0) {
      goats[current_goat].happiness--;
      printf("Boo hoo hoo! Goat is sad.\n");
    } else if (strcmp(command, "move") == 0) {
      goats[current_goat].location++;
      printf("Goat moved to a new location.\n");
    } else if (strcmp(command, "change_goat") == 0) {
      current_goat++;
      if (current_goat >= MAX_GOATS) {
        current_goat = 0;
      }
      printf("New goat selected: %s\n", goats[current_goat].name);
    } else {
      printf("Invalid command.\n");
    }

    printf("Current goat: %s\n", goats[current_goat].name);
    printf("Health: %d, Happiness: %d\n", goats[current_goat].health, goats[current_goat].happiness);
  }

  return 0;
}