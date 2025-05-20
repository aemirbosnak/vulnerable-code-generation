//FormAI DATASET v1.0 Category: Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator
  int shape = 0; // initialize the starting shape
  int score = 0; // initialize the starting score
  printf("Welcome to the Shape Shifting Game!\n");
  printf("Instructions: Shapeshift your way through different shapes to earn points. But be careful, some shapes are worth more than others!\n");

  while (1) { // infinite loop until the user quits
    int random_num = rand() % 10 + 1; // generate a random number between 1-10
    if (random_num <= 3) { // 30% chance of getting a square
      shape = 1;
      printf("You got a square!\n");
    }
    else if (random_num <= 6) { // 30% chance of getting a circle
      shape = 2;
      printf("You got a circle!\n");
    }
    else if (random_num <= 8) { // 20% chance of getting a triangle
      shape = 3;
      printf("You got a triangle!\n");
    }
    else { // 20% chance of getting a star
      shape = 4;
      printf("You got a star!\n");
    }
    
    // logic to calculate points based on the previous shape and current shape
    int points = 0;
    if (shape == 1) { // square
      if (score % 2 == 0) { // even points = 2 points
        points = 2;
      }
      else { // odd points = 1 point
        points = 1;
      }
    }
    else if (shape == 2) { // circle
      if (score % 3 == 0) { // multiple of 3 points = 3 points
        points = 3;
      }
      else { // not multiple of 3 points = 1 point
        points = 1;
      }
    }
    else if (shape == 3) { // triangle
      if (score % 5 == 0) { // multiple of 5 points = 5 points
        points = 5;
      }
      else { // not multiple of 5 points = 2 points
        points = 2;
      }
    }
    else if (shape == 4) { // star
      if (score % 7 == 0) { // multiple of 7 points = 7 points
        points = 7;
      }
      else { // not multiple of 7 points = 3 points
        points = 3;
      }
    }
    
    printf("You earned %d points!\n", points);
    score += points; // add points to the score
    printf("Your current score is %d\n", score);
    
    // ask user if they want to continue playing
    int play_again = 0;
    printf("Do you want to continue playing? (1 for YES, 0 for NO): ");
    scanf("%d", &play_again);
    if (play_again == 0) { // user wants to quit
      printf("Thanks for playing! Your final score is %d\n", score);
      break; // exit the while loop
    }
  }
  
  return 0;
}