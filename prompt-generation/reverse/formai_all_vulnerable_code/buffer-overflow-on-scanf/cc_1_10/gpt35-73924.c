//FormAI DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 20

char cards[MAX_CARDS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

int flipped[MAX_CARDS] = {0};

void shuffle_cards() {
  int i;
  srand(time(NULL));
  for (i = 0; i < MAX_CARDS; i++) {
    int r = rand() % (MAX_CARDS - i) + i;
    char temp = cards[i];
    cards[i] = cards[r];
    cards[r] = temp;
  }
}

void print_cards() {
  int i;
  for (i = 0; i < MAX_CARDS; i++) {
    printf("%c ", flipped[i] ? cards[i] : '*');
    if (i % 5 == 4) printf("\n");
  }
  printf("\n");
}

int all_flipped() {
  int i;
  for (i = 0; i < MAX_CARDS; i++) {
    if (!flipped[i]) return 0;
  }
  return 1;
}

int main() {
  int num_players;

  printf("Welcome to the Memory game!\n");

  do {
    printf("Enter number of players (1-4): ");
    scanf("%d", &num_players);
  } while (num_players < 1 || num_players > 4);

  printf("Shuffling the cards...\n");
  shuffle_cards();

  int current_player = 0;
  int pairs_found[MAX_PLAYERS] = {0};

  while (!all_flipped()) {
    printf("Scoreboard:\n");
    int i;
    for (i = 0; i < num_players; i++) {
      printf("Player %d: %d pairs found\n", i + 1, pairs_found[i]);
    }

    printf("Current board:\n");
    print_cards();

    int card1, card2;

    do {
      printf("Player %d, enter first card number (1-20): ",
             current_player + 1);
      scanf("%d", &card1);
    } while (card1 < 1 || card1 > 20 || flipped[card1 - 1]);

    do {
      printf("Player %d, enter second card number (1-20): ",
             current_player + 1);
      scanf("%d", &card2);
    } while (card2 < 1 || card2 > 20 || flipped[card2 - 1] || card2 == card1);

    card1--;
    card2--;

    if (cards[card1] == cards[card2]) {
      printf("Player %d found a pair!\n", current_player + 1);
      flipped[card1] = 1;
      flipped[card2] = 1;
      pairs_found[current_player]++;
    } else {
      printf("No match, next player's turn!\n");
      current_player = (current_player + 1) % num_players;
    }
  }

  printf("Game over!\n");
  printf("Final scoreboard:\n");
  int i;
  for (i = 0; i < num_players; i++) {
    printf("Player %d: %d pairs found\n", i + 1, pairs_found[i]);
  }

  return 0;
}