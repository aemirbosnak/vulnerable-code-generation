//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 // number of rows and columns
#define M 2 // number of pairs to match

int main() {
    int board[N][N]; // game board
    int pairs[M][2]; // pairs of matching cards
    int flips = 0; // number of flips
    int matched = 0; // number of matched pairs

    // generate random pairs
    srand(time(NULL));
    for (int i = 0; i < M; i++) {
        int r1 = rand() % N;
        int c1 = rand() % N;
        int r2 = rand() % N;
        int c2 = rand() % N;
        pairs[i][0] = r1 * N + c1;
        pairs[i][1] = r2 * N + c2;
    }

    // initialize game board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1; // -1 represents an unknown card
        }
    }

    // game loop
    while (matched < M) {
        // get player input
        int r1, c1, r2, c2;
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &r2, &c2);

        // flip cards
        board[r1][c1] = pairs[flips][0] % N;
        board[r2][c2] = pairs[flips][1] % N;
        flips++;

        // check if cards match
        if (board[r1][c1] == board[r2][c2]) {
            printf("Matched!\n");
            matched++;
        } else {
            printf("Try again!\n");
        }

        // print game board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == -1) {
                    printf(" X ");
                } else {
                    printf(" %d ", board[i][j]);
                }
            }
            printf("\n");
        }
    }

    // game over
    printf("Congratulations! You matched all the pairs in %d flips.\n", flips);

    return 0;
}