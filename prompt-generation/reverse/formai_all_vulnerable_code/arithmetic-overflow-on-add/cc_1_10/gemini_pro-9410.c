//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define CARDS SIZE * SIZE

typedef struct {
  int value;
  int revealed;
} Card;

void shuffle(Card *cards) {
  int i, j;
  Card temp;
  for (i = 0; i < CARDS; i++) {
    j = rand() % CARDS;
    temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }
}

void print_board(Card *cards) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (cards[i * SIZE + j].revealed) {
        printf("%2d ", cards[i * SIZE + j].value);
      } else {
        printf("## ");
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  Card cards[CARDS];
  int i, j, first_card, second_card;
  int matches = 0;

  for (i = 0; i < CARDS / 2; i++) {
    for (j = 0; j < 2; j++) {
      cards[2 * i + j].value = i + 1;
      cards[2 * i + j].revealed = 0;
    }
  }

  shuffle(cards);

  while (matches < CARDS / 2) {
    print_board(cards);

    printf("Enter first card (row, column): ");
    scanf("%d %d", &first_card, &second_card);
    first_card--;
    second_card--;

    printf("Enter second card (row, column): ");
    scanf("%d %d", &i, &j);
    i--;
    j--;

    if (cards[first_card * SIZE + second_card].value == cards[i * SIZE + j].value) {
      cards[first_card * SIZE + second_card].revealed = 1;
      cards[i * SIZE + j].revealed = 1;
      matches++;
    } else {
      printf("No match!\n");
    }
  }

  printf("You win!\n");

  return 0;
}