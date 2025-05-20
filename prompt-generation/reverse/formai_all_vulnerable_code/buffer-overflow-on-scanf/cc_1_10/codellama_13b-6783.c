//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: systematic
/*
 * Hotel Management System
 *
 * This program allows users to book rooms and check their status.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ROOMS 100
#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 256
#define MAX_ROOM_NAME_LENGTH 20

// Define structures
typedef struct {
  char name[MAX_NAME_LENGTH];
  int room_number;
  int arrival_date;
  int departure_date;
} Customer;

typedef struct {
  char name[MAX_ROOM_NAME_LENGTH];
  int number;
  int status;
} Room;

// Define functions
void print_menu();
void book_room(Customer *customers, Room *rooms, int *number_of_customers);
void check_status(Customer *customers, Room *rooms, int *number_of_customers);

int main() {
  // Initialize arrays
  Customer customers[MAX_CUSTOMERS];
  Room rooms[MAX_ROOMS];
  int number_of_customers = 0;

  // Print menu
  print_menu();

  // Get user input
  int choice;
  scanf("%d", &choice);

  // Call functions based on user input
  switch (choice) {
    case 1:
      book_room(customers, rooms, &number_of_customers);
      break;
    case 2:
      check_status(customers, rooms, &number_of_customers);
      break;
    case 3:
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
      return 1;
  }

  return 0;
}

void print_menu() {
  printf("Welcome to the Hotel Management System.\n");
  printf("Please select an option:\n");
  printf("1. Book a room\n");
  printf("2. Check room status\n");
  printf("3. Exit\n");
}

void book_room(Customer *customers, Room *rooms, int *number_of_customers) {
  // Ask for customer name and arrival date
  printf("Enter your name: ");
  scanf("%s", customers[*number_of_customers].name);
  printf("Enter your arrival date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &customers[*number_of_customers].arrival_date);

  // Find an available room
  int room_number = 0;
  for (int i = 0; i < MAX_ROOMS; i++) {
    if (rooms[i].status == 0) {
      room_number = i;
      break;
    }
  }

  // Book the room if available
  if (room_number != 0) {
    rooms[room_number].status = 1;
    customers[*number_of_customers].room_number = room_number;
    customers[*number_of_customers].departure_date = customers[*number_of_customers].arrival_date + 1;
    (*number_of_customers)++;
    printf("Room %d has been booked for you.\n", room_number);
  } else {
    printf("Sorry, all rooms are booked. Please try again later.\n");
  }
}

void check_status(Customer *customers, Room *rooms, int *number_of_customers) {
  // Ask for customer name
  printf("Enter your name: ");
  char name[MAX_NAME_LENGTH];
  scanf("%s", name);

  // Find the customer in the array
  int customer_index = -1;
  for (int i = 0; i < *number_of_customers; i++) {
    if (strcmp(name, customers[i].name) == 0) {
      customer_index = i;
      break;
    }
  }

  // Print room status if found
  if (customer_index != -1) {
    printf("Your room status is: ");
    if (rooms[customers[customer_index].room_number].status == 0) {
      printf("Vacant\n");
    } else {
      printf("Occupied\n");
    }
  } else {
    printf("Sorry, no such customer found.\n");
  }
}