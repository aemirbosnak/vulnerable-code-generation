//FormAI DATASET v1.0 Category: Math exercise ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int player_score = 0, computer_score = 0;
  int turn_number = 1, max_turns = 10;

  srand(time(NULL)); //initialize random seed

  printf("Welcome to Math Game!\n");

  while(turn_number <= max_turns) {
    int num1 = rand() % 100; 
    int num2 = rand() % 100; 

    printf("Turn %d:\n", turn_number);
    printf("Player's turn:\nWhat is the sum of %d and %d?\n", num1, num2);
    
    int player_answer = 0;
    scanf("%d", &player_answer);
    
    int correct_answer = num1 + num2;
    if(player_answer == correct_answer) {
      printf("You are correct!\n");
      player_score++;
    } else {
      printf("You are wrong!\n");
      computer_score++;
    }
    
    printf("Computer's turn:\n");
    int comp_num1 = rand() % 100;
    int comp_num2 = rand() % 100;
    int comp_answer = comp_num1 + comp_num2;
    printf("What is the sum of %d and %d?\n", comp_num1, comp_num2);

    if(comp_answer == correct_answer) {
      printf("Computer is correct!\n");
      computer_score++;
    } else {
      printf("Computer is wrong!\n");
      player_score++;
    }
    
    printf("\nCurrent Scores:\nPlayer: %d\nComputer: %d\n", player_score, computer_score);
    
    turn_number++;
  }

  printf("Game Over!\n");
  printf("Final Scores:\nPlayer: %d\nComputer: %d\n", player_score, computer_score);
  
  if(player_score > computer_score) {
    printf("Congratulations! You win!\n");
  } else if(computer_score > player_score) {
    printf("Sorry! You lose!\n");
  } else {
    printf("It's a tie!\n");
  }

  return 0;
}