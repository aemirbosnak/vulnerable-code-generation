//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4
#define MAX_ATTEMPTS 10

void initialize_board(char board[SIZE][SIZE], char values[SIZE * SIZE]) {
    int index = 0;
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        values[index++] = 'A' + i; // Fill with letters A, B, C, ...
        values[index++] = 'A' + i; // Duplicate letters for pairs
    }
    // Shuffle the values
    for (int i = 0; i < SIZE * SIZE; i++) {
        int j = rand() % (SIZE * SIZE);
        char temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }
    // Fill the board with values
    index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = values[index++];
        }
    }
}

void print_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("[%c] ", board[i][j]);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

int check_match(char board[SIZE][SIZE], int revealed[SIZE][SIZE], 
                int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    char values[SIZE * SIZE];
    int revealed[SIZE][SIZE] = {0};
    int attempts = 0;
    int pairs_found = 0;

    initialize_board(board, values);

    while (pairs_found < SIZE * SIZE / 2 && attempts < MAX_ATTEMPTS) {
        print_board(board, revealed);
        int x1, y1, x2, y2;

        printf("Enter coordinates for the first card (row col): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter coordinates for the second card (row col): ");
        scanf("%d %d", &x2, &y2);

        if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 ||
            x1 >= SIZE || y1 >= SIZE || x2 >= SIZE || y2 >= SIZE || 
            (x1 == x2 && y1 == y2) || revealed[x1][y1] || revealed[x2][y2]) {
            printf("Invalid input, please try again.\n");
            continue;
        }

        revealed[x1][y1] = 1;
        revealed[x2][y2] = 1;

        print_board(board, revealed);

        if (check_match(board, revealed, x1, y1, x2, y2)) {
            printf("It's a match!\n");
            pairs_found++;
        } else {
            printf("Not a match, try again.\n");
            attempts++;
            // Hide the cards again after a brief pause
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }

        printf("Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
    }

    if (pairs_found == SIZE * SIZE / 2) {
        printf("Congratulations! You've matched all pairs.\n");
    } else {
        printf("Game Over! You couldn't match all pairs within the attempts.\n");
    }

    return 0;
}