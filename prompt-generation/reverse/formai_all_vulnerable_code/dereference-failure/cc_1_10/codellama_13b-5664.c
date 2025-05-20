//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
// Hotel Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int room_number;
  char guest_name[50];
  char check_in_date[11];
  char check_out_date[11];
} Room;

typedef struct {
  Room* rooms;
  int num_rooms;
  int capacity;
} Hotel;

Hotel* create_hotel(int capacity) {
  Hotel* hotel = malloc(sizeof(Hotel));
  hotel->rooms = malloc(sizeof(Room) * capacity);
  hotel->num_rooms = 0;
  hotel->capacity = capacity;
  return hotel;
}

void add_room(Hotel* hotel, int room_number, char* guest_name, char* check_in_date, char* check_out_date) {
  if (hotel->num_rooms >= hotel->capacity) {
    printf("Hotel is full\n");
    return;
  }
  Room* room = &hotel->rooms[hotel->num_rooms++];
  room->room_number = room_number;
  strcpy(room->guest_name, guest_name);
  strcpy(room->check_in_date, check_in_date);
  strcpy(room->check_out_date, check_out_date);
}

void remove_room(Hotel* hotel, int room_number) {
  if (hotel->num_rooms <= 0) {
    printf("Hotel is empty\n");
    return;
  }
  Room* room = &hotel->rooms[hotel->num_rooms--];
  if (room->room_number != room_number) {
    printf("Room not found\n");
    return;
  }
  strcpy(room->guest_name, "");
  strcpy(room->check_in_date, "");
  strcpy(room->check_out_date, "");
}

void display_rooms(Hotel* hotel) {
  printf("Rooms:\n");
  for (int i = 0; i < hotel->num_rooms; i++) {
    Room* room = &hotel->rooms[i];
    printf("Room %d: %s, %s - %s\n", room->room_number, room->guest_name, room->check_in_date, room->check_out_date);
  }
}

int main() {
  Hotel* hotel = create_hotel(5);
  add_room(hotel, 101, "John Doe", "2022-03-10", "2022-03-15");
  add_room(hotel, 102, "Jane Doe", "2022-03-11", "2022-03-16");
  add_room(hotel, 103, "John Smith", "2022-03-12", "2022-03-17");
  display_rooms(hotel);
  remove_room(hotel, 102);
  display_rooms(hotel);
  return 0;
}