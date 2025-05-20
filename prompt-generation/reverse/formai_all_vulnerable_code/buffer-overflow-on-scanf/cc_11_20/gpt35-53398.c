//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to print the Tic Tac Toe board
void print_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n\n", board[2][0], board[2][1], board[2][2]);
}

// Function to get user input and validate it
void get_input(char board[3][3], char player) {
    int row, col;
    printf("Enter row and column separated by space (Ex: 1 2): ");
    scanf("%d %d", &row, &col);

    // Check if input is within limits and cell is not already occupied
    while ((row < 1 || row > 3 || col < 1 || col > 3) || board[row-1][col-1] != '-') {
        printf("Invalid input! Enter row and column separated by space (Ex: 1 2): ");
        scanf("%d %d", &row, &col);
    }

    // Update the board with user input
    board[row-1][col-1] = player;
}

// Function to check if the game has ended
int game_over(char board[3][3]) {
    int i, j;

    // Check rows for a win
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                return 1;
            } else if (board[i][0] == 'O') {
                return 2;
            }
        }
    }

    // Check columns for a win
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') {
                return 1;
            } else if (board[0][j] == 'O') {
                return 2;
            }
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        if (board[1][1] == 'X') {
            return 1;
        } else if (board[1][1] == 'O') {
            return 2;
        }
    }

    // Check for a tie
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }

    return 3;
}

// Function to simulate a computer move
void computer_move(char board[3][3], char computer) {
    printf("Computer's turn:\n");
    int i, j, found = 0;

    // Check for a winning move horizontally
    for (i = 0; i < 3; i++) {
        if (board[i][0] == computer && board[i][1] == computer && board[i][2] == '-') {
            board[i][2] = computer;
            found = 1;
            break;
        }
        else if (board[i][0] == '-' && board[i][1] == computer && board[i][2] == computer) {
            board[i][0] = computer;
            found = 1;
            break;
        }
        else if (board[i][0] == computer && board[i][1] == '-' && board[i][2] == computer) {
            board[i][1] = computer;
            found = 1;
            break;
        }
    }

    // Check for a winning move vertically
    if (!found) {
        for (j = 0; j < 3; j++) {
            if (board[0][j] == computer && board[1][j] == computer && board[2][j] == '-') {
                board[2][j] = computer;
                found = 1;
                break;
            }
            else if (board[0][j] == '-' && board[1][j] == computer && board[2][j] == computer) {
                board[0][j] = computer;
                found = 1;
                break;
            }
            else if (board[0][j] == computer && board[1][j] == '-' && board[2][j] == computer) {
                board[1][j] = computer;
                found = 1;
                break;
            }
        }
    }

    // Check for a winning move diagonally
    if (!found) {
        if (board[0][0] == computer && board[1][1] == computer && board[2][2] == '-') {
            board[2][2] = computer;
            found = 1;
        }
        else if (board[0][2] == computer && board[1][1] == computer && board[2][0] == '-') {
            board[2][0] = computer;
            found = 1;
        }
        else if (board[0][0] == '-' && board[1][1] == computer && board[2][2] == computer) {
            board[0][0] = computer;
            found = 1;
        }
        else if (board[0][2] == '-' && board[1][1] == computer && board[2][0] == computer) {
            board[0][2] = computer;
            found = 1;
        }
        else if (board[0][0] == computer && board[1][1] == '-' && board[2][2] == computer) {
            board[1][1] = computer;
            found = 1;
        }
        else if (board[0][2] == computer && board[1][1] == '-' && board[2][0] == computer) {
            board[1][1] = computer;
            found = 1;
        }
    }

    // If no winning move found, make a random move
    if (!found) {
        srand(time(0));
        int row = rand() % 3;
        int col = rand() % 3;
        while (board[row][col] != '-') {
            row = rand() % 3;
            col = rand() % 3;
        }
        board[row][col] = computer;
    }
}

int main() {
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    printf("*** Welcome to Tic Tac Toe! ***\n");
    printf("You are playing against the computer.\n");

    char player = 'X', computer = 'O';
    int result = 0;

    // Game loop
    while (1) {
        print_board(board);

        // User's turn
        get_input(board, player);

        result = game_over(board);
        if (result == 1) {
            print_board(board);
            printf("Congratulations! You won!\n");
            break;
        } else if (result == 3) {
            print_board(board);
            printf("It's a tie!\n");
            break;
        }

        // Computer's turn
        computer_move(board, computer);
        
        result = game_over(board);
        if (result == 2) {
            print_board(board);
            printf("Sorry, you lost!\n");
            break;
        } else if (result == 3) {
            print_board(board);
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}