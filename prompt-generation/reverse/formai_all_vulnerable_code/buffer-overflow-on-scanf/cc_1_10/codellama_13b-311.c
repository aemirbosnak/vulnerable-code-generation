//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: recursive
/*
 * Airport Baggage Handling Simulation using recursive functions
 */

#include <stdio.h>

// Global variables
int num_passengers = 0;
int num_bags = 0;
int num_checkins = 0;
int num_xrays = 0;

// Function prototypes
void checkin(int id);
void baggage(int id);
void xray(int id);

// Main function
int main() {
  int id, choice;

  printf("Welcome to Airport Baggage Handling Simulation!\n");
  printf("How many passengers would you like to simulate? ");
  scanf("%d", &num_passengers);

  // Loop for each passenger
  for (id = 1; id <= num_passengers; id++) {
    printf("\nPassenger %d:\n", id);
    printf("1. Check in\n");
    printf("2. Baggage\n");
    printf("3. X-ray\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    // Check in
    if (choice == 1) {
      checkin(id);
    }

    // Baggage
    else if (choice == 2) {
      baggage(id);
    }

    // X-ray
    else if (choice == 3) {
      xray(id);
    }

    // Exit
    else if (choice == 4) {
      printf("Goodbye!\n");
      break;
    }
  }

  // Display results
  printf("\n\nPassengers: %d\n", num_passengers);
  printf("Check-ins: %d\n", num_checkins);
  printf("Baggage: %d\n", num_bags);
  printf("X-rays: %d\n", num_xrays);

  return 0;
}

// Check in function
void checkin(int id) {
  int choice;

  printf("\nPassenger %d: Check in\n", id);
  printf("1. Yes\n");
  printf("2. No\n");
  printf("Choice: ");
  scanf("%d", &choice);

  // If checked in
  if (choice == 1) {
    num_checkins++;
    printf("You have checked in.\n");

    // Baggage
    printf("Would you like to check your baggage?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Choice: ");
    scanf("%d", &choice);

    // If baggage checked
    if (choice == 1) {
      baggage(id);
    }

    // If baggage not checked
    else if (choice == 2) {
      printf("You have not checked your baggage.\n");

      // X-ray
      printf("Would you like to go through X-ray?\n");
      printf("1. Yes\n");
      printf("2. No\n");
      printf("Choice: ");
      scanf("%d", &choice);

      // If X-ray
      if (choice == 1) {
        xray(id);
      }

      // If no X-ray
      else if (choice == 2) {
        printf("You have not gone through X-ray.\n");
      }
    }
  }

  // If not checked in
  else if (choice == 2) {
    printf("You have not checked in.\n");
  }
}

// Baggage function
void baggage(int id) {
  int choice;

  printf("\nPassenger %d: Baggage\n", id);
  printf("1. Yes\n");
  printf("2. No\n");
  printf("Choice: ");
  scanf("%d", &choice);

  // If baggage checked
  if (choice == 1) {
    num_bags++;
    printf("You have checked your baggage.\n");

    // X-ray
    printf("Would you like to go through X-ray?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Choice: ");
    scanf("%d", &choice);

    // If X-ray
    if (choice == 1) {
      xray(id);
    }

    // If no X-ray
    else if (choice == 2) {
      printf("You have not gone through X-ray.\n");
    }
  }

  // If baggage not checked
  else if (choice == 2) {
    printf("You have not checked your baggage.\n");
  }
}

// X-ray function
void xray(int id) {
  int choice;

  printf("\nPassenger %d: X-ray\n", id);
  printf("1. Yes\n");
  printf("2. No\n");
  printf("Choice: ");
  scanf("%d", &choice);

  // If X-ray
  if (choice == 1) {
    num_xrays++;
    printf("You have gone through X-ray.\n");
  }

  // If no X-ray
  else if (choice == 2) {
    printf("You have not gone through X-ray.\n");
  }
}