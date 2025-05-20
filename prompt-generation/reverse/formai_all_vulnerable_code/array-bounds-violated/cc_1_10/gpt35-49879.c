//FormAI DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>

char board[3][3]; // Initializing a 2D array for the board

void initialize_board(); // Function declaration
void print_board();
char check_winner();

int main()
{
    printf("Let's play Tic-Tac-Toe!\n");

    initialize_board(); // Initializing the board
    print_board(); // Printing the board

    int player = 1;
    char active_player = '-';
    int row, col;

    while (check_winner() == '-' && player <=9) {
        if (player % 2 == 1) {
            active_player = 'X';
        }
        else {
            active_player = 'O';
        }

        printf("Player %d, enter a row and column (0-2): ", player);
        scanf("%d %d", &row, &col);

        if (board[row][col] != '-') {
            printf("That spot is already taken!\n");
            continue;
        }

        board[row][col] = active_player;
        print_board();
        player++;
    }

    char winner = check_winner();
    if (winner == '-') {
        printf("It's a tie!\n");
    }
    else {
        printf("Player %c won!\n", winner);
    }

    return 0;
}

void initialize_board()
{
    int i, j;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board()
{
    int i, j;
    printf("\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

char check_winner()
{
    int i, j;
    // Check rows
    for (i=0; i<3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0];
        }
    }
    // Check columns
    for (j=0; j<3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-') {
            return board[0][j];
        }
    }
    // Check diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return board[0][2];
    }
    return '-';
}