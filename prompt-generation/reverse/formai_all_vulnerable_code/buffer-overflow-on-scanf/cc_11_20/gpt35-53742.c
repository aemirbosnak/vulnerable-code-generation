//FormAI DATASET v1.0 Category: Game ; Style: Ada Lovelace
#include <stdio.h>

void display_board(char board[])
{
    // Displays the current game board
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int check_win(char board[])
{
    // Check if a player has won the game
    if (board[0] == board[1] && board[1] == board[2])
        return 1;
    else if (board[3] == board[4] && board[4] == board[5])
        return 1;
    else if (board[6] == board[7] && board[7] == board[8])
        return 1;
    else if (board[0] == board[3] && board[3] == board[6])
        return 1;
    else if (board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] == board[5] && board[5] == board[8])
        return 1;
    else if (board[0] == board[4] && board[4] == board[8])
        return 1;
    else if (board[2] == board[4] && board[4] == board[6])
        return 1;
    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' 
             && board[3] != '4' && board[4] != '5' && board[5] != '6' 
             && board[6] != '7' && board[7] != '8' && board[8] != '9')
        return 0;
    else
        return -1;
}

int main()
{
    int player = 1; // Player 1 is X and player 2 is O
    int choice;
    char mark;
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int game_status;

    do {
        display_board(board);
        player = (player % 2) ? 1 : 2; // Alternate player turns
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O'; // Assigns mark based on player
        if (choice == 1 && board[0] == '1')
            board[0] = mark;
        else if (choice == 2 && board[1] == '2')
            board[1] = mark;
        else if (choice == 3 && board[2] == '3')
            board[2] = mark;
        else if (choice == 4 && board[3] == '4')
            board[3] = mark;
        else if (choice == 5 && board[4] == '5')
            board[4] = mark;
        else if (choice == 6 && board[5] == '6')
            board[5] = mark;
        else if (choice == 7 && board[6] == '7')
            board[6] = mark;
        else if (choice == 8 && board[7] == '8')
            board[7] = mark;
        else if (choice == 9 && board[8] == '9')
            board[8] = mark;
        else {
            printf("Invalid move. Please try again.\n");
            player--;
        }
        game_status = check_win(board);
    } while (game_status == -1);
    
    display_board(board);
    if (game_status == 1)
        printf("Player %d has won!\n", player);
    else
        printf("The game is a draw.\n");
        
    return 0;
}