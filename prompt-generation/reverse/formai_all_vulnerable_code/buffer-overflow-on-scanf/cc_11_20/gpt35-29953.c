//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

char symbol[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void draw_board();
int check_win();
void mark_board(char marker, int choice);
void paranoid_bot(char marker);

int main()
{
    int player = 1, choice, outcome;
    char marker;

    do
    {
        draw_board();

        player = (player % 2) ? 1 : 2;

        printf("\nPlayer %d, choose a box: ", player);
        scanf("%d", &choice);

        marker = (player == 1) ? 'X' : 'O';

        mark_board(marker, choice);

        outcome = check_win();

        player++;

    } while (outcome == -1);

    draw_board();

    if (outcome == 1)
        printf("==>\aPlayer %d wins!\n", --player);

    else
        printf("==>\aGame draw\n");

    return 0;
}

/*Draws the Tic Tac Toe board*/
void draw_board()
{
    system("clear");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", symbol[1], symbol[2], symbol[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", symbol[4], symbol[5], symbol[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", symbol[7], symbol[8], symbol[9]);

    printf("     |     |     \n\n");
}

/* Checks the board for any wins by either player*/
int check_win()
{
    if (symbol[1] == symbol[2] && symbol[2] == symbol[3])
        return 1;

    else if (symbol[4] == symbol[5] && symbol[5] == symbol[6])
        return 1;

    else if (symbol[7] == symbol[8] && symbol[8] == symbol[9])
        return 1;

    else if (symbol[1] == symbol[4] && symbol[4] == symbol[7])
        return 1;

    else if (symbol[2] == symbol[5] && symbol[5] == symbol[8])
        return 1;

    else if (symbol[3] == symbol[6] && symbol[6] == symbol[9])
        return 1;

    else if (symbol[1] == symbol[5] && symbol[5] == symbol[9])
        return 1;

    else if (symbol[3] == symbol[5] && symbol[5] == symbol[7])
        return 1;

    else if (symbol[1] != '1' && symbol[2] != '2' && symbol[3] != '3' && symbol[4] != '4' && symbol[5] != '5' && symbol[6] != '6' && symbol[7] != '7' && symbol[8] != '8' && symbol[9] != '9')
        return 0;

    else
        return -1;
}

/*Marks the board with a player's marker*/
void mark_board(char marker, int choice)
{
    if (choice == 1 && symbol[1] == '1')
        symbol[1] = marker;

    else if (choice == 2 && symbol[2] == '2')
        symbol[2] = marker;

    else if (choice == 3 && symbol[3] == '3')
        symbol[3] = marker;

    else if (choice == 4 && symbol[4] == '4')
        symbol[4] = marker;

    else if (choice == 5 && symbol[5] == '5')
        symbol[5] = marker;

    else if (choice == 6 && symbol[6] == '6')
        symbol[6] = marker;

    else if (choice == 7 && symbol[7] == '7')
        symbol[7] = marker;

    else if (choice == 8 && symbol[8] == '8')
        symbol[8] = marker;

    else if (choice == 9 && symbol[9] == '9')
        symbol[9] = marker;

    else
    {
        printf("Invalid move. Please try again.\n");
        paranoid_bot(marker);
    }
}

/*The Paranoid Tic Tac Toe AI*/
void paranoid_bot(char marker)
{
    int safe_move = 0;

    if (symbol[1] == marker && symbol[2] == marker && symbol[3] == '3')
        safe_move = 3;

    else if (symbol[4] == marker && symbol[5] == marker && symbol[6] == '6')
        safe_move = 6;

    else if (symbol[7] == marker && symbol[8] == marker && symbol[9] == '9')
        safe_move = 9;

    else if (symbol[1] == marker && symbol[4] == marker && symbol[7] == '7')
        safe_move = 7;

    else if (symbol[2] == marker && symbol[5] == marker && symbol[8] == '8')
        safe_move = 8;

    else if (symbol[3] == marker && symbol[6] == marker && symbol[9] == '9')
        safe_move = 9;

    else if (symbol[1] == marker && symbol[5] == marker && symbol[9] == '9')
        safe_move = 9;

    else if (symbol[3] == marker && symbol[5] == marker && symbol[7] == '7')
        safe_move = 7;

    if (safe_move != 0)
        mark_board(marker, safe_move);

    else
    {
        int i, random_move;
        srand(1);
        do
        {
            random_move = rand() % 9 + 1;
        } while (symbol[random_move] != random_move + '0');
        mark_board(marker, random_move);
    }
}