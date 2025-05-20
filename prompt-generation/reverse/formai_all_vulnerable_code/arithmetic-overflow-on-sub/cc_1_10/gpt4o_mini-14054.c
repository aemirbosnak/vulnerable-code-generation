//GPT-4o-mini DATASET v1.0 Category: Pong Game with AI Opponent ; Style: calm
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define PADDLE_WIDTH 1
#define PADDLE_HEIGHT 5
#define BALL_SIZE 1
#define PADDLE_SPEED 1
#define DELAY 60000

typedef struct {
    int x, y;
} Paddle;

typedef struct {
    int x, y;
    int dirX, dirY;
} Ball;

void init_game(Paddle *player, Paddle *ai, Ball *ball) {
    player->x = 1;
    player->y = (LINES - PADDLE_HEIGHT) / 2;
    ai->x = COLS - 2;
    ai->y = (LINES - PADDLE_HEIGHT) / 2;
    ball->x = COLS / 2;
    ball->y = LINES / 2;
    ball->dirX = 1;
    ball->dirY = 1;
}

void draw_paddle(Paddle *paddle) {
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        mvprintw(paddle->y + i, paddle->x, "|");
    }
}

void draw_ball(Ball *ball) {
    mvprintw(ball->y, ball->x, "O");
}

void erase_paddle(Paddle *paddle) {
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        mvprintw(paddle->y + i, paddle->x, " ");
    }
}

void erase_ball(Ball *ball) {
    mvprintw(ball->y, ball->x, " ");
}

void move_ai(Paddle *ai, Ball *ball) {
    if (ball->y < ai->y) {
        ai->y -= PADDLE_SPEED;
    }
    if (ball->y > ai->y + PADDLE_HEIGHT - 1) {
        ai->y += PADDLE_SPEED;
    }
}

void update_ball(Ball *ball, Paddle *player, Paddle *ai) {
    ball->x += ball->dirX;
    ball->y += ball->dirY;

    if (ball->y <= 0 || ball->y >= LINES - 1) {
        ball->dirY *= -1; // Bounce off top or bottom
    }

    if (ball->x == player->x + PADDLE_WIDTH && ball->y >= player->y && ball->y < player->y + PADDLE_HEIGHT) {
        ball->dirX *= -1; // Bounce off player paddle
    }

    if (ball->x == ai->x - BALL_SIZE && ball->y >= ai->y && ball->y < ai->y + PADDLE_HEIGHT) {
        ball->dirX *= -1; // Bounce off AI paddle
    }

    if (ball->x < 0 || ball->x >= COLS) {
        // Reset ball position
        ball->x = COLS / 2;
        ball->y = LINES / 2;
        ball->dirX = (rand() % 2 == 0) ? 1 : -1;
    }
}

int main() {
    Paddle player, ai;
    Ball ball;

    initscr();            // Initialize ncurses
    noecho();             // Don't echo input
    curs_set(FALSE);      // Hide cursor
    keypad(stdscr, TRUE); // Enable arrow keys
    timeout(0);           // Non-blocking input

    init_game(&player, &ai, &ball);

    while (1) {
        // Draw everything
        erase_ball(&ball);
        erase_paddle(&player);
        erase_paddle(&ai);

        draw_paddle(&player);
        draw_paddle(&ai);
        draw_ball(&ball);

        // Update game state
        update_ball(&ball, &player, &ai);
        move_ai(&ai, &ball);

        // Player input
        int ch = getch();
        if (ch == 'q') break; // Quit game
        if (ch == KEY_UP && player.y > 0) player.y -= PADDLE_SPEED;
        if (ch == KEY_DOWN && player.y < LINES - PADDLE_HEIGHT) player.y += PADDLE_SPEED;

        refresh();          // Refresh the screen
        usleep(DELAY);      // Manage game speed
    }

    endwin();              // End ncurses mode
    return 0;
}