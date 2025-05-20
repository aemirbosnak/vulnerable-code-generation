//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8

int main() {
    int board[ROWS][COLS];
    int num_cards_matched = 0;
    int choice;
    int flag = 0;
    int player_score = 0, computer_score = 0;
    int i, j, k, l, card_number, value;
    char again;

    srand(time(0));

    // Initialize the board with random card numbers
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % TOTAL_CARDS + 1;
        }
    }

    // Print the initial board
    printf("Initial Board:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    do {
        printf("\nPlayer's Turn:\n");
        printf("Enter the row and column of the card you want to flip: ");
        scanf("%d%d", &i, &j);

        card_number = board[i - 1][j - 1];

        if (card_number == 0) {
            printf("Both cards have already been matched.\n");
        } else {
            value = card_number % 13 + 1;

            if (value == 1 || value == 11 || value == 21) {
                board[i - 1][j - 1] = 0;
                num_cards_matched++;
                player_score++;
            } else {
                board[i - 1][j - 1] = 0;
                num_cards_matched++;
                computer_score++;
            }
        }

        printf("\nCurrent Board:\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        if (num_cards_matched == TOTAL_CARDS / 2) {
            printf("\nHalf of the cards have been matched.\n");
        }

        if (num_cards_matched == TOTAL_CARDS) {
            printf("\nAll cards have been matched.\n");
            break;
        }
    } while (1);

    printf("\nFinal Scores:\n");
    printf("Player: %d\n", player_score);
    printf("Computer: %d\n", computer_score);

    if (player_score > computer_score) {
        printf("\nPlayer wins!\n");
    } else if (computer_score > player_score) {
        printf("\nComputer wins!\n");
    } else {
        printf("\nIt's a tie!\n");
    }

    printf("\nDo you want to play again? (y/n): ");
    scanf(" %c", &again);

    if (again == 'y' || again == 'Y') {
        main();
    } else {
        exit(0);
    }

    return 0;
}