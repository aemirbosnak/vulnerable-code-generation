//FormAI DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// This function will generate a random board for the memory game
void generate_board(int board[][COLS], int rand_list[])
{
    int i, j, rand_index = 0;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            board[i][j] = rand_list[rand_index];
            rand_index++;
        }
    }
}

// This function will print the board for the game
void print_board(int board[][COLS], int revealed[][COLS])
{
    int i, j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            if(revealed[i][j])
            {
                printf("%2d  ", board[i][j]);
            }
            else
            {
                printf("??  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// This function will check if the user has won the game
int check_win(int revealed[][COLS])
{
    int i, j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            if(!revealed[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

// This function will clear the screen for each turn
void clear_screen()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main()
{
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0};
    int guess1_row, guess1_col, guess2_row, guess2_col;
    int num_guesses = 0;
    int rand_list[ROWS * COLS / 2];
    int i, j, k;

    // Generate a list of random numbers to be used for the board
    srand(time(NULL));
    for(i=0; i<ROWS*COLS/2; i++)
    {
        rand_list[i] = rand() % 10 + 1;
    }
    for(i=0; i<ROWS*COLS/2; i++)
    {
        rand_list[i+ROWS*COLS/2] = rand_list[i];
    }
    // Shuffle the list of random numbers
    for(i=0; i<ROWS*COLS; i++)
    {
        j = rand() % (ROWS*COLS);
        k = rand_list[i];
        rand_list[i] = rand_list[j];
        rand_list[j] = k;
    }

    // Generate the board
    generate_board(board, rand_list);

    // Print the rules
    printf("\nWelcome to the Memory Game!\n\n");
    printf("You will be presented with a 4x4 board of cards.\n");
    printf("Each card has a number on it from 1 to 10.\n");
    printf("Your goal is to reveal all the cards in as few turns as possible.\n");
    printf("To reveal a card, enter its row and column number.\n");
    printf("If the two cards match, they will remain revealed.\n");
    printf("If not, they will be hidden again.\n");
    printf("You win the game when all the cards are revealed.\n\n");
    printf("Press any key to start the game...");
    getchar();
    clear_screen();

    // Game loop
    while(!check_win(revealed))
    {
        // Print the board
        print_board(board, revealed);

        // Get the first guess
        printf("Enter the row and column numbers of your first guess: ");
        scanf("%d %d", &guess1_row, &guess1_col);
        while(guess1_row < 1 || guess1_row > ROWS || guess1_col < 1 || guess1_col > COLS ||
              revealed[guess1_row-1][guess1_col-1])
        {
            printf("Invalid guess. Enter the row and column numbers of your first guess: ");
            scanf("%d %d", &guess1_row, &guess1_col);
        }
        revealed[guess1_row-1][guess1_col-1] = 1;

        // Get the second guess
        printf("Enter the row and column numbers of your second guess: ");
        scanf("%d %d", &guess2_row, &guess2_col);
        while(guess2_row < 1 || guess2_row > ROWS || guess2_col < 1 || guess2_col > COLS ||
              revealed[guess2_row-1][guess2_col-1])
        {
            printf("Invalid guess. Enter the row and column numbers of your second guess: ");
            scanf("%d %d", &guess2_row, &guess2_col);
        }
        revealed[guess2_row-1][guess2_col-1] = 1;

        // Check if the guesses match
        num_guesses++;
        if(board[guess1_row-1][guess1_col-1] != board[guess2_row-1][guess2_col-1])
        {
            printf("\nSorry, the cards do not match.\n");
            revealed[guess1_row-1][guess1_col-1] = 0;
            revealed[guess2_row-1][guess2_col-1] = 0;
        }
        else
        {
            printf("\nNice job, you found a match!\n");
        }

        // Clear the screen for the next turn
        getchar();
        printf("Press any key to continue...");
        getchar();
        clear_screen();
    }

    // Print the final board and the score
    print_board(board, revealed);
    printf("Congratulations, you win!\n");
    printf("It took you %d turns to reveal all the cards.\n", num_guesses);

    return 0;
}