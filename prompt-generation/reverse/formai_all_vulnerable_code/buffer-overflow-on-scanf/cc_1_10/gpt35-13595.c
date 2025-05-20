//FormAI DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int dice[6] = {0};
  int num_rolls, roll, i, j;

  // ask user for number of rolls
  printf("How many times do you want to roll the dice? ");
  scanf("%d", &num_rolls);

  // seed the random number generator with current time
  srand(time(NULL));

  // roll the dice for the specified number of times
  for(i = 0; i < num_rolls; i++) {
    roll = rand() % 6 + 1; // generate random number between 1 and 6

    // increment count for the rolled value
    switch(roll) {
      case 1:
        dice[0]++;
        break;
      case 2:
        dice[1]++;
        break;
      case 3:
        dice[2]++;
        break;
      case 4:
        dice[3]++;
        break;
      case 5:
        dice[4]++;
        break;
      case 6:
        dice[5]++;
        break;
      default:
        printf("Error: invalid dice value!\n");
    }
  }

  // display the results
  printf("\nDice Rolls:\n");
  for(j = 0; j < 6; j++) {
    printf("%d: %d\n", j+1, dice[j]);
  }

  return 0;
}