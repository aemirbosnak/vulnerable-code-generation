//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: beginner-friendly
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define BRICK_HEIGHT 1
#define BRICK_WIDTH 5
#define PADDLE_WIDTH 7
#define PADDLE_HEIGHT 1
#define BALL_SIZE 1

typedef struct {
    int x, y;
    int dx, dy;
} Ball;

typedef struct {
    int x, y;
} Paddle;

typedef struct {
    int x, y;
    int destroyed;
} Brick;

void init_game(Brick bricks[], int *brick_count) {
    *brick_count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            bricks[*brick_count].x = 1 + j * (BRICK_WIDTH + 1);
            bricks[*brick_count].y = 1 + i * (BRICK_HEIGHT + 1);
            bricks[*brick_count].destroyed = 0;
            (*brick_count)++;
        }
    }
}

void draw_bricks(Brick bricks[], int brick_count) {
    for (int i = 0; i < brick_count; i++) {
        if (!bricks[i].destroyed) {
            mvprintw(bricks[i].y, bricks[i].x, "#####");
        }
    }
}

void draw_paddle(Paddle paddle) {
    mvprintw(paddle.y, paddle.x, "#######");
}

void draw_ball(Ball ball) {
    mvprintw(ball.y, ball.x, "O");
}

void update_ball(Ball *ball, Paddle paddle, Brick bricks[], int brick_count) {
    ball->x += ball->dx;
    ball->y += ball->dy;

    if (ball->x <= 0 || ball->x >= COLS - BALL_SIZE) {
        ball->dx *= -1; // Bounce off side walls
    }

    if (ball->y <= 0) {
        ball->dy *= -1; // Bounce off top
    }

    if (ball->y >= LINES - 1) {
        ball->y = LINES - 2; // Reset position if it hits the bottom
        ball->dx = 0;        // Stop the ball
        ball->dy = 0;        // Stop the ball
    }

    // Check collision with paddle
    if (ball->y == paddle.y - 1 && ball->x >= paddle.x && ball->x <= paddle.x + PADDLE_WIDTH) {
        ball->dy *= -1; // Bounce off paddle
    }

    // Check collision with bricks
    for (int i = 0; i < brick_count; i++) {
        if (!bricks[i].destroyed && ball->y == bricks[i].y + BRICK_HEIGHT) {
            if (ball->x >= bricks[i].x && ball->x <= bricks[i].x + BRICK_WIDTH) {
                ball->dy *= -1; // Bounce off brick
                bricks[i].destroyed = 1; // Destroy the brick
            }
        }
    }
}

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    srand(time(NULL));

    Paddle paddle = {COLS / 2 - PADDLE_WIDTH / 2, LINES - 2};
    Ball ball = {COLS / 2, LINES - 3, 1, -1};
    Brick bricks[50];
    int brick_count;

    init_game(bricks, &brick_count);

    while (1) {
        clear();
        draw_bricks(bricks, brick_count);
        draw_paddle(paddle);
        draw_ball(ball);

        // Move paddle
        int ch = getch();
        if (ch == KEY_LEFT && paddle.x > 0) paddle.x--;
        if (ch == KEY_RIGHT && paddle.x < COLS - PADDLE_WIDTH) paddle.x++;

        // Update ball
        update_ball(&ball, paddle, bricks, brick_count);

        refresh();
        usleep(50000); // Control the speed of the game

        // End the game if all bricks are destroyed
        int all_destroyed = 1;
        for (int i = 0; i < brick_count; i++) {
            if (!bricks[i].destroyed) {
                all_destroyed = 0;
                break;
            }
        }
        if (all_destroyed) {
            break;
        }
    }

    endwin(); // End ncurses mode
    return 0;
}