//FormAI DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main() {
    int size, i, j, score = 0;
    int board[MAX_SIZE][MAX_SIZE];
    int revealed[MAX_SIZE][MAX_SIZE];

    //Get board size from user
    printf("Enter board size (even numbers only): ");
    scanf("%d", &size);

    //Validate board size
    if(size % 2 != 0 || size > MAX_SIZE) {
        printf("Invalid board size!");
        return 1;
    }

    //Initialize random seed
    srand(time(NULL));

    //Fill board with random numbers
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            board[i][j] = rand() % 10;
            revealed[i][j] = 0;
        }
    }

    //Game loop
    int num_revealed = 0;
    while(num_revealed < size*size) {
        //Print board
        printf("\nScore: %d\n", score);
        for(i=0; i<size; i++) {
            for(j=0; j<size; j++) {
                if(revealed[i][j]) {
                    printf("%d ", board[i][j]);
                } else {
                    printf("? ");
                }
            }
            printf("\n");
        }

        //Get user input
        int row1, col1, row2, col2;
        printf("Enter row and column for first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter row and column for second card: ");
        scanf("%d %d", &row2, &col2);

        //Validate input
        if(row1 < 0 || row1 >= size || col1 < 0 || col1 >= size || row2 < 0 || row2 >= size || col2 < 0 || col2 >= size) {
            printf("Invalid input!");
            continue;
        }
        if(revealed[row1][col1] || revealed[row2][col2]) {
            printf("Card has already been revealed!");
            continue;
        }

        //Reveal cards and check for match
        if(board[row1][col1] == board[row2][col2]) {
            printf("Match!\n");
            revealed[row1][col1] = 1;
            revealed[row2][col2] = 1;
            score++;
            num_revealed += 2;
        } else {
            printf("No match.\n");
            revealed[row1][col1] = 1;
            revealed[row2][col2] = 1;
        }
    }

    //Print final score
    printf("\nFinal score: %d\n", score);

    return 0;
}