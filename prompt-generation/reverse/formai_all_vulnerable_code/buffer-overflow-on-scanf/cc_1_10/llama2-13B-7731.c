//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define APPLE 5
#define BANANA 3
#define ORANGE 2

int main() {
  int fruit_count[3] = {0};
  int random_fruit = 0;

  printf("Welcome to the fruit stand! Please select a fruit: \n");

  // Generate random fruit selection
  random_fruit = (rand() % 3) + 1;

  // Increment fruit count for selected fruit
  fruit_count[random_fruit - 1]++;

  // Print fruit selection and count
  printf("You selected: %c (%d)\n",
         (char)random_fruit, fruit_count[random_fruit - 1]);

  // Generate a silly message based on the selected fruit
  switch (random_fruit) {
    case 1:
      printf("Enjoy your juicy APPLE! 🍎\n");
      break;
    case 2:
      printf("Yum! You chose an ORANGE! 🍊\n");
      break;
    case 3:
      printf("BANANA time! 🍌\n");
      break;
    default:
      printf("You picked a weird fruit... 🤷‍♀️\n");
      break;
  }

  // Calculate the total price based on the selected fruit
  int total_price = (random_fruit == 1) ? 10 : (random_fruit == 2) ? 15 : 20;

  // Print the total price
  printf("Your total is: %d\n", total_price);

  // Ask the customer if they want to buy another fruit
  printf("Want another fruit? (y/n): ");
  char response;
  scanf("%c", &response);

  // If customer says yes, repeat the process
  if (response == 'y') {
    printf("Great choice! Here's your next fruit:\n");
    main();
  } else {
    printf("Thanks for shopping! Have a nice day!");
  }

  return 0;
}