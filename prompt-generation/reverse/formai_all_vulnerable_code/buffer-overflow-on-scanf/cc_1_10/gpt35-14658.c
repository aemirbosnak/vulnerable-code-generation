//FormAI DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_board(int board[][COLS], int revealed[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%d\t", board[i][j]);
            }
            else {
                printf("?\t");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };
    int solution[ROWS*COLS];
    for (int i = 0; i < ROWS*COLS; i++) {
        solution[i] = i;
    }
    shuffle(solution, ROWS*COLS);
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = solution[index];
            index++;
        }
    }
    int revealed[ROWS][COLS] = {0}; // 0 = not revealed, 1 = revealed
    int num_revealed = 0;
    int x1, y1, x2, y2;
    while (num_revealed < ROWS * COLS) {
        printf("Enter the indices of two cards to reveal (format: x1 y1 x2 y2):\n");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        // Check if indices are valid
        if (x1 < 0 || x1 >= ROWS || y1 < 0 || y1 >= COLS || x2 < 0 || x2 >= ROWS || y2 < 0 || y2 >= COLS) {
            printf("Invalid indices.\n");
        }
        // Check if cards have already been revealed
        else if (revealed[x1][y1] || revealed[x2][y2]) {
            printf("Cards have already been revealed.\n");
        }
        // Check if cards match
        else if (board[x1][y1] == board[x2][y2]) {
            printf("Match found!\n");
            revealed[x1][y1] = 1;
            revealed[x2][y2] = 1;
            num_revealed += 2;
            print_board(board, revealed);
        }
        // Cards do not match
        else {
            printf("No match.\n");
            print_board(board, revealed);
        }
    }
    printf("Congratulations, you won!\n");
    return 0;
}