//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randRange(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to generate a random fortune
char *genFortune() {
  // Array of possible fortunes
  char *fortunes[] = {
      "You will have a long and happy life.",
      "You will be rich and famous.",
      "You will find true love.",
      "You will make a difference in the world.",
      "You will be successful in all your endeavors.",
      "You will be happy and content.",
      "You will live a long and fulfilling life.",
      "You will be surrounded by loved ones.",
      "You will be successful in your career.",
      "You will be happy and healthy."};

  // Generate a random index
  int index = randRange(0, 9);

  // Return the fortune at the random index
  return fortunes[index];
}

// Function to print a fortune
void printFortune() {
  // Generate a random fortune
  char *fortune = genFortune();

  // Print the fortune
  printf("Your fortune is: %s\n", fortune);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Print a welcome message
  printf("Welcome to the Automated Fortune Teller!\n");

  // Get the user's name
  char name[256];
  printf("What is your name? ");
  scanf("%s", name);

  // Print a personalized greeting
  printf("Hello, %s!\n", name);

  // Ask the user if they want to hear their fortune
  char answer;
  printf("Do you want to hear your fortune? (y/n) ");
  scanf(" %c", &answer);

  // If the user wants to hear their fortune, print it
  if (answer == 'y') {
    printFortune();
  } else {
    printf("Okay, no problem. Maybe next time.\n");
  }

  // Say goodbye to the user
  printf("Goodbye, %s! Have a great day!\n", name);

  return 0;
}