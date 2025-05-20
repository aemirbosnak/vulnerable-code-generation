//FormAI DATASET v1.0 Category: Poker Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// Card struct to hold card's rank, suit, and value
struct Card {
  int rank;
  char suit;
  int value;
};

// Deck struct to hold array of Card
struct Deck {
  struct Card cards[DECK_SIZE];
  int count;
};

// Hand struct to hold array of Card and score of the hand
struct Hand {
  struct Card cards[HAND_SIZE];
  int score;
};

// Function to generate a deck of cards and shuffle it
struct Deck generateDeck() {
  struct Deck deck;
  deck.count = 0;
  
  // For each suit, add all ranks 1-13
  for (char suit = 'C'; suit <= 'S'; suit++) {
    for (int rank = 1; rank <= 13; rank++) {
      struct Card card;
      card.rank = rank;
      card.suit = suit;
      
      // Determine card's value (Ace is 14)
      if (rank == 1) {
        card.value = 14;
      } else {
        card.value = rank;
      }
      
      deck.cards[deck.count++] = card;
    }
  }
  
  // Shuffle the deck using Fisher-Yates shuffle algorithm
  srand(time(NULL));
  for (int i = DECK_SIZE-1; i >= 1; i--) {
    int j = rand() % (i+1);
    struct Card temp = deck.cards[i];
    deck.cards[i] = deck.cards[j];
    deck.cards[j] = temp;
  }
  
  return deck;
}

// Function to print a card
void printCard(struct Card card) {
  if (card.rank == 1) {
    printf("Ace");
  } else if (card.rank == 11) {
    printf("Jack");
  } else if (card.rank == 12) {
    printf("Queen");
  } else if (card.rank == 13) {
    printf("King");
  } else {
    printf("%d", card.rank);
  }
  printf(" of %c\n", card.suit);
}

// Function to print a hand
void printHand(struct Hand hand) {
  for (int i = 0; i < HAND_SIZE; i++) {
    printCard(hand.cards[i]);
  }
  
  printf("Score: %d\n", hand.score);
}

// Function to determine score of a hand
int getHandScore(struct Hand hand) {
  int score = 0;
  int hasAce = 0;
  
  // Calculate score by adding up all card values
  for (int i = 0; i < HAND_SIZE; i++) {
    score += hand.cards[i].value;
    if (hand.cards[i].rank == 1) {
      hasAce = 1;
    }
  }
  
  // If hand contains ace and score is over 21, subtract 10 to use ace as 1
  if (hasAce && score > 21) {
    score -= 10;
  }
  
  return score;
}

// Function to swap two cards in an array
void swapCards(struct Card *card1, struct Card *card2) {
  struct Card temp = *card1;
  *card1 = *card2;
  *card2 = temp;
}

// Function to sort a hand by rank (bubble sort)
void sortHand(struct Hand *hand) {
  for (int i = 0; i < HAND_SIZE-1; i++) {
    for (int j = 0; j < HAND_SIZE-i-1; j++) {
      if (hand->cards[j].rank > hand->cards[j+1].rank) {
        swapCards(&(hand->cards[j]), &(hand->cards[j+1]));
      }
    }
  }
}

// Function to deal one card from deck to a hand
void dealCard(struct Deck *deck, struct Hand *hand) {
  hand->cards[hand->score++ % HAND_SIZE] = deck->cards[--deck->count];
}

// Function to draw new cards for a hand and replace existing cards
void drawCards(struct Deck *deck, struct Hand *hand) {
  printf("Enter number of cards to replace: ");
  int numToReplace;
  scanf("%d", &numToReplace);
  
  if (numToReplace == 0) {
    return;
  }
  
  // Replace existing cards with new cards from deck
  printf("Enter positions of cards to replace (separated by spaces): ");
  for (int i = 0; i < numToReplace; i++) {
    int pos;
    scanf("%d", &pos);
    hand->cards[pos-1] = deck->cards[--deck->count];
  }
  
  // Sort the hand by rank
  sortHand(hand);
  
  // Recalculate score of the hand
  hand->score = getHandScore(*hand);
}

int main() {
  struct Deck deck = generateDeck();
  
  // Play 5 rounds of the game
  for (int i = 0; i < 5; i++) {
    printf("Round %d\n", i+1);
    
    struct Hand hand;
    hand.score = 0;
    
    // Deal initial hand and print it
    for (int j = 0; j < HAND_SIZE; j++) {
      dealCard(&deck, &hand);
      printCard(hand.cards[j]);
    }
    
    // Calculate and print score of the hand
    hand.score = getHandScore(hand);
    printf("Score: %d\n", hand.score);
    
    // Draw new cards and print new hand
    drawCards(&deck, &hand);
    printf("New hand:\n");
    printHand(hand);
  }
  
  return 0;
}