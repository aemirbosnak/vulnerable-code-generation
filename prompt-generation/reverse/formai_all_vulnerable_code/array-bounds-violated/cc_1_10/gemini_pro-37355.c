//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Define the number of rows and columns in the game board
#define ROWS 4
#define COLUMNS 4

// Define the number of pairs of cards in the game
#define NUM_PAIRS 8

// Define the maximum number of turns allowed
#define MAX_TURNS 20

// Define the card values
enum CardValue {
  ACE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING
};

// Define the card suits
enum CardSuit {
  CLUBS,
  DIAMONDS,
  HEARTS,
  SPADES
};

// Define the card structure
struct Card {
  enum CardValue value;
  enum CardSuit suit;
};

// Define the game board structure
struct GameBoard {
  struct Card cards[ROWS][COLUMNS];
  int revealedCards[ROWS][COLUMNS];
};

// Function to initialize the game board
void initializeGameBoard(struct GameBoard *gameBoard) {
  // Create an array of all the possible card values and suits
  struct Card allCards[NUM_PAIRS * 2];
  for (int i = 0; i < NUM_PAIRS; i++) {
    allCards[i * 2].value = i;
    allCards[i * 2].suit = CLUBS;
    allCards[i * 2 + 1].value = i;
    allCards[i * 2 + 1].suit = DIAMONDS;
  }

  // Shuffle the array of cards
  srand(time(NULL));
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    int j = rand() % (NUM_PAIRS * 2);
    struct Card temp = allCards[i];
    allCards[i] = allCards[j];
    allCards[j] = temp;
  }

  // Copy the shuffled cards into the game board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      gameBoard->cards[i][j] = allCards[i * COLUMNS + j];
      gameBoard->revealedCards[i][j] = 0;
    }
  }
}

// Function to print the game board
void printGameBoard(struct GameBoard *gameBoard) {
  printf("  ");
  for (int i = 0; i < COLUMNS; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < ROWS; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < COLUMNS; j++) {
      if (gameBoard->revealedCards[i][j]) {
        printf("%2d ", gameBoard->cards[i][j].value + 1);
      } else {
        printf("██ ");
      }
    }
    printf("\n");
  }
}

// Function to get the user's input
void getUserInput(int *row, int *column) {
  char input[3];
  printf("Enter the row and column of the card you want to reveal (e.g. 1 2): ");
  scanf("%s", input);

  *row = input[0] - '0' - 1;
  *column = input[2] - '0' - 1;
}

// Function to check if the two cards match
int checkMatch(struct Card *card1, struct Card *card2) {
  return card1->value == card2->value;
}

// Function to play the game
void playGame() {
  // Initialize the game board
  struct GameBoard gameBoard;
  initializeGameBoard(&gameBoard);

  // Print the game board
  printGameBoard(&gameBoard);

  // Initialize the number of turns taken
  int turnsTaken = 0;

  // Initialize the number of pairs found
  int pairsFound = 0;

  // Game loop
  while (turnsTaken < MAX_TURNS && pairsFound < NUM_PAIRS) {
    // Get the user's input
    int row1, column1, row2, column2;
    getUserInput(&row1, &column1);
    getUserInput(&row2, &column2);

    // Reveal the cards
    gameBoard.revealedCards[row1][column1] = 1;
    gameBoard.revealedCards[row2][column2] = 1;

    // Print the game board
    printGameBoard(&gameBoard);

    // Check if the cards match
    if (checkMatch(&gameBoard.cards[row1][column1], &gameBoard.cards[row2][column2])) {
      pairsFound++;
      printf("Match found!\n");
    } else {
      printf("No match found.\n");

      // Hide the cards
      gameBoard.revealedCards[row1][column1] = 0;
      gameBoard.revealedCards[row2][column2] = 0;
    }

    // Increment the number of turns taken
    turnsTaken++;
  }

  // Print the final game board
  printGameBoard(&gameBoard);

  // Print the results
  if (pairsFound == NUM_PAIRS) {
    printf("Congratulations! You found all the pairs in %d turns.\n", turnsTaken);
  } else {
    printf("Game over! You found %d pairs in %d turns.\n", pairsFound, turnsTaken);
  }
}

// Main function
int main() {
  playGame();
  return 0;
}