//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
  int num;
  srand(time(NULL));
  num = rand() % (max - min + 1) + min;
  return num;
}

// Function to print a random fortune
void print_fortune(int fortune_num) {
  switch(fortune_num) {
    case 1:
      printf("You will find a hidden cache of supplies.\n");
      break;
    case 2:
      printf("You will encounter a group of friendly survivors.\n");
      break;
    case 3:
      printf("You will stumble upon a dangerous raider camp.\n");
      break;
    case 4:
      printf("You will discover a new source of clean water.\n");
      break;
    case 5:
      printf("You will have a close call with a mutated creature.\n");
      break;
    case 6:
      printf("You will find a working vehicle.\n");
      break;
    case 7:
      printf("You will be forced to make a difficult decision.\n");
      break;
    case 8:
      printf("You will find a valuable piece of technology.\n");
      break;
    case 9:
      printf("You will encounter a mysterious stranger.\n");
      break;
    case 10:
      printf("You will have a run-in with a group of bandits.\n");
      break;
    default:
      printf("Your future is uncertain...\n");
  }
}

// Main function
int main() {
  int choice, fortune_num;

  // Seed the random number generator
  srand(time(NULL));

  // Print the menu
  printf("Welcome to the Post-Apocalyptic Fortune Teller!\n\n");
  printf("1. Get a random fortune\n");
  printf("2. Exit\n");
  printf("\n");

  // Get the user's choice
  scanf("%d", &choice);

  // Exit if the user chooses to quit
  if(choice == 2) {
    return 0;
  }

  // Generate a random fortune
  fortune_num = rand_num(1, 10);

  // Print the fortune
  print_fortune(fortune_num);

  return 0;
}