//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
  int number;
  int capacity;
  int guests;
  int occupied;
  int vacant;
};

struct Guest {
  int id;
  char name[50];
  char email[50];
  int room_number;
};

struct Hotel {
  struct Room* rooms;
  struct Guest* guests;
  int num_rooms;
  int num_guests;
};

void add_room(struct Hotel* hotel, int number, int capacity) {
  hotel->rooms[hotel->num_rooms].number = number;
  hotel->rooms[hotel->num_rooms].capacity = capacity;
  hotel->rooms[hotel->num_rooms].guests = 0;
  hotel->rooms[hotel->num_rooms].occupied = 0;
  hotel->rooms[hotel->num_rooms].vacant = capacity;
  hotel->num_rooms++;
}

void add_guest(struct Hotel* hotel, int id, char* name, char* email) {
  hotel->guests[hotel->num_guests].id = id;
  strcpy(hotel->guests[hotel->num_guests].name, name);
  strcpy(hotel->guests[hotel->num_guests].email, email);
  hotel->num_guests++;
}

void check_in(struct Hotel* hotel, int room_number, int guest_id) {
  for (int i = 0; i < hotel->num_rooms; i++) {
    if (hotel->rooms[i].number == room_number) {
      if (hotel->rooms[i].vacant > 0) {
        hotel->rooms[i].guests++;
        hotel->rooms[i].occupied++;
        hotel->rooms[i].vacant--;
        hotel->guests[guest_id].room_number = room_number;
        break;
      }
    }
  }
}

void check_out(struct Hotel* hotel, int room_number, int guest_id) {
  for (int i = 0; i < hotel->num_rooms; i++) {
    if (hotel->rooms[i].number == room_number) {
      if (hotel->rooms[i].guests > 0) {
        hotel->rooms[i].guests--;
        hotel->rooms[i].occupied--;
        hotel->rooms[i].vacant++;
        hotel->guests[guest_id].room_number = 0;
        break;
      }
    }
  }
}

int main() {
  struct Hotel hotel;
  hotel.num_rooms = 0;
  hotel.num_guests = 0;
  hotel.rooms = (struct Room*)malloc(sizeof(struct Room) * 10);
  hotel.guests = (struct Guest*)malloc(sizeof(struct Guest) * 100);

  add_room(&hotel, 101, 2);
  add_room(&hotel, 102, 3);
  add_room(&hotel, 103, 4);

  add_guest(&hotel, 1, "John", "john@example.com");
  add_guest(&hotel, 2, "Jane", "jane@example.com");
  add_guest(&hotel, 3, "Bob", "bob@example.com");

  check_in(&hotel, 101, 1);
  check_in(&hotel, 102, 2);
  check_in(&hotel, 103, 3);

  check_out(&hotel, 101, 1);
  check_out(&hotel, 102, 2);
  check_out(&hotel, 103, 3);

  free(hotel.rooms);
  free(hotel.guests);

  return 0;
}