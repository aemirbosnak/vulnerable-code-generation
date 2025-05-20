//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: distributed
#include <stdio.h>

void room1();
void room2();
void room3();
void gameOver();

int main() {
  room1();
  return 0;
}

void room1() {
  char choice;

  printf("You find yourself in a dark room. There is a door to your left and a door to your right. Which do you choose?\n");
  printf("L) Left door\nR) Right door\n");

  scanf("%c", &choice);

  switch (choice) {
    case 'L':
      room2();
      break;
    case 'R':
      room3();
      break;
    default:
      printf("Invalid choice.\n");
      room1();
  }
}

void room2() {
  char choice;

  printf("You enter a room with a table and a book on it. There is a door on the other side of the room. Do you:\n");
  printf("T) Read the book\nD) Go through the door\n");

  scanf(" %c", &choice);

  if (choice == 'T') {
    printf("The book contains codes for an enigma machine\n");
    room2();
  } else if (choice == 'D') {
    room3();
  } else {
    printf("Invalid choice.\n");
    room2();
  }
}

void room3() {
  printf("You find yourself in a room with a treasure chest. Do you:\n");
  printf("O) Open the chest\nL) Leave the room\n");

  char choice;
  scanf(" %c", &choice);

  if (choice == 'O') {
    gameOver();
  } else if (choice == 'L') {
    room1();
  } else {
    printf("Invalid choice.\n");
    room3();
  }
}

void gameOver() {
  printf("You open the chest and find a cursed amulet! GAME OVER.\n");
}