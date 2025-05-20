//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Board representation
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Function to display current state of board
void display_board() {
    printf("\n\t     0   1   2\n");
    printf("\t   -------------\n");
    for(int i = 0; i < 3; i++) {
        printf("\t%d  |", i);
        for(int j = 0; j < 3; j++)
            printf(" %c |", board[i][j]);
        printf("\n\t   -------------\n");
    }
}

// Function to check if game is over
int is_game_over() {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
    }
    // Check columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return 1;
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    // Check for tie
    int tie_flag = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                tie_flag = 0;
                break;
            }
        }
        if(tie_flag == 0)
            break;
    }
    if(tie_flag == 1)
        return 2;
    // Game not over yet
    return 0;
}

// Function for AI move
void ai_move(char symbol) {
    // Check for winning move
    for(int i = 0; i < 3; i++) {
        // Check winning move in rows
        if(board[i][0] == board[i][1] && board[i][0] == symbol && board[i][2] == ' ') {
            board[i][2] = symbol;
            printf("\nAI chose (%d, %d)\n", i, 2);
            return;
        }
        else if(board[i][0] == board[i][2] && board[i][0] == symbol && board[i][1] == ' ') {
            board[i][1] = symbol;
            printf("\nAI chose (%d, %d)\n", i, 1);
            return;
        }
        else if(board[i][1] == board[i][2] && board[i][1] == symbol && board[i][0] == ' ') {
            board[i][0] = symbol;
            printf("\nAI chose (%d, %d)\n", i, 0);
            return;
        }
        // Check winning move in columns
        else if(board[0][i] == board[1][i] && board[0][i] == symbol && board[2][i] == ' ') {
            board[2][i] = symbol;
            printf("\nAI chose (%d, %d)\n", 2, i);
            return;
        }
        else if(board[0][i] == board[2][i] && board[0][i] == symbol && board[1][i] == ' ') {
            board[1][i] = symbol;
            printf("\nAI chose (%d, %d)\n", 1, i);
            return;
        }
        else if(board[1][i] == board[2][i] && board[1][i] == symbol && board[0][i] == ' ') {
            board[0][i] = symbol;
            printf("\nAI chose (%d, %d)\n", 0, i);
            return;
        }
        // Check winning move in diagonals
        else if(board[0][0] == board[1][1] && board[0][0] == symbol && board[2][2] == ' ') {
            board[2][2] = symbol;
            printf("\nAI chose (%d, %d)\n", 2, 2);
            return;
        }
        else if(board[0][0] == board[2][2] && board[0][0] == symbol && board[1][1] == ' ') {
            board[1][1] = symbol;
            printf("\nAI chose (%d, %d)\n", 1, 1);
            return;
        }
        else if(board[1][1] == board[2][2] && board[1][1] == symbol && board[0][0] == ' ') {
            board[0][0] = symbol;
            printf("\nAI chose (%d, %d)\n", 0, 0);
            return;
        }
        else if(board[0][2] == board[1][1] && board[0][2] == symbol && board[2][0] == ' ') {
            board[2][0] = symbol;
            printf("\nAI chose (%d, %d)\n", 2, 0);
            return;
        }
        else if(board[0][2] == board[2][0] && board[0][2] == symbol && board[1][1] == ' ') {
            board[1][1] = symbol;
            printf("\nAI chose (%d, %d)\n", 1, 1);
            return;
        }
        else if(board[1][1] == board[2][0] && board[1][1] == symbol && board[0][2] == ' ') {
            board[0][2] = symbol;
            printf("\nAI chose (%d, %d)\n", 0, 2);
            return;
        }
    }
    // Check for blocking move
    for(int i = 0; i < 3; i++) {
        // Check blocking move in rows
        if(board[i][0] == board[i][1] && board[i][0] != ' ' && board[i][2] == ' ') {
            board[i][2] = symbol;
            printf("\nAI chose (%d, %d)\n", i, 2);
            return;
        }
        else if(board[i][0] == board[i][2] && board[i][0] != ' ' && board[i][1] == ' ') {
            board[i][1] = symbol;
            printf("\nAI chose (%d, %d)\n", i, 1);
            return;
        }
        else if(board[i][1] == board[i][2] && board[i][1] != ' ' && board[i][0] == ' ') {
            board[i][0] = symbol;
            printf("\nAI chose (%d, %d)\n", i, 0);
            return;
        }
        // Check blocking move in columns
        else if(board[0][i] == board[1][i] && board[0][i] != ' ' && board[2][i] == ' ') {
            board[2][i] = symbol;
            printf("\nAI chose (%d, %d)\n", 2, i);
            return;
        }
        else if(board[0][i] == board[2][i] && board[0][i] != ' ' && board[1][i] == ' ') {
            board[1][i] = symbol;
            printf("\nAI chose (%d, %d)\n", 1, i);
            return;
        }
        else if(board[1][i] == board[2][i] && board[1][i] != ' ' && board[0][i] == ' ') {
            board[0][i] = symbol;
            printf("\nAI chose (%d, %d)\n", 0, i);
            return;
        }
        // Check blocking move in diagonals
        else if(board[0][0] == board[1][1] && board[0][0] != ' ' && board[2][2] == ' ') {
            board[2][2] = symbol;
            printf("\nAI chose (%d, %d)\n", 2, 2);
            return;
        }
        else if(board[0][0] == board[2][2] && board[0][0] != ' ' && board[1][1] == ' ') {
            board[1][1] = symbol;
            printf("\nAI chose (%d, %d)\n", 1, 1);
            return;
        }
        else if(board[1][1] == board[2][2] && board[1][1] != ' ' && board[0][0] == ' ') {
            board[0][0] = symbol;
            printf("\nAI chose (%d, %d)\n", 0, 0);
            return;
        }
        else if(board[0][2] == board[1][1] && board[0][2] != ' ' && board[2][0] == ' ') {
            board[2][0] = symbol;
            printf("\nAI chose (%d, %d)\n", 2, 0);
            return;
        }
        else if(board[0][2] == board[2][0] && board[0][2] != ' ' && board[1][1] == ' ') {
            board[1][1] = symbol;
            printf("\nAI chose (%d, %d)\n", 1, 1);
            return;
        }
        else if(board[1][1] == board[2][0] && board[1][1] != ' ' && board[0][2] == ' ') {
            board[0][2] = symbol;
            printf("\nAI chose (%d, %d)\n", 0, 2);
            return;
        }
    }
    // Check for center move
    if(board[1][1] == ' ') {
        board[1][1] = symbol;
        printf("\nAI chose (%d, %d)\n", 1, 1);
        return;
    }
    // Check for corner move
    else if(board[0][0] == ' ') {
        board[0][0] = symbol;
        printf("\nAI chose (%d, %d)\n", 0, 0);
        return;
    }
    else if(board[0][2] == ' ') {
        board[0][2] = symbol;
        printf("\nAI chose (%d, %d)\n", 0, 2);
        return;
    }
    else if(board[2][0] == ' ') {
        board[2][0] = symbol;
        printf("\nAI chose (%d, %d)\n", 2, 0);
        return;
    }
    else if(board[2][2] == ' ') {
        board[2][2] = symbol;
        printf("\nAI chose (%d, %d)\n", 2, 2);
        return;
    }
}

// Function for player move
void player_move(char symbol) {
    int row, col;
    printf("\nYour turn (%c)\n", symbol);
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);
    while(board[row][col] != ' ' || row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid move. Enter row and column again: ");
        scanf("%d %d", &row, &col);
    }
    board[row][col] = symbol;
    printf("You chose (%d, %d)\n", row, col);
}

// Main function
int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("Instructions:\n");
    printf("- The board is a 3x3 grid of cells.\n");
    printf("- Players take turns to mark a cell with their symbol (X or O).\n");
    printf("- The player who succeeds in placing three of their symbols in a horizontal, vertical, or diagonal row wins.\n");
    display_board();
    int game_over = 0, turn = 0;
    char symbol = 'X';
    while(!game_over) {
        if(turn %2 == 0)
            player_move(symbol);
        else
            ai_move(symbol);
        turn++;
        display_board();
        game_over = is_game_over();
        if(game_over == 1) {
            if(turn %2 == 1)
                printf("\nCongratulations! You win!\n");
            else
                printf("\nGame over. AI wins!\n");
        }
        else if(game_over == 2) {
            printf("\nGame over. It's a tie!\n");
        }
        if(symbol == 'X')
            symbol = 'O';
        else
            symbol = 'X';
    }
    return 0;
}