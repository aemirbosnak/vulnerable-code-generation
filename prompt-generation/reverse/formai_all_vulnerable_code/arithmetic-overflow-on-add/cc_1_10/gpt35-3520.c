//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int randomNumberGenerator(int upperLimit) {
    srand(time(NULL));
    int randNo = rand() % upperLimit + 1;
    return randNo;
}

int main() {
    // Initialize the game
    int board[5][5] = { {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,-1,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0} };
    int numberCount = 0;
    int randomNumber;
    int gameOver = 0;

    // Print the board
    printf("Welcome to BINGO SIMULATOR\n\n");
    printf("B  I  N  G  O\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] != -1) {
                printf("%d  ", board[i][j]);
            } else {
                printf("X  ");
            }
        }
        printf("\n");
    }
    printf("\n");

    // Play the game
    while(!gameOver) {
        // Generate a random number
        randomNumber = randomNumberGenerator(25);

        // Check if the number is already present in the board
        int alreadyPresent = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(board[i][j] == randomNumber) {
                    alreadyPresent = 1;
                    break;
                }
            }
        }

        // If the number is not present, check if it matches with any element in the board and mark it
        if(!alreadyPresent) {
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(board[i][j] == randomNumber) {
                        board[i][j] = -1;
                        numberCount++;
                        break;
                    }
                }
            }
        }

        // Print the updated board
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(board[i][j] != -1) {
                    printf("%d  ", board[i][j]);
                } else {
                    printf("X  ");
                }
            }
            printf("\n");
        }
        printf("\n");

        // Check for winning condition
        if(numberCount == 25) {
            printf("Congratulations! You won the game!");
            gameOver = 1;
        }

        // Wait for 1 second before generating the next number
        clock_t start_time = clock();
        while (clock() < start_time + 1000);
    }

    return 0;
}