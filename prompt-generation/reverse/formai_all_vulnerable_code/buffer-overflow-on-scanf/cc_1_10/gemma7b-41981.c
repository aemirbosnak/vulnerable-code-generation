//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[20];
  int room_number;
  int status;
} Guest;

Guest guests[MAX_GUESTS];

void check_in(Guest *guest) {
  printf("Welcome, %s! Please select a room number:", guest->name);
  scanf("%d", &guest->room_number);

  if (guest->room_number < 1 || guest->room_number > MAX_GUESTS) {
    printf("Invalid room number.\n");
    check_in(guest);
  }

  guest->status = 1;
}

void check_out(Guest *guest) {
  printf("Thank you for your stay, %s. Please collect your belongings.", guest->name);
  guest->status = 0;
}

int main() {
  int i, guest_number = 0;

  for (i = 0; i < MAX_GUESTS; i++) {
    guests[i].status = 0;
  }

  printf("Welcome to the Grand Hotel!\n");

  while (guest_number < MAX_GUESTS) {
    printf("Please enter your name:");
    scanf("%s", guests[guest_number].name);

    check_in(&guests[guest_number]);

    guest_number++;
  }

  printf("All guests have checked in.\n");

  for (i = 0; i < guest_number; i++) {
    check_out(&guests[i]);
  }

  printf("Have a pleasant stay!\n");

  return 0;
}