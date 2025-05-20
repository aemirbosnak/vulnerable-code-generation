//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  printf("Welcome to the C Table Game!\n");
  printf("In this game, you will roll a pair of dice and try to land on a certain number.\n");
  printf("The goal is to reach that number in as few rolls as possible.\n");
  
  int target_num = 0;
  int roll_num = 0;
  int current_total = 0;
  
  printf("Please enter the target number: ");
  scanf("%d", &target_num);
  
  // Seeding the random number generator
  srand(time(NULL));
  
  // Game loop
  while (current_total != target_num) {
    
    // Roll the dice
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    
    // Calculate total and increment roll counter
    current_total += dice1 + dice2;
    roll_num++;
    
    printf("You rolled a %d and a %d, for a total of %d.\n", dice1, dice2, current_total);
    
    // Check if target number has been reached
    if (current_total == target_num) {
      
      printf("Congratulations! You reached your target number in %d rolls.\n", roll_num);
      break;
      
    } else if (current_total > target_num) {
      
      printf("Oh no! You went over your target number. Better luck next time!\n");
      break;
      
    } else {
      
      printf("Keep rolling!\n");
      
    }
  
  }
  
  return 0;
}