//FormAI DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define MAX_GUESSES 8

// Function declarations
void print_board(char board[]);
int valid_input(int input, int history[], int num_guesses);
int check_pair(char board[], int guess1, int guess2);
void update_board(char board[], int guess1, int guess2);

int main(void)
{
    // Initialize variables
    char board[BOARD_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                              'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int history[BOARD_SIZE] = {0};
    int guesses[MAX_GUESSES] = {0};
    int num_guesses = 0;
    int guess1, guess2;
    int pairs_found = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int j = rand() % BOARD_SIZE;
        char temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }

    // Game loop
    while (pairs_found < 8)
    {
        // Print the board
        print_board(board);

        // Get guess1 from player
        printf("Enter first guess: ");
        scanf("%d", &guess1);

        // Validate guess1 input
        if (valid_input(guess1, history, num_guesses))
        {
            // Mark guess1 as used
            history[guess1] = 1;

            // Save guess1 in guesses array
            guesses[num_guesses] = guess1;
            num_guesses++;

            // Get guess2 from player
            printf("Enter second guess: ");
            scanf("%d", &guess2);

            // Validate guess2 input
            if (valid_input(guess2, history, num_guesses))
            {
                // Check if guess1 and guess2 form a pair
                if (check_pair(board, guess1, guess2))
                {
                    printf("You found a pair!\n");
                    pairs_found++;
                }
                else
                {
                    printf("No match. Try again.\n");
                }

                // Mark guess2 as used
                history[guess2] = 1;

                // Save guess2 in guesses array
                guesses[num_guesses] = guess2;
                num_guesses++;
            }
            else
            {
                printf("Invalid input or guess already used. Try again.\n");
            }
        }
        else
        {
            printf("Invalid input or guess already used. Try again.\n");
        }
    }

    // Print final board with all pairs revealed
    print_board(board);

    printf("Congratulations, you found all the pairs!\n");

    return 0;
}

// Function definitions
void print_board(char board[])
{
    printf("\n");
    printf("   | 1 | 2 | 3 | 4 |\n");
    printf("---|---|---|---|---|\n");
    for (int i = 0; i < BOARD_SIZE; i += 4)
    {
        printf("%2d | %c | %c | %c | %c |\n", i/4+1, board[i], board[i+1], board[i+2], board[i+3]);
    }
    printf("\n");
}

int valid_input(int input, int history[], int num_guesses)
{
    if (input >= 1 && input <= 16 && history[input-1] == 0 && num_guesses < 8)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_pair(char board[], int guess1, int guess2)
{
    if (board[guess1-1] == board[guess2-1])
    {
        update_board(board, guess1, guess2);
        return 1;
    }
    else
    {
        return 0;
    }
}

void update_board(char board[], int guess1, int guess2)
{
    board[guess1-1] = ' ';
    board[guess2-1] = ' ';
}