//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Creating board
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

int win(char symbol) {
    // Horizontal check
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    
    // Vertical check
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    
    // Diagonal check
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    
    return 0;
}

int evaluate_board() {
    // -1 indicates player wins, 0 indicates draw, 1 indicates AI wins
    if (win('O')) {
        return 1;
    } else if (win('X')) {
        return -1;
    } else {
        return 0;
    }
}

int is_full() {
    // Check if board is full
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int minimax(int depth, int is_max) {
    int score = evaluate_board();
    
    if (score == 1) {
        return score - depth;
    }
    
    if (score == -1) {
        return score + depth;
    }
    
    if (is_full()) {
        return 0;
    }
    
    if (is_max) {
        int best = -1000;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int val = minimax(depth + 1, !is_max);
                    board[i][j] = ' ';
                    if (val > best) {
                        best = val;
                    }
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int val = minimax(depth + 1, !is_max);
                    board[i][j] = ' ';
                    if (val < best) {
                        best = val;
                    }
                }
            }
        }
        return best;
    }
}

void ai_move() {
    int best_value = -1000;
    int x = -1, y = -1;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int move_val = minimax(0, 0);
                board[i][j] = ' ';
                if (move_val > best_value) {
                    best_value = move_val;
                    x = i;
                    y = j;
                }
            }
        }
    }
    board[x][y] = 'O';
}

void display_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

int main() {
    int turn_count = 0;
    int player_turn;
    printf("Choose your turn:\n1. X\n2. O\n");
    scanf("%d", &player_turn);
    while (1) {
        display_board();
        int row, col;
        if (turn_count % 2 == 0 && player_turn == 1 || turn_count % 2 == 1 && player_turn == 2) {
            printf("Enter row and column to place your move (1-3): ");
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                if (player_turn == 1) {
                    board[row][col] = 'X';
                } else {
                    board[row][col] = 'O';
                }
                turn_count++;
            } else {
                printf("Invalid move! Try again.\n");
            }
        } else {
            ai_move();
            turn_count++;
        }
        
        int score = evaluate_board();
        if (score == 1) {
            display_board();
            printf("You lose! Better luck next time.\n");
            break;
        } else if (score == -1) {
            display_board();
            printf("Congratulations! You win.\n");
            break;
        } else if (is_full()) {
            display_board();
            printf("It's a draw!\n");
            break;
        }
    }
    return 0;
}