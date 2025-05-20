//FormAI DATASET v1.0 Category: Poker Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dealCards(int deck[]) {
  int val = deck[0];
  for (int i = 0; i < 51; i++) {
    deck[i] = deck[i + 1];
  }
  return val;
}

int main() {
  int deck[52];
  int suits = 4;
  int nums = 13;

  for (int i = 0; i < 52; i++) {
    deck[i] = i;
  }

  int player1[2];
  int player2[2];
  int shared[5];

  srand(time(NULL));

  player1[0] = dealCards(deck);
  player2[0] = dealCards(deck);
  player1[1] = dealCards(deck);
  player2[1] = dealCards(deck);

  for (int i = 0; i < 5; i++) {
    shared[i] = -1;
  }

  printf("Player 1: %d %d\n", player1[0], player1[1]);
  printf("Player 2: %d %d\n", player2[0], player2[1]);

  for (int i = 0; i < 3; i++) {
    shared[i] = dealCards(deck);
    printf("Shared card %d: %d\n", i + 1, shared[i]);
  }

  int bet1, bet2;
  printf("Player 1, place your bet: ");
  scanf("%d", &bet1);
  printf("Player 2, place your bet: ");
  scanf("%d", &bet2);

  int amount = bet1 < bet2 ? bet1 : bet2;

  printf("Pot: %d\n", amount * 2);

  printf("Turn Flop: ");
  shared[3] = dealCards(deck);
  printf("%d\n", shared[3]);

  printf("Player 1, check or raise: ");
  scanf("%d", &bet1);

  printf("Player 2, check or raise: ");
  scanf("%d", &bet2);

  amount = bet1 < bet2 ? bet1 : bet2;

  printf("Pot: %d\n", amount * 4);

  printf("Turn River: ");
  shared[4] = dealCards(deck);
  printf("%d\n", shared[4]);

  printf("Player 1, check or raise: ");
  scanf("%d", &bet1);

  printf("Player 2, check or raise: ");
  scanf("%d", &bet2);

  amount = bet1 < bet2 ? bet1 : bet2;

  printf("Pot: %d\n", amount * 8);

  printf("Turn End\n");
}