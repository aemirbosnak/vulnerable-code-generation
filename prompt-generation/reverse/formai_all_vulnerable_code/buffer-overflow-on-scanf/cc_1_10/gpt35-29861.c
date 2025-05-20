//FormAI DATASET v1.0 Category: Chess engine ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int board[8][8] = {{-1,-2,-3,-4,-5,-3,-2,-1},
                    {-6,-6,-6,-6,-6,-6,-6,-6},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {6,6,6,6,6,6,6,6},
                    {1,2,3,4,5,3,2,1}}; 

int current_turn = 0;   // 0 for white, 1 for black
int game_running = 1;
char player_names[2][50];

void print_board() {
    printf("\n         CHESS BOARD\n\n");
    printf("      A  B  C  D  E  F  G  H\n");
    printf("      ____________________\n\n");
    for(int i = 0; i < 8; i++) {
        printf("%d   |", i + 1);
        for(int j = 0; j < 8; j++) {
            switch(board[i][j]) {
                case 1:
                    printf(" wP|");
                    break;
                case 2:
                    printf(" wN|");
                    break;
                case 3:
                    printf(" wB|");
                    break;
                case 4:
                    printf(" wR|");
                    break;
                case 5:
                    printf(" wQ|");
                    break;
                case 6:
                    printf(" wK|");
                    break;
                case -1:
                    printf(" bP|");
                    break;
                case -2:
                    printf(" bN|");
                    break;
                case -3:
                    printf(" bB|");
                    break;
                case -4:
                    printf(" bR|");
                    break;
                case -5:
                    printf(" bQ|");
                    break;
                case -6:
                    printf(" bK|");
                    break;
                default:
                    printf("   |");
                    break;
            }
        }
        printf("   %d", i + 1);
        printf("\n\n");
    }
    printf("      ---------------------\n");
    printf("      A  B  C  D  E  F  G  H\n\n");
}

int check_move(char move[5], int player) {
    int is_valid = 0;
    int x1, y1, x2, y2;
    x1 = move[0] - 'a';
    y1 = move[1] - '1';
    x2 = move[2] - 'a';
    y2 = move[3] - '1';

    if(board[y1][x1] == 0 || ((board[y1][x1] > 0) != player)) {
        is_valid = 0;
    } else {
        switch(board[y1][x1]) {
            case 1:
                if(player == 0) {
                    if(y2 == y1 - 1 && x2 == x1 && board[y2][x2] == 0) {
                        is_valid = 1;
                    } else if(y2 == y1 - 2 && x2 == x1 && y1 == 6 && board[y2][x2] == 0 && board[y1 - 1][x1] == 0) {
                        is_valid = 1;
                    } else if(y2 == y1 - 1 && abs(x2 - x1) == 1 && board[y2][x2] < 0) {
                        is_valid = 1;
                    }
                } else {
                    if(y2 == y1 + 1 && x2 == x1 && board[y2][x2] == 0) {
                        is_valid = 1;
                    } else if(y2 == y1 + 2 && x2 == x1 && y1 == 1 && board[y2][x2] == 0 && board[y1 + 1][x1] == 0) {
                        is_valid = 1;
                    } else if(y2 == y1 + 1 && abs(x2 - x1) == 1 && board[y2][x2] > 0) {
                        is_valid = 1;
                    }
                }
                break;
                // other cases for each piece here
            default:
                is_valid = 0;
                break;
        }
    }
    return is_valid;
}

void move_piece(char move[5], int player) {
    int x1, y1, x2, y2;
    x1 = move[0] - 'a';
    y1 = move[1] - '1';
    x2 = move[2] - 'a';
    y2 = move[3] - '1';

    board[y2][x2] = board[y1][x1];
    board[y1][x1] = 0;
}

int check_win() {
    // check if white is in checkmate or black is in checkmate, return 1 if true, 0 if false
    return 0;
}

void play_game() {
    printf("Enter player 1 name: ");
    scanf("%s", player_names[0]);
    printf("Enter player 2 name: ");
    scanf("%s", player_names[1]);

    while(game_running) {
        system("@cls||clear");
        print_board();
        printf("%s's turn (enter move or 'q' to quit): ", player_names[current_turn]);
        char move[5];
        scanf("%s", move);
        if(strcmp(move, "q") == 0) {
            game_running = 0;
            break;
        }
        if(check_move(move, current_turn)) {
            move_piece(move, current_turn);
            current_turn = (current_turn + 1) % 2;
            if(check_win()) {
                game_running = 0;
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    printf("\n\nGame Over!\n");

}

int main() {
    play_game();
    return 0;
}