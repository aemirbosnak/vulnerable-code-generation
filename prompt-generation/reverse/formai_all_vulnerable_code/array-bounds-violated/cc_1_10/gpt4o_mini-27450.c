//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20
#define PADDLE_WIDTH 7
#define BRICK_ROWS 5
#define BRICK_COLUMNS 10

char brick[BRICK_ROWS][BRICK_COLUMNS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int paddle_x;
int ball_x, ball_y;
int ball_dx = 1, ball_dy = -1;

void init_game() {
    paddle_x = WIDTH / 2 - PADDLE_WIDTH / 2;
    ball_x = WIDTH / 2;
    ball_y = HEIGHT / 2;
}

void draw() {
    clear();
    
    // Draw bricks
    for (int r = 0; r < BRICK_ROWS; r++) {
        for (int c = 0; c < BRICK_COLUMNS; c++) {
            if (brick[r][c] == '#') {
                mvaddch(r + 1, c + 1, brick[r][c]);
            }
        }
    }

    // Draw paddle
    for (int i = 0; i < PADDLE_WIDTH; i++) {
        mvaddch(HEIGHT, paddle_x + i, '=');
    }

    // Draw ball
    mvaddch(ball_y, ball_x, 'O');
    
    refresh();
}

void update_ball() {
    ball_x += ball_dx;
    ball_y += ball_dy;

    // Bounce off walls
    if (ball_x <= 0 || ball_x >= WIDTH - 1) {
        ball_dx = -ball_dx;
    }

    // Bounce off top
    if (ball_y <= 0) {
        ball_dy = -ball_dy;
    }

    // Check for paddle collision
    if (ball_y == HEIGHT && ball_x >= paddle_x && ball_x < paddle_x + PADDLE_WIDTH) {
        ball_dy = -ball_dy;
    }

    // Check for brick collision
    if (ball_y > 0) {
        if (brick[ball_y - 1][ball_x - 1] == '#') {
            ball_dy = -ball_dy;
            brick[ball_y - 1][ball_x - 1] = ' ';  // Remove the brick
        }
    }

    // Check for game over
    if (ball_y >= HEIGHT) {
        mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "GAME OVER!");
        refresh();
        sleep(2);
        exit(0);
    }
}

void move_paddle(int direction) {
    if (direction == -1 && paddle_x > 0) {
        paddle_x--;
    } 
    else if (direction == 1 && paddle_x + PADDLE_WIDTH < WIDTH) {
        paddle_x++;
    }
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    init_game();

    while (1) {
        draw();
        update_ball();

        int ch = getch();
        if (ch == KEY_LEFT) {
            move_paddle(-1);
        } else if (ch == KEY_RIGHT) {
            move_paddle(1);
        } else if (ch == 'q') {
            break; // quit the game
        }

        usleep(100000); // Adjust speed
    }

    endwin();
    return 0;
}