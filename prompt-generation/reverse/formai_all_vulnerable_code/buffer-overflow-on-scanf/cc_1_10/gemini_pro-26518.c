//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Constants
#define BOARD_SIZE 4
#define MAX_ATTEMPTS 10

// Structs
typedef struct {
    int x, y;
} Position;

// Functions
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]);
int getValidInput(int min, int max);
Position getPosition(void);
int checkMatch(int board[BOARD_SIZE][BOARD_SIZE], Position pos1, Position pos2);

int main(void) {
    // Seed random number generator
    srand(time(NULL));

    // Initialize board
    int board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 10;
        }
    }

    // Print instructions
    printf("Welcome to the Memory Game!\n");
    printf("Your goal is to match all the pairs of numbers on the board.\n");
    printf("You have %d attempts.\n", MAX_ATTEMPTS);

    // Game loop
    int attempts = MAX_ATTEMPTS;
    while (attempts > 0) {
        // Print board
        printBoard(board);

        // Get first position
        Position pos1 = getPosition();

        // Get second position
        Position pos2 = getPosition();

        // Check if positions are valid
        if (!(pos1.x >= 0 && pos1.x < BOARD_SIZE && pos1.y >= 0 && pos1.y < BOARD_SIZE && pos2.x >= 0 && pos2.x < BOARD_SIZE && pos2.y >= 0 && pos2.y < BOARD_SIZE)) {
            printf("Invalid positions. Please try again.\n");
            continue;
        }

        // Check if positions match
        int match = checkMatch(board, pos1, pos2);
        if (match == 1) {
            // Positions match. Clear them from the board.
            board[pos1.x][pos1.y] = -1;
            board[pos2.x][pos2.y] = -1;
            printf("Match found!\n");
        } else if (match == 0) {
            // Positions do not match.
            printf("No match. Please try again.\n");
            attempts--;
            printf("%d attempts remaining.\n", attempts);
        } else {
            // Positions are already cleared.
            printf("Positions already cleared. Please try again.\n");
        }

        // Check if all pairs have been matched
        int allMatched = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != -1) {
                    allMatched = 0;
                    break;
                }
            }
        }

        if (allMatched) {
            // All pairs have been matched.
            printf("Congratulations! You won!\n");
            break;
        }
    }

    if (attempts == 0) {
        // All attempts have been used.
        printf("Game over! You lose.\n");
    }

    return 0;
}

void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                printf("  ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int getValidInput(int min, int max) {
    int input;
    while (1) {
        scanf("%d", &input);
        if (input >= min && input <= max) {
            return input;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

Position getPosition(void) {
    Position pos;
    printf("Enter the position of the first number (x, y): ");
    pos.x = getValidInput(0, BOARD_SIZE - 1);
    pos.y = getValidInput(0, BOARD_SIZE - 1);
    return pos;
}

int checkMatch(int board[BOARD_SIZE][BOARD_SIZE], Position pos1, Position pos2) {
    if (board[pos1.x][pos1.y] == -1 || board[pos2.x][pos2.y] == -1) {
        return -1; // Positions already cleared
    } else if (board[pos1.x][pos1.y] == board[pos2.x][pos2.y]) {
        return 1; // Positions match
    } else {
        return 0; // Positions do not match
    }
}