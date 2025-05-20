//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house_simulator(int difficulty) {
  int i, j, r, t;
  char c;
  time_t start, end;

  start = time(NULL);

  // Create a spooky atmosphere
  system("played_once.wav");
  for (i = 0; i < 5; i++) {
    printf("\n");
  }

  // The house is dark, so turn on the flashlight
  printf("You wake up in a dark and eerie haunted house. You have only a flashlight to guide you. Press any key to continue...\n");
  c = getchar();

  // Randomly generate the haunted house layout
  r = rand() % 5;
  switch (r) {
    case 0:
      printf("You find yourself in the living room. There is a creepy painting on the wall and a disembodied hand on the table.\n");
      break;
    case 1:
      printf("You are in the dining room. The table is set for a feast, but the food is rotten. There is a ghostly figure sitting at the head of the table.\n");
      break;
    case 2:
      printf("You are in the bedroom. The bed is covered in blood and the walls are covered in strange symbols.\n");
      break;
    case 3:
      printf("You are in the hallway. There are bloodstained footprints leading you deeper into the house.\n");
      break;
    case 4:
      printf("You are in the basement. The walls are covered in graffiti and the air is thick with the smell of decay.\n");
      break;
  }

  // The house is haunted, so prepare for a scare
  t = rand() % 3;
  switch (t) {
    case 0:
      printf("Suddenly, a loud noise echoes through the house. You hear footsteps running down the hallway.\n");
      break;
    case 1:
      printf("You hear a disembodied voice whispering your name. You feel a cold hand brush against your skin.\n");
      break;
    case 2:
      printf("You see a ghostly figure standing in the doorway to your room. The figure turns to you with its eyes glowing.\n");
      break;
  }

  // The sound of the clock ticking
  for (i = 0; i < 5; i++) {
    printf("\n");
  }

  end = time(NULL);

  // Calculate the time spent in the haunted house
  t = end - start;

  // Print the time spent in the haunted house
  printf("You have spent %d seconds in the haunted house.\n", t);

  // Leave the haunted house
  printf("You escape from the haunted house. You are safe now.\n");
}

int main() {
  haunted_house_simulator(5);

  return 0;
}