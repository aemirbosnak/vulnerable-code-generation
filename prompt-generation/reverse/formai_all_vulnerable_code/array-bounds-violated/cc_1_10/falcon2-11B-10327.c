//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[5][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else if (board[i][j] == 1) {
                printf("B");
            } else if (board[i][j] == 2) {
                printf("I");
            } else if (board[i][j] == 3) {
                printf("N");
            } else if (board[i][j] == 4) {
                printf("G");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int board[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    print_board(board, 5); // Print initial board
    int called_numbers[5] = {0, 0, 0, 0, 0}; // Keep track of called numbers
    int bingo = 0; // Check for bingo
    int game_over = 0; // Check if game is over

    while (game_over == 0) {
        int random_number = rand() % 25; // Generate random number between 1 and 25
        if (called_numbers[random_number - 1] == 0) { // Check if number has been called
            called_numbers[random_number - 1] = 1; // Mark number as called
            printf("Calling number: %d\n", random_number);
            print_board(board, 5); // Print updated board
            if (bingo == 0) { // Check for bingo
                int check_row = 1;
                int check_column = 1;
                for (int i = 0; i < 5; i++) {
                    if (board[i][check_row] == 1) {
                        check_row++;
                        continue;
                    }
                    if (board[check_column][i] == 1) {
                        check_column++;
                        continue;
                    }
                    if (check_row == 5 && check_column == 5) {
                        bingo = 1;
                        break;
                    }
                }
            }
        } else {
            printf("Number already called, try again\n");
        }
    }

    if (bingo == 1) {
        printf("Congratulations, you have won a bingo!\n");
    } else {
        printf("Sorry, you didn't win a bingo this time.\n");
    }

    return 0;
}