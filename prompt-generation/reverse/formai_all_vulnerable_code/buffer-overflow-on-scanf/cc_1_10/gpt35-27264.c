//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include<stdio.h>

char board[3][3] = {'-','-','-','-','-','-','-','-','-'};
char player = 'X';
char computer = 'O';

void display_board()
{
    printf("\n");
    printf("\t\t\t\t    %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t\t   ---|---|---\n");
    printf("\t\t\t\t    %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t\t   ---|---|---\n");
    printf("\t\t\t\t    %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

char check_win()
{
    int row, col;
    for(row=0; row<3; row++)
    {
        if(board[row][0]==board[row][1] && board[row][1]==board[row][2])
            return board[row][0];
    }

    for(col=0; col<3; col++)
    {
        if(board[0][col]==board[1][col] && board[1][col]==board[2][col])
            return board[0][col];
    }

    if(board[0][0]== board[1][1] && board[1][1]== board[2][2])
        return board[0][0];

    if(board[0][2]== board[1][1] && board[1][1]== board[2][0])
        return board[0][2];

    if(board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' &&
        board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' &&
        board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-')
    {
        return ' ';
    }

    return 'n';
}

int minmax(char curr_player)
{
    char result = check_win();
    if(result != 'n')
    {
        if(result == computer)
            return 10;
        else if(result == player)
            return -10;
        else
            return 0;
    }

    int best_score, row, col, score;
    if(curr_player == computer)
    {
        best_score = -1000;
        for(row=0; row<3; row++)
        {
            for(col=0; col<3; col++)
            {
                if(board[row][col] == '-')
                {
                    board[row][col] = curr_player;
                    score = minmax(player);
                    if(score > best_score)
                        best_score = score;

                    board[row][col] = '-';
                }
            }
        }

        return best_score;
    }
    else
    {
        best_score = 1000;
        for(row=0; row<3; row++)
        {
            for(col=0; col<3; col++)
            {
                if(board[row][col] == '-')
                {
                    board[row][col] = curr_player;
                    score = minmax(computer);
                    if(score < best_score)
                        best_score = score;

                    board[row][col] = '-';
                }
            }
        }

        return best_score;
    }

}

void computer_move()
{
    int best_score = -1000;
    int row, col;
    for(row=0; row<3; row++)
    {
        for(col=0; col<3; col++)
        {
            if(board[row][col] == '-')
            {
                board[row][col] = computer;
                int score = minmax(player);
                board[row][col] = '-';
                if(score > best_score)
                {
                    best_score = score;
                    printf("AI Moved to Row: %d and Column: %d \n", row+1, col+1);
                    board[row][col] = computer;
                    return;
                }
            }
        }
    }
}

int main()
{
    int row, col;
    printf("Welcome to Tic Tac Toe AI!\n\n");
    printf("\t\t\t\t    1 | 2 | 3\n");
    printf("\t\t\t\t   ---|---|---\n");
    printf("\t\t\t\t    4 | 5 | 6\n");
    printf("\t\t\t\t   ---|---|---\n");
    printf("\t\t\t\t    7 | 8 | 9\n\n");
    for(int i=0; i<9; i++)
    {
        int move;
        if(i%2 == 0)
        {
            printf("Player's turn (X) (1-9): ");
            scanf("%d", &move);
            row = (move-1)/3;
            col = (move-1)%3;
            if(board[row][col] != '-')
            {
                printf("Invalid Move! Try Again\n");
                i--;
                continue;
            }
            else
            {
                board[row][col] = player;
                display_board();
                char result = check_win();
                if(result != 'n')
                {
                    if(result == player)
                        printf("Player Wins!\n");
                    else if(result == computer)
                        printf("AI Wins!\n");
                    else
                        printf("Draw!\n");
                    return 0;

                }
            }

        }
        else
        {
            computer_move();
            display_board();
            char result = check_win();
            if(result != 'n')
            {
                if(result == computer)
                    printf("AI Wins!\n");
                else if(result == player)
                    printf("Player Wins!\n");
                else
                    printf("Draw!\n");
                return 0;
            }
        }

    }

}