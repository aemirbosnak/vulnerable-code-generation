//FormAI DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Guest struct */
typedef struct {
  char name[50];
  int room_number;
  int nights_stayed;
  float bill_amount;
} Guest;

/* Function declarations */
void check_in(Guest guests[], int *total_guests);
void check_out(Guest guests[], int *total_guests);
void print_guests(Guest guests[], int total_guests);

/* Main function */
int main() {
  system("clear");
  printf("========================= WELCOME TO THE MEDIEVAL HOTEL =========================\n\n");

  /* Define variables */
  Guest guests[50];
  int choice, total_guests = 0;

  /* Menu */
  do {
    printf("\n\n1. Check in\n");
    printf("2. Check out\n");
    printf("3. View current guests\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    /* Handle user choice */
    switch(choice) {
      case 1:
        check_in(guests, &total_guests);
        break;
      case 2:
        check_out(guests, &total_guests);
        break;
      case 3:
        print_guests(guests, total_guests);
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("\nInvalid choice. Try again.\n");
    }
  } while(choice != 4);

  return 0;
}

/* Function to check in a guest */
void check_in(Guest guests[], int *total_guests) {
  /* Check if there is space for another guest */
  if(*total_guests < 50) {
    /* Get guest information */
    printf("\nEnter guest name: ");
    scanf("%s", guests[*total_guests].name);
    printf("Enter room number: ");
    scanf("%d", &guests[*total_guests].room_number);
    printf("Enter number of nights staying: ");
    scanf("%d", &guests[*total_guests].nights_stayed);

    /* Calculate bill amount */
    guests[*total_guests].bill_amount = guests[*total_guests].nights_stayed * 10.0;

    /* Increase total guests */
    *total_guests += 1;

    printf("\n%s has been checked in.\n", guests[*total_guests - 1].name);
  } else {
    printf("\nSorry, the hotel is currently full.\n");
  }
}

/* Function to check out a guest */
void check_out(Guest guests[], int *total_guests) {
  /* Get room number of guest to check out */
  int room_number;
  printf("\nEnter room number of guest to check out: ");
  scanf("%d", &room_number);

  /* Search for guest in array */
  int i, found = 0;
  for(i = 0; i < *total_guests; i++) {
    if(guests[i].room_number == room_number) {
      /* Calculate total bill */
      float total_bill = guests[i].bill_amount + guests[i].bill_amount * 0.1;

      printf("\n%s has checked out of room %d.\n", guests[i].name, guests[i].room_number);
      printf("Total bill amount (with 10%% tax): $%.2f\n", total_bill);

      /* Remove guest from array */
      guests[i] = guests[*total_guests - 1];
      *total_guests -= 1;

      found = 1;
    }
  }

  /* If guest was not found */
  if(found == 0) {
    printf("\nGuest not found in hotel.\n");
  }
}

/* Function to print current guests */
void print_guests(Guest guests[], int total_guests) {
  /* If there are no guests */
  if(total_guests == 0) {
    printf("\nThere are no current guests in the hotel.\n");
  } else {
    printf("\nCurrent guests in the hotel:\n");

    int i;
    for(i = 0; i < total_guests; i++) {
      printf("%d. %s (Room %d, Nights stayed: %d, Bill amount: $%.2f)\n", i + 1, guests[i].name, guests[i].room_number, guests[i].nights_stayed, guests[i].bill_amount);
    }
  }
}