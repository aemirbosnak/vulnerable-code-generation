//Falcon2-11B DATASET v1.0 Category: Breakout Game Clone ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int width, height, paddle_x, paddle_y, ball_x, ball_y;
    int bricks_x[100], bricks_y[100], bricks_color[100], bricks_score[100];
    int score = 0;

    printf("Welcome to Breakout!\n");
    printf("Width: ");
    scanf("%d", &width);
    printf("Height: ");
    scanf("%d", &height);
    printf("Paddle width: ");
    scanf("%d", &paddle_x);
    printf("Paddle height: ");
    scanf("%d", &paddle_y);
    printf("Ball width: ");
    scanf("%d", &ball_x);
    printf("Ball height: ");
    scanf("%d", &ball_y);

    int bricks_num = 0;
    printf("Brick color: ");
    scanf("%d", &bricks_color[bricks_num]);
    while (bricks_num < 100) {
        printf("Brick color: ");
        scanf("%d", &bricks_color[bricks_num]);
        bricks_num++;
    }

    int bricks_score_num = 0;
    printf("Brick score: ");
    scanf("%d", &bricks_score[bricks_score_num]);
    while (bricks_score_num < 100) {
        printf("Brick score: ");
        scanf("%d", &bricks_score[bricks_score_num]);
        bricks_score_num++;
    }

    int ball_x_dir = 1, ball_y_dir = 0;
    int paddle_x_dir = 0, paddle_y_dir = 1;
    int brick_x_dir = 0, brick_y_dir = 1;

    int ball_x_start = (width / 2) - (ball_x / 2);
    int ball_y_start = (height / 2) - (ball_y / 2);
    int paddle_x_start = (width / 2) - (paddle_x / 2);
    int paddle_y_start = (height / 2) - (paddle_y / 2);
    int brick_x_start = (width / 2) - (width / 100);
    int brick_y_start = (height / 2) - (height / 100);

    int ball_x_end = (width / 2) - (ball_x / 2);
    int ball_y_end = (height / 2) - (ball_y / 2);
    int paddle_x_end = (width / 2) - (paddle_x / 2);
    int paddle_y_end = (height / 2) - (paddle_y / 2);
    int brick_x_end = (width / 2) - (width / 100);
    int brick_y_end = (height / 2) - (height / 100);

    printf("Ball x start: %d\n", ball_x_start);
    printf("Ball y start: %d\n", ball_y_start);
    printf("Paddle x start: %d\n", paddle_x_start);
    printf("Paddle y start: %d\n", paddle_y_start);
    printf("Brick x start: %d\n", brick_x_start);
    printf("Brick y start: %d\n", brick_y_start);

    printf("Ball x end: %d\n", ball_x_end);
    printf("Ball y end: %d\n", ball_y_end);
    printf("Paddle x end: %d\n", paddle_x_end);
    printf("Paddle y end: %d\n", paddle_y_end);
    printf("Brick x end: %d\n", brick_x_end);
    printf("Brick y end: %d\n", brick_y_end);

    while (1) {
        printf("Brick color: ");
        scanf("%d", &bricks_color[bricks_num]);
        while (bricks_num < 100) {
            printf("Brick color: ");
            scanf("%d", &bricks_color[bricks_num]);
            bricks_num++;
        }

        printf("Brick score: ");
        scanf("%d", &bricks_score[bricks_score_num]);
        while (bricks_score_num < 100) {
            printf("Brick score: ");
            scanf("%d", &bricks_score[bricks_score_num]);
            bricks_score_num++;
        }

        printf("Ball x start: %d\n", ball_x_start);
        printf("Ball y start: %d\n", ball_y_start);
        printf("Paddle x start: %d\n", paddle_x_start);
        printf("Paddle y start: %d\n", paddle_y_start);
        printf("Brick x start: %d\n", brick_x_start);
        printf("Brick y start: %d\n", brick_y_start);

        printf("Ball x end: %d\n", ball_x_end);
        printf("Ball y end: %d\n", ball_y_end);
        printf("Paddle x end: %d\n", paddle_x_end);
        printf("Paddle y end: %d\n", paddle_y_end);
        printf("Brick x end: %d\n", brick_x_end);
        printf("Brick y end: %d\n", brick_y_end);

        break;
    }

    return 0;
}