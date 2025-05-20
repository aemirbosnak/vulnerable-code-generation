//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define BOARD_SIZE 4

// Define the number of cards in the game
#define NUM_CARDS 8

// Define the hidden character for the cards
#define HIDDEN_CHAR '#'

// Define the victory message
#define VICTORY_MESSAGE "Congratulations! You found all the pairs!"

// Create a struct to represent a card
typedef struct {
    char value;
    int is_flipped;
} Card;

// Create a function to initialize the game board
void init_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    // Create an array of all the possible card values
    char values[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // Shuffle the array of values
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        char temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Place the values on the game board
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = values[index];
            board[i][j].is_flipped = 0;
            index++;
        }
    }
}

// Create a function to print the game board
void print_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    // Print the top border of the board
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    // Print the rows of the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_flipped) {
                printf("%c ", board[i][j].value);
            } else {
                printf("%c ", HIDDEN_CHAR);
            }
        }
        printf("\n");
    }
}

// Create a function to get the user's input
void get_input(int *row, int *col) {
    // Get the row and column from the user
    printf("Enter the row and column of the card you want to flip (e.g. 1 2): ");
    scanf("%d %d", row, col);
}

// Create a function to check if the game is over
int is_game_over(Card board[BOARD_SIZE][BOARD_SIZE]) {
    // Check if all the cards are flipped
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].is_flipped) {
                return 0;
            }
        }
    }

    // If all the cards are flipped, the game is over
    return 1;
}

// Create a function to play the game
void play_game(Card board[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize the game board
    init_board(board);

    // Print the game board
    print_board(board);

    // Get the user's input
    int row, col;
    get_input(&row, &col);

    // Flip the card
    board[row - 1][col - 1].is_flipped = 1;

    // Print the game board
    print_board(board);

    // Check if the game is over
    if (is_game_over(board)) {
        // Print the victory message
        printf("%s\n", VICTORY_MESSAGE);
    } else {
        // Play the game again
        play_game(board);
    }
}

// Main function
int main() {
    // Create the game board
    Card board[BOARD_SIZE][BOARD_SIZE];

    // Play the game
    play_game(board);

    return 0;
}