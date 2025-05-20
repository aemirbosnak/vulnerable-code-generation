//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

#define SIZE 4 // Dimensions of the game board
#define TOTAL_SHAPES (SIZE * SIZE / 2)
#define MAX_TRIES 10

// Function to hide and show the cursor in the terminal.
void hideCursor() {
    printf("\e[?25l");
}

void showCursor() {
    printf("\e[?25h");
}

// Function to clear the screen.
void clearScreen() {
    printf("\033[H\033[J");
}

// Function to get a key press without waiting for Enter.
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Function to display the game board.
void displayBoard(char board[SIZE][SIZE], char revealed[SIZE][SIZE]) {
    clearScreen();
    printf("Memory Game\n");
    printf("===========\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" # ");
            }
        }
        printf("\n");
    }
}

// Function to initialize the game board with shapes.
void initializeBoard(char board[SIZE][SIZE]) {
    char shapes[TOTAL_SHAPES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int index = 0;
    
    // Fill the board with pairs of shapes
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (index < TOTAL_SHAPES) {
                board[i][j] = shapes[index / 2];
            }
            index++;
        }
    }

    // Shuffle the board
    for (int i = 0; i < SIZE * SIZE; i++) {
        int r = rand() % (SIZE * SIZE);
        int r2 = rand() % (SIZE * SIZE);
        char temp = board[r / SIZE][r % SIZE];
        board[r / SIZE][r % SIZE] = board[r2 / SIZE][r2 % SIZE];
        board[r2 / SIZE][r2 % SIZE] = temp;
    }
}

// Function to play the game.
void playGame() {
    char board[SIZE][SIZE];
    char revealed[SIZE][SIZE] = {0};
    int tries = 0, pairs_found = 0;
    initializeBoard(board);

    while (pairs_found < TOTAL_SHAPES) {
        displayBoard(board, revealed);
        printf("Tries: %d, Pairs Found: %d\n", tries, pairs_found);
        
        printf("Enter coordinates (row1 col1 row2 col2): ");
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--; c1--; r2--; c2--; // Adjust for 0-indexing

        if (board[r1][c1] == board[r2][c2]) {
            revealed[r1][c1] = revealed[r2][c2] = 1;
            pairs_found++;
            printf("Match found!\n");
        } else {
            printf("No match! Try again.\n");
        }
        tries++;
        sleep(1);
        clearScreen();
    }
    printf("Congratulations! You've found all pairs in %d tries!\n", tries);
}

int main() {
    srand(time(NULL));
    hideCursor();
    playGame();
    showCursor();
    return 0;
}