//Falcon2-11B DATASET v1.0 Category: Breakout Game Clone ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_board(int board[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0)
                printf("_ ");
            else if (board[i][j] == 1)
                printf("O ");
            else if (board[i][j] == 2)
                printf("X ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

void initialize_board(int board[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
}

void move_paddle(int board[][10], int n, int x, int y, int x_paddle, int y_paddle) {
    if (board[y_paddle][x_paddle] == 2) {
        board[y_paddle][x_paddle] = 0;
        board[y_paddle][x_paddle+1] = 2;
    }
    else if (board[y_paddle][x_paddle] == 1) {
        board[y_paddle][x_paddle] = 0;
        board[y_paddle][x_paddle-1] = 1;
    }
}

void play_game(int board[][10], int n, int x_paddle, int y_paddle) {
    int rand_x = rand() % (n-1);
    int rand_y = rand() % (n-1);
    move_paddle(board, n, rand_x, rand_y, x_paddle, y_paddle);
    draw_board(board, n);
    printf("Player 2 move: (x, y) = ");
    scanf("%d%d", &rand_x, &rand_y);
    move_paddle(board, n, rand_x, rand_y, x_paddle, y_paddle);
    draw_board(board, n);
}

int main() {
    int board[10][10] = {0};
    int n = 10;
    int x_paddle = 5;
    int y_paddle = 5;
    int x_paddle_2 = 0;
    int y_paddle_2 = 0;
    int x_ball = 0;
    int y_ball = 0;
    srand(time(0));

    printf("Welcome to Breakout 2.0!\n");
    printf("Player 1 move: (x, y) = ");
    scanf("%d%d", &x_paddle, &y_paddle);
    draw_board(board, n);
    printf("Player 2 move: (x, y) = ");
    scanf("%d%d", &x_paddle_2, &y_paddle_2);
    draw_board(board, n);
    while (1) {
        play_game(board, n, x_paddle, y_paddle);
        if (board[y_ball][x_ball] == 2)
            break;
        play_game(board, n, x_paddle_2, y_paddle_2);
        if (board[y_ball][x_ball] == 1)
            break;
        printf("Press any key to continue...");
        getchar();
    }

    printf("Game over!\n");
    return 0;
}