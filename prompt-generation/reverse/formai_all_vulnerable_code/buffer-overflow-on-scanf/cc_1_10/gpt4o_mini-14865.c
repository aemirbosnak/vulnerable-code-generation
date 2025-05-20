//GPT-4o-mini DATASET v1.0 Category: Pong Game with AI Opponent ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define WIDTH 80
#define HEIGHT 24
#define PADDLE_HEIGHT 4
#define BALL_SPEED 1

typedef struct {
    int x, y;
    int direction_x, direction_y;
} Ball;

typedef struct {
    int x, y;
} Paddle;

void initialize_game(WINDOW *win, Paddle *player, Paddle *ai, Ball *ball) {
    player->x = 1;
    player->y = (HEIGHT / 2) - (PADDLE_HEIGHT / 2);
    ai->x = WIDTH - 2;
    ai->y = (HEIGHT / 2) - (PADDLE_HEIGHT / 2);
    ball->x = WIDTH / 2;
    ball->y = HEIGHT / 2;
    ball->direction_x = BALL_SPEED;
    ball->direction_y = BALL_SPEED;
    
    box(win, 0, 0);
}

void draw_ball(WINDOW *win, Ball *ball) {
    mvwaddch(win, ball->y, ball->x, 'O');
}

void draw_paddle(WINDOW *win, Paddle *paddle) {
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        mvwaddch(win, paddle->y + i, paddle->x, '|');
    }
}

void clear_paddle(WINDOW *win, Paddle *paddle) {
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        mvwaddch(win, paddle->y + i, paddle->x, ' ');
    }
}

void move_ball(Ball *ball, Paddle *player, Paddle *ai) {
    ball->x += ball->direction_x;
    ball->y += ball->direction_y;

    // Collision with top and bottom walls
    if (ball->y <= 1 || ball->y >= HEIGHT - 2) {
        ball->direction_y *= -1;
    }

    // Collision with paddles
    if ((ball->x == player->x + 1 && ball->y >= player->y && ball->y < player->y + PADDLE_HEIGHT) ||
        (ball->x == ai->x - 1 && ball->y >= ai->y && ball->y < ai->y + PADDLE_HEIGHT)) {
        ball->direction_x *= -1;
    }

    // Reset ball if it goes past paddles
    if (ball->x <= 0 || ball->x >= WIDTH - 1) {
        ball->x = WIDTH / 2;
        ball->y = HEIGHT / 2;
        ball->direction_x *= -1;
    }
}

void move_ai_paddle(Ball *ball, Paddle *ai) {
    // Simple AI to follow the ball's Y position
    if (ball->y < ai->y) {
        ai->y--;
    } else if (ball->y >= ai->y + PADDLE_HEIGHT) {
        ai->y++;
    }
}

void configure_game(int *paddle_height, int *ball_speed) {
    printf("Configure your game:\n");
    printf("Enter paddle height (1-6): ");
    scanf("%d", paddle_height);
    printf("Enter ball speed (1-5): ");
    scanf("%d", ball_speed);
}

int main() {
    Paddle player, ai;
    Ball ball;
    WINDOW *win;
    
    int paddle_height = PADDLE_HEIGHT;
    int ball_speed = BALL_SPEED;

    configure_game(&paddle_height, &ball_speed);
    if (paddle_height < 1 || paddle_height > 6) paddle_height = PADDLE_HEIGHT;
    if (ball_speed < 1 || ball_speed > 5) ball_speed = BALL_SPEED;

    ball.direction_x = ball_speed;
    ball.direction_y = ball_speed;

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    win = newwin(HEIGHT, WIDTH, 0, 0);
    nodelay(win, TRUE);
    keypad(win, TRUE);

    initialize_game(win, &player, &ai, &ball);
    
    while (1) {
        clear_paddle(win, &player);
        clear_paddle(win, &ai);
        
        draw_ball(win, &ball);
        draw_paddle(win, &player);
        draw_paddle(win, &ai);
        
        wrefresh(win);
        usleep(100000);
        
        int ch = wgetch(win);
        if (ch == 'q') break;
        if (ch == 'w' && player.y > 1) player.y--;
        if (ch == 's' && player.y < HEIGHT - paddle_height - 1) player.y++;
        
        move_ball(&ball, &player, &ai);
        move_ai_paddle(&ball, &ai);
    }

    endwin();
    return 0;
}