//FormAI DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for each hotel guest
typedef struct Guest {
  char name[50];
  int roomNumber;
  int numDays;
  float totalCost;
} Guest;

// Array to hold hotel guests
Guest guests[100];

// Track current number of guests
int guestCount = 0;

// Function to add a new guest to the system
void addGuest() {
  printf("Enter guest name: ");
  scanf("%s", guests[guestCount].name);
  printf("Enter room number: ");
  scanf("%d", &guests[guestCount].roomNumber);
  printf("Enter number of days staying: ");
  scanf("%d", &guests[guestCount].numDays);

  // Calculate total cost based on number of days staying
  guests[guestCount].totalCost = guests[guestCount].numDays * 100;

  guestCount++;
}

// Function to print out all guests in the system
void printGuests() {
  printf("%-20s %-20s %-20s %-20s\n", "Name", "Room Number", "Days Staying", "Total Cost");
  for (int i = 0; i < guestCount; i++) {
    printf("%-20s %-20d %-20d %-20.2f\n", guests[i].name, guests[i].roomNumber, guests[i].numDays, guests[i].totalCost);
  }
}

int main() {
  int choice;

  while (1) {
    printf("Welcome to the Hotel Management System.\n");
    printf("1 - Add new guest\n");
    printf("2 - Print all guests\n");
    printf("3 - Exit\n");
    printf("\nEnter your selection: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addGuest();
        break;

      case 2:
        printGuests();
        break;

      case 3:
        printf("Thank you for using the Hotel Management System.\n");
        return 0;

      default:
        printf("Invalid selection. Please try again.\n");
        break;
    }
  }

  return 0;
}