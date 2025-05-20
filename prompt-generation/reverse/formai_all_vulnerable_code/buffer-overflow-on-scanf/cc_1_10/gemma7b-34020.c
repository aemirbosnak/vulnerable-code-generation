//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
  char name[20];
  int room_num;
  int num_nights;
  struct Guest* next;
} Guest;

typedef struct Room {
  int room_num;
  int occupancy;
  struct Room* next;
} Room;

Guest* insert_guest(Guest* head) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  printf("Enter your name: ");
  scanf("%s", new_guest->name);
  printf("Enter your room number: ");
  scanf("%d", &new_guest->room_num);
  printf("Enter the number of nights you will be staying: ");
  scanf("%d", &new_guest->num_nights);
  new_guest->next = head;
  return new_guest;
}

Room* insert_room(Room* head) {
  Room* new_room = (Room*)malloc(sizeof(Room));
  new_room->room_num = head->room_num + 1;
  new_room->occupancy = 0;
  new_room->next = head;
  return new_room;
}

int main() {
  Guest* head = NULL;
  Room* head_room = NULL;

  // Insert guests and rooms
  insert_guest(head);
  insert_guest(head);
  insert_room(head_room);
  insert_room(head_room);

  // Check if the room is occupied
  printf("Enter the room number: ");
  int room_num;
  scanf("%d", &room_num);

  Room* current_room = head_room;
  while (current_room) {
    if (current_room->room_num == room_num) {
      if (current_room->occupancy) {
        printf("The room is occupied.\n");
      } else {
        current_room->occupancy = 1;
        printf("The room is available.\n");
      }
    }
    current_room = current_room->next;
  }

  return 0;
}