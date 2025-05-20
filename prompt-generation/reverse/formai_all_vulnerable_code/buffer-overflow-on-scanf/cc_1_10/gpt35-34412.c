//FormAI DATASET v1.0 Category: Hotel Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
  char name[50];
  int room_number;
  int days_staying;
  float bill;
};

struct guest guest_list[50];
int num_guests = 0;

void check_in() {
  printf("Welcome to the Romantic Hotel Management System!\n");
  printf("Enter your name: ");
  scanf("%s", guest_list[num_guests].name);
  printf("Choose a room number (1-50): ");
  scanf("%d", &guest_list[num_guests].room_number);
  printf("How many days will you be staying?: ");
  scanf("%d", &guest_list[num_guests].days_staying);

  guest_list[num_guests].bill = guest_list[num_guests].days_staying * 150.0;
  printf("\nWelcome %s, you are staying in room %d for %d days.\nYour bill is $%.2f.\n",
         guest_list[num_guests].name, guest_list[num_guests].room_number, guest_list[num_guests].days_staying, guest_list[num_guests].bill);

  num_guests++;
}

void display_guests() {
  printf("\nCurrent Guests:\n");
  printf("------------------\n");
  for (int i = 0; i < num_guests; i++) {
    printf("%d. %s, Room %d, Bill: $%.2f\n", i+1, guest_list[i].name, guest_list[i].room_number, guest_list[i].bill);
  }
  printf("------------------\n\n");
}

void check_out() {
  int room_num;
  printf("Enter room number of guest checking out: ");
  scanf("%d", &room_num);

  for (int i = 0; i < num_guests; i++) {
    if (guest_list[i].room_number == room_num) {
      printf("\nThank you for staying with us, %s.\nYour bill is $%.2f. Please come again!\n", guest_list[i].name, guest_list[i].bill);

      for (int j = i; j < num_guests-1; j++) {
        guest_list[j] = guest_list[j+1];
      }
      num_guests--;
      return;
    }
  }

  printf("\nRoom not found.\n");
}

int main() {
  int choice;

  do {
    printf("\nRomantic Hotel Management Menu:\n");
    printf("1. Check In\n");
    printf("2. Display Guests\n");
    printf("3. Check Out\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        check_in();
        break;
      case 2:
        display_guests();
        break;
      case 3:
        check_out();
        break;
      case 4:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
    }

  } while (choice != 4);

  return 0;
}