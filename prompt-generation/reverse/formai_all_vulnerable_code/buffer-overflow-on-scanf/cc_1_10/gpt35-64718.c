//FormAI DATASET v1.0 Category: Data validation ; Style: funny
#include <stdio.h>
#include <stdbool.h>

int main() {
   printf("Hello there! Let's play a game of data validation, shall we?\n");
   printf("I'll ask you to enter your age, and you'll have to tell me the truth. Ready? Go!\n");

   bool valid_age = false;
   int age = 0;

   while (!valid_age) {
      printf("Please enter your age: ");
      scanf("%d", &age);

      if (age <= 0) {
         printf("Come on, now! You can't be negative or zero years old. Let's try this again.\n");
      } else if (age >= 120) {
         printf("Wow, you must be immortal! But seriously, please enter your real age.\n");
      } else {
         printf("Great job! You entered a valid age.\n");
         valid_age = true;
      }
   }

   printf("\nNow let's move on to height. Please enter your height in inches: ");

   bool valid_height = false;
   int height = 0;

   while (!valid_height) {
      scanf("%d", &height);

      if (height <= 0) {
         printf("Sorry, I don't think you're an ant. Please enter a valid height.\n");
      } else if (height >= 96) {
         printf("Hold on there, giant! Please enter a valid height.\n");
      } else {
         printf("Awesome! You entered a valid height.\n");
         valid_height = true;
      }
   }

   printf("\nLast but not least, let's check your weight. Please enter your weight in pounds: ");

   bool valid_weight = false;
   int weight = 0;

   while (!valid_weight) {
      scanf("%d", &weight);

      if (weight <= 0) {
         printf("Nice try, but you can't be weightless. Enter a valid weight.\n");
      } else if (weight >= 1000) {
         printf("That's no moon, it's a space station! Please enter a valid weight.\n");
      } else {
         printf("Wonderful! You entered a valid weight.\n");
         valid_weight = true;
      }
   }

   printf("\nCongratulations! You have successfully passed the data validation test. You are officially a human being.\n");

   return 0;
}