//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>

int main() {
  printf("Welcome to the C Hotel Management System!");
  printf("Here, we provide surreal experiences to our guests!");

  int guests = 0;
  int rooms = 0;
  int beds = 0;
  int checkIns = 0;
  int checkOuts = 0;

  printf("Number of guests: %d\n", guests);
  printf("Number of rooms: %d\n", rooms);
  printf("Number of beds: %d\n", beds);
  printf("Check-ins: %d\n", checkIns);
  printf("Check-outs: %d\n", checkOuts);

  printf("Surrealist Room Service:");
  printf("-------------------------\n");
  printf("1. Unicorn Milk: $10.00\n");
  printf("2. Dreamcatcher: $15.00\n");
  printf("3. Flying Carpet: $20.00\n");
  printf("4. Time Travel Machine: $30.00\n");
  printf("5. Exit: $0.00\n");

  int choice;
  printf("Please select a surrealist room service: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enjoy your Unicorn Milk!\n");
      break;
    case 2:
      printf("Dream on with your Dreamcatcher!\n");
      break;
    case 3:
      printf("Take a ride on your Flying Carpet!\n");
      break;
    case 4:
      printf("Travel through time with your Time Travel Machine!\n");
      break;
    case 5:
      printf("Thank you for choosing the C Hotel Management System. Have a surreal day!\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
  }

  return 0;
}