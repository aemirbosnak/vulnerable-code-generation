//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome message
  printf("Welcome to the Haunted House Simulator!\n");
  
  // Seed the random number generator
  srand(time(NULL));
  
  // Define the location variables
  int room = 1;
  int hallway = 1;
  
  // Define the ghost variables
  int ghost_alive = 1;
  int ghost_location = 0;
  
  // Main game loop
  while (1) {
    // Print the current location description
    printf("\nYou are in ");
    if (room == 1) {
      printf("the living room.\n");
      if (ghost_location == 1 && ghost_alive == 1) {
        printf("You hear something moaning in the corner.\n");
      }
      printf("You see a stairway leading up.\n");
      printf("Where do you want to go? (up/down): ");
      char choice[10];
      scanf("%s", choice);
      if (strcmp(choice, "up") == 0) {
        room = 2;
      } else if (strcmp(choice, "down") == 0) {
        printf("You can't go any further down.\n");
      }
    } else if (room == 2) {
      printf("the hallway.\n");
      if (ghost_location == 2 && ghost_alive == 1) {
        printf("You see a ghost floating towards you!\n");
        printf("What do you want to do? (run/fight): ");
        char choice[10];
        scanf("%s", choice);
        if (strcmp(choice, "run") == 0) {
          printf("You run back to the living room.\n");
          hallway = 1;
          ghost_location = 0;
        } else if (strcmp(choice, "fight") == 0) {
          printf("You fight the ghost but it's no use, it's a ghost!\n");
          printf("You die!\n");
          return 0;
        }
      }
      printf("You can see a bedroom to your left.\n");
      printf("You can see a bathroom to your right.\n");
      printf("Where do you want to go? (left/right/back): ");
      char choice[10];
      scanf("%s", choice);
      if (strcmp(choice, "left") == 0) {
        room = 3;
      } else if (strcmp(choice, "right") == 0) {
        room = 4;
      } else if (strcmp(choice, "back") == 0) {
        room = 1;
      }
    } else if (room == 3) {
      printf("the bedroom.\n");
      printf("You see a closet in the corner.\n");
      printf("Where do you want to go? (closet/back): ");
      char choice[10];
      scanf("%s", choice);
      if (strcmp(choice, "closet") == 0) {
        printf("You open the closet but there's nothing inside.\n");
      } else if (strcmp(choice, "back") == 0) {
        room = 2;
      }
    } else if (room == 4) {
      printf("the bathroom.\n");
      printf("You see a mirror on the wall.\n");
      printf("Where do you want to go? (mirror/back): ");
      char choice[10];
      scanf("%s", choice);
      if (strcmp(choice, "mirror") == 0) {
        printf("You look into the mirror but you don't see your reflection.\n");
        printf("You turn around and see a ghost floating towards you!\n");
        printf("What do you want to do? (run/fight): ");
        char choice[10];
        scanf("%s", choice);
        if (strcmp(choice, "run") == 0) {
          printf("You run back to the hallway.\n");
          room = 2;
          hallway = 2;
          ghost_location = 2;
        } else if (strcmp(choice, "fight") == 0) {
          printf("You fight the ghost but it's no use, it's a ghost!\n");
          printf("You die!\n");
          return 0;
        }
      } else if (strcmp(choice, "back") == 0) {
        room = 2;
      }
    }
    
    // Move the ghost randomly
    if (ghost_alive == 1) {
      int random = rand() % 3;
      if (random == 0 && hallway == 2 && ghost_location == 0) {
        ghost_location = 2;
      } else if (random == 1 && hallway == 2 && ghost_location == 2) {
        ghost_location = 0;
      } else if (random == 2 && room == 1 && ghost_location == 0) {
        ghost_location = 1;
      } else if (random == 2 && room == 1 && ghost_location == 1) {
        ghost_location = 0;
      }
    }
    
    // Check if the player has won
    if (room == 2 && ghost_alive == 0) {
      printf("\nYou won! You made it out of the house alive!\n");
      return 0;
    }
  }
}