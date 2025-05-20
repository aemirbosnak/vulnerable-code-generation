//FormAI DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  srand(time(NULL)); // seed the random number generator with the current time
  
  int num1, num2, result, choice, answer;
  
  do {
    printf("\nWhat math operation would you like to practice?");
    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Quit\n");
    scanf("%d", &choice);
    
    if (choice == 5) {
      printf("\nThanks for playing! Goodbye.\n");
      return 0;
    }
    
    num1 = rand() % 100; // generate random number from 0 to 99
    num2 = rand() % 100;
    
    switch (choice) {
      
      case 1: // addition
        printf("\n%d + %d = ", num1, num2);
        scanf("%d", &answer);
        result = num1 + num2;
        break;
        
      case 2: // subtraction
        printf("\n%d - %d = ", num1, num2);
        scanf("%d", &answer);
        result = num1 - num2;
        break;
        
      case 3: // multiplication
        printf("\n%d * %d = ", num1, num2);
        scanf("%d", &answer);
        result = num1 * num2;
        break;
        
      case 4: // division
        printf("\n%d / %d = ", num1, num2);
        scanf("%d", &answer);
        result = num1 / num2;
        break;
    }
    
    if (result == answer) {
      printf("\nCongratulations! You got the right answer!\n");
    } else {
      printf("\nOops! The correct answer is: %d\n", result);
    }
    
  } while (choice != 5);
  
  return 0;
}