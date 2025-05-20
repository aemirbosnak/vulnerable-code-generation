//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3  // size of the board

int board[SIZE][SIZE];  // 2D array to represent the board
int player_turn = 1;  // 1 for player 1, 2 for player 2
int count_moves = 0;  // to keep track of number of moves played
char player1_name[20], player2_name[20];  // to store player names

// function declarations
void initialize_board(void);
void display_board(void);
int get_player_move(int);
int check_win(void);
int check_three(int, int, int);
void announce_winner(int);

int main()
{
    // initialize the board
    initialize_board();

    // get player names
    printf("Player 1, please enter your name: ");
    scanf("%s", player1_name);

    printf("Player 2, please enter your name: ");
    scanf("%s", player2_name);

    // play the game
    int winner = 0;
    while (!winner)
    {
        // display board
        display_board();

        // get player move
        int row, col;
        printf("It's %s's turn (X).\n", player_turn == 1 ? player1_name : player2_name);
        int valid_move = 0;
        while (!valid_move)
        {
            int move = get_player_move(player_turn);
            row = move / SIZE;
            col = move % SIZE;

            if (board[row][col] == 0)  // check if spot is available
            {
                board[row][col] = player_turn;
                valid_move = 1;
                count_moves++;
            }
            else
            {
                printf("That spot is already taken. Please choose another one.\n");
            }
        }

        // check for winner
        winner = check_win();
        if (winner)
        {
            break;
        }

        // switch player turn
        if (player_turn == 1)
        {
            player_turn = 2;
        }
        else
        {
            player_turn = 1;
        }

        // check if game is tie
        if (count_moves == SIZE*SIZE)
        {
            break;
        }
    }

    // display final result
    display_board();
    if (winner == -1)
    {
        printf("Game tied.\n");
    }
    else
    {
        announce_winner(winner);
    }

    return 0;
}

// function to initialize the board
void initialize_board(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = 0;  // set all spots to 0
        }
    }

    srand(time(NULL));  // seed random number generator
    player_turn = rand() % 2 + 1;  // randomly choose player turn
}

// function to display the board
void display_board(void)
{
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" %c ", '-');
            }
            else if (board[i][j] == 1)
            {
                printf(" %c ", 'X');
            }
            else
            {
                printf(" %c ", 'O');
            }
            if (j != SIZE-1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i != SIZE-1)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// function to get player move
int get_player_move(int player)
{
    int move;
    printf("Enter a number between 1 and %d: ", SIZE*SIZE);
    scanf("%d", &move);
    return move-1;  // convert to 0-based index
}

// function to check for winner
int check_win(void)
{
    // check rows
    for (int i = 0; i < SIZE; i++)
    {
        if (check_three(board[i][0], board[i][1], board[i][2]))
        {
            return board[i][0];
        }
    }

    // check columns
    for (int i = 0; i < SIZE; i++)
    {
        if (check_three(board[0][i], board[1][i], board[2][i]))
        {
            return board[0][i];
        }
    }

    // check diagonals
    if (check_three(board[0][0], board[1][1], board[2][2]))
    {
        return board[0][0];
    }
    if (check_three(board[0][2], board[1][1], board[2][0]))
    {
        return board[0][2];
    }

    // no winner yet
    if (count_moves == SIZE*SIZE)
    {
        return -1;  // game tied
    }
    else
    {
        return 0;  // game not over yet
    }
}

// helper function to check if three values are equal and not 0
int check_three(int a, int b, int c)
{
    return (a == b && b == c && a != 0);
}

// function to announce the winner
void announce_winner(int winner)
{
    printf("Congratulations, %s! You won the game.\n", winner == 1 ? player1_name : player2_name);
}