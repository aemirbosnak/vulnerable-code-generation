//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8
#define MATCH 1
#define NO_MATCH 0

int main() {
    int board[ROWS][COLS] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int matches = 0;
    int attempts = 0;
    int choice;
    int card1, card2;
    int value;
    int i, j;
    int flag = 0;
    srand(time(0));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % TOTAL_CARDS + 1;
        }
    }

    while (flag == 0) {
        system("clear");
        printf("Score: %d\n", matches);
        printf("Attempts: %d\n", attempts);
        printf("Press 1 to choose a card\n");
        printf("Press 2 to quit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Choose row (1-4): ");
            scanf("%d", &i);
            printf("Choose column (1-4): ");
            scanf("%d", &j);

            if (board[i - 1][j - 1] == 0) {
                printf("This card has already been chosen.\n");
            } else {
                card1 = board[i - 1][j - 1];
                board[i - 1][j - 1] = 0;
                attempts++;

                if (attempts == 1) {
                    card2 = rand() % TOTAL_CARDS + 1;
                } else {
                    do {
                        card2 = rand() % TOTAL_CARDS + 1;
                    } while (card2 == card1);
                }

                value = board[i - 1][j - 1] = card2;

                if (card1 == card2) {
                    matches++;
                    printf("Match!\n");
                } else {
                    printf("No match.\n");
                    board[i - 1][j - 1] = 0;
                }
            }
        } else if (choice == 2) {
            flag = 1;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}