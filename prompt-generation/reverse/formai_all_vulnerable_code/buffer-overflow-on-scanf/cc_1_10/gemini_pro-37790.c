//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store guest information
typedef struct guest {
  char name[50];
  char address[100];
  char phone[20];
  int room_number;
  int num_nights;
  float bill_amount;
} guest;

// Function to display the main menu
void display_menu() {
  printf("\n------ Hotel Management System ------\n");
  printf("1. Check In\n");
  printf("2. Check Out\n");
  printf("3. Display Guest List\n");
  printf("4. Search Guest by Name\n");
  printf("5. Exit\n");
  printf("Enter your choice: ");
}

// Function to check in a guest
void check_in(guest *guests, int *num_guests) {
  // Get guest information
  printf("\nEnter guest name: ");
  scanf("%s", guests[*num_guests].name);
  printf("Enter guest address: ");
  scanf(" %[^\n]%*c", guests[*num_guests].address);  // Read address with spaces
  printf("Enter guest phone number: ");
  scanf("%s", guests[*num_guests].phone);
  printf("Enter room number: ");
  scanf("%d", &guests[*num_guests].room_number);
  printf("Enter number of nights: ");
  scanf("%d", &guests[*num_guests].num_nights);

  // Calculate bill amount
  guests[*num_guests].bill_amount = guests[*num_guests].num_nights * 100.0;

  // Increment the number of guests
  (*num_guests)++;
}

// Function to check out a guest
void check_out(guest *guests, int *num_guests) {
  int room_number;

  // Get room number
  printf("\nEnter room number of guest checking out: ");
  scanf("%d", &room_number);

  // Find the guest with the given room number
  int guest_index = -1;
  for (int i = 0; i < *num_guests; i++) {
    if (guests[i].room_number == room_number) {
      guest_index = i;
      break;
    }
  }

  // If guest not found, display error message
  if (guest_index == -1) {
    printf("Guest not found.\n");
    return;
  }

  // Print guest information and bill amount
  printf("\nGuest Name: %s\n", guests[guest_index].name);
  printf("Guest Address: %s\n", guests[guest_index].address);
  printf("Guest Phone: %s\n", guests[guest_index].phone);
  printf("Room Number: %d\n", guests[guest_index].room_number);
  printf("Number of Nights: %d\n", guests[guest_index].num_nights);
  printf("Bill Amount: %.2f\n", guests[guest_index].bill_amount);

  // Remove guest from the list
  for (int i = guest_index; i < *num_guests - 1; i++) {
    guests[i] = guests[i + 1];
  }

  // Decrement the number of guests
  (*num_guests)--;
}

// Function to display the list of guests
void display_guest_list(guest *guests, int num_guests) {
  printf("\n------ Guest List ------\n");
  for (int i = 0; i < num_guests; i++) {
    printf("Guest Name: %s\n", guests[i].name);
    printf("Guest Address: %s\n", guests[i].address);
    printf("Guest Phone: %s\n", guests[i].phone);
    printf("Room Number: %d\n", guests[i].room_number);
    printf("Number of Nights: %d\n", guests[i].num_nights);
    printf("Bill Amount: %.2f\n", guests[i].bill_amount);
    printf("\n");
  }
}

// Function to search for a guest by name
void search_guest_by_name(guest *guests, int num_guests) {
  char name[50];

  // Get guest name
  printf("\nEnter guest name to search for: ");
  scanf("%s", name);

  // Find the guest with the given name
  int guest_index = -1;
  for (int i = 0; i < num_guests; i++) {
    if (strcmp(guests[i].name, name) == 0) {
      guest_index = i;
      break;
    }
  }

  // If guest not found, display error message
  if (guest_index == -1) {
    printf("Guest not found.\n");
    return;
  }

  // Print guest information and bill amount
  printf("\nGuest Name: %s\n", guests[guest_index].name);
  printf("Guest Address: %s\n", guests[guest_index].address);
  printf("Guest Phone: %s\n", guests[guest_index].phone);
  printf("Room Number: %d\n", guests[guest_index].room_number);
  printf("Number of Nights: %d\n", guests[guest_index].num_nights);
  printf("Bill Amount: %.2f\n", guests[guest_index].bill_amount);
}

int main() {
  // Initialize array of guests
  guest guests[100];
  int num_guests = 0;

  // Display the main menu and get user choice
  int choice;
  do {
    display_menu();
    scanf("%d", &choice);

    // Perform the selected action
    switch (choice) {
      case 1:
        check_in(guests, &num_guests);
        break;
      case 2:
        check_out(guests, &num_guests);
        break;
      case 3:
        display_guest_list(guests, num_guests);
        break;
      case 4:
        search_guest_by_name(guests, num_guests);
        break;
      case 5:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);

  return 0;
}