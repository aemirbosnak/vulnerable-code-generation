//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Coordinate;

int max(int a, int b) {
    return a > b? a : b;
}

int get_max_coord(int n, int m) {
    return max(n, m) + 1;
}

void print_board(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void free_board(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        free(board[i]);
    }
    free(board);
}

int play_game(int board[3][3], Coordinate player_coord) {
    int n = get_max_coord(board[0][0], board[1][1]);
    int m = get_max_coord(board[0][2], board[1][1]);

    if (player_coord.x > n || player_coord.y > m) {
        printf("Invalid position\n");
        return 0;
    }

    if (board[player_coord.x][player_coord.y]!= 0) {
        printf("Position already taken\n");
        return 0;
    }

    board[player_coord.x][player_coord.y] = player_coord.x + 1;
    return 1;
}

int check_win(int board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= 0) {
            printf("%c wins!\n", player);
            return 1;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= 0) {
            printf("%c wins!\n", player);
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= 0) {
        printf("%c wins!\n", player);
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= 0) {
        printf("%c wins!\n", player);
        return 1;
    }

    return 0;
}

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    Coordinate player_coord;
    int player_turn = 1;
    int game_over = 0;

    while (!game_over) {
        printf("Player %d's turn.\n", player_turn);
        scanf("%d %d", &player_coord.x, &player_coord.y);

        if (play_game(board, player_coord) == 0) {
            continue;
        }

        if (player_turn % 2 == 0) {
            printf("Computer's turn\n");
            Coordinate computer_coord = {0, 0};
            int computer_move = 0;

            do {
                computer_move = rand() % 9;
                computer_coord.x = computer_move / 3;
                computer_coord.y = computer_move % 3;
            } while (!play_game(board, computer_coord) && (computer_move == 6 || computer_move == 8));

            if (computer_move == 6 || computer_move == 8) {
                computer_move = 4;
            }

            if (computer_move == 4 || computer_move == 5 || computer_move == 6 || computer_move == 7 || computer_move == 8) {
                computer_coord.x = 2 - computer_coord.x;
                computer_coord.y = 2 - computer_coord.y;
            }

            board[computer_coord.x][computer_coord.y] = computer_move;
        }

        game_over = check_win(board, 'X');
        game_over |= check_win(board, 'O');

        if (game_over) {
            break;
        }

        printf("---------------\n");
        print_board(board);

        player_turn = 1 - player_turn;
    }

    printf("Game over\n");

    if (game_over) {
        if (check_win(board, 'X')) {
            printf("Player X wins!\n");
        } else {
            printf("Player O wins!\n");
        }
    }

    free_board(board);
    return 0;
}