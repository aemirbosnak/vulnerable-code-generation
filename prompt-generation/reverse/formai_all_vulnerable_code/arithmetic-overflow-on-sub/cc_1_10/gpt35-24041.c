//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void drawBoard()
{
    printf("\n\n");
    printf("\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

int isFull()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j] == ' ')
                return 0;
    return 1;
}

int checkForWin(char symbol)
{
    if(board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol)
        return 1;
    if(board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol)
        return 1;
    if(board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol)
        return 1;
    if(board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol)
        return 1;
    if(board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol)
        return 1;
    if(board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol)
        return 1;
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return 1;
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return 1;
    return 0;
}

int evaluate()
{
    if(checkForWin('O'))
        return 10;
    else if(checkForWin('X'))
        return -10;
    else
        return 0;
}

int minimax(int depth, int isMaximizer)
{
    int score = evaluate();
    if(score == 10)
        return score;
    if(score == -10)
        return score;
    if(isFull())
        return 0;

    int bestScore;
    if(isMaximizer)
    {
        bestScore = -1000;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    bestScore = fmax(bestScore, minimax(depth+1, !isMaximizer));
                    board[i][j] = ' ';
                }
            }
        }
        return bestScore - depth;
    }
    else
    {
        bestScore = 1000;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = 'X';
                    bestScore = fmin(bestScore, minimax(depth+1, !isMaximizer));
                    board[i][j] = ' ';
                }
            }
        }
        return bestScore + depth;
    }
}

void runAI()
{
    int bestScore = -1000;
    int bestI = -1, bestJ = -1;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = 'O';
                int score = minimax(0, 0);
                board[i][j] = ' ';
                if(score > bestScore)
                {
                    bestScore = score;
                    bestI = i;
                    bestJ = j;
                }
            }
        }
    }

    board[bestI][bestJ] = 'O';
}

int main()
{
    printf("Welcome to Tic Tac Toe!\n");
    printf("To play, simply enter the row (1-3) and column (1-3) where you want to place your mark.\n");

    int row, col;
    int currentPlayer = 0;
    char marking;
    drawBoard();

    while(!isFull())
    {
        currentPlayer = !currentPlayer;
        marking = (currentPlayer == 1) ? 'X' : 'O';

        if(currentPlayer == 0)
            runAI();
        else
        {
            printf("Player %d, enter row: ", currentPlayer+1);
            scanf("%d", &row);
            printf("Player %d, enter column: ", currentPlayer+1);
            scanf("%d", &col);

            row--;
            col--;
            if(board[row][col] != ' ')
            {
                printf("That spot is already taken! Choose another.\n");
                currentPlayer = !currentPlayer;
                continue;
            }
            board[row][col] = marking;
        }

        drawBoard();
        if(checkForWin(marking))
        {
            printf("Player %d has won!\n", currentPlayer+1);
            return 0;
        }
    }

    printf("It's a draw!\n");
    return 0;
}