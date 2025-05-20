//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int total_score;

void roll_dice(int *dice1, int *dice2) {
  srand(time(NULL));
  *dice1 = rand() % 6 + 1;
  *dice2 = rand() % 6 + 1;
  printf("Your roll: %d, %d\n", *dice1, *dice2);
}

void play_turn() {
  int dice1, dice2, sum;
  roll_dice(&dice1, &dice2);
  sum = dice1 + dice2;
  if (sum == 7 || sum == 11) {
    printf("You win!\n");
    total_score += 10;
  } else if (sum == 2 || sum == 3 || sum == 12) {
    printf("You lose :(\n");
    total_score -= 5;
  } else {
    printf("Roll again!\n");
    int point = sum;
    while (1) {
      roll_dice(&dice1, &dice2);
      sum = dice1 + dice2;
      if (sum == point) {
        printf("You rolled your point! You win!\n");
        total_score += 5;
        break;
      } else if (sum == 7) {
        printf("You rolled a seven. You lose :(\n");
        total_score -= 5;
        break;
      }
    }
  }
  printf("Your current total score is: %d\n\n", total_score);
}

int main() {
  printf("Welcome to the C Table Game!\n");
  while (1) {
    printf("Press any key to play a turn or 'q' to quit: ");
    char input;
    scanf("%c", &input);
    if (input == 'q') {
      printf("Thanks for playing! Your final score is: %d\n", total_score);
      break;
    } else {
      getchar(); // stifle newline character from scanf
      play_turn();
    }
  }
  return 0;
}