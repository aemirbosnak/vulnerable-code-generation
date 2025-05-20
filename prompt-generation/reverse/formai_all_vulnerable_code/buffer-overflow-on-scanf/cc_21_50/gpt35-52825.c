//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>

int main() {

  int month, day, birthstone, lucky_num;

  // prompt the user for their birth month and day
  printf("Welcome to the Birthstone & Lucky Number Calculator!\n");
  printf("Please enter your birth month (1-12): ");
  scanf("%d", &month);
  printf("Please enter your birth day (1-31): ");
  scanf("%d", &day);

  // calculate which birthstone corresponds to the user's birth month
  switch(month) {
    case 1:
      birthstone = 1; // garnet
      break;
    case 2:
      birthstone = 2; // amethyst
      break;
    case 3:
      birthstone = 3; // aquamarine
      break;
    case 4:
      birthstone = 4; // diamond
      break;
    case 5:
      birthstone = 5; // emerald
      break;
    case 6:
      birthstone = 6; // pearl
      break;
    case 7:
      birthstone = 7; // ruby
      break;
    case 8:
      birthstone = 8; // peridot
      break;
    case 9:
      birthstone = 9; // sapphire
      break;
    case 10:
      birthstone = 10; // opal
      break;
    case 11:
      birthstone = 11; // topaz
      break;
    case 12:
      birthstone = 12; // turquoise
      break;
    default:
      printf("Invalid input. Please enter a number between 1-12.\n");
      return 1;
  }

  // calculate the user's lucky number based on their birth day
  int sum = (day % 10) + (day / 10); // add the digits together
  lucky_num = (sum + month) % 10; // add the month and take the last digit

  // output the results
  printf("Your birthstone is: ");
  switch(birthstone) {
    case 1:
      printf("Garnet\n");
      break;
    case 2:
      printf("Amethyst\n");
      break;
    case 3:
      printf("Aquamarine\n");
      break;
    case 4:
      printf("Diamond\n");
      break;
    case 5:
      printf("Emerald\n");
      break;
    case 6:
      printf("Pearl\n");
      break;
    case 7:
      printf("Ruby\n");
      break;
    case 8:
      printf("Peridot\n");
      break;
    case 9:
      printf("Sapphire\n");
      break;
    case 10:
      printf("Opal\n");
      break;
    case 11:
      printf("Topaz\n");
      break;
    case 12:
      printf("Turquoise\n");
      break;
  }
  printf("Your lucky number is: %d\n", lucky_num);

  return 0;
}