//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[20];
  int room_number;
  int days_stayed;
  double total_cost;
} Guest;

Guest guests[MAX_GUESTS];

void create_guest(int guest_number) {
   guests[guest_number].name[0] = '\0';
  guests[guest_number].room_number = 0;
  guests[guest_number].days_stayed = 0;
  guests[guest_number].total_cost = 0.0;
}

void check_in(int guest_number) {
  printf("Enter guest name: ");
  scanf("%s", guests[guest_number].name);
  printf("Enter room number: ");
  scanf("%d", &guests[guest_number].room_number);
  printf("Enter number of days stayed: ");
  scanf("%d", &guests[guest_number].days_stayed);
}

void calculate_cost(int guest_number) {
  double daily_rate = 100.0;
  guests[guest_number].total_cost = daily_rate * guests[guest_number].days_stayed;
}

void check_out(int guest_number) {
  printf("Guest name: %s\n", guests[guest_number].name);
  printf("Room number: %d\n", guests[guest_number].room_number);
  printf("Number of days stayed: %d\n", guests[guest_number].days_stayed);
  printf("Total cost: $%.2lf\n", guests[guest_number].total_cost);
}

int main() {
  int guest_number = 0;

  // Create guests
  for (guest_number = 0; guest_number < MAX_GUESTS; guest_number++) {
    create_guest(guest_number);
  }

  // Check in guests
  for (guest_number = 0; guest_number < MAX_GUESTS; guest_number++) {
    check_in(guest_number);
  }

  // Calculate costs
  for (guest_number = 0; guest_number < MAX_GUESTS; guest_number++) {
    calculate_cost(guest_number);
  }

  // Check out guests
  for (guest_number = 0; guest_number < MAX_GUESTS; guest_number++) {
    check_out(guest_number);
  }

  return 0;
}