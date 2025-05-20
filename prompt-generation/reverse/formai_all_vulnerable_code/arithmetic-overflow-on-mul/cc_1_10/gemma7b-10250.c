//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[50];
  int room_no;
  int num_days;
  double total_bill;
} Guest;

Guest guests[MAX_GUESTS];

void calculate_bill(Guest *guest) {
  guest->total_bill = guest->num_days * 100;
}

void check_in(Guest *guest) {
  printf("Welcome, %s! Please take your seat in room %d.\n", guest->name, guest->room_no);
}

void check_out(Guest *guest) {
  printf("Thank you for your stay, %s. We hope you enjoyed your time at the hotel.\n", guest->name);
}

int main() {
  int i = 0;
  for (i = 0; i < MAX_GUESTS; i++) {
    guests[i].name[0] = '\0';
  }

  Guest *guest = &guests[0];

  printf("Please enter your name: ");
  scanf("%s", guest->name);

  printf("Please enter your room number: ");
  scanf("%d", &guest->room_no);

  printf("Please enter the number of days you will be staying: ");
  scanf("%d", &guest->num_days);

  calculate_bill(guest);

  check_in(guest);

  check_out(guest);

  printf("Your total bill is $%.2lf.\n", guest->total_bill);

  return 0;
}