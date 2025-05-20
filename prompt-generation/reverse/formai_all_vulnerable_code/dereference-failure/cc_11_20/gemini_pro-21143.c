//GEMINI-pro DATASET v1.0 Category: Poker Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int rank;
  char suit;
} Card;

typedef struct {
  Card *cards;
  int num_cards;
  int score;
} Hand;

int compare_cards(const void *a, const void *b) {
  Card *card1 = (Card *)a;
  Card *card2 = (Card *)b;

  return card1->rank - card2->rank;
}

int get_hand_score(Hand *hand) {
  int i;
  int score = 0;

  // Sort the cards in the hand.
  qsort(hand->cards, hand->num_cards, sizeof(Card), compare_cards);

  // Check for a straight.
  if (hand->num_cards == 5) {
    for (i = 0; i < hand->num_cards - 1; i++) {
      if (hand->cards[i].rank + 1 != hand->cards[i + 1].rank) {
        break;
      }
    }

    if (i == hand->num_cards - 1) {
      score += 4;
    }
  }

  // Check for a flush.
  if (hand->num_cards == 5) {
    for (i = 0; i < hand->num_cards - 1; i++) {
      if (hand->cards[i].suit != hand->cards[i + 1].suit) {
        break;
      }
    }

    if (i == hand->num_cards - 1) {
      score += 5;
    }
  }

  // Check for a full house.
  if (hand->num_cards == 5) {
    if (hand->cards[0].rank == hand->cards[1].rank &&
        hand->cards[1].rank == hand->cards[2].rank &&
        hand->cards[3].rank == hand->cards[4].rank) {
      score += 6;
    }

    if (hand->cards[0].rank == hand->cards[1].rank &&
        hand->cards[2].rank == hand->cards[3].rank &&
        hand->cards[3].rank == hand->cards[4].rank) {
      score += 6;
    }
  }

  // Check for a four of a kind.
  if (hand->num_cards == 5) {
    if (hand->cards[0].rank == hand->cards[1].rank &&
        hand->cards[1].rank == hand->cards[2].rank &&
        hand->cards[2].rank == hand->cards[3].rank) {
      score += 7;
    }

    if (hand->cards[1].rank == hand->cards[2].rank &&
        hand->cards[2].rank == hand->cards[3].rank &&
        hand->cards[3].rank == hand->cards[4].rank) {
      score += 7;
    }
  }

  // Check for a three of a kind.
  if (hand->num_cards == 5) {
    if (hand->cards[0].rank == hand->cards[1].rank &&
        hand->cards[1].rank == hand->cards[2].rank) {
      score += 3;
    }

    if (hand->cards[1].rank == hand->cards[2].rank &&
        hand->cards[2].rank == hand->cards[3].rank) {
      score += 3;
    }

    if (hand->cards[2].rank == hand->cards[3].rank &&
        hand->cards[3].rank == hand->cards[4].rank) {
      score += 3;
    }
  }

  // Check for a two pair.
  if (hand->num_cards == 5) {
    if (hand->cards[0].rank == hand->cards[1].rank &&
        hand->cards[2].rank == hand->cards[3].rank) {
      score += 2;
    }

    if (hand->cards[1].rank == hand->cards[2].rank &&
        hand->cards[3].rank == hand->cards[4].rank) {
      score += 2;
    }
  }

  // Check for a pair.
  if (hand->num_cards == 5) {
    for (i = 0; i < hand->num_cards - 1; i++) {
      if (hand->cards[i].rank == hand->cards[i + 1].rank) {
        score += 1;
        break;
      }
    }
  }

  return score;
}

int main() {
  Hand hand;
  int i;

  // Create a new hand.
  hand.cards = malloc(5 * sizeof(Card));
  hand.num_cards = 5;

  // Get the cards for the hand.
  for (i = 0; i < hand.num_cards; i++) {
    printf("Enter the rank of card %d: ", i + 1);
    scanf("%d", &hand.cards[i].rank);

    printf("Enter the suit of card %d: ", i + 1);
    scanf(" %c", &hand.cards[i].suit);
  }

  // Get the score for the hand.
  hand.score = get_hand_score(&hand);

  // Print the score for the hand.
  printf("The score for the hand is: %d\n", hand.score);

  // Free the memory for the hand.
  free(hand.cards);

  return 0;
}