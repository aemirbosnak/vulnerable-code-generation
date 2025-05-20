//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3];   // 3x3 board representation
char player_token, ai_token;   // tokens for player and AI

void init_board() {
    // initialize board with empty spaces
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    printf("\n-------------\n");
    for(int i=0; i<3; i++) {
        printf("| ");
        for(int j=0; j<3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

bool is_empty(int row, int col) {
    // check if the cell is empty
    if (board[row][col] == ' ')
        return true;
    return false;
}

bool player_wins() {
    // check if player wins
    for(int i=0; i<3; i++) {
        if (board[i][0] == player_token && board[i][1] == player_token && board[i][2] == player_token)
            return true;
    }
    for(int i=0; i<3; i++) {
        if (board[0][i] == player_token && board[1][i] == player_token && board[2][i] == player_token)
            return true;
    }
    if (board[0][0] == player_token && board[1][1] == player_token && board[2][2] == player_token)
        return true;
    if (board[0][2] == player_token && board[1][1] == player_token && board[2][0] == player_token)
        return true;
    return false;
}

bool ai_wins() {
    // check if AI wins
    for(int i=0; i<3; i++) {
        if (board[i][0] == ai_token && board[i][1] == ai_token && board[i][2] == ai_token)
            return true;
    }
    for(int i=0; i<3; i++) {
        if (board[0][i] == ai_token && board[1][i] == ai_token && board[2][i] == ai_token)
            return true;
    }
    if (board[0][0] == ai_token && board[1][1] == ai_token && board[2][2] == ai_token)
        return true;
    if (board[0][2] == ai_token && board[1][1] == ai_token && board[2][0] == ai_token)
        return true;
    return false;
}

bool is_tie() {
    // check if the game is tie
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int minimax(bool isMaximizer) {
    // minimax algorithm implementation
    if (player_wins())
        return -10;
    else if (ai_wins())
        return 10;
    else if (is_tie())
        return 0;
    
    int best_score = isMaximizer ? -1000 : 1000;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (is_empty(i, j)) {
                board[i][j] = isMaximizer ? ai_token : player_token;
                int score = minimax(!isMaximizer);
                board[i][j] = ' ';
                if (isMaximizer) {
                    if (score > best_score)
                        best_score = score;
                } else {
                    if (score < best_score)
                        best_score = score;
                }
            }
        }
    }
    return best_score;
}

void ai_move() {
    // AI moves using minimax algorithm
    int best_score = -1000;
    int best_row = -1, best_col = -1;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (is_empty(i, j)) {
                board[i][j] = ai_token;
                int score = minimax(false);
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    board[best_row][best_col] = ai_token;
}

void play_game() {
    // main game loop
    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose your token (X or O): ");
    scanf("%c", &player_token);
    ai_token = (player_token == 'X') ? 'O' : 'X';
    init_board();
    display_board();
    bool player_turn = true;
    while(true) {
        if (player_turn) {
            int row, col;
            printf("Enter row and column (1-3) to make your move: ");
            scanf("%d %d", &row, &col);
            row--, col--;
            if (is_empty(row, col)) {
                board[row][col] = player_token;
                player_turn = false;
            } else {
                printf("Invalid move! Try again.\n");
            }
        } else {
            printf("AI is making its move...\n");
            ai_move();
            player_turn = true;
        }
        display_board();
        if (player_wins()) {
            printf("Congratulations! You win!\n");
            break;
        } else if (ai_wins()) {
            printf("Sorry, you lose. Better luck next time!\n");
            break;
        } else if (is_tie()) {
            printf("It's a tie!\n");
            break;
        }
    }
}

int main() {
    play_game();
    return 0;
}