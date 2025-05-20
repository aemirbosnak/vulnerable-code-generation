//Falcon2-11B DATASET v1.0 Category: Breakout Game Clone ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_ball(int x, int y) {
    printf("%d %d\n", x, y);
}

void draw_paddle(int x, int y) {
    printf("paddle %d %d\n", x, y);
}

void draw_brick(int x, int y, int width, int height) {
    printf("%d %d %d %d\n", x, y, width, height);
}

int main() {
    srand(time(NULL));

    int bricks[10][10];
    int paddle_x = 50;
    int paddle_y = 400;
    int ball_x = 100;
    int ball_y = 200;
    int ball_width = 10;
    int ball_height = 10;
    int ball_speed_x = 1;
    int ball_speed_y = 1;
    int paddle_width = 10;
    int paddle_height = 40;
    int brick_width = 10;
    int brick_height = 10;
    int brick_x[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int brick_y[10] = {400, 410, 420, 430, 440, 450, 460, 470, 480, 490};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bricks[i][j] = rand() % 2;
        }
    }

    while (1) {
        draw_ball(ball_x, ball_y);
        draw_paddle(paddle_x, paddle_y);
        draw_brick(brick_x[0], brick_y[0], brick_width, brick_height);
        draw_brick(brick_x[1], brick_y[1], brick_width, brick_height);
        draw_brick(brick_x[2], brick_y[2], brick_width, brick_height);
        draw_brick(brick_x[3], brick_y[3], brick_width, brick_height);
        draw_brick(brick_x[4], brick_y[4], brick_width, brick_height);
        draw_brick(brick_x[5], brick_y[5], brick_width, brick_height);
        draw_brick(brick_x[6], brick_y[6], brick_width, brick_height);
        draw_brick(brick_x[7], brick_y[7], brick_width, brick_height);
        draw_brick(brick_x[8], brick_y[8], brick_width, brick_height);
        draw_brick(brick_x[9], brick_y[9], brick_width, brick_height);

        if (ball_y <= 0 || ball_y >= 480) {
            ball_speed_y = -ball_speed_y;
        }
        if (ball_x <= 0 || ball_x >= 540) {
            ball_speed_x = -ball_speed_x;
        }
        if (ball_y == paddle_y && ball_x <= paddle_x + paddle_width && ball_x >= paddle_x) {
            ball_speed_x = -ball_speed_x;
        }
        if (bricks[brick_y[0]][brick_x[0]] == 1 && ball_y == brick_y[0] + brick_height - 1) {
            bricks[brick_y[0]][brick_x[0]] = 0;
            ball_speed_y = -ball_speed_y;
        }
        if (bricks[brick_y[1]][brick_x[1]] == 1 && ball_y == brick_y[1] + brick_height - 1) {
            bricks[brick_y[1]][brick_x[1]] = 0;
            ball_speed_y = -ball_speed_y;
        }
        if (bricks[brick_y[2]][brick_x[2]] == 1 && ball_y == brick_y[2] + brick_height - 1) {
            bricks[brick_y[2]][brick_x[2]] = 0;
            ball_speed_y = -ball_speed_y;
        }
        if (bricks[brick_y[3]][brick_x[3]] == 1 && ball_y == brick_y[3] + brick_height - 1) {
            bricks[brick_y[3]][brick_x[3]] = 0;
            ball_speed_y = -ball_speed_y;
        }
        if (bricks[brick_y[4]][brick_x[4]] == 1 && ball_y == brick_y[4] + brick_height - 1) {
            bricks[brick_y[4]][brick_x[4]] = 0;
            ball_speed_y = -ball_speed_y;
        }
        if (bricks[brick_y[5]][brick_x[5]] == 1 && ball_y == brick_y[5] + brick_height - 1) {
            bricks[brick_y[5]][brick_x[5]] = 0;
            ball_speed_y = -ball_speed_y;
        }
        if (bricks[brick_y[6]][brick_x[6]] == 1 && ball_y == brick_y[6] + brick_height - 1) {
            bricks[brick_y[6]][brick_x[6]] = 0;
            ball_speed_y = -ball_speed_y;
        }
        if (bricks[brick_y[7]][brick_x[7]] == 1 && ball_y == brick_y[7] + brick_height - 1) {
            bricks[brick_y[7]][brick_x[7]] = 0;
            ball_speed_y = -ball_speed_y;
        }
        if (bricks[brick_y[8]][brick_x[8]] == 1 && ball_y == brick_y[8] + brick_height - 1) {
            bricks[brick_y[8]][brick_x[8]] = 0;
            ball_speed_y = -ball_speed_y;
        }
        if (bricks[brick_y[9]][brick_x[9]] == 1 && ball_y == brick_y[9] + brick_height - 1) {
            bricks[brick_y[9]][brick_x[9]] = 0;
            ball_speed_y = -ball_speed_y;
        }

        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        if (ball_y > 480) {
            printf("Congratulations! You won!\n");
            break;
        }
    }

    return 0;
}