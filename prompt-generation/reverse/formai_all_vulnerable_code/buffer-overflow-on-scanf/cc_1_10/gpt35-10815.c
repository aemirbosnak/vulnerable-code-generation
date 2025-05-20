//FormAI DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Global variables
int action = 0;
int drama = 0;
int comedy = 0;

// Function prototypes
void welcomeMessage();
void askQuestion();
void displayResults();

int main() {

   welcomeMessage();
   askQuestion();
   displayResults();

   return 0;
}

void welcomeMessage() {
   printf("Welcome to the Unique C Movie Rating System!\n");
   printf("Please rate the following categories (1-10):\n");
}

void askQuestion() {
   printf("\nAction: ");
   scanf("%d", &action);

   printf("Drama: ");
   scanf("%d", &drama);

   printf("Comedy: ");
   scanf("%d", &comedy);
}

void displayResults() {
   printf("\nThank you for rating the categories!\n");
   printf("Here are your results:\n\n");
   printf("Action: %d\n", action);
   printf("Drama: %d\n", drama);
   printf("Comedy: %d\n", comedy);

   printf("\nBased on your ratings, here is our recommendation:\n");

   if (action > drama && action > comedy) {
      printf("You seem to enjoy action movies. We recommend you watch a thriller like 'John Wick'.\n");
   } else if (drama > action && drama > comedy) {
      printf("You seem to enjoy dramatic movies. We recommend you watch a tear-jerker like 'The Notebook'.\n");
   } else if (comedy > action && comedy > drama) {
      printf("You seem to enjoy comedy movies. We recommend you watch a hilarious movie like 'Bridesmaids'.\n");
   } else if (action == drama && drama == comedy) {
      printf("You seem to enjoy all genres of movies. We recommend you watch an epic movie like 'The Lord of the Rings'.\n");
   } else {
      printf("We're sorry, we couldn't provide you a recommendation based on your ratings. Please try again.\n");
   }
}