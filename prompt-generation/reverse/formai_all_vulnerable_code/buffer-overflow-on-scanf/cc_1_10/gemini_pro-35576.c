//GEMINI-pro DATASET v1.0 Category: Poker Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  STRAIGHT_FLUSH = 0,
  FOUR_OF_A_KIND,
  FULL_HOUSE,
  FLUSH,
  STRAIGHT,
  THREE_OF_A_KIND,
  TWO_PAIR,
  ONE_PAIR,
  HIGH_CARD
} HandRank;

typedef struct {
  int rank;
  int suit;
} Card;

typedef struct {
  Card cards[5];
  HandRank rank;
} Hand;

int compare_cards(const void *a, const void *b) {
  const Card *card1 = a;
  const Card *card2 = b;

  return card1->rank - card2->rank;
}

HandRank evaluate_hand(Hand *hand) {
  qsort(hand->cards, 5, sizeof(Card), compare_cards);

  int ranks[5];
  int suits[4];

  for (int i = 0; i < 5; i++) {
    ranks[i] = hand->cards[i].rank;
    suits[hand->cards[i].suit]++;
  }

  if (ranks[0] == ranks[4] && suits[0] == 5) {
    return STRAIGHT_FLUSH;
  } else if (ranks[0] == ranks[3] || ranks[1] == ranks[4]) {
    return FOUR_OF_A_KIND;
  } else if (ranks[0] == ranks[2] && ranks[3] == ranks[4]) {
    return FULL_HOUSE;
  } else if (suits[0] == 5 || suits[1] == 5 || suits[2] == 5 || suits[3] == 5) {
    return FLUSH;
  } else if (ranks[0] == ranks[4] - 4) {
    return STRAIGHT;
  } else if (ranks[0] == ranks[2] || ranks[1] == ranks[3] || ranks[2] == ranks[4]) {
    return THREE_OF_A_KIND;
  } else if (ranks[0] == ranks[1] && ranks[2] == ranks[3]) {
    return TWO_PAIR;
  } else if (ranks[0] == ranks[1] || ranks[1] == ranks[2] || ranks[2] == ranks[3] || ranks[3] == ranks[4]) {
    return ONE_PAIR;
  } else {
    return HIGH_CARD;
  }
}

int main() {
  Hand hand;

  for (int i = 0; i < 5; i++) {
    scanf("%d %d", &hand.cards[i].rank, &hand.cards[i].suit);
  }

  HandRank rank = evaluate_hand(&hand);

  printf("%d\n", rank);

  return 0;
}