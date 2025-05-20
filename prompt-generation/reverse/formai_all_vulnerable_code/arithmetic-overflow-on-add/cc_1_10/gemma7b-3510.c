//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[20];
  int room_number;
  time_t check_in_time;
  time_t check_out_time;
} Guest;

Guest guests[MAX_GUESTS];

void print_guest_list() {
  for (int i = 0; i < MAX_GUESTS; i++) {
    if (guests[i].name[0] != '\0') {
      printf("Name: %s, Room Number: %d, Check-in Time: %s, Check-out Time: %s\n", guests[i].name, guests[i].room_number, guests[i].check_in_time, guests[i].check_out_time);
    }
  }
}

void add_guest() {
  Guest new_guest;

  printf("Enter your name: ");
  scanf("%s", new_guest.name);

  printf("Enter your room number: ");
  scanf("%d", &new_guest.room_number);

  time_t now = time(NULL);
  new_guest.check_in_time = now;

  time_t checkout_time = now + 60 * 60 * 24;
  new_guest.check_out_time = checkout_time;

  for (int i = 0; i < MAX_GUESTS; i++) {
    if (guests[i].name[0] == '\0') {
      guests[i] = new_guest;
      break;
    }
  }
}

void check_out() {
  char guest_name[20];

  printf("Enter your name: ");
  scanf("%s", guest_name);

  for (int i = 0; i < MAX_GUESTS; i++) {
    if (strcmp(guests[i].name, guest_name) == 0) {
      guests[i].name[0] = '\0';
      printf("Check-out successful!\n");
      break;
    }
  }
}

int main() {
  int choice;

  printf("Welcome to the Hotel Management System!\n");

  while (1) {
    printf("Please select an option:\n");
    printf("1. Print Guest List\n");
    printf("2. Add Guest\n");
    printf("3. Check Out\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        print_guest_list();
        break;
      case 2:
        add_guest();
        break;
      case 3:
        check_out();
        break;
      case 4:
        exit(0);
    }
  }

  return 0;
}