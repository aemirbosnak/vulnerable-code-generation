//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>

int main() {
  char name[20];
  int room = 0;

  printf("Welcome to the Text-Based Adventure Game!\n");
  printf("What is your name?\n");

  scanf("%s", name);

  printf("Hello, %s! You find yourself in a dark room. \n", name);

  while (room >= 0) {
    switch (room) {
      case 0:
        printf("You see a ladder leading up to a trap door and a door leading to the east. Which one do you take?\n");
        break;
      case 1:
        printf("You enter a room with a chest in the center. There is a door to the north and south. Do you open the chest, go north, or go south?\n");
        break;
      case 2:
        printf("You find yourself in a maze of twisty passages, all alike. You can go north, east, south, or west. Which way do you choose?\n");
        break;
      case 3:
        printf("You enter a room with a pedestal. Upon the pedestal lays a great sword. Do you pick up the sword and risk harm? Or do you leave it be and exit to the east?\n");
        break;
      case 4:
        printf("Congratulations! You have found the exit and defeated the dragon. Thanks for playing, %s!\n", name);
        return 0;
    }

    char action[20];
    scanf("%s", action);

    if (room == 0 && strcmp(action, "ladder") == 0) {
      printf("You climb up the ladder and find yourself in a room with a chest. There is a door to the north. Do you want to open the chest or go north?\n");
      room = 1;
    }
    else if (room == 0 && strcmp(action, "door") == 0) {
      printf("You enter the room to the east and encounter a fierce dragon. Fight or flight?\n");
      room = 2;
    }
    else if (room == 1 && strcmp(action, "north") == 0) {
      printf("You enter a small room with a key hanging from the ceiling. Do you grab the key or leave and go south?\n");
      room = 3;
    }
    else if (room == 1 && strcmp(action, "chest") == 0) {
      printf("The chest is trapped! You take damage and find nothing of value.");
    }
    else if (room == 1 && strcmp(action, "south") == 0) {
      printf("You exit to the south and find yourself in a circular room. There are doors to the west and east. Which way do you go?\n");
      room = -1;
    }
    else if (room == 2 && strcmp(action, "north") == 0) {
      printf("You find yourself in a room with a dragon guarding a key. Defeat the dragon and take the key, or flee and retrace your steps?\n");
      room = -1;
    }
    else if (room == 2 && strcmp(action, "east") == 0) {
      printf("You wander the maze until you stumble upon a hidden passage to the south. Do you take it or keep wandering?\n");
      room = -1;
    }
    else if (room == 2 && strcmp(action, "south") == 0) {
      printf("You find yourself in a room with a deadly trap. You narrowly avoid it and come face-to-face with the dragon guarding the exit. Fight or flight?\n");
      room = -1;
    }
    else if (room == 2 && strcmp(action, "west") == 0) {
      printf("You wander the maze until you stumble upon a dead end. You must retrace your steps.\n");
      room = 2;
    }
    else if (room == 3 && strcmp(action, "grab") == 0) {
      printf("You take the key and proceed through the door to the east. You encounter a dragon guarding the exit. Fight or flight?\n");
      room = -1;
    }
    else if (room == 3 && strcmp(action, "leave") == 0) {
      printf("You exit to the east and find yourself in a room with a pedestal. There is a great sword laying upon it. Do you pick it up or leave it be?\n");
      room = 4;
    }
    else {
      printf("Invalid input. Try again.\n");
    }
  }

  return 0;
}