//FormAI DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the functions to be used
void display_intro();
int generate_random_number();
void play_game(int random_num, int guess);

int main()
{
   srand(time(NULL)); // Seed random number generator

   int random_num = generate_random_number(); // Generate random number
   int guess = -1;

   display_intro(); // Display game introduction

   while (guess != random_num)
   {
       printf("Enter your guess: ");
       scanf("%d", &guess);
       printf("\n"); // Add line break for clarity

       play_game(random_num, guess); // Check if the guess is correct
   }

   printf("Congratulations, you guessed the number!\n");
   return 0;
}

void display_intro()
{
   printf("Welcome to the Guessing Game! \n");
   printf("Try to guess the random number between 1 and 1000\n");
   printf("You have unlimited guesses\n\n");
}

int generate_random_number()
{
   return rand() % 1000 + 1; // Generate random number between 1 and 1000
}

void play_game(int random_num, int guess)
{
   if (guess > random_num)
   {
       printf("Too high! Guess again.\n");
   }
   else if (guess < random_num)
   {
       printf("Too low! Guess again.\n");
   }
   else
   {
       // Do nothing, the guess is correct
   }
}