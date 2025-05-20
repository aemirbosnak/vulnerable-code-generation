//FormAI DATASET v1.0 Category: Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int choice;
  int prevChoice = -1;
  int score = 0;
  srand(time(NULL)); //initialize random seed
  
  while (score < 10) { //play until the score is 10
    printf("Current score: %d\n", score);
    printf("Choose a shape:\n1. Square\n2. Circle\n3. Triangle\n");
    scanf("%d", &choice);
    
    if (choice == prevChoice && prevChoice != -1) { //if the same shape is chosen twice in a row
      printf("Shape already used. Penalty of -1 to score.\n");
      score -= 1;
      continue; //restart loop without executing remaining code
    }
    
    switch(choice) {
      case 1: //square
        printf("You have chosen a square!\n");
        score += 2;
        break;
        
      case 2: //circle
        printf("You have chosen a circle!\n");
        score += 1;
        break;
        
      case 3: //triangle
        printf("You have chosen a triangle!\n");
        score += 3;
        break;
        
      default: //invalid choice
        printf("Invalid choice. Penalty of -1 to score.\n");
        score -= 1;
        break;
    }
    
    prevChoice = choice; //store current choice as previous choice
  }
  
  printf("Congratulations! You have reached a score of 10.\n");
  
  return 0;
}