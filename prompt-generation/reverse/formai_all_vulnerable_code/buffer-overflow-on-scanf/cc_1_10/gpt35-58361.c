//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: genious
#include<stdio.h>
#include<stdlib.h>

//Initialising the variable for declaration of board size
int size_of_board;

//Structuring the board
struct TicTacToe {
    char **board;
};

//Function to create board
struct TicTacToe createBoard(int size) {
    struct TicTacToe board;
    board.board = (char **) malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        board.board[i] = (char *) malloc(size * sizeof(char));
        for (int j = 0; j < size; j++) {
            board.board[i][j] = '-';
        }
    }
    return board;
}

//Function to print board
void printBoard(struct TicTacToe game) {
    for (int i = 0; i < size_of_board; i++) {
        for (int j = 0; j < size_of_board; j++) {
            printf("%c ", game.board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Structuring the Player
struct Player {
    int x_move;
    int y_move;
    char symbol;
};

struct Player player1, player2;

//Function to determine the winner of the game
int winner(struct TicTacToe game) {
    int diag1 = 0, diag2 = 0, col, row;

    //Check Diagonal1
    for (int i = 0; i < size_of_board; i++) {
        if (game.board[i][i] == player1.symbol) {
            diag1++;
        } else if (game.board[i][i] == player2.symbol) {
            diag1--;
        }
    }

    //Check Diagonal2
    for (int i = 0; i < size_of_board; i++) {
        int j = size_of_board - 1 - i;
        if (game.board[i][j] == player1.symbol) {
            diag2++;
        } else if (game.board[i][j] == player2.symbol) {
            diag2--;
        }
    }

    //Check Rows and Columns
    for (int i = 0; i < size_of_board; i++) {
        row = 0;
        col = 0;
        for (int j = 0; j < size_of_board; j++) {
            if (game.board[i][j] == player1.symbol) {
                row++;
            } else if (game.board[i][j] == player2.symbol) {
                row--;
            }
            if (game.board[j][i] == player1.symbol) {
                col++;
            } else if (game.board[j][i] == player2.symbol) {
                col--;
            }
        }
        if ((row == size_of_board) || (col == size_of_board)) {
            return 1;
        } else if ((row == -size_of_board) || (col == -size_of_board)) {
            return -1;
        }
    }

    //Check tie
    for (int i = 0; i < size_of_board; i++) {
        for (int j = 0; j < size_of_board; j++) {
            if (game.board[i][j] == '-') {
                return 0;
            }
        }
    }

    //Check for a draw
    return 2;
}

//Main function for running the game
int main() {

    //Welcome Message
    printf("Welcome to the Genius Tic Tac Toe\n");
    printf("Please enter board size: ");
    scanf("%d", &size_of_board);

    struct TicTacToe game = createBoard(size_of_board);

    printf("\nEnter the symbol for player 1(X or O): ");

    //Taking input of the Player symbols
    scanf(" %c", &player1.symbol);

    //Adding symbol for player 2 using Tenary Operator
    player2.symbol = (player1.symbol == 'X') ? 'O' : 'X';

    //Initialise Move
    int move = 1;
    int winner_or_not = 0;

    while (winner_or_not == 0) {
        int row, col;
        if (move % 2 == 1) {
            printf("\nPlayer 1 move (symbol - %c)\n", player1.symbol);
        } else {
            printf("\nPlayer 2 move (symbol - %c)\n", player2.symbol);
        }
        printf("Please enter the row and collumn number (0 based indexed): ");
        scanf("%d%d", &row, &col);

        //Check Validity of Move
        if ((row < 0) || (row >= size_of_board) || (col < 0) || (col >= size_of_board)) {
            printf("Invalid Move! Try Again.\n");
            continue;
        }
        if (game.board[row][col] != '-') {
            printf("Invalid Move! Spot already occupied. Try Again.\n");
            continue;
        }
        //Add to the board
        if (move % 2 == 1) {
            game.board[row][col] = player1.symbol;
        } else {
            game.board[row][col] = player2.symbol;
        }
        printBoard(game);
        winner_or_not = winner(game);
        move++;
    }

    //Check the result and print who won
    if (winner_or_not == 1) {
        printf("Player 1 wins!\n");
    } else if (winner_or_not == -1) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a draw!\n");
    }
    return 0;
}