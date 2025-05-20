//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int choice1, choice2;
  int p1score = 0, p2score = 0;
  srand(time(NULL));
  printf("\nWelcome to Rock-Paper-Scissors game!\n");
  printf("\nPlayer 1, please choose 1 for Rock, 2 for Paper, or 3 for Scissors: ");
  scanf("%d", &choice1);
  printf("Player 2, please choose 1 for Rock, 2 for Paper, or 3 for Scissors: ");
  scanf("%d", &choice2);
  if(choice1 == 1) {
    printf("Player 1 chose Rock.\n");
    if(choice2 == 1) {
      printf("Player 2 also chose Rock. It's a tie!\n");
    }
    else if(choice2 == 2) {
      printf("Player 2 chose Paper. Player 2 wins!\n");
      p2score++;
    }
    else {
      printf("Player 2 chose Scissors. Player 1 wins!\n");
      p1score++;
    }
  }
  else if(choice1 == 2) {
    printf("Player 1 chose Paper.\n");
    if(choice2 == 1) {
      printf("Player 2 chose Rock. Player 1 wins!\n");
      p1score++;
    }
    else if(choice2 == 2) {
      printf("Player 2 also chose Paper. It's a tie!\n");
    }
    else {
      printf("Player 2 chose Scissors. Player 2 wins!\n");
      p2score++;
    }
  }
  else {
    printf("Player 1 chose Scissors.\n");
    if(choice2 == 1) {
      printf("Player 2 chose Rock. Player 2 wins!\n");
      p2score++;
    }
    else if(choice2 == 2) {
      printf("Player 2 chose Paper. Player 1 wins!\n");
      p1score++;
    }
    else {
      printf("Player 2 also chose Scissors. It's a tie!\n");
    }
  }
  printf("\nPlayer 1 score: %d\n", p1score);
  printf("Player 2 score: %d\n\n", p2score);
  return 0;
}