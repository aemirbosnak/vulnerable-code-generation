//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 8
#define HEIGHT 8

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

char board[WIDTH][HEIGHT] = {
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
};

void draw_board() {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int player_x = 0;
    int player_y = 0;
    char direction = ' ';

    draw_board();

    while (direction != 'q') {
        printf("Enter direction (w, a, s, d, q): ");
        scanf(" %c", &direction);

        switch (direction) {
            case 'w':
                player_y--;
                break;
            case 'a':
                player_x--;
                break;
            case 's':
                player_y++;
                break;
            case 'd':
                player_x++;
                break;
            case 'q':
                printf("Thanks for playing!");
                break;
            default:
                printf("Invalid direction.");
                break;
        }

        if (board[player_y][player_x] == 'o') {
            printf("Game over!");
            break;
        }

        board[player_y][player_x] = 'o';
        draw_board();
    }

    return 0;
}