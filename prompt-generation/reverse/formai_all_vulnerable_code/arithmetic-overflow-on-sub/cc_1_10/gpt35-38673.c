//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int current_year, target_year, year_difference, option;
  bool is_travel_possible = true;

  printf("Welcome to the Time Travel Simulator! Let's go on an adventure!\n\n");
  printf("Enter the current year: ");
  scanf("%d", &current_year);
  printf("Enter the target year: ");
  scanf("%d", &target_year);

  if (target_year <= current_year) {
    printf("\nSorry, time travel can only go into the future!\n");
    is_travel_possible = false;
  } else {
    year_difference = target_year - current_year;
    printf("\nWow! You are traveling %d years into the future! This is going to be exciting!\n", year_difference);

    printf("\nChoose your mode of transportation:\n");
    printf("1. Time Machine\n");
    printf("2. Super Car\n");
    printf("3. Spaceship\n");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("\nYou have chosen the Time Machine! Let's go!\n");
        break;
      case 2:
        printf("\nYou have chosen the Super Car! Buckle up and let's go!\n");
        break;
      case 3:
        printf("\nYou have chosen the Spaceship! Hold on tight and let's blast off!\n");
        break;
      default:
        printf("\nInvalid option selected. Let's take the default mode of transportation.\n");
        break;
    }

    printf("\nYou have arrived in %d. Welcome to the future! Here are a few highlights:\n", target_year);
    printf("- Flying cars are the norm!\n");
    printf("- Artificial Intelligence is everywhere!\n");
    printf("- People live up to 150 years!\n");

    printf("\nThanks for traveling with us! Have a great time in the future! Goodbye!\n");
  }

  return 0;
}