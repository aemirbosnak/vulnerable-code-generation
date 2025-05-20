//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BINGO_SIZE 5
#define BINGO_NUMBERS 75

typedef struct {
  int numbers[BINGO_SIZE][BINGO_SIZE];
  int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void print_card(BingoCard *card) {
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      printf("%2d ", card->numbers[i][j]);
    }
    printf("\n");
  }
}

int check_card(BingoCard *card) {
  for (int i = 0; i < BINGO_SIZE; i++) {
    if (card->marked[i][0] && card->marked[i][1] && card->marked[i][2] && card->marked[i][3] && card->marked[i][4]) {
      return 1;
    }
    if (card->marked[0][i] && card->marked[1][i] && card->marked[2][i] && card->marked[3][i] && card->marked[4][i]) {
      return 1;
    }
  }
  if (card->marked[0][0] && card->marked[1][1] && card->marked[2][2] && card->marked[3][3] && card->marked[4][4]) {
    return 1;
  }
  if (card->marked[0][4] && card->marked[1][3] && card->marked[2][2] && card->marked[3][1] && card->marked[4][0]) {
    return 1;
  }
  return 0;
}

int main() {
  srand(time(NULL));

  BingoCard cards[4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      for (int k = 0; k < BINGO_SIZE; k++) {
        cards[i].numbers[j][k] = (rand() % BINGO_NUMBERS) + 1;
        cards[i].marked[j][k] = 0;
      }
    }
  }

  int numbers_drawn[BINGO_NUMBERS];
  for (int i = 0; i < BINGO_NUMBERS; i++) {
    numbers_drawn[i] = 0;
  }

  int number;
  while (1) {
    number = (rand() % BINGO_NUMBERS) + 1;
    if (numbers_drawn[number] == 0) {
      numbers_drawn[number] = 1;
      break;
    }
  }

  printf("Number drawn: %d\n", number);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      for (int k = 0; k < BINGO_SIZE; k++) {
        if (cards[i].numbers[j][k] == number) {
          cards[i].marked[j][k] = 1;
        }
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    printf("Card %d:\n", i + 1);
    print_card(&cards[i]);
    if (check_card(&cards[i])) {
      printf("BINGO!\n");
    }
    printf("\n");
  }

  return 0;
}