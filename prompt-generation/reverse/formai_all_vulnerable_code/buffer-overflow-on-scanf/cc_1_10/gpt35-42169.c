//FormAI DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ROOM {
  int room_number;
  int capacity;
  char room_type[20];
  float price;
  int availability;
};

int main() {
  int num_rooms;
  printf("Enter the number of rooms: ");
  scanf("%d", &num_rooms);
  struct ROOM hotel_rooms[num_rooms];
  
  // Initialize the rooms
  for(int i=0; i<num_rooms; i++) {
    hotel_rooms[i].room_number = i+1;
    hotel_rooms[i].availability = 1;
    printf("\nEnter details for Room %d:\n", hotel_rooms[i].room_number);
    printf("Capacity: ");
    scanf("%d", &hotel_rooms[i].capacity);
    printf("Room Type: ");
    scanf("%s", hotel_rooms[i].room_type);
    printf("Price per night: ");
    scanf("%f", &hotel_rooms[i].price);
  }

  // Display the list of rooms
  printf("\nList of Rooms:\n");
  printf("Room Number\tCapacity\tRoom Type\tPrice per night\n");
  for(int i=0; i<num_rooms; i++) {
    printf("%d\t\t%d\t\t%s\t\t%.2f\n", hotel_rooms[i].room_number, hotel_rooms[i].capacity, hotel_rooms[i].room_type, hotel_rooms[i].price);
  }

  // Book a room
  int choice;
  do {
    printf("\nEnter the room number you want to book (Enter 0 to exit): ");
    scanf("%d", &choice);
    if(choice == 0) {
      break;
    }
    if(hotel_rooms[choice-1].availability == 1) {
      printf("\nCongratulations! Room number %d has been booked for you.\n", choice);
      hotel_rooms[choice-1].availability = 0;
    } else {
      printf("\nSorry, this room is not available.\n");
    }
  } while(1);

  // Display the available rooms
  int available_rooms = 0;
  printf("\nList of Available Rooms:\n");
  printf("Room Number\tCapacity\tRoom Type\tPrice per night\n");
  for(int i=0; i<num_rooms; i++) {
    if(hotel_rooms[i].availability == 1) {
      available_rooms++;
      printf("%d\t\t%d\t\t%s\t\t%.2f\n", hotel_rooms[i].room_number, hotel_rooms[i].capacity, hotel_rooms[i].room_type, hotel_rooms[i].price);
    }
  }
  if(available_rooms == 0) {
    printf("\nSorry, there are no available rooms.\n");
  }

  return 0;
}