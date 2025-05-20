//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int board[ROWS][COLS];
    init_board(board);

    int num_cards = 0;
    int *cards = malloc(sizeof(int) * (ROWS * COLS / 2));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                board[i][j] = num_cards++;
                cards[num_cards - 1] = rand() % 12 + 1;
            }
        }
    }

    int player_score = 0;
    int num_turns = 0;

    while (num_turns < num_cards) {
        print_board(board);
        printf("Your score: %d\n", player_score);
        printf("Enter two numbers: ");
        int choice1, choice2;
        scanf("%d %d", &choice1, &choice2);

        if (board[choice1][choice2]!= -1) {
            if (board[choice1][choice2] == cards[num_turns]) {
                board[choice1][choice2] = -1;
                player_score += cards[num_turns];
                num_turns++;
            } else {
                printf("Sorry, try again.\n");
                board[choice1][choice2] = -1;
            }
        } else {
            printf("Sorry, try again.\n");
        }
    }

    printf("Game over! Your final score is: %d\n", player_score);

    return 0;
}