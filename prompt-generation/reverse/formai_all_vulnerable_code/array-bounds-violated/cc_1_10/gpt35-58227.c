//FormAI DATASET v1.0 Category: Memory Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void shuffle(int arr[], int size);
void printBoard(char board[SIZE][SIZE], int reveal[]);
void initializeBoard(char board[SIZE][SIZE], int pairs[]);
int isPair(char board[SIZE][SIZE], int row1, int col1, int row2, int col2);
int won(int reveal[]);

int main() {
    char board[SIZE][SIZE];
    int pairs[SIZE*SIZE/2];
    int reveal[SIZE*SIZE] = { 0 };
    int guess1 = 0, guess2 = 0;
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
    int moves = 0;
    
    // Create pairs of numbers
    for (int i = 0; i < SIZE*SIZE/2; i++) {
        pairs[i] = i+1;
        pairs[i+ SIZE*SIZE/2] = i+1;
    }

    // Shuffle pairs
    srand(time(NULL));
    shuffle(pairs, SIZE*SIZE);

    // Initialize board with pairs
    initializeBoard(board, pairs);

    // Start game
    printf("Welcome to the Romeo and Juliet Memory Game!\n");
    printf("Try to find all pairs of Romeo and Juliet images.\n");
    printf("Enter row and column of the first image: ");
    scanf("%d %d", &row1, &col1);
    reveal[row1*SIZE + col1] = 1;
    printBoard(board, reveal);

    while (!won(reveal)) {
        printf("\nEnter row and column of the second image: ");
        scanf("%d %d", &row2, &col2);
        if (row2 == row1 && col2 == col1) {
            printf("You cannot select the same square as your first guess.\n");
            continue;
        }
        if (reveal[row2*SIZE + col2] == 1) {
            printf("That square has already been revealed.\n");
            continue;
        }
        reveal[row2*SIZE + col2] = 1;
        printBoard(board, reveal);
        moves++;
        if (isPair(board, row1, col1, row2, col2)) {
            printf("Congratulations! You found a pair!\n");
        } else {
            printf("Sorry! Those images do not match.\n");
            reveal[row1*SIZE + col1] = 0;
            reveal[row2*SIZE + col2] = 0;
        }
        printf("Enter row and column of the first image: ");
        scanf("%d %d", &row1, &col1);
        reveal[row1*SIZE + col1] = 1;
        printBoard(board, reveal);
    }

    printf("Congratulations! You won in %d moves!\n", moves);

    return 0;
}

void shuffle(int arr[], int size) {
    for (int i = size-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printBoard(char board[SIZE][SIZE], int reveal[]) {
    printf("   ");
    for (int j = 0; j < SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n  -");
    for (int j = 0; j < SIZE; j++) {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d| ", i);
        for (int j = 0; j < SIZE; j++) {
            if (reveal[i*SIZE + j] == 1) {
                printf("%c ", board[i][j]);
            } else {
                printf(". ");
            }
        }
        printf("|\n");
    }
    printf("  -");
    for (int j = 0; j < SIZE; j++) {
        printf("--");
    }
    printf("\n");
}

void initializeBoard(char board[SIZE][SIZE], int pairs[]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = pairs[count] + '0';
            count++;
        }
    }
}

int isPair(char board[SIZE][SIZE], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        return 1;
    } else {
        return 0;
    }
}

int won(int reveal[]) {
    for (int i = 0; i < SIZE*SIZE; i++) {
        if (reveal[i] == 0) {
            return 0;
        }
    }
    return 1;
}