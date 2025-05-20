//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: irregular
/*
 * Hotel Management System
 *
 * This program is an example of a simple hotel management system. It allows
 * guests to check in and out, and to pay for their stay. It also allows
 * the hotel staff to view and manage the guest information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the guest structure
struct guest {
  char name[20];
  char room[10];
  int days;
  float cost;
};

// Define the hotel staff structure
struct staff {
  char name[20];
  char position[10];
  int salary;
};

// Function prototypes
void print_menu();
void check_in(struct guest *guest);
void check_out(struct guest *guest);
void view_guests(struct guest *guest);
void view_staff(struct staff *staff);

int main() {
  // Declare variables
  int choice;
  struct guest guest;
  struct staff staff;

  // Print the menu
  print_menu();

  // Get the user's choice
  scanf("%d", &choice);

  // Check if the choice is valid
  if (choice < 1 || choice > 4) {
    printf("Invalid choice. Please try again.\n");
    return 1;
  }

  // Call the appropriate function
  switch (choice) {
    case 1:
      check_in(&guest);
      break;
    case 2:
      check_out(&guest);
      break;
    case 3:
      view_guests(&guest);
      break;
    case 4:
      view_staff(&staff);
      break;
  }

  return 0;
}

void print_menu() {
  printf("Welcome to the Hotel Management System\n");
  printf("1. Check in\n");
  printf("2. Check out\n");
  printf("3. View guests\n");
  printf("4. View staff\n");
  printf("Enter your choice: ");
}

void check_in(struct guest *guest) {
  printf("Enter the guest's name: ");
  scanf("%s", guest->name);
  printf("Enter the room number: ");
  scanf("%s", guest->room);
  printf("Enter the number of days: ");
  scanf("%d", &guest->days);
  printf("Enter the cost: ");
  scanf("%f", &guest->cost);
}

void check_out(struct guest *guest) {
  printf("Enter the guest's name: ");
  scanf("%s", guest->name);
  printf("Enter the room number: ");
  scanf("%s", guest->room);
  printf("Enter the number of days: ");
  scanf("%d", &guest->days);
  printf("Enter the cost: ");
  scanf("%f", &guest->cost);
}

void view_guests(struct guest *guest) {
  printf("Guest name: %s\n", guest->name);
  printf("Room number: %s\n", guest->room);
  printf("Number of days: %d\n", guest->days);
  printf("Cost: %f\n", guest->cost);
}

void view_staff(struct staff *staff) {
  printf("Staff name: %s\n", staff->name);
  printf("Position: %s\n", staff->position);
  printf("Salary: %d\n", staff->salary);
}