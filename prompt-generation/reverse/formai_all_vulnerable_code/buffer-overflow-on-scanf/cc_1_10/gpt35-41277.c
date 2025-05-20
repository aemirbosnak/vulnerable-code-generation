//FormAI DATASET v1.0 Category: Educational ; Style: brave
#include <stdio.h>

int main() {
   printf("Welcome to the Brave C Educational Example Program!\n");
   
   int age;
   printf("How old are you (in years)? ");
   scanf("%d", &age);
   
   if (age < 18) {
      printf("Sorry, you're not old enough to brave this program.\n");
      return 0;
   }
   
   printf("Awesome! You're braver than we thought.\n");
   
   printf("To test your bravery, we're going to play a game.\n");
   printf("Are you ready?\n");
   printf("(Type 1 for Yes or 0 for No)\n");
   
   int ready;
   scanf("%d", &ready);
   
   if (!ready) {
      printf("No? That's okay, come back to the program when you're feeling braver.\n");
      return 0;
   }
   
   printf("Great! Let's play.\n");
   printf("I'm going to pick a number between 1 and 10, and you have to guess it.\n");
   
   int number = 7;
   int guess;
   int guesses = 0;
   
   while (guesses < 3) {
      printf("Guess a number: ");
      scanf("%d", &guess);
      
      if (guess == number) {
         printf("You got it! You're truly brave!\n");
         return 0;
      } else if (guess < number) {
         printf("Too low! Try again!\n");
      } else {
         printf("Too high! Try again!\n");
      }
      
      guesses++;
   }
   
   printf("Sorry, you've run out of guesses. Better luck next time!\n");
   
   return 0;
}