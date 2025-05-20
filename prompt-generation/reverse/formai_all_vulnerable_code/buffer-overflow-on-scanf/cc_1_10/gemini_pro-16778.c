//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Structure to store guest details
typedef struct guest {
  int room_number;
  char name[50];
  char address[100];
  char phone_number[20];
  char email_address[50];
} guest;

// Function to add a new guest
void add_guest(guest *guests, int *num_guests) {
  // Get guest details from the user
  printf("Enter room number: ");
  scanf("%d", &guests[*num_guests].room_number);
  printf("Enter guest name: ");
  scanf("%s", guests[*num_guests].name);
  printf("Enter guest address: ");
  scanf("%s", guests[*num_guests].address);
  printf("Enter guest phone number: ");
  scanf("%s", guests[*num_guests].phone_number);
  printf("Enter guest email address: ");
  scanf("%s", guests[*num_guests].email_address);

  // Increment the number of guests
  (*num_guests)++;
}

// Function to display all guests
void display_guests(guest *guests, int num_guests) {
  // Loop through all guests and display their details
  for (int i = 0; i < num_guests; i++) {
    printf("Room number: %d\n", guests[i].room_number);
    printf("Guest name: %s\n", guests[i].name);
    printf("Guest address: %s\n", guests[i].address);
    printf("Guest phone number: %s\n", guests[i].phone_number);
    printf("Guest email address: %s\n", guests[i].email_address);
    printf("\n");
  }
}

// Function to search for a guest by room number
void search_guest(guest *guests, int num_guests) {
  // Get the room number from the user
  int room_number;
  printf("Enter room number: ");
  scanf("%d", &room_number);

  // Loop through all guests and search for the guest with the given room number
  for (int i = 0; i < num_guests; i++) {
    if (guests[i].room_number == room_number) {
      // Display the guest details
      printf("Room number: %d\n", guests[i].room_number);
      printf("Guest name: %s\n", guests[i].name);
      printf("Guest address: %s\n", guests[i].address);
      printf("Guest phone number: %s\n", guests[i].phone_number);
      printf("Guest email address: %s\n", guests[i].email_address);
      printf("\n");
      return;
    }
  }

  // If the guest is not found, display an error message
  printf("Guest not found.\n");
}

// Function to delete a guest by room number
void delete_guest(guest *guests, int *num_guests) {
  // Get the room number from the user
  int room_number;
  printf("Enter room number: ");
  scanf("%d", &room_number);

  // Loop through all guests and search for the guest with the given room number
  for (int i = 0; i < *num_guests; i++) {
    if (guests[i].room_number == room_number) {
      // Shift all guests after the deleted guest to the left
      for (int j = i; j < *num_guests - 1; j++) {
        guests[j] = guests[j + 1];
      }

      // Decrement the number of guests
      (*num_guests)--;

      // Display a success message
      printf("Guest deleted successfully.\n");
      return;
    }
  }

  // If the guest is not found, display an error message
  printf("Guest not found.\n");
}

// Main function
int main() {
  // Create an array of guests
  guest guests[100];

  // Initialize the number of guests to 0
  int num_guests = 0;

  // Display a welcome message
  printf("Welcome to the Hotel Management System!\n");

  // Loop until the user chooses to exit
  int choice;
  do {
    // Display the menu
    printf("1. Add a new guest\n");
    printf("2. Display all guests\n");
    printf("3. Search for a guest by room number\n");
    printf("4. Delete a guest by room number\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected action
    switch (choice) {
      case 1:
        add_guest(guests, &num_guests);
        break;
      case 2:
        display_guests(guests, num_guests);
        break;
      case 3:
        search_guest(guests, num_guests);
        break;
      case 4:
        delete_guest(guests, &num_guests);
        break;
      case 5:
        printf("Thank you for using the Hotel Management System!\n");
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);

  return 0;
}