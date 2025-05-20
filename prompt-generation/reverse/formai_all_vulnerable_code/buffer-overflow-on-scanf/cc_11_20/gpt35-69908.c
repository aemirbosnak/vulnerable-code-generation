//FormAI DATASET v1.0 Category: Table Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initializing seed for random values
    srand(time(NULL));

    // Defining the board size
    int rows = 8;
    int cols = 8;

    // Creating the board as a 2D array
    char board[rows][cols];

    // Filling the board with random values
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {

            // Randomly selecting values for each cell
            int rand_value = rand() % 26;
            board[i][j] = (char)(rand_value + 'A'); // Converting the value to a letter (A-Z)
        }
    }

    // Displaying the board to the player
    printf("Welcome to the C Table Game!\n");
    printf("----------------------------\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Starting the game loop
    int score = 0;
    int turns = 0;
    while(1) {

        // Getting user input
        int x, y;
        printf("Enter the row and column of the letter you want to select: ");
        scanf("%d %d", &x, &y);

        // Checking if the input is valid
        if(x < 0 || x >= rows || y < 0 || y >= cols) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Checking if the letter has already been selected
        if(board[x][y] == ' ') {
            printf("This letter has already been removed. Try again.\n");
            continue;
        }

        // Removing the selected letter and calculating points
        char selected = board[x][y];
        board[x][y] = ' ';
        score += (int)selected - (int)'A';
        turns++;

        // Displaying the updated board and score
        printf("----------------------------\n");
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("Score: %d\n", score);

        // Checking if the game is over
        int remaining_letters = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] != ' ') {
                    remaining_letters++;
                }
            }
        }
        if(remaining_letters == 0) {
            printf("Congratulations! You won!\n");
            printf("Final score: %d\n", score);
            printf("Turns taken: %d\n", turns);
            break;
        }
    }

    return 0;
}