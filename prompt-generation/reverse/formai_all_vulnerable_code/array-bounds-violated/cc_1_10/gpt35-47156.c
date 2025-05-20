//FormAI DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GAME_SIZE 4

// Function to shuffle the cards
void shuffle(int cards[])
{
    srand(time(0));
 
    for (int i = GAME_SIZE * GAME_SIZE - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

// Function to print the game board
void print_board(int board[][GAME_SIZE])
{
    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given move is valid
int is_valid_move(int board[][GAME_SIZE], int row1, int col1, int row2, int col2)
{
    if (row1 < 0 || row1 > GAME_SIZE - 1 || col1 < 0 || col1 > GAME_SIZE - 1 || row2 < 0 || row2 > GAME_SIZE - 1 || col2 < 0 || col2 > GAME_SIZE - 1)
    {
        return 0; // Out of bounds
    }
    else if (board[row1][col1] == -1 || board[row2][col2] == -1)
    {
        return 0; // Invalid card
    }
    else if (row1 == row2 && col1 == col2)
    {
        return 0; // Same card
    }
    else if (board[row1][col1] != board[row2][col2])
    {
        return 0; // Cards don't match
    }
    else
    {
        return 1; // Valid move
    }
}

// Function to update the game board after a valid move
void update_board(int board[][GAME_SIZE], int row1, int col1, int row2, int col2)
{
    board[row1][col1] = -1;
    board[row2][col2] = -1;
}

// Function to check if the game is over
int is_game_over(int board[][GAME_SIZE])
{
    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            if (board[i][j] != -1)
            {
                return 0;
            }
        }
    }
    return 1;
}

// Function for multiplayer game
void multiplayer()
{
    int cards[GAME_SIZE * GAME_SIZE / 2];
    int board[GAME_SIZE][GAME_SIZE];
    int player1_score = 0, player2_score = 0;
    int player_turn = 1;
    int row1, col1, row2, col2;
 
    // Initialize the cards
    for (int i = 0; i < GAME_SIZE * GAME_SIZE / 2; i++)
    {
        cards[2*i] = i + 1;
        cards[2*i + 1] = i + 1;
    }
 
    // Shuffle the cards
    shuffle(cards);
 
    // Initialize the game board
    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            board[i][j] = cards[i * GAME_SIZE + j];
        }
    }
 
    // Game loop
    while (!is_game_over(board))
    {
        printf("\n\nPlayer %d's turn:\n", player_turn);
        print_board(board);
        
        // Get the user's move
        printf("\nSelect the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("\nSelect the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);
 
        // Check if the move is valid
        if (is_valid_move(board, row1, col1, row2, col2))
        {
            printf("\nMatch found!");
            update_board(board, row1, col1, row2, col2);
            if (player_turn == 1)
            {
                player1_score++;
            }
            else
            {
                player2_score++;
            }
        }
        else
        {
            printf("\nInvalid move, try again!");
        }
 
        // Switch player turn
        if (player_turn == 1)
        {
            player_turn = 2;
        }
        else
        {
            player_turn = 1;
        }
    }
 
    // Game over
    printf("\n\nGame over!\n");
    printf("Player 1 score: %d\n", player1_score);
    printf("Player 2 score: %d\n", player2_score);
    if (player1_score > player2_score)
    {
        printf("Player 1 wins!");
    }
    else if (player2_score > player1_score)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("It's a tie!");
    }
}

// Main function
int main()
{
    multiplayer();
    return 0;
}