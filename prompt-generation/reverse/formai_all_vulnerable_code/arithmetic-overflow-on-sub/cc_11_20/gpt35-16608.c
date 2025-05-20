//FormAI DATASET v1.0 Category: Checkers Game ; Style: sophisticated
#include <stdio.h>
#define ROWS 8
#define COLS 8

void initialize_board(char board[ROWS][COLS]) {
    // Initialize the board with checker pieces
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i%2 == 0 && j%2 == 0 && i < 3) {
                board[i][j] = 'B';
            } else if(i%2 == 1 && j%2 == 1 && i < 3) {
                board[i][j] = 'B';
            } else if(i%2 == 0 && j%2 == 0 && i > 4) {
                board[i][j] = 'W';
            } else if(i%2 == 1 && j%2 == 1 && i > 4) {
                board[i][j] = 'W';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    // Print the current state of the board
    printf("   0 1 2 3 4 5 6 7\n");
    for(int i=0; i<ROWS; i++) {
        printf("%d  ", i);
        for(int j=0; j<COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(char board[ROWS][COLS], int start_row, int start_col, int end_row, int end_col, char player) {
    // Check if the move is valid for the current player
    if(end_row < 0 || end_col < 0 || end_row > 7 || end_col > 7) {
        return 0;
    }
    if(board[end_row][end_col] != ' ') {
        return 0;
    }
    if(player == 'B') {
        if(start_row-end_row == 1 && start_col-end_col == 1 && board[end_row][end_col] == ' ') {
            return 1;
        } else if(start_row-end_row == 1 && start_col-end_col == -1 && board[end_row][end_col] == ' ') {
            return 1;
        } else if(start_row-end_row == 2 && start_col-end_col == 2 && board[start_row-1][start_col-1] == 'W' && board[end_row][end_col] == ' ') {
            return 1;
        } else if(start_row-end_row == 2 && start_col-end_col == -2 && board[start_row-1][start_col+1] == 'W' && board[end_row][end_col] == ' ') {
            return 1;
        } else {
            return 0;
        }
    } else if(player == 'W') {
        if(start_row-end_row == -1 && start_col-end_col == 1 && board[end_row][end_col] == ' ') {
            return 1;
        } else if(start_row-end_row == -1 && start_col-end_col == -1 && board[end_row][end_col] == ' ') {
            return 1;
        } else if(start_row-end_row == -2 && start_col-end_col == 2 && board[start_row+1][start_col-1] == 'B' && board[end_row][end_col] == ' ') {
            return 1;
        } else if(start_row-end_row == -2 && start_col-end_col == -2 && board[start_row+1][start_col+1] == 'B' && board[end_row][end_col] == ' ') {
            return 1;
        } else {
            return 0;
        }
    }
}

int move_piece(char board[ROWS][COLS], int start_row, int start_col, int end_row, int end_col, char player) {
    // Move the piece to the new position
    if(is_valid_move(board, start_row, start_col, end_row, end_col, player)) {
        board[end_row][end_col] = board[start_row][start_col];
        board[start_row][start_col] = ' ';
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char board[ROWS][COLS];
    initialize_board(board);
    print_board(board);

    int game_over = 0;
    char current_player = 'B';
    
    while(!game_over) {
        printf("Current player: %c\n", current_player);
        int start_row, start_col, end_row, end_col;
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &start_row, &start_col);
        printf("Enter the row and column of the position you want to move to: ");
        scanf("%d %d", &end_row, &end_col);

        int move_successful = move_piece(board, start_row, start_col, end_row, end_col, current_player);
        if(!move_successful) {
            printf("Invalid move. Try again.\n");
        } else {
            print_board(board);
            
            // Check if game over
            int no_black_pieces = 1;
            int no_white_pieces = 1;
            for(int i=0; i<ROWS; i++) {
                for(int j=0; j<COLS; j++) {
                    if(board[i][j] == 'B') {
                        no_black_pieces = 0;
                    } else if(board[i][j] == 'W') {
                        no_white_pieces = 0;
                    }
                }
            }
            if(no_black_pieces || no_white_pieces) {
                game_over = 1;
                printf("Game over. ");
                if(no_black_pieces) {
                    printf("White wins!\n");
                } else if(no_white_pieces) {
                    printf("Black wins!\n");
                }
            }
            
            // Switch players
            if(current_player == 'B') {
                current_player = 'W';
            } else if(current_player == 'W') {
                current_player = 'B';
            }
        }
    }
    
    return 0;
}