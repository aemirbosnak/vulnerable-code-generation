//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>

int playGame(int rows, int columns);

int main()
{
    int rows, columns;

    printf("Welcome to the C table game!\n");

    printf("Please enter the number of rows: ");
    scanf("%d", &rows);

    printf("Please enter the number of columns: ");
    scanf("%d", &columns);

    int winner = playGame(rows, columns);

    if (winner == 1)
        printf("Player 1 wins the game!");
    else
        printf("Player 2 wins the game!");

    return 0;
}

int playGame(int rows, int columns)
{
    static int player = 1;
    static int turn = 1;
    int rowChoice, colChoice;
    int winner = 0;

    printf("Turn %d: It is Player %d's turn.\n", turn, player);

    printf("Please choose a row: ");
    scanf("%d", &rowChoice);

    printf("Please choose a column: ");
    scanf("%d", &colChoice);

    if (rowChoice < 1 || rowChoice > rows || colChoice < 1 || colChoice > columns)
    {
        printf("Invalid choice. Try again.\n");
        return playGame(rows, columns);
    }

    printf("Player %d chooses row %d and column %d\n", player, rowChoice, colChoice);

    if (rowChoice == rows && colChoice == columns)
    {
        winner = player;
        return winner;
    }
    else
    {
        player = (player == 1) ? 2 : 1;
        turn++;
        return playGame(rows, columns);
    }
}