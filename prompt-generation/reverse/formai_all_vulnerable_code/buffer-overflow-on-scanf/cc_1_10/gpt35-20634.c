//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>

// These are the external functions used by the program
extern void moveAI(char *board, char ai);
extern int checkForWin(char *board, char player);
extern void drawBoard(char *board);

// The main entry point of the program
int main()
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int won, moves = 0;
    char player, ai;

    // Prompt the user to choose a symbol
    printf("Do you want to play as 'X' or 'O'? ");
    scanf("%c", &player);
    ai = player == 'X' ? 'O' : 'X';

    // The main game loop
    do
    {
        // Check whose turn it is and make a move
        if (moves % 2 == 0)
        {
            // Player's turn
            printf("Your turn: ");
            int pos;
            scanf("%d", &pos);

            // Ensure the move is valid
            if (board[pos] != ' ')
            {
                printf("Invalid move! Try again.\n");
                continue;
            }
            board[pos] = player;
        }
        else
        {
            // AI's turn
            moveAI(board, ai);
        }

        // Draw the new state of the board
        drawBoard(board);

        // Check for a win or a draw
        won = checkForWin(board, player);
        if (!won) won = checkForWin(board, ai);

        if (won)
        {
            if (won == 1) printf("You won!\n");
            else if (won == 2) printf("The AI won!\n");
        }
        else if (moves == 8)
        {
            printf("Draw!\n");
            break;
        }

        // Increment the move counter
        moves++;
    }
    while (!won);

    return 0;
}

/**
 * The brain of the AI that makes a move.
 *
 * @param board char* The game board.
 * @param ai char The symbol of the AI player.
 */
void moveAI(char *board, char ai)
{
    int i;
    for (i = 0; i < 9; i++)
    {
        // Check if the current position is available
        if (board[i] == ' ')
        {
            board[i] = ai;
            return;
        }
    }
}

/**
 * Check for a win of a certain player.
 *
 * @param board char* The game board.
 * @param player char The symbol of the player we're checking for a win.
 * @returns int 0 if nobody won, 1 if the player won, 2 if the AI won.
 */
int checkForWin(char *board, char player)
{
    int i;

    // Horizontal wins
    for (i = 0; i < 9; i += 3)
    {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player)
        {
            if (player == 'X') return 1;
            else return 2;
        }
    }

    // Vertical wins
    for (i = 0; i < 3; i++)
    {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player)
        {
            if (player == 'X') return 1;
            else return 2;
        }
    }

    // Diagonal wins
    if (board[0] == player && board[4] == player && board[8] == player)
    {
        if (player == 'X') return 1;
        else return 2;
    }
    else if (board[2] == player && board[4] == player && board[6] == player)
    {
        if (player == 'X') return 1;
        else return 2;
    }

    return 0;
}

/**
 * Draw the game board on the screen.
 *
 * @param board char* The game board.
 */
void drawBoard(char *board)
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}