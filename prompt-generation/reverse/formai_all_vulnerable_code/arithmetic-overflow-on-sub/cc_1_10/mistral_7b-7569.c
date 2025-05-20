//MISTRAL-7B DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define BALL_RADIUS 3
#define GRAVITY 0.001
#define FPS 60

typedef struct {
    float x, y, vx, vy;
} ball_t;

void update_ball(ball_t *ball) {
    float dx, dy;

    dx = ball->vx;
    dy = ball->vy;

    ball->vx += dx * 0.99;
    ball->vy += dy * 0.99 + GRAVITY;

    if (ball->y + BALL_RADIUS >= HEIGHT || ball->y - BALL_RADIUS <= 0) {
        dy *= -1;
        ball->vy = dy;
    }

    if (ball->x + BALL_RADIUS >= WIDTH || ball->x - BALL_RADIUS <= 0) {
        dx *= -1;
        ball->vx = dx;
    }
}

int main() {
    clock_t last_frame = clock();
    ball_t ball = { 40, 10, 1, 1 };

    while (1) {
        update_ball(&ball);

        printf("\033[H\033[2J"); // Clear console
        printf("x: %5.2f y: %5.2f vx: %5.2f vy: %5.2f\n", ball.x, ball.y, ball.vx, ball.vy);

        usleep(1000000 / FPS);

        clock_t current_frame = clock();
        float dt = (float)(current_frame - last_frame) / CLOCKS_PER_SEC;

        ball.x += ball.vx * dt;
        ball.y += ball.vy * dt;

        last_frame = current_frame;
    }

    return 0;
}