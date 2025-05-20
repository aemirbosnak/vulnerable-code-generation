//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

char board[8][8];
int player_turn;
int king_pos[2];

void initialize_board(){
    // fill board with '0's
    memset(board, 0, sizeof(board));

    // place white and black pieces
    board[0][0] = 'wP';
    board[0][1] = 'wR';
    board[0][2] = 'wN';
    board[0][3] = 'wB';
    board[0][4] = 'wQ';
    board[0][5] = 'wK';
    board[0][6] = 'wB';
    board[0][7] = 'wR';
    board[0][8] = 'wP';

    board[7][0] = 'bP';
    board[7][1] = 'bR';
    board[7][2] = 'bN';
    board[7][3] = 'bB';
    board[7][4] = 'bQ';
    board[7][5] = 'bK';
    board[7][6] = 'bB';
    board[7][7] = 'bR';
    board[7][8] = 'bP';

    board[1][0] = 'bK';
    board[6][0] = 'wK';
    board[1][1] = 'bQ';
    board[6][1] = 'wQ';
    board[1][2] = 'bN';
    board[6][2] = 'wN';
    board[1][3] = 'bB';
    board[6][3] = 'wB';
    board[1][4] = 'bR';
    board[6][4] = 'wR';
    board[1][5] = 'bP';
    board[6][5] = 'wP';

    board[2][0] = 'wP';
    board[5][0] = 'bP';
    board[2][1] = 'wR';
    board[5][1] = 'bR';
    board[2][2] = 'wN';
    board[5][2] = 'bN';
    board[2][3] = 'wB';
    board[5][3] = 'bB';
    board[2][4] = 'wQ';
    board[5][4] = 'bQ';
    board[2][5] = 'wK';
    board[5][5] = 'bK';
    board[2][6] = 'wB';
    board[5][6] = 'bB';
    board[2][7] = 'wR';
    board[5][7] = 'bR';
    board[2][8] = 'wP';
    board[5][8] = 'bP';

    // set player_turn to white
    player_turn = 1;

    // set king positions
    king_pos[0] = 1;
    king_pos[1] = 6;
}

void print_board(){
    printf("    a b c d e f g h\n");
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("    a b c d e f g h\n");
}

void make_move(int row, int col, int player){
    if (player == 1){
        board[row][col] = 'w';
    } else {
        board[row][col] = 'b';
    }
}

int is_valid_move(int row, int col, int player){
    int i, j;
    int row_change = row - king_pos[player - 1];
    int col_change = col - king_pos[player - 1];
    for (i = -1; i < 2; i++){
        for (j = -1; j < 2; j++){
            if (i!= 0 || j!= 0){
                int new_row = row + i;
                int new_col = col + j;
                if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8){
                    if (board[new_row][new_col] == 'K'){
                        return 0;
                    } else if (board[new_row][new_col]!= '0'){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int get_move_score(int row, int col, int player){
    int i, j;
    int row_change = row - king_pos[player - 1];
    int col_change = col - king_pos[player - 1];
    for (i = -1; i < 2; i++){
        for (j = -1; j < 2; j++){
            if (i!= 0 || j!= 0){
                int new_row = row + i;
                int new_col = col + j;
                if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8){
                    if (board[new_row][new_col] == 'K'){
                        return 1;
                    } else if (board[new_row][new_col]!= '0'){
                        return -1;
                    }
                }
            }
        }
    }
    return 0;
}

void make_best_move(){
    int i, j;
    int best_score = -999;
    int best_row = -1;
    int best_col = -1;

    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if (is_valid_move(i, j, 1)){
                int score = get_move_score(i, j, 1);
                if (score > best_score){
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }

    make_move(best_row, best_col, 1);
}

void make_best_move_computer(){
    int i, j;
    int best_score = -999;
    int best_row = -1;
    int best_col = -1;

    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if (is_valid_move(i, j, 2)){
                int score = get_move_score(i, j, 2);
                if (score > best_score){
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }

    make_move(best_row, best_col, 2);
}

int main(){
    initialize_board();
    print_board();

    while (1){
        if (player_turn == 1){
            printf("Player's Turn!\n");
            int move_row, move_col;
            printf("Enter row (1-8): ");
            scanf("%d", &move_row);
            printf("Enter column (1-8): ");
            scanf("%d", &move_col);
            make_move(move_row, move_col, 1);
            print_board();
            make_best_move();
            player_turn = 2;
        } else {
            printf("Computer's Turn!\n");
            make_best_move_computer();
            print_board();
            player_turn = 1;
        }
    }
    return 0;
}