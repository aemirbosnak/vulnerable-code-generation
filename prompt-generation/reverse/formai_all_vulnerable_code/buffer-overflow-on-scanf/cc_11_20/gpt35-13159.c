//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
  printf("Welcome to the Haunted House Simulator!\n");

  int current_room = 1;
  bool has_key = false;
  bool has_flashlight = false;

  printf("\nYou are in the first room of the house. The door shuts behind you and won't budge. ");
  printf("You see a hallway heading left and a staircase heading up. ");

  while (current_room != 5) {
    printf("\n\nYou are currently in room %d.", current_room);

    // Room 1
    if (current_room == 1) {
      printf("\nYou see a table in the corner with a key on it.");

      char choice;
      printf("\nDo you take the key? (y/n): ");
      scanf(" %c", &choice);

      if (choice == 'y') {
        has_key = true;
        printf("\nYou now have the key!");
      }
    }

    // Room 2
    else if (current_room == 2) {
      printf("\nYou are in a dark room with nothing but a pile of bones in the corner.");
    }

    // Room 3
    else if (current_room == 3) {
      if (has_key == false) {
        printf("\nThe door is locked. You need a key.");
      }
      else {
        printf("\nThe door is unlocked. You can move on to the next room.");
        char choice;
        printf("\nDo you go through the door? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y') {
          current_room++;
        }
      }
    }

    // Room 4
    else if (current_room == 4) {
      printf("\nYou are in an empty room with a hole in the ceiling. You need a flashlight to see what's up there.");

      if (has_flashlight == false) {
        printf("\nThere is a flashlight on the floor. Do you take it? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y') {
          has_flashlight = true;
          printf("\nYou now have the flashlight.");
        }
      }
      else {
        printf("\nYou already have the flashlight.");
      }
    }

    // Room 5
    else if (current_room == 5) {
      printf("\nCongratulations! You made it out of the haunted house alive!");
      break;
    }

    // Get user input for next move
    char move;
    printf("\n\nWhere do you want to go next? (l for left, u for up): ");
    scanf(" %c", &move);

    // Update current room based on user input
    if (move == 'l') {
      if (current_room == 1) {
        printf("\nYou head down the hallway to the left.");
        current_room = 2;
      }
      else if (current_room == 2) {
        printf("\nYou head back to the first room.");
        current_room = 1;
      }
    }
    else if (move == 'u') {
      if (current_room == 1 || current_room == 2) {
        printf("\nYou head up the staircase.");
        current_room = 3;
      }
      else if (current_room == 3) {
        printf("\nYou go through the door at the end of the room.");
        current_room = 4;
      }
      else if (current_room == 4) {
        printf("\nYou climb up the hole in the ceiling.");
        current_room = 5;
      }
    }
  }

  return 0;
}