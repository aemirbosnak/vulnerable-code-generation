//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store hotel room details
typedef struct room {
  int room_number;
  char room_type;
  int is_occupied;
  float room_price;
} room;

// Structure to store guest details
typedef struct guest {
  char guest_name[50];
  char guest_address[100];
  char guest_phone[20];
  char guest_email[50];
  int room_number;
  int check_in_date;
  int check_out_date;
  float bill_amount;
} guest;

// Function to initialize the hotel rooms
void initialize_rooms(room *rooms, int num_rooms) {
  for (int i = 0; i < num_rooms; i++) {
    rooms[i].room_number = i + 1;
    rooms[i].room_type = 'S';
    rooms[i].is_occupied = 0;
    rooms[i].room_price = 100.00;
  }
}

// Function to check if a room is available
int is_room_available(room *rooms, int num_rooms, int room_number) {
  if (room_number < 1 || room_number > num_rooms) {
    return 0;
  }
  return !rooms[room_number - 1].is_occupied;
}

// Function to book a room
int book_room(room *rooms, int num_rooms, guest *guest) {
  int room_number;

  // Get the room number from the guest
  printf("Enter the room number you want to book: ");
  scanf("%d", &room_number);

  // Check if the room is available
  if (!is_room_available(rooms, num_rooms, room_number)) {
    printf("Sorry, the room is not available.\n");
    return 0;
  }

  // Get the guest details
  printf("Enter your name: ");
  scanf("%s", guest->guest_name);

  printf("Enter your address: ");
  scanf("%s", guest->guest_address);

  printf("Enter your phone number: ");
  scanf("%s", guest->guest_phone);

  printf("Enter your email address: ");
  scanf("%s", guest->guest_email);

  // Set the room number for the guest
  guest->room_number = room_number;

  // Set the check-in date for the guest
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);
  guest->check_in_date = tm->tm_mday;

  // Set the check-out date for the guest
  printf("Enter the number of nights you want to stay: ");
  int num_nights;
  scanf("%d", &num_nights);
  guest->check_out_date = guest->check_in_date + num_nights;

  // Calculate the bill amount for the guest
  guest->bill_amount = rooms[room_number - 1].room_price * num_nights;

  // Set the room as occupied
  rooms[room_number - 1].is_occupied = 1;

  // Print the booking details
  printf("Booking successful!\n");
  printf("Guest Name: %s\n", guest->guest_name);
  printf("Room Number: %d\n", guest->room_number);
  printf("Check-in Date: %d\n", guest->check_in_date);
  printf("Check-out Date: %d\n", guest->check_out_date);
  printf("Bill Amount: %.2f\n", guest->bill_amount);

  return 1;
}

// Function to check out a guest
int check_out_guest(room *rooms, int num_rooms, guest *guest) {
  int room_number;

  // Get the room number from the guest
  printf("Enter the room number you want to check out: ");
  scanf("%d", &room_number);

  // Check if the room is occupied
  if (is_room_available(rooms, num_rooms, room_number)) {
    printf("Sorry, the room is not occupied.\n");
    return 0;
  }

  // Set the room as unoccupied
  rooms[room_number - 1].is_occupied = 0;

  // Print the check-out details
  printf("Check-out successful!\n");
  printf("Guest Name: %s\n", guest->guest_name);
  printf("Room Number: %d\n", guest->room_number);
  printf("Bill Amount: %.2f\n", guest->bill_amount);

  return 1;
}

// Main function
int main() {
  // Initialize the hotel rooms
  room rooms[10];
  initialize_rooms(rooms, 10);

  // Create a guest
  guest guest;

  // Display the menu
  int choice;
  do {
    printf("\n***** Hotel Management System *****\n");
    printf("1. Book a room\n");
    printf("2. Check out a guest\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        book_room(rooms, 10, &guest);
        break;
      case 2:
        check_out_guest(rooms, 10, &guest);
        break;
      case 3:
        printf("Thank you for using the Hotel Management System!\n");
        break;
      default:
        printf("Invalid choice. Please enter a valid choice.\n");
    }
  } while (choice != 3);

  return 0;
}