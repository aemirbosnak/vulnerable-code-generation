//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int option;
  srand(time(NULL)); // Seed random number generator

  printf("Welcome to the Haunted House Simulator!\n");
  printf("You find yourself standing in front of an old, abandoned house.\n");
  printf("Do you dare enter?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  scanf("%d", &option);

  if(option == 2) {
    printf("You decide not to enter the house. Coward.\n");
    return 0;
  }

  printf("You slowly open the creaky door and step inside.\n");
  printf("As you walk through the entrance, you hear whispers and whispers of ghosts all around you.\n");
  printf("Suddenly, the door slams shut behind you and you feel a cold chill run down your spine.\n");

  int room = 1;
  int ghost = rand() % 10 + 1; // Random ghost generator

  while(room != 0) {
    printf("You are in room %d.\n", room);
    printf("What do you do?\n");
    printf("1. Look around.\n");
    printf("2. Go to the next room.\n");
    printf("3. Try to communicate with ghosts.\n");
    scanf("%d", &option);

    switch(option) {
      case 1:
        printf("You look around the room and see nothing out of the ordinary.\n");
        break;
      case 2:
        if(room == 1) {
          printf("You open the door and enter the next room.\n");
          room = 2;
        }
        else {
          printf("You open the door and enter the next room.\n");
          printf("As you enter the room, you see a ghost hovering in front of you!\n");
          if(ghost == 1) {
            printf("The ghost attacks you, and you realize it's real!\n");
            printf("GAME OVER.\n");
            return 0;
          }
          room++;
        }
        break;
      case 3:
        if(ghost == 1) {
          printf("You try to communicate with the ghosts and suddenly one of them answers you!\n");
        }
        else {
          printf("You try to communicate with the ghosts, but they remain silent.\n");
        }
        break;
      default:
        printf("Invalid option. Try again.\n");
        break;
    }

    if(room == 5) {
      printf("You've made it to the end of the haunted house! Congratulations, you're free!\n");
      return 0;
    }
  }

  printf("You have exited the haunted house. Goodbye.\n");
  return 0;
}