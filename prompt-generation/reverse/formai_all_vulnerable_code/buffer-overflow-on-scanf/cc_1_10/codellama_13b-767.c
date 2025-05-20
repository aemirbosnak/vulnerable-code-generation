//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: immersive
// Hotel Management System

#include <stdio.h>
#include <stdlib.h>

// Structure for guest information
struct guest {
  char name[50];
  char room_number[10];
  char phone_number[15];
  char email[50];
};

// Structure for room information
struct room {
  char room_number[10];
  char type[20];
  int price;
};

// Function to display the menu
void display_menu() {
  printf("Hotel Management System\n");
  printf("----------------------\n");
  printf("1. Check-in\n");
  printf("2. Check-out\n");
  printf("3. Room information\n");
  printf("4. Guest information\n");
  printf("5. Exit\n");
}

// Function to check-in a guest
void check_in(struct guest* guest, struct room* room) {
  // Get guest information
  printf("Enter guest name: ");
  scanf("%s", guest->name);
  printf("Enter room number: ");
  scanf("%s", guest->room_number);
  printf("Enter phone number: ");
  scanf("%s", guest->phone_number);
  printf("Enter email: ");
  scanf("%s", guest->email);

  // Get room information
  printf("Enter room number: ");
  scanf("%s", room->room_number);
  printf("Enter room type: ");
  scanf("%s", room->type);
  printf("Enter room price: ");
  scanf("%d", &room->price);

  // Display confirmation message
  printf("Guest checked-in successfully!\n");
}

// Function to check-out a guest
void check_out(struct guest* guest, struct room* room) {
  // Get guest information
  printf("Enter guest name: ");
  scanf("%s", guest->name);
  printf("Enter room number: ");
  scanf("%s", guest->room_number);

  // Get room information
  printf("Enter room number: ");
  scanf("%s", room->room_number);
  printf("Enter room type: ");
  scanf("%s", room->type);
  printf("Enter room price: ");
  scanf("%d", &room->price);

  // Display confirmation message
  printf("Guest checked-out successfully!\n");
}

// Function to display room information
void display_room_info(struct room* room) {
  printf("Room Information\n");
  printf("---------------\n");
  printf("Room number: %s\n", room->room_number);
  printf("Room type: %s\n", room->type);
  printf("Room price: %d\n", room->price);
}

// Function to display guest information
void display_guest_info(struct guest* guest) {
  printf("Guest Information\n");
  printf("---------------\n");
  printf("Name: %s\n", guest->name);
  printf("Room number: %s\n", guest->room_number);
  printf("Phone number: %s\n", guest->phone_number);
  printf("Email: %s\n", guest->email);
}

int main() {
  // Initialize variables
  struct guest guest;
  struct room room;
  int choice;

  // Display menu
  display_menu();

  // Get user input
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Check user input
  switch (choice) {
    case 1:
      check_in(&guest, &room);
      break;
    case 2:
      check_out(&guest, &room);
      break;
    case 3:
      display_room_info(&room);
      break;
    case 4:
      display_guest_info(&guest);
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid input. Try again.\n");
      break;
  }

  return 0;
}