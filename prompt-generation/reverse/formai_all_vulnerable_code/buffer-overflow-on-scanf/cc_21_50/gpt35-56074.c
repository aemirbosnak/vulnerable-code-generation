//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up random number generator
    srand(time(0));

    // Initialize board
    int board[5][5] = {0};
    board[2][2] = -1;

    // Initialize variables
    int num, row, col, count = 0, bingo = 0, option = 0;

    // Print welcome message and options
    printf("Welcome to Bingo Simulator!\n");
    printf("Choose an option:\n");
    printf("1. Play game\n");
    printf("2. Quit\n");

    // Get user input for option
    scanf("%d", &option);

    // Play game option
    if (option == 1)
    {
        // Loop until player gets bingo
        while (bingo == 0)
        {
            // Generate random number
            num = rand() % 25 + 1;

            // Check if number already called
            for (row = 0; row < 5; row++)
            {
                for (col = 0; col < 5; col++)
                {
                    if (board[row][col] == num)
                    {
                        num = rand() % 25 + 1;
                        row = 0;
                        col = 0;
                    }
                }
            }

            // Print called number
            printf("The called number is: %d\n", num);

            // Mark called number on board
            for (row = 0; row < 5; row++)
            {
                for (col = 0; col < 5; col++)
                {
                    if (board[row][col] == num)
                    {
                        board[row][col] = -1;
                        count++;
                    }
                }
            }

            // Print updated board
            printf("\n     B  I  N  G  O\n");
            for (row = 0; row < 5; row++)
            {
                printf("   +--+--+--+--+--+\n");
                for (col = 0; col < 5; col++)
                {
                    if (board[row][col] == -1)
                    {
                        printf("   | X");
                    }
                    else
                    {
                        printf("   | %d", board[row][col]);
                    }
                }
                printf("   |\n");
            }
            printf("   +--+--+--+--+--+\n");

            // Check for bingo
            if (count >= 5)
            {
                // Check horizontal rows
                for (row = 0; row < 5; row++)
                {
                    if (board[row][0] == -1 && board[row][1] == -1 && board[row][2] == -1 && board[row][3] == -1 && board[row][4] == -1)
                    {
                        bingo = 1;
                    }
                }

                // Check vertical columns
                for (col = 0; col < 5; col++)
                {
                    if (board[0][col] == -1 && board[1][col] == -1 && board[2][col] == -1 && board[3][col] == -1 && board[4][col] == -1)
                    {
                        bingo = 1;
                    }
                }

                // Check diagonal lines
                if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1)
                {
                    bingo = 1;
                }
                if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1)
                {
                    bingo = 1;
                }
            }

            // Print bingo message
            if (bingo == 1)
            {
                printf("\nBINGO! You won the game!\n");
                break;
            }

            // Get user input to continue game
            printf("\nEnter 1 to continue: ");
            scanf("%d", &option);
        }
    }
    // Quit option
    else if (option == 2)
    {
        printf("Goodbye!\n");
        return 0;
    }
    // Invalid option
    else
    {
        printf("Invalid option. Please try again.\n");
        return 0;
    }

    return 0;
}