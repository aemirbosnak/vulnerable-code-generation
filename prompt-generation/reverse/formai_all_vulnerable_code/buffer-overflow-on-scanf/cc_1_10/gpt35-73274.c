//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int score = 0; //initialize score
  char input; //initialize input variable
  int num_generated; //initialize variable for generated number
  int num_guesses = 0; //initialize number of guesses
  srand(time(0)); //set seed for random number generator

  printf("Welcome to the Guessing Game!\n");
  printf("You have 5 attempts to guess the number between 1 and 100.\n");

  num_generated = rand() % 100 + 1; //generate random number between 1 and 100

  while (num_guesses < 5) //loop until user has used all attempts
  {
    printf("Enter your guess: ");
    scanf(" %c", &input); //get user input

    if (!isdigit(input)) //check if input is a digit
    {
      printf("Invalid input. Please enter a number.\n");
      continue; //skip to next iteration of loop
    }

    int guess = input - '0'; //convert char to int

    if (guess >= 1 && guess <= 100) //check if guess is within range
    {
      num_guesses++; //increment number of guesses

      if (guess == num_generated) //check if guess is correct
      {
        printf("Congratulations, you guessed the number!\n");
        printf("Your score is: %d\n", score);
        return 0; //end program
      }

      else if (guess < num_generated) //check if guess is too low
      {
        printf("Your guess is too low.\n");
        score += 10; //add points to score
      }

      else //guess is too high
      {
        printf("Your guess is too high.\n");
        score += 5; //add points to score
      }
    }

    else //guess is out of range
    {
      printf("Guess out of range. Please enter a number between 1 and 100.\n");
      continue; //skip to next iteration of loop
    }
  }

  printf("Sorry, you have used all of your attempts.\n");
  printf("The number was: %d\n", num_generated);
  printf("Your score is: %d\n", score);

  return 0; //end program
}