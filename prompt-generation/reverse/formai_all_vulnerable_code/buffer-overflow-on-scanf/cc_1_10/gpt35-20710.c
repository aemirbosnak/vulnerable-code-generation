//FormAI DATASET v1.0 Category: Table Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int money = 1000; // player's starting money
  int bet;
  int sum;
  int guess;
  char choice;

  printf("Welcome to Lucky 7! You have $%d.\n", money);

  // loop until the player runs out of money or chooses to quit
  while (money > 0) {
    printf("How much do you want to bet? ");
    scanf("%d", &bet);

    // check if the player can afford the bet
    if (bet > money) {
      printf("You don't have enough money to bet $%d\n", bet);
      continue;
    }

    // roll the dice
    srand(time(NULL));
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    sum = dice1 + dice2;
    printf("The dealer rolls the dice: %d, %d.\n", dice1, dice2);

    printf("What's your guess for the sum of two dice? ");
    scanf("%d", &guess);

    // check if the player guessed correctly
    if (guess == sum) {
      printf("You win $%d!\n", bet * 2);
      money += bet;
    } else {
      printf("You lose $%d.\n", bet);
      money -= bet;
    }

    printf("You have $%d. Do you want to continue playing? (y/n) ", money);
    scanf(" %c", &choice);

    if (choice != 'y' && choice != 'Y') {
      break;
    }
  }

  printf("Thanks for playing Lucky 7! You walk away with $%d.\n", money);

  return 0;
}