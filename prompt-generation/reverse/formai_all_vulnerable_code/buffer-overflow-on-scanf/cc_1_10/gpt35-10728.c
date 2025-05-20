//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // seed for random number generator
   int e_prob, t_prob, u_prob; // variables to hold probability values
   char letter, choice; // variables to hold user input
   
   printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
   printf("Do you think your planet is at risk of an alien invasion? (Y/N) ");
   scanf("%c", &choice);
   
   // If user thinks their planet is at risk
   if (choice == 'Y' || choice == 'y') {
      printf("Let's calculate the probability of an alien invasion on your planet.\n");
      printf("Please enter the first letter of your planet's name: ");
      scanf(" %c", &letter);
      
      // Calculate probability based on first letter of planet's name
      if (letter == 'a' || letter == 'A') {
         e_prob = rand() % 90 + 10; // Earth-like planet probability
         t_prob = rand() % 70 + 20; // Technology probability
         u_prob = rand() % 50 + 50; // Unknown factor probability
      }
      else if (letter == 'b' || letter == 'B') {
         e_prob = rand() % 70 + 30;
         t_prob = rand() % 80 + 10;
         u_prob = rand() % 60 + 40;
      }
      else if (letter == 'c' || letter == 'C') {
         e_prob = rand() % 50 + 50;
         t_prob = rand() % 90 + 5;
         u_prob = rand() % 70 + 30;
      }
      else {
         e_prob = rand() % 80 + 20;
         t_prob = rand() % 70 + 30;
         u_prob = rand() % 80 + 20;
      }
      
      printf("\nBased on the first letter of your planet's name, the probability of an alien invasion is:\n");
      printf("Earth-like planet probability: %d%%\n", e_prob);
      printf("Technology probability: %d%%\n", t_prob);
      printf("Unknown factor probability: %d%%\n", u_prob);
      printf("\nRemember, these are just probabilities. Your planet may or may not be at risk of an alien invasion.\n");
   }
   else {
      printf("Thank you for using the Alien Invasion Probability Calculator!\n");
   }
   
   return 0;
}