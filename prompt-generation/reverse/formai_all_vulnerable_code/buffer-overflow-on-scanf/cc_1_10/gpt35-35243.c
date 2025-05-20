//FormAI DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLUMNS 4

void printCard(int x, int y, char cards[ROWS][COLUMNS], int selected[ROWS][COLUMNS]);
int selectCard(int* x, int* y, char cards[ROWS][COLUMNS], int selected[ROWS][COLUMNS]);
int gameWon(int selected[ROWS][COLUMNS]);

int main()
{
    char cards[ROWS][COLUMNS] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'}
    };
    int selected[ROWS][COLUMNS] = {0};

    int x1, y1, x2, y2;
    int attempts = 0;

    srand(time(NULL));

    while (!gameWon(selected)) {
        printf("Attempt %d\n\n", attempts);

        // Print current state of cards
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                printCard(i, j, cards, selected);
            }
            printf("\n");
        }

        printf("\n\n");

        // Get first card selection
        printf("Enter the row and column indices of the first card: ");
        selectCard(&x1, &y1, cards, selected);

        // Get second card selection
        printf("Enter the row and column indices of the second card: ");
        selectCard(&x2, &y2, cards, selected);

        // Check if selected cards match
        if (cards[x1][y1] == cards[x2][y2]) {
            selected[x1][y1] = 1;
            selected[x2][y2] = 1;
            printf("MATCHED!\n\n");
        } else {
            printf("NO MATCH!\n\n");
        }

        attempts++;
    }
    printf("Congratulations! You won in %d attempts.\n", attempts);
    return 0;
}

void printCard(int x, int y, char cards[ROWS][COLUMNS], int selected[ROWS][COLUMNS])
{
    if (selected[x][y]) {
        printf("%c", cards[x][y]);
    } else {
        printf("*");
    }
    printf("\t");
}

int selectCard(int* x, int* y, char cards[ROWS][COLUMNS], int selected[ROWS][COLUMNS])
{
    int inputRow, inputColumn;

    do {
        scanf("%d %d", &inputRow, &inputColumn);
    } while (inputRow < 1 || inputRow > ROWS || inputColumn < 1 || inputColumn > COLUMNS || selected[inputRow-1][inputColumn-1]);

    *x = inputRow-1;
    *y = inputColumn-1;

    return 0;
}

int gameWon(int selected[ROWS][COLUMNS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (!selected[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}