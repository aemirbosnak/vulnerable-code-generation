//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n = 4, temp, count = 0, guess1, guess2;
    int gameboard[n][n], gameboard_copy[n][n], board_size = n * n + 1;
    int* board_values = calloc(board_size, sizeof(int));
    int* found_pairs = calloc(board_size, sizeof(int));
    int* positions = calloc(board_size, sizeof(int));

    srand(time(0));

    for (i = 0; i < board_size; i++)
    {
        board_values[i] = i % (n * n / 2) + 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            temp = rand() % board_size;
            while (found_pairs[board_values[temp]] == 2)
            {
                temp = rand() % board_size;
            }
            gameboard[i][j] = board_values[temp];
            found_pairs[board_values[temp]]++;
            positions[board_values[temp]] = i * n + j;
        }
    }

    printf("\n\nWelcome to the Memory Game!\n\n");
    printf("Instructions:\n");
    printf("1. You will be presented with a board of %d x %d numbers.\n", n, n);
    printf("2. Each number occurs exactly twice in the board.\n");
    printf("3. You need to guess the positions of the matching pairs.\n");
    printf("4. To guess, enter the row and column number of the two positions separated by a space.\n");
    printf("5. You get one point for each correct guess.\n");
    printf("6. The game ends when you find all the matching pairs.\n");
    printf("7. Good luck and have fun!\n\n");

    while (count < n * n / 2)
    {
        printf("   ");
        for (i = 0; i < n; i++)
        {
            printf("%-3d", i);
        }
        printf("\n");

        for (i = 0; i < n; i++)
        {
            printf("%-3d", i);
            for (j = 0; j < n; j++)
            {
                if (gameboard[i][j] < 0)
                {
                    printf("  X");
                }
                else
                {
                    printf("%-3d", gameboard[i][j]);
                }
            }
            printf("\n");
        }

        printf("\nEnter your guesses (row column): ");
        scanf("%d %d", &guess1, &guess2);
        printf("\n");

        if (guess1 < 0 || guess1 >= n || guess2 < 0 || guess2 >= n)
        {
            printf("Invalid guess! Please enter values between 0 and %d.\n", n - 1);
        }
        else
        {
            if (gameboard[guess1][guess2] < 0)
            {
                printf("You've already guessed this pair, try again.\n");
            }
            else
            {
                if (count == n * n / 2 - 1)
                {
                    printf("You have found all the matching pairs! Congratulations!\n");
                    gameboard[guess1][guess2] = -gameboard[guess1][guess2];
                    count++;
                }
                else if (gameboard[guess1][guess2] == gameboard_copy[guess1][guess2])
                {
                    printf("You have found a matching pair! Congratulations!\n");
                    gameboard[guess1][guess2] = -gameboard[guess1][guess2];
                    gameboard_copy[guess1][guess2] = -gameboard_copy[guess1][guess2];
                    count++;
                }
                else
                {
                    printf("Sorry, that's not a match. Keep trying!\n");
                    gameboard[guess1][guess2] = -gameboard[guess1][guess2];
                }
            }
        }
    }

    free(board_values);
    free(found_pairs);
    free(positions);

    return 0;
}