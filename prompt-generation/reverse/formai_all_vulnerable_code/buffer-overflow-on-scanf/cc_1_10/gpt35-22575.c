//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int choice;

  printf("Welcome to the Haunted House Simulator!\n");
  printf("You find yourself in front of a creepy old mansion.\n");
  printf("Do you dare to enter?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  scanf("%d", &choice);

  if (choice == 2) {
    printf("You chicken out and leave.\n");
    return 0;
  }

  printf("You summon up all your courage and enter the mansion.\n");
  printf("As you step inside, the door slams shut behind you.\n");
  printf("You are trapped!\n");

  printf("You look around and see a staircase leading up to the second floor.\n");
  printf("1. Climb the stairs\n");
  printf("2. Look for another way out\n");
  scanf("%d", &choice);

  if (choice == 2) {
    printf("You search for another way out, but find nothing.\n");
  } else {
    printf("You climb the stairs, heart pounding in your chest.\n");
    printf("As you reach the top of the stairs, you hear creaking floorboards in the hallway.\n");
    printf("In front of you are three doors. Which do you choose?\n");
    printf("1. The left door\n");
    printf("2. The middle door\n");
    printf("3. The right door\n");
    scanf("%d", &choice);

    if (choice == 1) {
      printf("You open the left door and see a ghostly figure floating in the air.\n");
    } else if (choice == 2) {
      printf("You open the middle door and see a room filled with cobwebs and spiders.\n");
    } else {
      printf("You open the right door and see a dusty library.\n");
    }
  }

  printf("You hear strange noises coming from below.\n");
  printf("1. Go back downstairs\n");
  printf("2. Stay put\n");
  scanf("%d", &choice);

  if (choice == 2) {
    printf("You stay in the room, afraid to move.\n");
  } else {
    printf("You descend the stairs, apprehensive about what you might find.\n");
    printf("As you reach the bottom of the stairs, a figure jumps out at you!\n");
    printf("You scream and run towards the front door, which miraculously opens.\n");
    printf("You run outside and look back at the mansion, which disappears before your eyes.\n");
    printf("You realize that you have just survived a haunted house!\n");
  }

  return 0;
}