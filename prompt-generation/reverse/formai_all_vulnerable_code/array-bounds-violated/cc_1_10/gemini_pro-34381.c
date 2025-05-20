//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_SIZE 4
#define NUM_PAIRS  (BOARD_SIZE * BOARD_SIZE) / 2
#define MAX_ATTEMPTS 10

// Types
typedef struct {
    int row;
    int col;
} Card;

// Function prototypes
void init_board(Card board[BOARD_SIZE][BOARD_SIZE]);
void shuffle_board(Card board[BOARD_SIZE][BOARD_SIZE]);
void print_board(Card board[BOARD_SIZE][BOARD_SIZE]);
int get_card(Card *card);
int check_match(Card card1, Card card2);
int play_game(Card board[BOARD_SIZE][BOARD_SIZE]);

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the game board
    Card board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    shuffle_board(board);

    // Print the initial board
    print_board(board);

    // Play the game
    int attempts = 0;
    int matches = 0;
    while (attempts < MAX_ATTEMPTS && matches < NUM_PAIRS) {
        // Get the first card
        Card card1;
        if (get_card(&card1) == -1) {
            printf("Invalid card\n");
            continue;
        }

        // Get the second card
        Card card2;
        if (get_card(&card2) == -1) {
            printf("Invalid card\n");
            continue;
        }

        // Check if the cards match
        if (check_match(card1, card2)) {
            printf("Match!\n");
            matches++;
        } else {
            printf("No match\n");
        }

        // Print the updated board
        print_board(board);

        // Increment the number of attempts
        attempts++;
    }

    // Print the final results
    if (matches == NUM_PAIRS) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Game over. You ran out of attempts.\n");
    }

    return 0;
}

// Function to initialize the game board
void init_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    // Create a list of numbers
    int numbers[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        numbers[i] = i;
    }

    // Shuffle the list of numbers
    for (int i = 0; i < NUM_PAIRS; i++) {
        int r = rand() % NUM_PAIRS;
        int tmp = numbers[i];
        numbers[i] = numbers[r];
        numbers[r] = tmp;
    }

    // Fill the board with the numbers
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].row = numbers[index] / BOARD_SIZE;
            board[i][j].col = numbers[index] % BOARD_SIZE;
            index++;
        }
    }
}

// Function to shuffle the game board
void shuffle_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    // Create a list of indices
    int indices[BOARD_SIZE * BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        indices[i] = i;
    }

    // Shuffle the list of indices
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int r = rand() % (BOARD_SIZE * BOARD_SIZE);
        int tmp = indices[i];
        indices[i] = indices[r];
        indices[r] = tmp;
    }

    // Create a new board
    Card new_board[BOARD_SIZE][BOARD_SIZE];

    // Fill the new board with the shuffled indices
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            new_board[i][j] = board[indices[index] / BOARD_SIZE][indices[index] % BOARD_SIZE];
            index++;
        }
    }

    // Copy the new board to the original board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

// Function to print the game board
void print_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j].row * BOARD_SIZE + board[i][j].col);
        }
        printf("\n");
    }
}

// Function to get a card from the user
int get_card(Card *card) {
    printf("Enter the row and column of the card: ");
    scanf("%d %d", &card->row, &card->col);

    // Check if the row and column are valid
    if (card->row < 0 || card->row >= BOARD_SIZE || card->col < 0 || card->col >= BOARD_SIZE) {
        return -1;
    }

    return 0;
}

// Function to check if two cards match
int check_match(Card card1, Card card2) {
    return card1.row == card2.row && card1.col == card2.col;
}

// Function to play the game
int play_game(Card board[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize the number of attempts and matches
    int attempts = 0;
    int matches = 0;

    // While the player has not run out of attempts and has not matched all the pairs
    while (attempts < MAX_ATTEMPTS && matches < NUM_PAIRS) {
        // Get the first card
        Card card1;
        if (get_card(&card1) == -1) {
            printf("Invalid card\n");
            continue;
        }

        // Get the second card
        Card card2;
        if (get_card(&card2) == -1) {
            printf("Invalid card\n");
            continue;
        }

        // Check if the cards match
        if (check_match(card1, card2)) {
            printf("Match!\n");
            matches++;
        } else {
            printf("No match\n");
        }

        // Print the updated board
        print_board(board);

        // Increment the number of attempts
        attempts++;
    }

    // Return the number of matches
    return matches;
}