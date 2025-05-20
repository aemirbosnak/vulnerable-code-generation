//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  printf("Welcome to the C Table Game!\n");
  printf("In this game, you will be playing against the computer.\n");
  printf("The objective of the game is to finish with the highest score.\n");
  printf("We will both be rolling a pair of dice, and whoever rolls the highest total wins that round.\n");
  printf("We will keep playing until all of the rounds have been played.\n");
  printf("Ready? Let's get started!\n\n");

  int rounds;
  printf("How many rounds would you like to play? ");
  scanf("%d", &rounds);

  int player_total = 0;
  int comp_total = 0;

  srand(time(0));
  for (int i = 1; i <= rounds; i++) {
    printf("Round %d\n", i);
    int player_roll1 = (rand() % 6) + 1;
    int player_roll2 = (rand() % 6) + 1;
    int player_sum = player_roll1 + player_roll2;
    printf("You rolled a %d and a %d.\n", player_roll1, player_roll2);
    printf("Your total score for this round is %d.\n", player_sum);
    player_total += player_sum;

    int comp_roll1 = (rand() % 6) + 1;
    int comp_roll2 = (rand() % 6) + 1;
    int comp_sum = comp_roll1 + comp_roll2;
    printf("The computer rolled a %d and a %d.\n", comp_roll1, comp_roll2);
    printf("The computer's total score for this round is %d.\n", comp_sum);
    comp_total += comp_sum;

    if (player_sum > comp_sum) {
      printf("Congratulations, you won this round!\n");
    } else if (player_sum < comp_sum) {
      printf("Sorry, the computer won this round.\n");
    } else {
      printf("It's a tie!\n");
    }

    printf("\n");
  }

  printf("Game over!\n");

  if (player_total > comp_total) {
    printf("Congratulations, you won the game with a total score of %d!\n", player_total);
  } else if (player_total < comp_total) {
    printf("Sorry, you lost the game. The computer ended up with the highest score of %d.\n", comp_total);
  } else {
    printf("It's a tie! Both you and the computer ended up with a total score of %d.\n", player_total);
  }

  return 0;
}