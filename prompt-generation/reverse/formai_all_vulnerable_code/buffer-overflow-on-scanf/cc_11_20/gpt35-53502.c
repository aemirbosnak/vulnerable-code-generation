//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the C Table Game!\n");
    printf("This is a happy game so let's start with a smile :)\n");

    int table[5][5];
    srand(time(0)); // initialize random seed

    // fill the table with random numbers from 1 to 25
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            table[i][j] = rand() % 25 + 1;
        }
    }

    // print the table
    printf("\nHere's the table:\n\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }

    // ask the player if they want to play
    char choice;
    printf("\nWould you like to play? (y/n): ");
    scanf(" %c", &choice);

    // play the game
    while (choice == 'y') {
        int row, col;
        printf("\nEnter the row and column numbers (1-5) of the number you want to guess: ");
        scanf("%d %d", &row, &col);

        // check if the input is valid
        if (row < 1 || row > 5 || col < 1 || col > 5) {
            printf("\nInvalid input, please try again.\n");
            continue;
        }

        // check if the guess is correct
        if (table[row-1][col-1] == (row-1)*5 + col) {
            printf("\nCongratulations, you found it! :)\n");
            table[row-1][col-1] = 0; // mark the number as found
        } else {
            printf("\nSorry, that's not the right number. :(\n");
        }

        // print the updated table
        printf("\nHere's the table:\n\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d\t", table[i][j]);
            }
            printf("\n");
        }

        // check if all numbers have been found
        int found = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (table[i][j] != 0) {
                    found = 0;
                    break;
                }
            }
            if (found == 0) {
                break;
            }
        }
        if (found == 1) {
            printf("\nCongratulations, you have found all the numbers! You're a winner! :D\n");
            break;
        }

        // ask the player if they want to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);
    }

    // say goodbye
    printf("\nThank you for playing the C Table Game! Have a happy day! :)\n");

    return 0;
}