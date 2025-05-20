//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 20

typedef struct {
  char name[50];
  char email[50];
  char phone[20];
  int room_number;
} Guest;

typedef struct {
  char name[50];
  char location[50];
  int capacity;
  int price;
} Room;

int main() {
  Room rooms[MAX_ROOMS];
  Guest guests[MAX_GUESTS];

  // Initialize rooms and guests
  int i;
  for (i = 0; i < MAX_ROOMS; i++) {
    strcpy(rooms[i].name, "Room ");
    strcat(rooms[i].name, i + 1);
    strcpy(rooms[i].location, "Location ");
    strcat(rooms[i].location, i + 1);
    rooms[i].capacity = 100;
    rooms[i].price = 100;
  }

  for (i = 0; i < MAX_GUESTS; i++) {
    strcpy(guests[i].name, "Guest ");
    strcat(guests[i].name, i + 1);
    strcpy(guests[i].email, "guest");
    strcat(guests[i].email, i + 1);
    strcpy(guests[i].phone, "1234567890");
    guests[i].room_number = 0;
  }

  // Display available rooms
  printf("Available rooms:\n");
  for (i = 0; i < MAX_ROOMS; i++) {
    printf("%s (%s): %d/%d\n", rooms[i].name, rooms[i].location, rooms[i].capacity, rooms[i].price);
  }

  // Display available guests
  printf("Available guests:\n");
  for (i = 0; i < MAX_GUESTS; i++) {
    printf("%s (%s): %s (%s)\n", guests[i].name, guests[i].email, guests[i].phone);
  }

  // Assign guests to rooms
  for (i = 0; i < MAX_GUESTS; i++) {
    int room_index = rand() % MAX_ROOMS;
    if (rooms[room_index].capacity > 0) {
      rooms[room_index].capacity--;
      guests[i].room_number = room_index + 1;
    }
  }

  // Display assigned rooms and guests
  printf("Assigned rooms:\n");
  for (i = 0; i < MAX_ROOMS; i++) {
    if (rooms[i].capacity == 0) {
      printf("%s (%s): %d/%d\n", rooms[i].name, rooms[i].location, rooms[i].capacity, rooms[i].price);
    }
  }

  printf("Assigned guests:\n");
  for (i = 0; i < MAX_GUESTS; i++) {
    if (guests[i].room_number > 0) {
      printf("%s (%s): Room %d\n", guests[i].name, guests[i].email, guests[i].room_number);
    }
  }

  return 0;
}