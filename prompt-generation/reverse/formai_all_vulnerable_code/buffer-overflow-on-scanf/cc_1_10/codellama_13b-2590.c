//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BINGO_SIZE 5
#define BINGO_NUM_CARDS 3

typedef struct {
  char numbers[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void generate_bingo_card(BingoCard* card) {
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      card->numbers[i][j] = rand() % 9 + 1;
    }
  }
}

void print_bingo_card(BingoCard* card) {
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      printf("%d ", card->numbers[i][j]);
    }
    printf("\n");
  }
}

int check_bingo(BingoCard* card) {
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      if (card->numbers[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  srand(time(NULL));

  BingoCard cards[BINGO_NUM_CARDS];
  for (int i = 0; i < BINGO_NUM_CARDS; i++) {
    generate_bingo_card(&cards[i]);
    print_bingo_card(&cards[i]);
  }

  printf("Enter a number: ");
  int num;
  scanf("%d", &num);

  for (int i = 0; i < BINGO_NUM_CARDS; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      for (int k = 0; k < BINGO_SIZE; k++) {
        if (cards[i].numbers[j][k] == num) {
          cards[i].numbers[j][k] = 0;
        }
      }
    }
  }

  for (int i = 0; i < BINGO_NUM_CARDS; i++) {
    if (check_bingo(&cards[i])) {
      printf("Bingo! Card %d is the winner!\n", i + 1);
    }
  }

  return 0;
}