//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int player_choice, correct_solution, tries = 0, score = 0;
  srand(time(0)); // Set seed for random number generator
  
  printf("Welcome to the Math Adventure Game!\n");
  
  while (tries < 3) { // Player gets 3 tries to answer each question
    int x = rand() % 20 + 1; // Random number from 1 to 20
    int y = rand() % 20 + 1;
    int operation = rand() % 3; // Random operation: 0 = add, 1 = subtract, 2 = multiply
    
    printf("\nQuestion %d:\n", tries + 1);
    
    if (operation == 0) {
      correct_solution = x + y;
      printf("%d + %d = ?\n", x, y);
    } else if (operation == 1) {
      correct_solution = x - y;
      printf("%d - %d = ?\n", x, y);
    } else {
      correct_solution = x * y;
      printf("%d * %d = ?\n", x, y);
    }
    
    printf("Enter your answer: ");
    scanf("%d", &player_choice);
    
    if (player_choice == correct_solution) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct answer is %d.\n", correct_solution);
    }
    
    tries++;
  }
  
  printf("\nYour final score is %d out of 3. ", score);
  
  if (score == 3) {
    printf("Excellent job!\n");
  } else if (score == 2) {
    printf("Good job!\n");
  } else if (score == 1) {
    printf("Better luck next time!\n");
  } else {
    printf("Sorry, you need to practice your math skills.\n");
  }
  
  return 0;
}