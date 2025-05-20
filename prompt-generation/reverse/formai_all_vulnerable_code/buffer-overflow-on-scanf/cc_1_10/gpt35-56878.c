//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Haunted House Simulator!\n\n");
  printf("You find yourself standing in front of a spooky old mansion. Will you enter?\n");

  char response[20];
  scanf("%s", response);

  if(strcmp(response, "yes") == 0 || strcmp(response, "Yes") == 0) {
    printf("\nYou bravely walk up to the mansion and push open the creaky door.\n");

    // Set up random generator for jump scare
    srand(time(0));
    int jump_scare_chance = rand() % 10 + 1;

    // Loop until player exits or gets jump scared
    int room_number = 1;
    while(room_number <= 5) {
      printf("\nYou find yourself in room %d. What will you do?\n", room_number);
      printf("1. Look around\n");
      printf("2. Leave the room\n");

      int choice;
      scanf("%d", &choice);

      switch(choice) {
        case 1:
          printf("\nYou start to look around the room. Suddenly, you hear a loud noise...\n");

          if(jump_scare_chance == 10) {
            printf("A ghostly figure appears before you and you let out a blood-curdling scream!\n");
            printf("GAME OVER\n");
            return 0;
          } else {
            printf("Phew, it was just a gust of wind. You breathe a sigh of relief and continue exploring the room.\n");
            break;
          }

        case 2:
          printf("\nYou quickly leave the room and find yourself in the hallway again.\n");
          room_number++;
          break;

        default:
          printf("\nInvalid choice\n");
          break;
      }
    }

    // Out of rooms, player wins
    printf("\nCongratulations! You made it out of the haunted house alive!\n");
    printf("Thanks for playing!\n");
    return 0;

  } else {
    printf("\nYou decide not to enter the haunted house. Good choice...\n");
    printf("Thanks for playing!\n");
    return 0;
  }
}