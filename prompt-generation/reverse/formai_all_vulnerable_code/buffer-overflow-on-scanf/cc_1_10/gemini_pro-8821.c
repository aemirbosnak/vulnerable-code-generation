//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int room_number;
  int days_stayed;
  double bill;
} guest;

int main() {
  // Initialize the hotel with 100 rooms
  guest *hotel[100];

  // Loop until the user enters a negative number of days stayed
  int days_stayed;
  while ((printf("Enter the number of days stayed (-1 to exit): "), scanf("%d", &days_stayed)) && days_stayed >= 0) {
    // Allocate memory for the guest
    guest *new_guest = malloc(sizeof(guest));

    // Get the guest's name
    printf("Enter the guest's name: ");
    char *name = malloc(100);
    scanf("%s", name);

    // Set the guest's details
    new_guest->name = name;
    new_guest->room_number = rand() % 100 + 1;
    new_guest->days_stayed = days_stayed;
    new_guest->bill = days_stayed * 100;

    // Add the guest to the hotel
    hotel[new_guest->room_number - 1] = new_guest;
  }

  // Print the hotel's guests
  for (int i = 0; i < 100; i++) {
    if (hotel[i] != NULL) {
      printf("Guest %s stayed in room %d for %d days and has a bill of $%.2f\n", hotel[i]->name, hotel[i]->room_number, hotel[i]->days_stayed, hotel[i]->bill);
    }
  }

  // Free the memory allocated for the guests
  for (int i = 0; i < 100; i++) {
    if (hotel[i] != NULL) {
      free(hotel[i]->name);
      free(hotel[i]);
    }
  }

  return 0;
}