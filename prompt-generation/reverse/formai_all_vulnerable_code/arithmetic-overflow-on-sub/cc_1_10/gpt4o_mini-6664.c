//GPT-4o-mini DATASET v1.0 Category: Pong Game with AI Opponent ; Style: synchronous
#include <ncurses.h>
#include <unistd.h>

#define PADDLE_WIDTH 1
#define PADDLE_HEIGHT 4
#define BALL_SYMBOL 'O'

typedef struct {
    int x, y;
} Ball;

typedef struct {
    int x, y;
    int score;
} Paddle;

void init();
void draw_borders();
void draw_paddle(Paddle *paddle);
void draw_ball(Ball *ball);
void update_ball(Ball *ball, Paddle *player, Paddle *ai);
void move_ai(Paddle *ai, Ball *ball);
void game_over(Paddle *player, Paddle *ai);

int main() {
    init();

    Paddle player = {1, LINES / 2 - PADDLE_HEIGHT / 2, 0};
    Paddle ai = {COLS - 2, LINES / 2 - PADDLE_HEIGHT / 2, 0};
    Ball ball = {COLS / 2, LINES / 2};
    int ball_dir_x = 1, ball_dir_y = 1;

    while (1) {
        clear();
        draw_borders();
        draw_paddle(&player);
        draw_paddle(&ai);
        draw_ball(&ball);
        refresh();

        // AI Moves
        move_ai(&ai, &ball);
        
        // Update Ball
        ball.x += ball_dir_x;
        ball.y += ball_dir_y;

        // Check ball boundaries and collisions
        if (ball.y <= 0 || ball.y >= LINES - 1) {
            ball_dir_y *= -1;
        }
        if (ball.x <= player.x + PADDLE_WIDTH && ball.y >= player.y && ball.y < player.y + PADDLE_HEIGHT) {
            ball_dir_x *= -1;
        }
        if (ball.x >= ai.x - 1 && ball.y >= ai.y && ball.y < ai.y + PADDLE_HEIGHT) {
            ball_dir_x *= -1;
        }
        if (ball.x < 0 || ball.x >= COLS) {
            // Scoring
            if (ball.x < 0) {
                ai.score++;
            } else {
                player.score++;
            }
            ball.x = COLS / 2;
            ball.y = LINES / 2;
            ball_dir_x = ball_dir_x > 0 ? 1 : -1;
            ball_dir_y = ball_dir_y > 0 ? 1 : -1;

            // Check the game over condition
            if (player.score >= 5 || ai.score >= 5) {
                game_over(&player, &ai);
                break;
            }
        }

        // Player controls
        int ch = getch();
        if (ch == 'q') {
            break; // Exit game
        }
        if (ch == 'w' && player.y > 0) {
            player.y--;
        }
        if (ch == 's' && player.y < LINES - PADDLE_HEIGHT) {
            player.y++;
        }

        usleep(50000); // Control game speed
    }

    endwin();
    return 0;
}

void init() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

void draw_borders() {
    for (int x = 0; x < COLS; x++) {
        mvaddch(0, x, '*');
        mvaddch(LINES - 1, x, '*');
    }
}

void draw_paddle(Paddle *paddle) {
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        mvaddch(paddle->y + i, paddle->x, '|');
    }
}

void draw_ball(Ball *ball) {
    mvaddch(ball->y, ball->x, BALL_SYMBOL);
}

void move_ai(Paddle *ai, Ball *ball) {
    ai->y = ball->y - PADDLE_HEIGHT / 2;
    if (ai->y < 1) ai->y = 1;
    if (ai->y > LINES - PADDLE_HEIGHT - 1) ai->y = LINES - PADDLE_HEIGHT - 1;
}

void game_over(Paddle *player, Paddle *ai) {
    clear();
    mvprintw(LINES / 2, COLS / 2 - 5, "Game Over");
    mvprintw(LINES / 2 + 1, COLS / 2 - 10, "Player Score: %d", player->score);
    mvprintw(LINES / 2 + 2, COLS / 2 - 10, "AI Score: %d", ai->score);
    refresh();
    usleep(2000000);
}