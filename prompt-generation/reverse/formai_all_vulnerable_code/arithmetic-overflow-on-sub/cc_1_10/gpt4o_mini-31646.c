//GPT-4o-mini DATASET v1.0 Category: Pong Game with AI Opponent ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#define PADDLE_HEIGHT 4
#define PADDLE_WIDTH 1
#define BALL_SYMBOL 'O'

typedef struct {
    int x, y;
    int dx, dy;
} Ball;

typedef struct {
    int x, y;
} Paddle;

void init_game(Ball *ball, Paddle *player, Paddle *ai) {
    ball->x = COLS / 2;
    ball->y = LINES / 2;
    ball->dx = 1;
    ball->dy = 1;

    player->x = 2;
    player->y = LINES / 2 - PADDLE_HEIGHT / 2;

    ai->x = COLS - 3;
    ai->y = LINES / 2 - PADDLE_HEIGHT / 2;
}

void draw_ball(Ball *ball) {
    mvaddch(ball->y, ball->x, BALL_SYMBOL);
}

void draw_paddle(Paddle *paddle) {
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        mvaddch(paddle->y + i, paddle->x, '|');
    }
}

void move_ball(Ball *ball) {
    ball->x += ball->dx;
    ball->y += ball->dy;
}

void check_ball_collision(Ball *ball, Paddle *player, Paddle *ai) {
    if (ball->y <= 0 || ball->y >= LINES - 1) {
        ball->dy *= -1; // Bounce off top or bottom
    }

    if (ball->x == player->x + 1 && ball->y >= player->y && ball->y < player->y + PADDLE_HEIGHT) {
        ball->dx *= -1; // Bounce off player's paddle
    }

    if (ball->x == ai->x - 1 && ball->y >= ai->y && ball->y < ai->y + PADDLE_HEIGHT) {
        ball->dx *= -1; // Bounce off AI's paddle
    }
}

void move_ai(Ball *ball, Paddle *ai) {
    if (ball->y < ai->y) {
        ai->y--;
    } else if (ball->y >= ai->y + PADDLE_HEIGHT) {
        ai->y++;
    }
}

int main() {
    Ball ball;
    Paddle player, ai;

    initscr(); // Initialize ncurses
    cbreak(); // Disable line buffering
    noecho(); // Do not display typed characters
    keypad(stdscr, TRUE); // Enable function keys and arrow keys
    curs_set(0); // Hide cursor
    nodelay(stdscr, TRUE); // Do not block on getch()
    getmaxyx(stdscr, LINES, COLS);

    init_game(&ball, &player, &ai);

    while (1) {
        clear(); // Clear screen

        draw_ball(&ball);
        draw_paddle(&player);
        draw_paddle(&ai);

        move_ball(&ball);
        check_ball_collision(&ball, &player, &ai);
        move_ai(&ball, &ai);

        refresh(); // Update screen

        int ch = getch();
        if (ch == 'q') { // Quit the game
            break;
        }

        if (ch == KEY_UP && player.y > 0) {
            player.y--;
        } else if (ch == KEY_DOWN && player.y < LINES - PADDLE_HEIGHT) {
            player.y++;
        }

        usleep(50000); // Control game speed
    }

    endwin(); // End ncurses mode
    return 0;
}