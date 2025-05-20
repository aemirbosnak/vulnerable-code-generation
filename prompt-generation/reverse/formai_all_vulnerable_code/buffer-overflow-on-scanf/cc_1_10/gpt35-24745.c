//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>

bool is_board_full(char board[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // game not over yet
        }
    }
    return true; // board is full, game over
}

char check_game_status(char board[][3]) {
    // check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }
    // check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    // neither winning nor full board
    return ' ';
}

int best_score(char board[][3], char player_symbol, bool is_max) {
    // check game status
    char game_state = check_game_status(board);
    if (game_state != ' ') {
        if (game_state == player_symbol)
            return 1; // win
        else
            return -1; // lose
    }
    // check if board is full
    if (is_board_full(board))
        return 0; // tie
    // simulate all possible moves and pick the best one
    int best = is_max ? -2 : 2; // initialize best to a value outside the range of game scores
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                if (is_max) {
                    board[i][j] = player_symbol;
                    int score = best_score(board, player_symbol, false); // opponent's turn
                    board[i][j] = ' '; // undo move
                    if (score > best)
                        best = score;
                } else {
                    char opponent_symbol = (player_symbol == 'X') ? 'O' : 'X';
                    board[i][j] = opponent_symbol;
                    int score = best_score(board, player_symbol, true); // player's turn
                    board[i][j] = ' '; // undo move
                    if (score < best)
                        best = score;
                }
            }
        }
    }
    return best;
}

void get_best_move(char board[][3], char player_symbol, int* row, int* col) {
    int best = -2; // initialize best to a value outside the range of game scores
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = player_symbol;
                int score = best_score(board, player_symbol, false); // opponent's turn
                board[i][j] = ' '; // undo move
                if (score > best) {
                    best = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}

void print_board(char board[][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player_symbol, ai_symbol;
    printf("Choose symbol ('X' or 'O'): ");
    scanf("%c", &player_symbol);
    ai_symbol = (player_symbol == 'X') ? 'O' : 'X';
    while (true) {
        print_board(board);
        // player's turn
        printf("Player's turn (row col): ");
        int row, col;
        scanf("%d%d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move!\n");
            continue;
        }
        board[row][col] = player_symbol;
        // check game status
        char game_state = check_game_status(board);
        if (game_state != ' ') {
            print_board(board);
            if (game_state == player_symbol) {
                printf("Congratulations! You won!\n");
            } else {
                printf("Game over! AI won!\n");
            }
            break;
        }
        // AI's turn
        int ai_row, ai_col;
        get_best_move(board, ai_symbol, &ai_row, &ai_col);
        board[ai_row][ai_col] = ai_symbol;
        // check game status
        game_state = check_game_status(board);
        if (game_state != ' ') {
            print_board(board);
            if (game_state == player_symbol) {
                printf("Congratulations! You won!\n");
            } else {
                printf("Game over! AI won!\n");
            }
            break;
        }
    }
    return 0;
}