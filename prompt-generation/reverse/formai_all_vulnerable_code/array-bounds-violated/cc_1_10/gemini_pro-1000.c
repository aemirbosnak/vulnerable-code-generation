//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants to define game parameters
#define GRID_SIZE 4
#define NUM_PAIRS 8

// Function prototypes
void initializeBoard(char[][GRID_SIZE]);
void shuffleBoard(char[][GRID_SIZE]);
void printBoard(char[][GRID_SIZE]);
int checkMatch(char, char);
void getCoordinates(int*, int*);
int playGame(char[][GRID_SIZE]);

int main() {
    // Seed the random number generator for shuffling the board
    srand(time(NULL));

    // Create the game board
    char board[GRID_SIZE][GRID_SIZE];

    // Initialize the board with characters and shuffle it
    initializeBoard(board);
    shuffleBoard(board);

    // Welcome the player to the game
    printf("Welcome to the Memory Match Odyssey!\n");
    printf("Can you uncover all the matching pairs?\n");
    printf("\n");

    // Begin the game and get the player's input
    int result = playGame(board);

    // Display the result of the game
    if (result == NUM_PAIRS) {
        printf("Congratulations! You have uncovered all the pairs.\n");
    } else {
        printf("Game Over! You didn't uncover all the pairs.\n");
    }

    return 0;
}

void initializeBoard(char board[][GRID_SIZE]) {
    // Initialize the board with characters
    char chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    int i, j, k;
    k = 0;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            board[i][j] = chars[k];
            k++;
        }
    }
}

void shuffleBoard(char board[][GRID_SIZE]) {
    // Shuffle the board randomly using the Fisher-Yates shuffle algorithm
    int i, j, k;

    for (i = GRID_SIZE - 1; i > 0; i--) {
        for (j = GRID_SIZE - 1; j > 0; j--) {
            k = rand() % j;
            char temp = board[i][j];
            board[i][j] = board[k][j];
            board[k][j] = temp;
        }
    }
}

void printBoard(char board[][GRID_SIZE]) {
    // Clear the screen and print the game board
    system("clear");

    printf("    ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d: ", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int checkMatch(char c1, char c2) {
    // Check if two characters match
    return (c1 == c2);
}

void getCoordinates(int* x, int* y) {
    // Get the coordinates of the tile the player wants to uncover
    printf("Enter the row (0-%d): ", GRID_SIZE - 1);
    scanf("%d", x);

    printf("Enter the column (0-%d): ", GRID_SIZE - 1);
    scanf("%d", y);
}

int playGame(char board[][GRID_SIZE]) {
    // Initialize the number of pairs uncovered to 0
    int numPairsUncovered = 0;

    // Initialize the previous two coordinates to -1
    int prevX = -1, prevY = -1;

    while (numPairsUncovered < NUM_PAIRS) {
        // Print the board
        printBoard(board);

        // Get the player's input
        int x, y;
        getCoordinates(&x, &y);

        // Check if the coordinates are valid
        if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }

        // Uncover the tile at the given coordinates
        char c = board[x][y];
        board[x][y] = '#';

        // Check if the tile matches the previously uncovered tile
        if (prevX != -1 && prevY != -1) {
            if (checkMatch(c, board[prevX][prevY])) {
                printf("Match found!\n");
                numPairsUncovered++;
            } else {
                printf("No match. Try again.\n");

                // Cover the two tiles back up
                board[x][y] = '?';
                board[prevX][prevY] = '?';
            }
        }

        // Update the previously uncovered tile
        prevX = x;
        prevY = y;
    }

    return numPairsUncovered;
}