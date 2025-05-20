//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize the random number generator with a surrealist seed.
  srand48(609085);

  // Create an array of stock prices.
  float prices[100];
  for (int i = 0; i < 100; i++) {
    // Generate a random stock price between 0 and 100.
    prices[i] = drand48() * 100;
  }

  // Create an array of surrealist stock names.
  char *names[] = {
    "The Dreamt of Falling Feathers",
    "The Song of the Sirens",
    "The Dance of the Seven Veils",
    "The Garden of Eden",
    "The Tower of Babel",
    "The City of Lost Children",
    "The Labyrinth of Dreams",
    "The Fountain of Youth",
    "The Holy Grail",
    "The Philosopher's Stone"
  };

  // Create an array of surrealist stock descriptions.
  char *descriptions[] = {
    "A stock that dreams of falling feathers.",
    "A stock that sings the song of the sirens.",
    "A stock that dances the dance of the seven veils.",
    "A stock that grows in the Garden of Eden.",
    "A stock that reaches for the Tower of Babel.",
    "A stock that wanders the City of Lost Children.",
    "A stock that explores the Labyrinth of Dreams.",
    "A stock that flows from the Fountain of Youth.",
    "A stock that seeks the Holy Grail.",
    "A stock that transforms into the Philosopher's Stone."
  };

  // Create a surrealist stock market tracker.
  printf("Welcome to the Surrealist Stock Market Tracker!\n\n");
  printf("Here is a list of our current surrealist stocks:\n\n");
  for (int i = 0; i < 10; i++) {
    printf("%s\n", names[i]);
    printf("\t%s\n", descriptions[i]);
    printf("\tPrice: $%.2f\n\n", prices[i]);
  }

  // Allow the user to buy and sell stocks.
  while (1) {
    char input;
    printf("Would you like to buy or sell a stock? (b/s/q): ");
    scanf(" %c", &input);

    if (input == 'b') {
      // Get the name of the stock the user wants to buy.
      char name[100];
      printf("What stock would you like to buy?: ");
      scanf(" %s", name);

      // Find the index of the stock in the array.
      int index = -1;
      for (int i = 0; i < 10; i++) {
        if (strcmp(name, names[i]) == 0) {
          index = i;
          break;
        }
      }

      // If the stock was found, buy it.
      if (index != -1) {
        printf("You bought 1 share of %s for $%.2f.\n", names[index], prices[index]);
      } else {
        printf("That stock does not exist.\n");
      }
    } else if (input == 's') {
      // Get the name of the stock the user wants to sell.
      char name[100];
      printf("What stock would you like to sell?: ");
      scanf(" %s", name);

      // Find the index of the stock in the array.
      int index = -1;
      for (int i = 0; i < 10; i++) {
        if (strcmp(name, names[i]) == 0) {
          index = i;
          break;
        }
      }

      // If the stock was found, sell it.
      if (index != -1) {
        printf("You sold 1 share of %s for $%.2f.\n", names[index], prices[index]);
      } else {
        printf("That stock does not exist.\n");
      }
    } else if (input == 'q') {
      // Quit the program.
      break;
    } else {
      // Invalid input.
      printf("Invalid input.\n");
    }
  }

  return 0;
}