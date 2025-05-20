//FormAI DATASET v1.0 Category: Chess engine ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int positions;

struct Move {
    int from_x, from_y, to_x, to_y, value;
};

//Function to get the value of pieces
int get_value(char c) {
    switch (c) {
        case 'P': return 1;
        case 'N': return 3;
        case 'B': return 3;
        case 'R': return 5;
        case 'Q': return 9;
        case 'K': return 100;
        case 'p': return -1;
        case 'n': return -3;
        case 'b': return -3;
        case 'r': return -5;
        case 'q': return -9;
        case 'k': return -100;
    }
}

//Function to print the board
void print_board(char board[][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

//Function to get a random move for the computer
struct Move get_random_move(char board[][8], int player) {
    struct Move m;
    do {
        m.from_x = rand() % 8;
        m.from_y = rand() % 8;
        m.to_x = rand() % 8;
        m.to_y = rand() % 8;
        m.value = 0;
    } while (board[m.from_x][m.from_y] == ' ' || get_value(board[m.from_x][m.from_y]) * player < 0);
    return m;
}

//Function that returns the value of the position
int evaluate(char board[][8]) {
    int value = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            value += get_value(board[i][j]);
        }
    }
    return value;
}

//Function that gets the best move
struct Move get_best_move(char board[][8], int player, int depth, int alpha, int beta) {
    if (depth == 0) {
        struct Move m = {-1, -1, -1, -1, evaluate(board)};
        positions++;
        return m;
    }
    struct Move best_move = {-1, -1, -1, -1, -1000};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != ' ' && get_value(board[i][j]) * player > 0) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        char temp = board[k][l];
                        board[k][l] = board[i][j];
                        board[i][j] = ' ';
                        int value = -get_best_move(board, -player, depth - 1, -beta, -alpha).value;
                        board[i][j] = board[k][l];
                        board[k][l] = temp;
                        if (value > best_move.value) {
                            best_move.from_x = i;
                            best_move.from_y = j;
                            best_move.to_x = k;
                            best_move.to_y = l;
                            best_move.value = value;
                        }
                        alpha = alpha > value ? alpha : value;
                        if (alpha >= beta) {
                            return best_move;
                        }
                    }
                }
            }
        }
    }
    positions++;
    return best_move;
}

//Function that runs the game
void run_game() {
    char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    int player = 1;
    while (1) {
        if (player == 1) {
            printf("Player 1 (white) move:\n");
            struct Move m;
            scanf("%d%d%d%d", &m.from_x, &m.from_y, &m.to_x, &m.to_y);
            char temp = board[m.to_x][m.to_y];
            board[m.to_x][m.to_y] = board[m.from_x][m.from_y];
            board[m.from_x][m.from_y] = ' ';
            if (temp == 'k') {
                printf("Player 1 (white) wins!\n");
                break;
            }
        } else {
            printf("Computer (black) move:\n");
            struct Move m = get_best_move(board, -1, 3, -1000, 1000);
            char temp = board[m.to_x][m.to_y];
            board[m.to_x][m.to_y] = board[m.from_x][m.from_y];
            board[m.from_x][m.from_y] = ' ';
            if (temp == 'K') {
                printf("Computer (black) wins!\n");
                break;
            }
            printf("Computer (black) moved from (%d, %d) to (%d, %d)\n", m.from_x+1, m.from_y+1, m.to_x+1, m.to_y+1);
        }
        print_board(board);
        player = -player;
    }
}

//Main function
int main() {
    srand(time(NULL));
    run_game();
    return 0;
}