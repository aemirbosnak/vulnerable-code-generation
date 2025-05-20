//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome message
  printf("Welcome to the Brave Bingo Simulator!\n");

  // Ask for number of players
  int num_players;
  printf("How many players will be in the game?\n");
  scanf("%d", &num_players);

  // Ask for number of rounds
  int num_rounds;
  printf("How many rounds will be played?\n");
  scanf("%d", &num_rounds);

  // Initialize players' cards
  int cards[num_players][5][5];
  for (int i = 0; i < num_players; i++) {
    printf("Enter card for player %d:\n", i+1);
    for (int row = 0; row < 5; row++) {
      for (int col = 0; col < 5; col++) {
        scanf("%d", &cards[i][row][col]);
      }
    }
  }

  // Display players' cards
  printf("Players' cards:\n");
  for (int i = 0; i < num_players; i++) {
    printf("Player %d:\n", i+1);
    for (int row = 0; row < 5; row++) {
      for (int col = 0; col < 5; col++) {
        printf("%2d ", cards[i][row][col]);
      }
      printf("\n");
    }
  }

  // Initialize random number generator
  srand(time(NULL));

  // Play rounds
  for (int round = 1; round <= num_rounds; round++) {
    printf("ROUND %d:\n", round);
    int called_nums[75] = {0};
    int num_called = 0;
    int winner = -1;
    while (num_called < 75 && winner < 0) {
      // Call a random number between 1 and 75
      int num = rand() % 75 + 1;
      // Check if number has already been called
      if (called_nums[num-1] == 0) {
        called_nums[num-1] = 1;
        num_called++;
        printf("Number called: %d\n", num);
        // Check players' cards for matching number
        for (int i = 0; i < num_players; i++) {
          int bingo_count = 0;
          for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
              if (cards[i][row][col] == num) {
                cards[i][row][col] = 0;
                bingo_count++;
              }
            }
            // Check for bingo on a row
            if (bingo_count == 5) {
              winner = i;
              break;
            }
          }
          // Check for bingo on a column
          if (bingo_count < 5) {
            for (int col = 0; col < 5; col++) {
              bingo_count = 0;
              for (int row = 0; row < 5; row++) {
                if (cards[i][row][col] == 0) {
                  bingo_count++;
                }
              }
              if (bingo_count == 5) {
                winner = i;
                break;
              }
            }
          }
          // Check for bingo on a diagonal
          if (bingo_count < 5) {
            if (cards[i][0][0] == 0 && cards[i][1][1] == 0 &&
                cards[i][2][2] == 0 && cards[i][3][3] == 0 &&
                cards[i][4][4] == 0) {
              winner = i;
              break;
            }
            if (cards[i][0][4] == 0 && cards[i][1][3] == 0 &&
                cards[i][2][2] == 0 && cards[i][3][1] == 0 &&
                cards[i][4][0] == 0) {
              winner = i;
              break;
            }
          }
        }
      }
    }
    // Display winner (if any) for the round
    if (winner >= 0) {
      printf("We have a winner! Congratulations Player %d!\n", winner+1);
    } else {
      printf("No winner in this round.\n");
    }
  }

  // End of simulation message
  printf("End of Brave Bingo Simulator. Thanks for playing!\n");

  return 0;
}