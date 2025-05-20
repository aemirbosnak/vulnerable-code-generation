//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct guest {
  char name[50];
  int room_no;
  int days_stayed;
  float total_amount;
} guest;

guest guests[MAX_GUESTS];

void create_guest(int guest_no) {
  printf("Enter guest name: ");
  scanf("%s", guests[guest_no].name);

  printf("Enter room number: ");
  scanf("%d", &guests[guest_no].room_no);

  printf("Enter number of days stayed: ");
  scanf("%d", &guests[guest_no].days_stayed);
}

void calculate_total_amount(int guest_no) {
  int days_stayed = guests[guest_no].days_stayed;
  float room_charge = 1000;
  guests[guest_no].total_amount = days_stayed * room_charge;
}

void print_guest_details(int guest_no) {
  printf("Name: %s\n", guests[guest_no].name);
  printf("Room Number: %d\n", guests[guest_no].room_no);
  printf("Days Stayed: %d\n", guests[guest_no].days_stayed);
  printf("Total Amount: %.2f\n", guests[guest_no].total_amount);
}

int main() {
  int guest_no = 0;

  // Create a guest
  create_guest(guest_no);

  // Calculate total amount
  calculate_total_amount(guest_no);

  // Print guest details
  print_guest_details(guest_no);

  return 0;
}