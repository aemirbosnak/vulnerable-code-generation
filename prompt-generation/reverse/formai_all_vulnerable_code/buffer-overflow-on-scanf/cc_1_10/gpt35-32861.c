//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int roll, turn_total, player_total = 0;
  char choice;

  printf("----- WELCOME TO THE ROLL-A-TABLE GAME -----\n");
  printf("You start with a score of 0. You will be given a dice to roll. If you roll less than 5, you lose your turn and your score remains the same. If you roll 5 or higher, you can choose to roll again or stop.\n");
  printf("If you choose to roll again, you will add the second roll to your turn total. If you roll less than 5 on the second roll, your turn ends and your turn total is reset to 0.\n");
  printf("If you choose to stop, your turn total will be added to your score. The first player to reach a score of 100 wins!\n\n");

  srand(time(0));

  while (player_total < 100) {
    turn_total = 0;
    printf("Your current score: %d\n", player_total);
    printf("Press any key to roll the dice!\n");
    getchar();

    roll = rand() % 6 + 1;
    printf("You rolled a %d!\n", roll);

    if (roll < 5) {
      printf("You lose your turn and your score remains %d.\n\n", player_total);
    }
    else {
      choice = 'r';

      while (choice == 'r') {
        printf("Roll again or stop? (r/s) ");
        scanf(" %c", &choice);

        if (choice == 'r') {
          roll = rand() % 6 + 1;
          printf("You rolled a %d!\n", roll);

          if (roll < 5) {
            printf("You lose your turn and your turn total is reset to 0.\n\n");
            turn_total = 0;
            break;
          }
          else {
            turn_total += roll;
            printf("Your turn total is %d. ", turn_total);
          }
        }
      }

      player_total += turn_total;
      printf("Your total score is now %d!\n\n", player_total);
    }
  }

  printf("Congratulations, you have won the game with a score of %d!", player_total);

  return 0;
}