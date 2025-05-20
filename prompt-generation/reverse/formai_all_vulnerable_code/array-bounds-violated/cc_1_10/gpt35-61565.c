//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void setup_game(int board[][COLS]);
void print_board(int board[][COLS], int choice1[2], int choice2[2]);
void play_game(int board[][COLS], int player[2], int choice1[2], int choice2[2]);
void end_game(int board[][COLS]);

int main()
{
    int board[ROWS][COLS];
    int choice1[2] = {-1, -1};
    int choice2[2] = {-1, -1};
    int player[2] = {0, 0};

    setup_game(board);

    while (1)
    {
        print_board(board, choice1, choice2);
        play_game(board, player, choice1, choice2);
        if (player[0] + player[1] == (ROWS * COLS) / 2)
        {
            end_game(board);
            break;
        }
    }

    return 0;
}

void setup_game(int board[][COLS])
{
    int num_pairs = (ROWS * COLS) / 2;
    int pairs[num_pairs];
    int count = 0;

    for (int i = 1; i <= num_pairs; i++)
    {
        pairs[count++] = i;
        pairs[count++] = i;
    }

    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int index = rand() % num_pairs * 2;
            board[i][j] = pairs[index];
            pairs[index] = pairs[num_pairs * 2 - 1];
            num_pairs--;
        }
    }
}

void print_board(int board[][COLS], int choice1[2], int choice2[2])
{
    system("clear");
    printf("   ");
    for (int i = 0; i < COLS; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("%c ", i + 'A');
        for (int j = 0; j < COLS; j++)
        {
            if (i == choice1[0] && j == choice1[1])
            {
                printf("%d ", board[i][j]);
            }
            else if (i == choice2[0] && j == choice2[1])
            {
                printf("%d ", board[i][j]);
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void play_game(int board[][COLS], int player[2], int choice1[2], int choice2[2])
{
    int row1, col1, row2, col2;

    printf("Player 1: %d, Player 2: %d\n", player[0], player[1]);

    while (1)
    {
        printf("Player %d, choose first card (e.g. A1): ", (player[0] + player[1]) % 2 + 1);
        scanf(" %c%d", &row1, &col1);
        row1 -= 'A';
        col1--;
        if (choice1[0] == row1 && choice1[1] == col1)
        {
            printf("You've already chosen this card. Choose a different one.\n");
            continue;
        }
        if (choice2[0] == row1 && choice2[1] == col1)
        {
            printf("This card is already matched. Choose a different one.\n");
            continue;
        }
        choice1[0] = row1;
        choice1[1] = col1;
        break;
    }

    while (1)
    {
        printf("Player %d, choose second card (e.g. B2): ", (player[0] + player[1]) % 2 + 1);
        scanf(" %c%d", &row2, &col2);
        row2 -= 'A';
        col2--;
        if (choice1[0] == row2 && choice1[1] == col2)
        {
            printf("You've already chosen this card. Choose a different one.\n");
            continue;
        }
        if (choice2[0] == row2 && choice2[1] == col2)
        {
            printf("This card is already matched. Choose a different one.\n");
            continue;
        }
        choice2[0] = row2;
        choice2[1] = col2;
        break;
    }

    if (board[row1][col1] == board[row2][col2])
    {
        printf("Match!\n");
        player[(player[0] + player[1]) % 2]++;
        choice1[0] = choice1[1] = choice2[0] = choice2[1] = -1;
    }
    else
    {
        printf("No match, try again.\n");
    }
    printf("Press enter to continue...");
    while (getchar() != '\n');
}

void end_game(int board[][COLS])
{
    printf("Game over!\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}