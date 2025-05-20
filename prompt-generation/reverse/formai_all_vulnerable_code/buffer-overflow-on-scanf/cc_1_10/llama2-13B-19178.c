//LLAMA2-13B DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define WELCOME_MESSAGE "Welcome to the land of cheerful code!"
#define GOODBYE_MESSAGE "Goodbye, have a fantastic day!"

int main() {
  // Print a cheerful welcome message
  printf(WELCOME_MESSAGE);

  // Ask the user for their name
  printf("What's your name, my dear? ");
  char name[50];
  fgets(name, 50, stdin);

  // Print a cheerful message with the user's name
  printf("Hello, %s! I'm so glad you're here! \n", name);

  // Generate a random joke and print it
  int joke_number = rand() % 10;
  switch (joke_number) {
    case 0:
      printf("Why did the tomato turn red? Because it saw the salad dressing! \n");
      break;
    case 1:
      printf("What do you call a fake noodle? An impasta! \n");
      break;
    case 2:
      printf("Why did the scarecrow win an award? Because he was outstanding in his field! \n");
      break;
    default:
      printf("Oh no, I couldn't come up with a joke for you today! Maybe try again tomorrow? \n");
      break;
  }

  // Ask the user if they want to play a game
  printf("Do you want to play a game? (y/n) ");
  char answer;
  scanf(" %c", &answer);

  if (answer == 'y' || answer == 'Y') {
    // Print a cheerful game message
    printf("Great choice! Let's play a game of 'Guess the Number'! \n");

    // Generate a random number between 1 and 100
    int number = rand() % 100;

    // Print the number and ask the user to guess
    printf("I'm thinking of a number between 1 and 100... can you guess it? \n");
    printf("Hint: It's a prime number! \n");

    // Get the user's guess
    int guess;
    scanf(" %d", &guess);

    // Check if the user guessed correctly
    if (guess == number) {
      // Print a cheerful message if the user guessed correctly
      printf("Woohoo! You guessed it! You're so clever! \n");
    } else {
      // Print a cheerful message if the user didn't guess correctly
      printf("Oh no! You didn't guess it... but that's okay, we still love you! \n");
    }
  } else {
    // Print a cheerful goodbye message
    printf(GOODBYE_MESSAGE);
  }

  return 0;
}