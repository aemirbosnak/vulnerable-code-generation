//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define SIZE 2 // Size of the pattern (2x2 matrix)
#define MAX 4 // Maximum pairs to find
#define TOTAL_PAIRS (SIZE * SIZE / 2)

char board[SIZE][SIZE];
char revealed[SIZE][SIZE];
int revealedCount = 0;

void initializeBoard(){
    char symbols[MAX] = {'A', 'B', 'C', 'D'};
    int count = 0;
    
    // Fill the board with pairs
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i * SIZE + j) % 2 == 0) {
                board[i][j] = symbols[count];
            } else {
                board[i][j] = symbols[count];
                count++;
            }
        }
    }
    
    // Shuffle the board
    for (int i = 0; i < SIZE * SIZE; i++) {
        int randIndex = rand() % (SIZE * SIZE);
        char temp = board[i / SIZE][i % SIZE];
        board[i / SIZE][i % SIZE] = board[randIndex / SIZE][randIndex % SIZE];
        board[randIndex / SIZE][randIndex % SIZE] = temp;
    }

    // Initialize the revealed board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            revealed[i][j] = '*';
        }
    }
}

void displayBoard(){
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", revealed[i][j]);
        }
        printf("\n");
    }
}

bool checkMatch(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

bool allRevealed() {
    return revealedCount == TOTAL_PAIRS;
}

void reveal(int x, int y) {
    revealed[x][y] = board[x][y];
    revealedCount++;
}

void hide(int x, int y) {
    revealed[x][y] = '*';
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to the Memory Game!\n");
    printf("Try to find all the matching pairs.\n");
    sleep(1);
    printf("Let's start!\n");

    initializeBoard();
    int firstX, firstY, secondX, secondY;
    
    while (!allRevealed()) {
        displayBoard();
        
        printf("Enter the coordinates of the first card (row[0-1] column[0-1]): ");
        scanf("%d %d", &firstX, &firstY);
        reveal(firstX, firstY);
        displayBoard();
        
        printf("Enter the coordinates of the second card (row[0-1] column[0-1]): ");
        scanf("%d %d", &secondX, &secondY);
        
        if (checkMatch(firstX, firstY, secondX, secondY)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match. Try again!\n");
            sleep(1); // Pause to give player time to view the wrong match
            hide(firstX, firstY);
            hide(secondX, secondY);
        }
    }
    
    printf("Congratulations! You've found all the pairs!\n");
    return 0;
}