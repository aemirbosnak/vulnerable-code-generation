//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define PADDLE_WIDTH 7
#define BRICK_ROWS 5
#define BRICK_COLS 8
#define BALL_SPEED 30000

typedef struct {
    int x, y;
} Paddle;

typedef struct {
    int x, y;
    int dx, dy;
} Ball;

void initialize_bricks(int bricks[BRICK_ROWS][BRICK_COLS]) {
    for (int i = 0; i < BRICK_ROWS; i++)
        for (int j = 0; j < BRICK_COLS; j++)
            bricks[i][j] = 1;  // brick exists
}

void draw_bricks(int bricks[BRICK_ROWS][BRICK_COLS]) {
    for (int i = 0; i < BRICK_ROWS; i++)
        for (int j = 0; j < BRICK_COLS; j++)
            if (bricks[i][j])
                mvprintw(i + 1, j * 5, "#####");
}

void draw_paddle(Paddle paddle) {
    mvprintw(HEIGHT - 1, paddle.x, "*******");
}

void draw_ball(Ball ball) {
    mvprintw(ball.y, ball.x, "o");
}

int main() {
    Paddle paddle = {WIDTH / 2 - PADDLE_WIDTH / 2, HEIGHT - 1};
    Ball ball = {WIDTH / 2, HEIGHT / 2, 1, 1};
    int bricks[BRICK_ROWS][BRICK_COLS];
    initialize_bricks(bricks);
    int score = 0;

    initscr();
    noecho();
    curs_set(FALSE);
    timeout(0);
    keypad(stdscr, TRUE);
    srand(time(NULL));

    while (1) {
        clear();
        draw_bricks(bricks);
        draw_paddle(paddle);
        draw_ball(ball);

        int ch = getch();
        if (ch == KEY_LEFT && paddle.x > 0)
            paddle.x--;
        else if (ch == KEY_RIGHT && paddle.x < WIDTH - PADDLE_WIDTH)
            paddle.x++;

        // Move ball
        ball.x += ball.dx;
        ball.y += ball.dy;

        // Ball collision with walls
        if (ball.x <= 0 || ball.x >= WIDTH - 1)
            ball.dx *= -1;
        if (ball.y <= 0)
            ball.dy *= -1;

        // Ball collision with paddle
        if (ball.y == HEIGHT - 1 && ball.x >= paddle.x && ball.x < paddle.x + PADDLE_WIDTH)
            ball.dy *= -1;

        // Ball collision with bricks
        if (ball.y > 0) {
            if (bricks[ball.y - 1][ball.x / 5]) {
                bricks[ball.y - 1][ball.x / 5] = 0; // break the brick
                ball.dy *= -1;
                score++;
            }
        }

        // Check if the ball is out of bounds
        if (ball.y >= HEIGHT) {
            mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "Game Over!");
            mvprintw(HEIGHT / 2 + 1, WIDTH / 2 - 5, "Score: %d", score);
            refresh();
            sleep(2);
            break;
        }

        refresh();
        usleep(BALL_SPEED);
    }

    endwin();
    return 0;
}