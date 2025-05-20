//FormAI DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// Global variables
char board[ROWS][COLS];
char hidden_board[ROWS][COLS];

// Function prototypes
void print_board();
void print_hidden_board();
void init_board();
void init_hidden_board();
void shuffle_board();

int main()
{
    // Set seed for random number generation
    srand((unsigned int)time(NULL));

    // Initialize the board
    init_board();

    // Hide the board
    init_hidden_board();

    // Shuffle the board
    shuffle_board();

    // Print the hidden board
    print_hidden_board();

    // Prompt user to start the game
    printf("Press any key to start the game...");
    getchar();

    // Start the game
    int num_guesses = 0;
    char prev_guess[3] = {'\0', '\0', '\0'};
    while (1)
    {
        // Print the board
        print_board();

        // Get user input
        char guess[3];
        printf("Enter row and column to guess (format: ROW COL): ");
        scanf("%s", guess);

        // Check the guess
        int row = guess[0] - '0';
        int col = guess[2] - '0';
        if (row < 1 || row > ROWS || col < 1 || col > COLS)
        {
            printf("Invalid input. Please enter a valid row and column.\n");
            continue;
        }
        if (hidden_board[row - 1][col - 1] == '*')
        {
            printf("You already guessed that spot.\n");
            continue;
        }
        if (prev_guess[0] != '\0' && board[row - 1][col - 1] != board[prev_guess[0] - '0' - 1][prev_guess[2] - '0' - 1])
        {
            printf("Sorry, those spots do not match.\n");
            hidden_board[row - 1][col - 1] = '*';
            hidden_board[prev_guess[0] - '0' - 1][prev_guess[2] - '0' - 1] = '*';
        }
        else
        {
            hidden_board[row - 1][col - 1] = board[row - 1][col - 1];
            if (prev_guess[0] != '\0')
            {
                printf("Congratulations, you found a match!\n");
            }
            prev_guess[0] = guess[0];
            prev_guess[1] = guess[1];
            prev_guess[2] = guess[2];
            num_guesses++;
            if (num_guesses == ROWS * COLS / 2)
            {
                printf("Congratulations, you won the game!\n");
                break;
            }
        }
    }

    return 0;
}

void print_board()
{
    printf("\n-------------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("|");
        for (int j = 0; j < COLS; j++)
        {
            printf(" %c |", hidden_board[i][j]);
        }
        printf("\n-------------------\n");
    }
}

void print_hidden_board()
{
    printf("\n-------------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("|");
        for (int j = 0; j < COLS; j++)
        {
            printf(" %c |", board[i][j]);
        }
        printf("\n-------------------\n");
    }
}

void init_board()
{
    char letters[ROWS * COLS / 2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int letter_index = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = letters[letter_index];
            letter_index++;
            if (letter_index == ROWS * COLS / 2)
            {
                letter_index = 0;
            }
        }
    }
}

void init_hidden_board()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            hidden_board[i][j] = '-';
        }
    }
}

void shuffle_board()
{
    for (int i = 0; i < ROWS * COLS; i++)
    {
        int rand_row1 = rand() % ROWS;
        int rand_col1 = rand() % COLS;
        int rand_row2 = rand() % ROWS;
        int rand_col2 = rand() % COLS;
        char temp = board[rand_row1][rand_col1];
        board[rand_row1][rand_col1] = board[rand_row2][rand_col2];
        board[rand_row2][rand_col2] = temp;
    }
}