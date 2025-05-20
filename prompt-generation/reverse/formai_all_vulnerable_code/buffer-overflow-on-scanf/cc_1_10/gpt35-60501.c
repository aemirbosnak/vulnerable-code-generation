//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

int main() {

  // introduction
  printf("Welcome to the Bitwise Beer Bar!\n");
  printf("Here, we'll use bitwise operations to serve your drinks!\n\n");

  // declaring variables
  unsigned int user_input;
  unsigned int drink_choice;
  int beer_count = 0;
  int soda_count = 0;

  // loop for serving drinks
  while (1) {

    // getting user input
    printf("Enter a number between 1 and 6 to choose your drink: ");
    scanf("%d", &user_input);

    // checking drink choice
    switch (user_input) {

      // beer
      case 1:
        // using bitwise OR to add 1 to beer count
        beer_count = beer_count | 1;
        printf("Here's your beer! Enjoy!\n\n");
        break;

      // soda
      case 2:
        // using bitwise OR to add 2 to soda count
        soda_count = soda_count | 2;
        printf("Here's your soda! Enjoy!\n\n");
        break;

      // exit
      case 3:
        printf("Thank you for visiting us!\n\n");

        // printing drink counts using bitwise AND
        printf("Total beers served: %d\n", beer_count & 255);
        printf("Total sodas served: %d\n", soda_count & 255);

        // exiting the program
        return 0;

      // invalid input
      default:
        printf("Invalid input! Try again.\n\n");
    }
  }
}