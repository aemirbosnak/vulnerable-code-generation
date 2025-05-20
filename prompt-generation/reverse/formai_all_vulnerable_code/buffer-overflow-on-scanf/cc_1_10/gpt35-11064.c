//FormAI DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 20
#define MAX_NAME_LENGTH 30

typedef struct {
  int id;
  char name[MAX_NAME_LENGTH];
  int occupied;
} Room;

int choose_option();
void add_room(Room *rooms, int *num_rooms);
void list_rooms(Room *rooms, int num_rooms);
Room *find_room(Room *rooms, int num_rooms);
void check_in(Room *rooms, int num_rooms);
void check_out(Room *rooms, int num_rooms);

int main() {
  Room rooms[MAX_ROOMS];
  int num_rooms = 0;
  int option;

  while(1) {
    option = choose_option();

    switch(option) {
      case 1:
        add_room(rooms, &num_rooms);
        break;
      case 2:
        list_rooms(rooms, num_rooms);
        break;
      case 3:
        check_in(rooms, num_rooms);
        break;
      case 4:
        check_out(rooms, num_rooms);
        break;
      case 5:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid option. Please choose again.\n");
        break;
    }

    printf("\n");
  }

  return 0;
}

int choose_option() {
  int option;

  printf("Choose an option:\n");
  printf("1. Add room\n");
  printf("2. List rooms\n");
  printf("3. Check in\n");
  printf("4. Check out\n");
  printf("5. Exit\n");

  scanf("%d", &option);

  return option;
}

void add_room(Room *rooms, int *num_rooms) {
  if(*num_rooms == MAX_ROOMS) {
    printf("Cannot add more rooms. Already at maximum capacity of %d rooms.\n", MAX_ROOMS);
    return;
  }

  Room new_room;
  new_room.id = (*num_rooms) + 1;

  printf("Enter name of new room: ");
  scanf("%s", new_room.name);

  new_room.occupied = 0;

  rooms[*num_rooms] = new_room;
  *num_rooms = *num_rooms + 1;

  printf("New room added. ID is %d.\n", new_room.id);
}

void list_rooms(Room *rooms, int num_rooms) {
  if(num_rooms == 0) {
    printf("No rooms available.\n");
    return;
  }

  printf("ID\tName\tOccupied\n");
  for(int i = 0; i < num_rooms; i++) {
    Room room = rooms[i];
    printf("%d\t%s\t%d\n", room.id, room.name, room.occupied);
  }
}

Room *find_room(Room *rooms, int num_rooms) {
  int id;

  printf("Enter room ID: ");
  scanf("%d", &id);

  for(int i = 0; i < num_rooms; i++) {
    if(rooms[i].id == id) {
      return &rooms[i];
    }
  }

  printf("Room with ID %d not found.\n", id);
  return NULL;
}

void check_in(Room *rooms, int num_rooms) {
  Room *room = find_room(rooms, num_rooms);
  
  if(room != NULL) {
    if(room->occupied) {
      printf("Room already occupied.\n");
    } else {
      room->occupied = 1;
      printf("Room checked in.\n");
    }
  }
}

void check_out(Room *rooms, int num_rooms) {
  Room *room = find_room(rooms, num_rooms);

  if(room != NULL) {
    if(!room->occupied) {
      printf("Room already vacant.\n");
    } else {
      room->occupied = 0;
      printf("Room checked out.\n");
    }
  }
}