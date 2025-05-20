//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int choice, guess, number, count = 1;
   char playerName[20];

   printf("Welcome to the C Table Game!\n");
   printf("Please enter your name: ");
   scanf("%s", playerName);

   printf("Hello %s!\n", playerName);
   printf("Choose an option: \n");
   printf("1. Guess the Number\n");
   printf("2. Roll the Dice\n");
   printf("Enter your choice (1 or 2): ");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         printf("Guess the number between 1 and 50\n");
         srand(time(NULL));
         number = rand() % 50 + 1;

         do {
            printf("Guess #%d: ", count);
            scanf("%d", &guess);

            if (guess > number) {
               printf("Wrong guess, try again with a smaller number\n");
               count++;
            }
            else if (guess < number) {
               printf("Wrong guess, try again with a larger number\n");
               count++;
            }
         } while (guess != number);

         printf("Congratulations %s! You guessed the number in %d tries\n", playerName, count);
         break;

      case 2:
         printf("Rolling the dice...\n");
         srand(time(NULL));
         number = rand() % 6 + 1;
         printf("You rolled a %d\n", number);
         break;

      default:
         printf("Invalid choice\n");
   }

   return 0;
}