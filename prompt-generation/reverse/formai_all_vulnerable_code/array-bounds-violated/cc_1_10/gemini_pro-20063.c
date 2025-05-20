//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define NUM_PAIRS 8

typedef struct {
  int value;
  int revealed;
} Card;

Card deck[NUM_PAIRS * 2];
int num_guesses = 0;
int num_matches = 0;

void init_deck() {
  // Initialize the deck with pairs of random numbers
  int values[NUM_PAIRS];
  for (int i = 0; i < NUM_PAIRS; i++) {
    values[i] = rand() % 10;
  }

  // Shuffle the values
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    int j = rand() % (NUM_PAIRS * 2);
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
  }

  // Create the deck
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    deck[i].value = values[i];
    deck[i].revealed = 0;
  }
}

void print_deck() {
  // Print the deck in a 4x4 grid
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    if (deck[i].revealed) {
      printf("%d ", deck[i].value);
    } else {
      printf("X ");
    }

    if ((i + 1) % 4 == 0) {
      printf("\n");
    }
  }
}

int get_guess() {
  // Get the user's guess
  int guess;
  printf("Enter your guess (1-%d): ", NUM_PAIRS * 2);
  scanf("%d", &guess);

  // Validate the guess
  while (guess < 1 || guess > NUM_PAIRS * 2 || deck[guess - 1].revealed) {
    printf("Invalid guess. Enter a valid guess (1-%d): ", NUM_PAIRS * 2);
    scanf("%d", &guess);
  }

  return guess;
}

int check_match(int guess1, int guess2) {
  // Check if the two guesses match
  return deck[guess1 - 1].value == deck[guess2 - 1].value;
}

void reveal_card(int guess) {
  // Reveal the card at the given guess
  deck[guess - 1].revealed = 1;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the deck
  init_deck();

  // Start the game loop
  while (num_matches < NUM_PAIRS) {
    // Print the deck
    print_deck();

    // Get the first guess
    int guess1 = get_guess();

    // Reveal the card
    reveal_card(guess1);

    // Get the second guess
    int guess2 = get_guess();

    // Reveal the card
    reveal_card(guess2);

    // Check if the guesses match
    if (check_match(guess1, guess2)) {
      // The guesses match! Increment the number of matches.
      num_matches++;
      printf("Match!\n");
    } else {
      // The guesses don't match. Reset the revealed cards.
      deck[guess1 - 1].revealed = 0;
      deck[guess2 - 1].revealed = 0;
      printf("No match. Try again.\n");
    }

    // Increment the number of guesses
    num_guesses++;
  }

  // Game over! Print the final deck and the number of guesses.
  print_deck();
  printf("Game over! You found all the matches in %d guesses.\n", num_guesses);

  return 0;
}