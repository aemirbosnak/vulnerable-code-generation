//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

void printBricks(int bricks[5][10]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (bricks[i][j] == 0) {
                printf(" ");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

struct termios orig_termios;

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    srand(time(NULL));

    int ball_x = 5, ball_y = 5;
    int ball_vx = 1, ball_vy = -1;
    int paddle_x = 3, paddle_y = 9;
    int bricks[5][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    enableRawMode();

    while (1) {
        system("clear");

        printBricks(bricks);

        printf("\n\n");

        for (int i = 0; i < ball_x; i++) {
            printf("\n");
        }

        for (int i = 0; i < paddle_x; i++) {
            printf(" ");
        }

        printf("#");

        for (int i = paddle_x + 1; i < 10; i++) {
            printf(" ");
        }

        printf("\n\n");

        usleep(100000);

        int c = '\0';

        if (read(STDIN_FILENO, &c, 1) == -1) {
            break;
        }

        switch (c) {
            case 'a':
                if (paddle_x > 0) {
                    paddle_x--;
                }
                break;
            case 'd':
                if (paddle_x < 9) {
                    paddle_x++;
                }
                break;
            default:
                break;
        }

        ball_x += ball_vx;
        ball_y += ball_vy;

        if (ball_x == 0) {
            ball_vx = 1;
        }

        if (ball_x == 4) {
            if (ball_y >= paddle_x && ball_y <= paddle_x + 2) {
                ball_vy = -1;
            } else {
                ball_vy = 1;
            }
        }

        if (ball_y == 0) {
            ball_vy = 1;
        }

        if (ball_y == 9) {
            ball_vy = -1;
        }

        if (bricks[ball_x][ball_y] == 1) {
            bricks[ball_x][ball_y] = 0;
            ball_vy *= -1;
        }

        int bricks_remaining = 0;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                if (bricks[i][j] == 1) {
                    bricks_remaining = 1;
                }
            }
        }

        if (!bricks_remaining) {
            printf("You win!\n");
            disableRawMode();
            exit(0);
        }
    }

    disableRawMode();

    return 0;
}