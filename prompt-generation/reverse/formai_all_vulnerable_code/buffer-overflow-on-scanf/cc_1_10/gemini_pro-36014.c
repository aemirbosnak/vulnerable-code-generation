//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int **board;
int rows, cols;
int num_pairs;
int num_flips;
int num_matches;
int game_over;

// Function prototypes
void initialize_board();
void print_board();
void flip_card(int row, int col);
int check_match(int row1, int col1, int row2, int col2);
int game_won();

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Create the game board
    board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        board[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the game board
    initialize_board();

    // Print the game board
    print_board();

    // Main game loop
    while (!game_over) {
        // Get the first card from the user
        int row1, col1;
        printf("Enter the row of the first card: ");
        scanf("%d", &row1);
        printf("Enter the column of the first card: ");
        scanf("%d", &col1);

        // Flip the first card
        flip_card(row1, col1);

        // Print the game board
        print_board();

        // Get the second card from the user
        int row2, col2;
        printf("Enter the row of the second card: ");
        scanf("%d", &row2);
        printf("Enter the column of the second card: ");
        scanf("%d", &col2);

        // Flip the second card
        flip_card(row2, col2);

        // Print the game board
        print_board();

        // Check if the two cards match
        if (check_match(row1, col1, row2, col2)) {
            // Increment the number of matches
            num_matches++;

            // Check if the game is won
            if (game_won()) {
                // Print the winning message
                printf("You win!\n");

                // Set the game over flag
                game_over = 1;
            }
        } else {
            // Flip the two cards back over
            flip_card(row1, col1);
            flip_card(row2, col2);
        }

        // Increment the number of flips
        num_flips++;
    }

    // Print the game statistics
    printf("Number of flips: %d\n", num_flips);
    printf("Number of matches: %d\n", num_matches);

    // Free the game board
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

void initialize_board() {
    // Create a list of all the possible pairs of cards
    int *pairs = (int *)malloc(num_pairs * 2 * sizeof(int));
    for (int i = 0; i < num_pairs; i++) {
        pairs[2 * i] = i;
        pairs[2 * i + 1] = i;
    }

    // Shuffle the list of pairs
    for (int i = 0; i < num_pairs * 2; i++) {
        int random_index = rand() % (num_pairs * 2);
        int temp = pairs[i];
        pairs[i] = pairs[random_index];
        pairs[random_index] = temp;
    }

    // Place the pairs on the game board
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = pairs[index++];
        }
    }

    // Free the list of pairs
    free(pairs);
}

void print_board() {
    // Print the top border of the board
    printf("  ");
    for (int i = 0; i < cols; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    // Print the rows of the board
    for (int i = 0; i < rows; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < cols; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

void flip_card(int row, int col) {
    // Flip the card over
    board[row][col] = -board[row][col];
}

int check_match(int row1, int col1, int row2, int col2) {
    // Check if the two cards match
    return board[row1][col1] == board[row2][col2];
}

int game_won() {
    // Check if all the cards have been matched
    return num_matches == num_pairs;
}