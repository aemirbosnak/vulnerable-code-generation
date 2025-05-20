//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

// Function to display the game board
void display_board(char board[][3]) {
    printf("\n-----------------------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("|     |     |     |\n");
        for (int j = 0; j < 3; j++) {
            printf("|  %c  ", board[i][j]);
        }
        printf("|\n");
        printf("|_____|_____|_____|\n");
    }
    printf("-----------------------------------\n");
}

// Function to check if any player has won the game
bool check_win(char board[][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool check_draw(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to get the input move from the human player
int get_human_move() {
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    return move;
}

// Function to get the best move for the AI player
int get_ai_move(char board[][3], char player) {
    // Check if AI can win in the next move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (check_win(board, player)) {
                    board[i][j] = ' ';
                    return 3 * i + j + 1;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Check if human can win in the next move
    char other_player = (player == 'X') ? 'O' : 'X';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = other_player;
                if (check_win(board, other_player)) {
                    board[i][j] = ' ';
                    return 3 * i + j + 1;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Try to take the center
    if (board[1][1] == ' ') {
        return 5;
    }
    // Try to take a corner
    if (board[0][0] == ' ') {
        return 1;
    }
    if (board[0][2] == ' ') {
        return 3;
    }
    if (board[2][0] == ' ') {
        return 7;
    }
    if (board[2][2] == ' ') {
        return 9;
    }
    // Take any available spot
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 3 * i + j + 1;
            }
        }
    }
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char human_player, ai_player, current_player;
    int move;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose your player (X/O): ");
    scanf(" %c", &human_player);
    ai_player = (human_player == 'X') ? 'O' : 'X';
    printf("You will be playing as %c\n", human_player);
    display_board(board);
    if (ai_player == 'X') {
        printf("The AI player will make the first move.\n");
        current_player = ai_player;
    } else {
        printf("You will make the first move.\n");
        current_player = human_player;
    }
    while (true) {
        if (current_player == human_player) {
            move = get_human_move();
            while (board[(move - 1) / 3][(move - 1) % 3] != ' ') {
                printf("Invalid move. Please try again.\n");
                move = get_human_move();
            }
        } else {
            move = get_ai_move(board, ai_player);
        }
        board[(move - 1) / 3][(move - 1) % 3] = current_player;
        display_board(board);
        if (check_win(board, current_player)) {
            printf("%c wins!\n", current_player);
            break;
        }
        if (check_draw(board)) {
            printf("It's a draw!\n");
            break;
        }
        current_player = (current_player == human_player) ? ai_player : human_player;
    }
    return 0;
}