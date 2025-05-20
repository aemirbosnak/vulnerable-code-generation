//FormAI DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

int board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int i, j, k;
    int num_pairs_placed = 0;
    srand(time(NULL));

    while(num_pairs_placed < NUM_PAIRS) {
        int value = rand() % NUM_PAIRS + 1;

        for(k = 0; k < 2; k++) {
            do {
                i = rand() % BOARD_SIZE;
                j = rand() % BOARD_SIZE;
            } while(board[i][j] != 0);

            board[i][j] = value;
            num_pairs_placed++;
        }
    }

    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            revealed[i][j] = 0;
        }
    }
}

void print_board() {
    int i, j;

    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    int num_attempts = 0;

    initialize_board();

    while(1) {
        printf("Attempt #%d\n", num_attempts);

        print_board();

        printf("Enter the position of the numbers to reveal.\n");
        printf("Enter the row of the first number: ");
        scanf("%d", &i);
        printf("Enter the column of the first number: ");
        scanf("%d", &j);

        if(i < 0 || i >= BOARD_SIZE || j < 0 || j >= BOARD_SIZE) {
            printf("Invalid position!\n");
            continue;
        }

        if(revealed[i][j]) {
            printf("Position already revealed!\n");
            continue;
        }

        revealed[i][j] = 1;

        printf("Enter the row of the second number: ");
        scanf("%d", &i);
        printf("Enter the column of the second number: ");
        scanf("%d", &j);

        if(i < 0 || i >= BOARD_SIZE || j < 0 || j >= BOARD_SIZE) {
            printf("Invalid position!\n");
            continue;
        }

        if(revealed[i][j]) {
            printf("Position already revealed!\n");
            continue;
        }

        revealed[i][j] = 1;

        num_attempts++;

        if(board[i][j] != board[i][j]) {
            printf("Wrong! Try again.\n");
            revealed[i][j] = 0;
            revealed[i][j] = 0;
        }

        int num_revealed = 0;

        for(i = 0; i < BOARD_SIZE; i++) {
            for(j = 0; j < BOARD_SIZE; j++) {
                if(revealed[i][j]) {
                    num_revealed++;
                }
            }
        }

        if(num_revealed == BOARD_SIZE * BOARD_SIZE) {
            printf("You won in %d attempts!\n", num_attempts);
            break;
        }
    }

    return 0;
}