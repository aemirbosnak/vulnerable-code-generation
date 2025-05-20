//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: automated
// Hotel Management System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a guest
typedef struct {
  char* name;
  int room_number;
  int booking_id;
} Guest;

// Struct to represent a room
typedef struct {
  int number;
  int capacity;
  int occupancy;
  Guest* guests;
} Room;

// Struct to represent a hotel
typedef struct {
  int num_rooms;
  Room* rooms;
} Hotel;

// Function to create a new hotel
Hotel* create_hotel(int num_rooms) {
  Hotel* hotel = malloc(sizeof(Hotel));
  hotel->num_rooms = num_rooms;
  hotel->rooms = malloc(sizeof(Room) * num_rooms);
  for (int i = 0; i < num_rooms; i++) {
    hotel->rooms[i].number = i + 1;
    hotel->rooms[i].capacity = 2;
    hotel->rooms[i].occupancy = 0;
    hotel->rooms[i].guests = malloc(sizeof(Guest) * hotel->rooms[i].capacity);
  }
  return hotel;
}

// Function to add a guest to a room
void add_guest(Hotel* hotel, Guest guest) {
  for (int i = 0; i < hotel->num_rooms; i++) {
    if (hotel->rooms[i].occupancy < hotel->rooms[i].capacity) {
      hotel->rooms[i].guests[hotel->rooms[i].occupancy] = guest;
      hotel->rooms[i].occupancy++;
      break;
    }
  }
}

// Function to remove a guest from a room
void remove_guest(Hotel* hotel, int room_number, int booking_id) {
  for (int i = 0; i < hotel->num_rooms; i++) {
    if (hotel->rooms[i].number == room_number) {
      for (int j = 0; j < hotel->rooms[i].occupancy; j++) {
        if (hotel->rooms[i].guests[j].booking_id == booking_id) {
          hotel->rooms[i].guests[j] = hotel->rooms[i].guests[hotel->rooms[i].occupancy - 1];
          hotel->rooms[i].occupancy--;
          break;
        }
      }
    }
  }
}

// Function to print the details of a guest
void print_guest(Guest guest) {
  printf("Name: %s\nRoom Number: %d\nBooking ID: %d\n", guest.name, guest.room_number, guest.booking_id);
}

// Function to print the details of a room
void print_room(Room room) {
  printf("Room Number: %d\nCapacity: %d\nOccupancy: %d\n", room.number, room.capacity, room.occupancy);
}

// Function to print the details of a hotel
void print_hotel(Hotel* hotel) {
  for (int i = 0; i < hotel->num_rooms; i++) {
    printf("Room %d: ", i + 1);
    print_room(hotel->rooms[i]);
    printf("Guests: ");
    for (int j = 0; j < hotel->rooms[i].occupancy; j++) {
      print_guest(hotel->rooms[i].guests[j]);
    }
    printf("\n");
  }
}

int main() {
  Hotel* hotel = create_hotel(5);

  // Add guests to the hotel
  add_guest(hotel, (Guest){"John Doe", 1, 1001});
  add_guest(hotel, (Guest){"Jane Doe", 2, 1002});
  add_guest(hotel, (Guest){"Bob Smith", 3, 1003});
  add_guest(hotel, (Guest){"Alice Johnson", 4, 1004});
  add_guest(hotel, (Guest){"John Johnson", 5, 1005});

  // Remove a guest from the hotel
  remove_guest(hotel, 2, 1002);

  // Print the details of the hotel
  print_hotel(hotel);

  // Free the memory allocated by the hotel
  for (int i = 0; i < hotel->num_rooms; i++) {
    free(hotel->rooms[i].guests);
  }
  free(hotel->rooms);
  free(hotel);

  return 0;
}