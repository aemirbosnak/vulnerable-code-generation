//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a guest
typedef struct guest {
  char name[50];
  int age;
  char gender;
  int roomNumber;
  int daysStayed;
  float bill;
} Guest;

// Function to initialize a guest
Guest initializeGuest() {
  Guest g;
  strcpy(g.name, "");
  g.age = 0;
  g.gender = 'M';
  g.roomNumber = 0;
  g.daysStayed = 0;
  g.bill = 0.0f;
  return g;
}

// Function to check in a guest
void checkInGuest(Guest *g) {
  printf("Enter guest name: ");
  scanf("%s", g->name);
  printf("Enter guest age: ");
  scanf("%d", &g->age);
  printf("Enter guest gender (M/F): ");
  scanf(" %c", &g->gender);
  printf("Enter guest room number: ");
  scanf("%d", &g->roomNumber);
  printf("Enter number of days guest will stay: ");
  scanf("%d", &g->daysStayed);
  printf("Guest checked in successfully!\n");
}

// Function to check out a guest
void checkOutGuest(Guest *g) {
  printf("Guest %s checked out.\n", g->name);
  g->roomNumber = 0;
  g->daysStayed = 0;
  g->bill = 0.0f;
  strcpy(g->name, "");
}

// Function to calculate the bill for a guest
float calculateBill(Guest *g) {
  float roomRate = 10.0f;  // Rate per day
  float serviceCharge = 2.0f;  // Flat service charge
  g->bill = (roomRate * g->daysStayed) + serviceCharge;
  return g->bill;
}

// Function to print the guest details
void printGuestDetails(Guest *g) {
  printf("Guest Name: %s\n", g->name);
  printf("Guest Age: %d\n", g->age);
  printf("Guest Gender: %c\n", g->gender);
  printf("Guest Room Number: %d\n", g->roomNumber);
  printf("Guest Days Stayed: %d\n", g->daysStayed);
  printf("Guest Bill: %.2f\n", g->bill);
}

// Main function
int main() {
  int choice;
  Guest guest = initializeGuest();

  while (1) {
    printf("\n\nMedieval Hotel Management System\n");
    printf("1. Check in a guest\n");
    printf("2. Check out a guest\n");
    printf("3. Calculate bill for a guest\n");
    printf("4. Print guest details\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        checkInGuest(&guest);
        break;
      case 2:
        checkOutGuest(&guest);
        break;
      case 3:
        calculateBill(&guest);
        printf("Guest bill: %.2f\n", guest.bill);
        break;
      case 4:
        printGuestDetails(&guest);
        break;
      case 5:
        printf("Thank you for using the Medieval Hotel Management System!\n");
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}