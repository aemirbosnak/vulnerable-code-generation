//GEMINI-pro DATASET v1.0 Category: Poker Game ; Style: mind-bending
#define DECK_SIZE 52
#define HAND_SIZE 5
#define SUITS "♠♣♦♥"
#define RANKS "23456789TJQKA"
#define FLUSH_MASK 0xF000
#define STRAIGHT_MASK 0x7C00
#define HIGH_CARD_MASK 0x03FF
#define PAIR_MASK (0x0003 << 12)
#define TWO_PAIR_MASK (0x000C << 12)
#define THREE_KIND_MASK (0x0030 << 12)
#define FULL_HOUSE_MASK (0x00C0 << 12)
#define FOUR_KIND_MASK (0x0300 << 12)
#define STRAIGHT_FLUSH_MASK (0x7000)

typedef unsigned short hand_t;

hand_t deal_hand() {
  hand_t hand = 0;
  for (int i = 0; i < HAND_SIZE; i++) {
    hand |= 1 << (rand() % DECK_SIZE);
  }
  return hand;
}

char* get_rank(hand_t hand) {
  return RANKS + ((hand & HIGH_CARD_MASK) >> 12);
}

char* get_suit(hand_t hand) {
  return SUITS + ((hand & FLUSH_MASK) >> 12);
}

int get_score(hand_t hand) {
  int score = 0;
  if (hand & STRAIGHT_FLUSH_MASK) score += 9;
  else if (hand & FOUR_KIND_MASK) score += 8;
  else if (hand & FULL_HOUSE_MASK) score += 7;
  else if (hand & FLUSH_MASK) score += 6;
  else if (hand & STRAIGHT_MASK) score += 5;
  else if (hand & THREE_KIND_MASK) score += 4;
  else if (hand & TWO_PAIR_MASK) score += 3;
  else if (hand & PAIR_MASK) score += 2;
  else score += 1;
  return score;
}

int main() {
  hand_t hand1 = deal_hand();
  hand_t hand2 = deal_hand();
  printf("Hand 1: %s of %s\n", get_rank(hand1), get_suit(hand1));
  printf("Hand 2: %s of %s\n", get_rank(hand2), get_suit(hand2));
  int score1 = get_score(hand1);
  int score2 = get_score(hand2);
  printf("Hand 1 score: %d\n", score1);
  printf("Hand 2 score: %d\n", score2);
  printf("Winner: %s", score1 > score2 ? "Hand 1" : "Hand 2");
  return 0;
}