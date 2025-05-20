//GPT-4o-mini DATASET v1.0 Category: Pong Game with AI Opponent ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#define PADDLE_HEIGHT 4
#define PADDLE_WIDTH 1
#define PADDLE_OFFSET 2
#define BALL_SYMBOL 'O'
#define PLAYER_SYMBOL '|'
#define AI_SYMBOL '|'

typedef struct {
    int x, y;
    int dy;
} Paddle;

typedef struct {
    int x, y;
    int dx, dy;
} Ball;

void init_game(Paddle *player, Paddle *ai, Ball *ball, int width, int height) {
    player->x = PADDLE_OFFSET;
    player->y = height / 2 - PADDLE_HEIGHT / 2;
    player->dy = 1;

    ai->x = width - PADDLE_OFFSET - PADDLE_WIDTH;
    ai->y = height / 2 - PADDLE_HEIGHT / 2;
    ai->dy = 1;

    ball->x = width / 2;
    ball->y = height / 2;
    ball->dx = 1;
    ball->dy = 1;
}

void render(Paddle *player, Paddle *ai, Ball *ball, int height, int width) {
    clear();
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        mvaddch(player->y + i, player->x, PLAYER_SYMBOL);
        mvaddch(ai->y + i, ai->x, AI_SYMBOL);
    }
    mvaddch(ball->y, ball->x, BALL_SYMBOL);
    refresh();
}

void update_ball(Ball *ball, Paddle player, Paddle ai) {
    ball->x += ball->dx;
    ball->y += ball->dy;

    // Bounce off top and bottom walls
    if (ball->y <= 0 || ball->y >= LINES - 1) {
        ball->dy *= -1;
    }

    // Bounce off paddles
    if (ball->x == player.x + PADDLE_WIDTH && ball->y >= player.y && ball->y < player.y + PADDLE_HEIGHT) {
        ball->dx *= -1;
    } else if (ball->x == ai.x && ball->y >= ai.y && ball->y < ai.y + PADDLE_HEIGHT) {
        ball->dx *= -1;
    }

    // Reset ball if it goes out of bounds
    if (ball->x <= 0 || ball->x >= COLS - 1) {
        ball->x = COLS / 2;
        ball->y = LINES / 2;
        ball->dx = (ball->dx < 0) ? 1 : -1;
        ball->dy = (rand() % 2 == 0) ? 1 : -1;
    }
}

void update_ai(Ball *ball, Paddle *ai) {
    if (ball->y < ai->y) {
        ai->y -= ai->dy;
    } else if (ball->y >= ai->y + PADDLE_HEIGHT) {
        ai->y += ai->dy;
    }
}

void move_player(Paddle *player, int input) {
    switch (input) {
        case 'w':
            if (player->y > 0) player->y -= player->dy;
            break;
        case 's':
            if (player->y < LINES - PADDLE_HEIGHT) player->y += player->dy;
            break;
    }
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);

    Paddle player, ai;
    Ball ball;
    init_game(&player, &ai, &ball, COLS, LINES);

    int input;
    while (1) {
        input = getch();
        move_player(&player, input);
        update_ball(&ball, player, ai);
        update_ai(&ball, &ai);
        render(&player, &ai, &ball, LINES, COLS);
        usleep(10000);  // Control game speed
    }

    endwin();
    return 0;
}