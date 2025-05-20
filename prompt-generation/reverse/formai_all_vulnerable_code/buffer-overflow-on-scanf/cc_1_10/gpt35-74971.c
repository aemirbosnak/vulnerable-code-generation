//FormAI DATASET v1.0 Category: Dice Roller ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rollDice(void);

int main(void) {
  int i, sum, roll1, roll2, point;
  srand(time(NULL));

  printf("\nA CRAPS GAME\n");

  do {
    printf("\nRolling the dice...\n");
    roll1 = rollDice();
    roll2 = rollDice();
    sum = roll1 + roll2;
    printf("You rolled %d + %d = %d\n", roll1, roll2, sum);

    switch(sum) {
      case 7:
      case 11:
        printf("You win!\n");
        break;

      case 2:
      case 3:
      case 12:
        printf("You lose!\n");
        break;

      default:
        printf("The point is %d\n", sum);
        point = sum;
        do {
          printf("\nRolling the dice...\n");
          roll1 = rollDice();
          roll2 = rollDice();
          sum = roll1 + roll2;
          printf("You rolled %d + %d = %d\n", roll1, roll2, sum);
        } while(sum != point && sum != 7);

        if(sum == point) {
          printf("You win!\n");
        } else {
          printf("You lose!\n");
        }
        break;
    }

    printf("\nDo you want to play again? (y/n): ");
    fflush(stdout);
    scanf(" %c", &i);
  } while(i == 'y' || i == 'Y');

  printf("\nThank you for playing!\n");

  return 0;
}

int rollDice(void) {
  return (1 + rand() % 6);
}