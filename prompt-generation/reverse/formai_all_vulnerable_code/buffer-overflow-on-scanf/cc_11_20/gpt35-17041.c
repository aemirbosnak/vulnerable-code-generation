//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int choice = 0;
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You find yourself standing in front of a spooky old house. Do you:\n1. Go inside\n2. Run away\n");
  scanf("%d", &choice);
  while(choice != 1 && choice != 2) {
    printf("Invalid choice. Please enter 1 or 2.\n");
    scanf("%d", &choice);
  }
  if(choice == 1) {
    printf("You enter the house and the door slams shut behind you. It's too dark to see anything.\n");
    printf("Do you:\n1. Light a match\n2. Keep walking in the dark\n");
    scanf("%d", &choice);
    while(choice != 1 && choice != 2) {
      printf("Invalid choice. Please enter 1 or 2.\n");
      scanf("%d", &choice);
    }
    if(choice == 1) {
      printf("You light a match and see a staircase leading upstairs. Do you:\n1. Climb the stairs\n2. Stay on the ground floor\n");
      scanf("%d", &choice);
      while(choice != 1 && choice != 2) {
        printf("Invalid choice. Please enter 1 or 2.\n");
        scanf("%d", &choice);
      }
      if(choice == 1) {
        printf("You climb the stairs and hear eerie laughter coming from the end of the hallway.\n");
        printf("Do you:\n1. Investigate the laughter\n2. Find a place to hide\n");
        scanf("%d", &choice);
        while(choice != 1 && choice != 2) {
          printf("Invalid choice. Please enter 1 or 2.\n");
          scanf("%d", &choice);
        }
        if(choice == 1) {
          printf("You follow the laughter to find a ghostly figure staring back at you. You scream and...\n");
          srand(time(0));
          int death = rand() % 3;
          if(death == 0) {
            printf("...you die of fright.\n");
          } else if(death == 1) {
            printf("...you run away and escape the house.\n");
          } else {
            printf("...you wake up, realizing it was all a dream.\n");
          }
        } else {
          printf("You find a closet and hide inside. You hear footsteps passing by and you wait for what seems like hours.\n");
          printf("Eventually, you come out and find a way out of the house.\n");
        }
      } else {
        printf("You stay on the ground floor and find a room with a fireplace. You sit down next to it and get warm.\n");
        printf("Hours go by and you start dozing off. You wake up to find the fire has gone out and the room is pitch black.\n");
        printf("You try to find your way out, but realize the door is locked.\n");
        printf("You wait for hours until someone finally comes to rescue you.\n");
      }
    } else {
      printf("You keep walking in the dark and trip over a table. You hear a loud crash and...\n");
      srand(time(0));
      int death = rand() % 3;
      if(death == 0) {
        printf("...you die from your injuries.\n");
      } else if(death == 1) {
        printf("...you get up and explore the rest of the house.\n");
        printf("You eventually find a way out and escape.\n");
      } else {
        printf("...you realize it was just a dream.\n");
      }
    }
  } else {
    printf("You run away from the house and never look back.\n");
  }
  return 0;
}