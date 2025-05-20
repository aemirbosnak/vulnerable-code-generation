//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ROOMS 10

typedef struct {
  char* name;
  int num_exits;
  int* exits;
} room_t;

room_t rooms[NUM_ROOMS] = {
  {"The Great Hall", 3, {1, 2, 3}},
  {"The Dining Room", 4, {1, 4, 5, 6}},
  {"The Study", 2, {2, 7}},
  {"The Bedroom", 3, {3, 8, 9}},
  {"The Kitchen", 3, {4, 5, 10}},
  {"The Library", 3, {6, 7, 8}},
  {"The Basement", 2, {9, 10}},
  {"The Attic", 2, {5, 10}},
  {"The Garden", 3, {1, 6, 10}}
};

int main() {
  srand(time(NULL));

  int current_room = 0;
  int num_rooms = NUM_ROOMS;

  while (num_rooms > 0) {
    int exit = rooms[current_room].exits[rand() % rooms[current_room].num_exits];
    printf("You are in room %s.\n", rooms[current_room].name);
    printf("There are exits to the following rooms: ");
    for (int i = 0; i < rooms[current_room].num_exits; i++) {
      printf("%s ", rooms[rooms[current_room].exits[i]].name);
    }
    printf("\n");
    printf("Which room would you like to go to? ");
    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > NUM_ROOMS) {
      printf("Invalid choice. Please try again.\n");
      continue;
    }
    current_room = exit;
    num_rooms--;
  }

  printf("Congratulations, you have solved the haunted house!\n");

  return 0;
}