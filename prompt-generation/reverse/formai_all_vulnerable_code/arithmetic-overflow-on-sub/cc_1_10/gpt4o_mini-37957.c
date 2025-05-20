//GPT-4o-mini DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Ken Thompson
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define PADDLE_HEIGHT 4
#define PADDLE_WIDTH 1
#define PADDLE_LEFT_X 1
#define PADDLE_RIGHT_X 78
#define BALL_SPEED 1

typedef struct {
    int x, y;
} Ball;

typedef struct {
    int y;
} Paddle;

void init_game(Paddle *left_paddle, Paddle *right_paddle, Ball *ball) {
    left_paddle->y = 10;
    right_paddle->y = 10;
    ball->x = 40;
    ball->y = 12;
}

void draw_paddle(int x, int y) {
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        mvaddch(y + i, x, '|');
    }
}

void draw_ball(Ball *ball) {
    mvaddch(ball->y, ball->x, 'O');
}

void erase_ball(Ball *ball) {
    mvaddch(ball->y, ball->x, ' ');
}

void move_ball(Ball *ball, int *ball_speed_x, int *ball_speed_y) {
    ball->x += *ball_speed_x;
    ball->y += *ball_speed_y;

    if (ball->y <= 0 || ball->y >= LINES - 1) {
        *ball_speed_y = -(*ball_speed_y);
    }
}

int check_collision(Ball *ball, Paddle *paddle) {
    if (ball->x == PADDLE_LEFT_X + PADDLE_WIDTH && ball->y >= paddle->y && ball->y < paddle->y + PADDLE_HEIGHT) {
        return 1; // Collision with left paddle
    }
    if (ball->x == PADDLE_RIGHT_X - 1 && ball->y >= paddle->y && ball->y < paddle->y + PADDLE_HEIGHT) {
        return 1; // Collision with right paddle
    }
    return 0;
}

void ai_move(Paddle *ai_paddle, Ball *ball) {
    if (ball->y < ai_paddle->y) {
        ai_paddle->y--;
    } else if (ball->y > ai_paddle->y + PADDLE_HEIGHT - 1) {
        ai_paddle->y++;
    }
}

void draw_boundary() {
    for (int i = 0; i < COLS; i++) {
        mvaddch(0, i, '-');
        mvaddch(LINES - 1, i, '-');
    }
}

int main() {
    Paddle left_paddle, right_paddle;
    Ball ball;
    int ball_speed_x = BALL_SPEED;
    int ball_speed_y = BALL_SPEED;

    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    cbreak();

    init_game(&left_paddle, &right_paddle, &ball);

    while (1) {
        clear();
        draw_boundary();
        draw_paddle(PADDLE_LEFT_X, left_paddle.y);
        draw_paddle(PADDLE_RIGHT_X, right_paddle.y);
        draw_ball(&ball);
        
        move_ball(&ball, &ball_speed_x, &ball_speed_y);
        ai_move(&right_paddle, &ball);

        erase_ball(&ball);

        if (check_collision(&ball, &left_paddle)) {
            ball_speed_x = BALL_SPEED; // Reflect ball
        }

        if (check_collision(&ball, &right_paddle)) {
            ball_speed_x = -BALL_SPEED; // Reflect ball
        }

        if (ball.x <= 0 || ball.x >= COLS - 1) {
            ball.x = 40;
            ball.y = 12;
            ball_speed_x = BALL_SPEED;
            ball_speed_y = BALL_SPEED;
        }

        int ch = getch();
        if (ch == 'q') break; // Exit on 'q'
        if (ch == KEY_UP && left_paddle.y > 0) left_paddle.y--;
        if (ch == KEY_DOWN && left_paddle.y < LINES - PADDLE_HEIGHT) left_paddle.y++;

        refresh();
        usleep(100000); // Control speed
    }

    endwin();
    return 0;
}