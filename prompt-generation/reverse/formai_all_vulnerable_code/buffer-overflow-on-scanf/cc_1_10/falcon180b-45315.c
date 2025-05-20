//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_CARDS 25
#define MAX_PLAYERS 5

typedef struct {
    char name[20];
    int card[MAX_ROWS][MAX_COLS];
} Player;

void initCard(int card[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            card[i][j] = -1;
        }
    }
}

void drawNumber(int num) {
    srand(time(NULL));
    int randomNum = rand() % 75 + 1;
    printf("The number drawn is: %d\n", randomNum);
    if (randomNum % 15 == 0) {
        printf("Bingo!\n");
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        initCard(players[i].card);
    }

    int card[MAX_ROWS][MAX_COLS];
    initCard(card);

    int currentPlayer = 0;
    while (1) {
        printf("Current player: %s\n", players[currentPlayer].name);
        printf("Current card:\n");
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                printf("%d ", card[i][j]);
            }
            printf("\n");
        }

        int choice;
        printf("Enter your choice:\n1. Mark a number\n2. Check for bingo\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int row, col;
            printf("Enter the row and column of the number: ");
            scanf("%d %d", &row, &col);
            if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS && card[row][col] == -1) {
                card[row][col] = players[currentPlayer].card[row][col];
                printf("Number marked.\n");
            } else {
                printf("Invalid choice.\n");
            }
        } else if (choice == 2) {
            int bingo = 1;
            for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0; j < MAX_COLS; j++) {
                    if (card[i][j]!= -1) {
                        bingo = 0;
                        break;
                    }
                }
                if (!bingo) {
                    break;
                }
            }

            if (bingo) {
                printf("%s wins!\n", players[currentPlayer].name);
                break;
            }
        }

        currentPlayer = (currentPlayer + 1) % numPlayers;
    }

    return 0;
}