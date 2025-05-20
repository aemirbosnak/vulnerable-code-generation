//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void play_game() {
  char name[20];
  printf("Hello, what is your name?\n");
  scanf("%s", name);

  int room_num = 1;
  char room_name[20];

  switch (room_num) {
    case 1:
      strcpy(room_name, "The Foyer");
      printf("You are in the foyer. There is a grand piano and a painting of a portrait.\n");
      break;
    case 2:
      strcpy(room_name, "The Living Room");
      printf("You are in the living room. There is a sofa, a coffee table, and a television.\n");
      break;
    case 3:
      strcpy(room_name, "The Dining Room");
      printf("You are in the dining room. There is a table, chairs, and a buffet.\n");
      break;
  }

  printf("What would you like to do? (e.g. go north, south, east, west)\n");
  char input[20];
  scanf("%s", input);

  // Move to the next room
  if (strcmp(input, "go north") == 0) {
    room_num++;
  } else if (strcmp(input, "go south") == 0) {
    room_num--;
  } else if (strcmp(input, "go east") == 0) {
    room_num++;
  } else if (strcmp(input, "go west") == 0) {
    room_num--;
  }

  // Play the game again
  play_game();
}

int main() {
  play_game();

  return 0;
}