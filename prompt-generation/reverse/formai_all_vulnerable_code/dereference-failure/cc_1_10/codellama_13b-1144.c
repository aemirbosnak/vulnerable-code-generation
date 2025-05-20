//Code Llama-13B DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define NUM_PAIRS 5

typedef struct {
  int row;
  int col;
  char value;
} Card;

void print_card(Card card) {
  printf("%c", card.value);
}

void shuffle_cards(Card cards[MAX_ROWS][MAX_COLS]) {
  srand(time(NULL));
  for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
      int rand_i = rand() % MAX_ROWS;
      int rand_j = rand() % MAX_COLS;
      Card temp = cards[i][j];
      cards[i][j] = cards[rand_i][rand_j];
      cards[rand_i][rand_j] = temp;
    }
  }
}

void print_grid(Card cards[MAX_ROWS][MAX_COLS]) {
  for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
      Card card = cards[i][j];
      print_card(card);
    }
    printf("\n");
  }
}

void match_cards(Card cards[MAX_ROWS][MAX_COLS]) {
  for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
      Card card1 = cards[i][j];
      Card card2 = cards[i][j+1];
      if (card1.value == card2.value) {
        card1.value = ' ';
        card2.value = ' ';
      }
    }
  }
}

int main() {
  Card cards[MAX_ROWS][MAX_COLS];
  for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
      cards[i][j].row = i;
      cards[i][j].col = j;
      cards[i][j].value = 'A' + rand() % 26;
    }
  }
  shuffle_cards(cards);
  print_grid(cards);
  match_cards(cards);
  return 0;
}