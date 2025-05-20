//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define BOARD_SIZE 4

// Define the number of cards in the game
#define NUM_CARDS 8

// Define the states of a card
#define CARD_FACE_UP    1
#define CARD_FACE_DOWN  0

// Create a struct to represent a card
typedef struct card {
    int value;
    int state;
} Card;

// Create a struct to represent the game board
typedef struct board {
    Card cards[BOARD_SIZE][BOARD_SIZE];
} Board;

// Create a function to initialize the game board
void initialize_board(Board *board) {
    // Initialize the random number generator
    srand(time(NULL));

    // Create an array of values for the cards
    int values[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        values[i] = i + 1;
    }

    // Shuffle the values
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Assign the values to the cards
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->cards[i][j].value = values[index];
            board->cards[i][j].state = CARD_FACE_DOWN;
            index++;
        }
    }
}

// Create a function to print the game board
void print_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cards[i][j].state == CARD_FACE_UP) {
                printf("%d ", board->cards[i][j].value);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Create a function to get the input from the user
void get_input(Board *board, int *row, int *col) {
    printf("Enter the row and column of the card you want to flip: ");
    scanf("%d %d", row, col);
}

// Create a function to flip a card
void flip_card(Board *board, int row, int col) {
    board->cards[row][col].state = CARD_FACE_UP;
}

// Create a function to check if two cards match
int cards_match(Card *card1, Card *card2) {
    return card1->value == card2->value;
}

// Create a function to check if the game is over
int game_over(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cards[i][j].state == CARD_FACE_DOWN) {
                return 0;
            }
        }
    }

    return 1;
}

// Create a function to play the game
void play_game(Board *board) {
    // Initialize the game
    initialize_board(board);

    // While the game is not over
    while (!game_over(board)) {
        // Print the game board
        print_board(board);

        // Get the input from the user
        int row1, col1, row2, col2;
        get_input(board, &row1, &col1);
        get_input(board, &row2, &col2);

        // Flip the two cards
        flip_card(board, row1, col1);
        flip_card(board, row2, col2);

        // Check if the two cards match
        if (cards_match(&board->cards[row1][col1], &board->cards[row2][col2])) {
            printf("Match!\n");
        } else {
            printf("No match.\n");

            // Flip the two cards back down
            flip_card(board, row1, col1);
            flip_card(board, row2, col2);
        }
    }

    // Print the final game board
    print_board(board);

    // Congratulate the player
    printf("Congratulations! You won the game!\n");
}

// Create a main function
int main() {
    // Create a game board
    Board board;

    // Play the game
    play_game(&board);

    return 0;
}