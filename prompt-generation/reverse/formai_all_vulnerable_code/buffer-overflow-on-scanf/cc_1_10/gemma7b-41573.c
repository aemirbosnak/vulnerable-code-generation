//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 50

typedef struct Room {
  char name[20];
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
  int treasures;
} Room;

Room* generate_room(int num) {
  Room* room = malloc(sizeof(Room));
  room->name[0] = 'a' + num;
  room->north = NULL;
  room->south = NULL;
  room->east = NULL;
  room->west = NULL;
  room->treasures = rand() % 10;
  return room;
}

void connect_rooms(Room* room1, Room* room2) {
  room1->north = room2;
  room2->south = room1;
}

void play_game() {
  srand(time(NULL));
  Room* start_room = generate_room(0);
  connect_rooms(start_room, generate_room(1));
  connect_rooms(start_room, generate_room(2));
  connect_rooms(start_room, generate_room(3));
  connect_rooms(start_room, generate_room(4));

  Room* current_room = start_room;
  char direction;

  while (current_room->treasures > 0) {
    printf("You are in the %s room. There are %d treasures.\n", current_room->name, current_room->treasures);
    printf("Enter a direction (n, s, e, w): ");
    scanf("%c", &direction);

    switch (direction) {
      case 'n':
        current_room = current_room->north;
        break;
      case 's':
        current_room = current_room->south;
        break;
      case 'e':
        current_room = current_room->east;
        break;
      case 'w':
        current_room = current_room->west;
        break;
    }
  }

  printf("You have found all the treasures!");
}

int main() {
  play_game();
  return 0;
}