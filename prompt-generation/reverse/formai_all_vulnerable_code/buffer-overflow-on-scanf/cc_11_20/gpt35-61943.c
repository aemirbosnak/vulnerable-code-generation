//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the array
void shuffle(int *array, int size)
{
    srand(time(NULL));  // Seed the random number generator
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main()
{
    int board[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int pairs[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int pairs_index = 0;

    // Shuffle the pairs and fill the board
    shuffle(pairs, 8);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] >= 1 && board[i][j] <= 8)
            {
                board[i][j] = pairs[pairs_index];
                pairs_index++;
            }
        }
    }

    // Print the initial board
    printf("\nMemory Game\n\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Game loop
    int num_guesses = 0;
    int guess1_row = -1, guess1_col = -1, guess2_row = -1, guess2_col = -1;
    while (1)
    {
        printf("\nGuess a pair of cards (row, col): ");
        scanf("%d %d", &guess1_row, &guess1_col);

        // Check if guess is valid
        if (guess1_row >= 1 && guess1_row <= 4 && guess1_col >= 1 && guess1_col <= 4)
        {
            // Subtract 1 from row and col to convert to array index
            guess1_row--;
            guess1_col--;
            if (board[guess1_row][guess1_col] == 0)
            {
                printf("\nError: That card has already been guessed. Please try again.\n");
                continue;
            }
        }
        else
        {
            printf("\nError: That is an invalid guess. Please choose a number between 1 and 4.\n");
            continue;
        }

        // Flip over the first card
        int guess1_value = board[guess1_row][guess1_col];
        board[guess1_row][guess1_col] = 0;
        num_guesses++;

        // Print the board with the first card flipped over
        printf("\n");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i == guess1_row && j == guess1_col)
                    printf("%d ", guess1_value);
                else
                    printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Guess the second card
        printf("\nGuess the second card (row, col): ");
        scanf("%d %d", &guess2_row, &guess2_col);

        // Check if guess is valid
        if (guess2_row >= 1 && guess2_row <= 4 && guess2_col >= 1 && guess2_col <= 4)
        {
            // Subtract 1 from row and col to convert to array index
            guess2_row--;
            guess2_col--;
            if (board[guess2_row][guess2_col] == 0)
            {
                printf("\nError: That card has already been guessed. Please try again.\n");
                board[guess1_row][guess1_col] = guess1_value;
                continue;
            }
        }
        else
        {
            printf("\nError: That is an invalid guess. Please choose a number between 1 and 4.\n");
            board[guess1_row][guess1_col] = guess1_value;
            continue;
        }

        // Flip over the second card
        int guess2_value = board[guess2_row][guess2_col];
        board[guess2_row][guess2_col] = 0;
        num_guesses++;

        // Print the board with the second card flipped over
        printf("\n");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if ((i == guess1_row && j == guess1_col) || (i == guess2_row && j == guess2_col))
                    printf("%d ", board[i][j]);
                else
                    printf("0 ");
            }
            printf("\n");
        }

        // Check if the cards match
        if (guess1_value == guess2_value)
        {
            printf("\nCongratulations, you found a pair!\n");
        }
        else
        {
            printf("\nSorry, those cards do not match.\n");
            board[guess1_row][guess1_col] = guess1_value;
            board[guess2_row][guess2_col] = guess2_value;
        }

        // Check if the game is over
        int game_over = 1;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] != 0)
                    game_over = 0;
            }
        }
        if (game_over)
        {
            printf("\nCongratulations, you won in %d guesses!\n", num_guesses);
            break;
        }
    }

    return 0;
}