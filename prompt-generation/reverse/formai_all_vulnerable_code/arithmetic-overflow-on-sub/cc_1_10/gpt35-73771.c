//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

// Global constants
#define TABLE_SIZE 3
#define SQUARE_EMPTY ' '

// Function prototypes
void init_table(char table[][TABLE_SIZE]);
void display_table(char table[][TABLE_SIZE]);
bool make_move(char table[][TABLE_SIZE], char symbol, int row, int col);
bool check_win(char table[][TABLE_SIZE], char symbol);
bool is_draw(char table[][TABLE_SIZE]);

int main()
{
    char table[TABLE_SIZE][TABLE_SIZE];
    char player1 = 'X';
    char player2 = 'O';
    int row, col;
    bool win, draw;
    
    // Initialize the table
    init_table(table);
    
    // Display the empty table
    display_table(table);
    
    // Keep looping until we have a winner or draw
    while (true)
    {
        // Get player 1's move
        printf("Player 1 (X), enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        if (make_move(table, player1, row-1, col-1))
        {
            display_table(table);
            win = check_win(table, player1);
            draw = is_draw(table);
            if (win)
            {
                printf("Player 1 wins!\n");
                break;
            }
            else if (draw)
            {
                printf("Game over! It's a draw.\n");
                break;
            }
        }
        else
        {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        // Get player 2's move
        printf("Player 2 (O), enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        if (make_move(table, player2, row-1, col-1))
        {
            display_table(table);
            win = check_win(table, player2);
            draw = is_draw(table);
            if (win)
            {
                printf("Player 2 wins!\n");
                break;
            }
            else if (draw)
            {
                printf("Game over! It's a draw.\n");
                break;
            }
        }
        else
        {
            printf("Invalid move. Try again.\n");
            continue;
        }
    }
    
    return 0;
}

// Initialize the table with empty squares
void init_table(char table[][TABLE_SIZE])
{
    int i, j;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        for (j = 0; j < TABLE_SIZE; j++)
        {
            table[i][j] = SQUARE_EMPTY;
        }
    }
}

// Display the current state of the table
void display_table(char table[][TABLE_SIZE])
{
    int i, j;
    printf("\n");
    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf(" %c | %c | %c ", table[i][0], table[i][1], table[i][2]);
        if (i != TABLE_SIZE-1) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Make a move for the specified player at the specified row and column
bool make_move(char table[][TABLE_SIZE], char symbol, int row, int col)
{
    if (table[row][col] == SQUARE_EMPTY)
    {
        table[row][col] = symbol;
        return true;
    }
    else
    {
        return false;
    }
}

// Check if the specified player has won
bool check_win(char table[][TABLE_SIZE], char symbol)
{
    int i;
    // Check rows
    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i][0] == symbol && table[i][1] == symbol && table[i][2] == symbol)
        {
            return true;
        }
    }
    // Check columns
    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (table[0][i] == symbol && table[1][i] == symbol && table[2][i] == symbol)
        {
            return true;
        }
    }
    // Check diagonals
    if (table[0][0] == symbol && table[1][1] == symbol && table[2][2] == symbol)
    {
        return true;
    }
    if (table[0][2] == symbol && table[1][1] == symbol && table[2][0] == symbol)
    {
        return true;
    }
    // If we get here, the player has not won
    return false;
}

// Check if the game has ended in a draw
bool is_draw(char table[][TABLE_SIZE])
{
    int i, j;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        for (j = 0; j < TABLE_SIZE; j++)
        {
            if (table[i][j] == SQUARE_EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}