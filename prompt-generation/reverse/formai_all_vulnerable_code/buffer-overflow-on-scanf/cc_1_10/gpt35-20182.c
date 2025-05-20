//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void start_game();
void enter_room();
void examine_sword();
void examine_door();
void examine_wall();
void end_game();

// global variables
int has_sword = 0;

int main() {
  start_game();
  return 0;
}

void start_game() {
  printf("Welcome to the Adventure Game!\n");
  printf("You find yourself in a room with no windows and only one door.\n");
  enter_room();
}

void enter_room() {
  char choice;
  printf("What would you like to do?\n");
  printf("1. Examine the sword on the wall\n");
  printf("2. Examine the door\n");
  printf("3. Examine the wall\n");
  printf("4. Quit game\n");
  scanf(" %c", &choice);

  switch (choice) {
    case '1': examine_sword(); break;
    case '2': examine_door(); break;
    case '3': examine_wall(); break;
    case '4': end_game(); break;
    default: printf("Invalid choice, please try again\n"); enter_room();
  }
}

void examine_sword() {
  printf("You see a sword hanging on the wall, it looks sharp and deadly.\n");
  printf("Do you want to take it?\n");
  char choice;
  scanf(" %c", &choice);
  if (choice == 'y') {
    has_sword = 1;
    printf("You take the sword from the wall\n");
  } else {
    printf("You leave the sword on the wall\n");
  }
  enter_room();
}

void examine_door() {
  if (has_sword) {
    printf("You approach the door and swing your sword, slicing through the lock.\n");
    printf("The door swings open and you escape the room, congrats you win!\n");
    end_game();
  } else {
    printf("The door is locked, you need a weapon to break it down\n");
    enter_room();
  }
}

void examine_wall() {
  printf("You examine the wall, but find nothing of interest.\n");
  enter_room();
}

void end_game() {
  printf("Thanks for playing!\n");
  exit(0);
}