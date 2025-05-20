//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numCards, maxCardValue, numTurns = 0;
  srand(time(NULL));

  printf("Welcome to the Memory Game! \n\n");
  printf("How many cards do you want to play with? (min 4, max 10) ");
  scanf("%d", &numCards);

  while (numCards < 4 || numCards > 10) {
    printf("Invalid number of cards. Please choose between 4 and 10. \n");
    printf("How many cards do you want to play with? ");
    scanf("%d", &numCards);
  }

  maxCardValue = numCards / 2;
  int* cards = (int*) malloc(numCards * sizeof(int));
  int* flippedCards = (int*) malloc(numCards * sizeof(int));
  for (int i = 0; i < numCards; i++) {
    flippedCards[i] = 0;
    if (i % 2 == 0) {
      cards[i] = rand() % maxCardValue + 1;
    } else {
      cards[i] = cards[i - 1];
    }
  }

  printf("\nLet's play! \n");
  int firstCard, secondCard, matches = 0;
  while (matches < numCards / 2) {
    printf("Turn %d \n", numTurns + 1);
    numTurns++;

    // Print out current board state
    for (int i = 0; i < numCards; i++) {
      if (flippedCards[i] == 1) {
        printf("%d ", cards[i]);
      } else {
        printf("* ");
      }
    }
    printf("\n");

    // Get input for first card
    printf("Choose your first card: ");
    scanf("%d", &firstCard);
    while (flippedCards[firstCard - 1] == 1) {
      printf("Card already flipped. Choose another: ");
      scanf("%d", &firstCard);
    }
    flippedCards[firstCard - 1] = 1;

    // Get input for second card
    printf("Choose your second card: ");
    scanf("%d", &secondCard);
    while (flippedCards[secondCard - 1] == 1 || secondCard == firstCard) {
      printf("Invalid choice. Choose another: ");
      scanf("%d", &secondCard);
    }
    flippedCards[secondCard - 1] = 1;

    // Check if cards match
    if (cards[firstCard - 1] == cards[secondCard - 1]) {
      printf("\nMatch found! \n");
      matches++;
    } else {
      printf("\nNo match. Try again. \n");
      flippedCards[firstCard - 1] = 0;
      flippedCards[secondCard - 1] = 0;
    }

    printf("\n\n");
  }

  printf("Congratulations, you won! It took %d turns. \n", numTurns);

  free(cards);
  free(flippedCards);

  return 0;
}