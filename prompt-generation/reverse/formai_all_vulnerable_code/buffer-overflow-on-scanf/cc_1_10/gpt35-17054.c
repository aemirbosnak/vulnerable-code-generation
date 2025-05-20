//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for room types
#define SINGLE 1
#define DOUBLE 2
#define SUITE 3

// Define a struct to store room information
struct Room {
  int roomNumber;
  int roomType;
  char guestName[50];
  float costPerNight;
};

// Define an array to store all rooms in the hotel
struct Room rooms[100];

// Define a function to check if a given room number is valid
int validateRoomNumber(int roomNumber) {
  int i;
  for (i = 0; i < 100; i++) {
    if (rooms[i].roomNumber == roomNumber) {
      return 1; // Room number is valid
    }
  }
  return 0; // Room number is invalid
}

// Define a function to find the index of a room in the rooms array
int findRoomIndex(int roomNumber) {
  int i;
  for (i = 0; i < 100; i++) {
    if (rooms[i].roomNumber == roomNumber) {
      return i; // Found the room, return its index
    }
  }
  return -1; // Room not found
}

// Define a function to display the menu and get user input
int menu() {
  int choice;
  printf("Welcome to C Hotel Management System\n\n");
  printf("1. Check in guest\n");
  printf("2. Check out guest\n");
  printf("3. View guest list\n");
  printf("4. Exit\n\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

// Define a function to handle checking in a guest
void checkInGuest() {
  int roomNumber;
  int roomType;
  char guestName[50];
  float costPerNight;

  // Get room number from user
  printf("Enter room number: ");
  scanf("%d", &roomNumber);

  // Check if room number is valid
  if (validateRoomNumber(roomNumber)) {
    printf("Room number is not available\n");
    return;
  }

  // Get room type from user
  printf("Enter room type (1=single, 2=double, 3=suite): ");
  scanf("%d", &roomType);

  // Get guest name from user
  printf("Enter guest name: ");
  scanf("%s", guestName);

  // Get cost per night from user
  printf("Enter cost per night: ");
  scanf("%f", &costPerNight);

  // Find the first empty room in the rooms array
  int i, roomIndex = -1;
  for (i = 0; i < 100; i++) {
    if (rooms[i].roomNumber == 0) {
      roomIndex = i;
      break;
    }
  }

  // Add the new room to the rooms array
  rooms[roomIndex].roomNumber = roomNumber;
  rooms[roomIndex].roomType = roomType;
  strcpy(rooms[roomIndex].guestName, guestName);
  rooms[roomIndex].costPerNight = costPerNight;

  printf("Guest checked in successfully!\n");
}

// Define a function to handle checking out a guest
void checkOutGuest() {
  int roomNumber;

  // Get room number from user
  printf("Enter room number: ");
  scanf("%d", &roomNumber);

  // Find the room in the rooms array
  int roomIndex = findRoomIndex(roomNumber);
  if (roomIndex == -1) {
    printf("Room not found\n");
    return;
  }

  // Remove the guest from the room
  rooms[roomIndex].roomNumber = 0;
  rooms[roomIndex].roomType = 0;
  strcpy(rooms[roomIndex].guestName, "");
  rooms[roomIndex].costPerNight = 0;

  printf("Guest checked out successfully\n");
}

// Define a function to display the guest list
void viewGuestList() {
  printf("Room\tRoom Type\tGuest Name\tCost per Night\n");
  int i;
  for (i = 0; i < 100; i++) {
    if (rooms[i].roomNumber != 0) {
      printf("%d\t", rooms[i].roomNumber);
      switch (rooms[i].roomType) {
        case SINGLE:
          printf("Single\t\t");
          break;
        case DOUBLE:
          printf("Double\t\t");
          break;
        case SUITE:
          printf("Suite\t\t");
          break;
        default:
          printf("Unknown\t\t");
          break;
      }
      printf("%s\t\t%.2f\n", rooms[i].guestName, rooms[i].costPerNight);
    }
  }
}

int main() {
  int choice;
  while ((choice = menu()) != 4) {
    switch (choice) {
      case 1:
        checkInGuest();
        break;
      case 2:
        checkOutGuest();
        break;
      case 3:
        viewGuestList();
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  printf("Thank you for using C Hotel Management System\n");
  return 0;
}