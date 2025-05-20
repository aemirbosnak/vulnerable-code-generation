//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 20

void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
void init_board(int board[BOARD_SIZE][BOARD_SIZE]);
int get_random_number(int lower, int upper);

int main()
{
    srand(time(NULL));

    int board[BOARD_SIZE][BOARD_SIZE];
    int players[MAX_PLAYERS][2];
    int num_players = 0;
    char name[20];

    // Get number of players and their names
    printf("Enter the number of players (1-4): ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++)
    {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", name);
        printf("Welcome %s!\n", name);
        players[i][0] = i+1;
        players[i][1] = get_random_number(0, BOARD_SIZE-1);
    }

    // Initialize board
    init_board(board);
    print_board(board);

    // Start game loop
    int winner = 0;
    while (winner == 0)
    {
        for (int i = 0; i < num_players; i++)
        {
            // Get player's move
            printf("%s, enter your move: ", name);
            int move;
            scanf("%d", &move);

            // Update player's position
            players[i][1] += move;

            // Check if player has reached end of board
            if (players[i][1] >= BOARD_SIZE-1)
            {
                winner = i+1;
                break;
            }
        }

        // Update board
        init_board(board);
        for (int i = 0; i < num_players; i++)
        {
            board[players[i][1]][i+1] = 1;
        }
        print_board(board);
    }

    // Declare winner
    printf("Congratulations %s! You won!\n", name);

    return 0;
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = BOARD_SIZE-1; i >= 0; i--)
    {
        for (int j = 0; j < MAX_PLAYERS+1; j++)
        {
            if (board[i][j] == 1)
            {
                printf("| %c ", 'A'+j-1);
            }
            else
            {
                printf("|   ");
            }
        }
        printf("|\n");
    }
}

void init_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < MAX_PLAYERS+1; j++)
        {
            board[i][j] = 0;
        }
    }
}

int get_random_number(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}