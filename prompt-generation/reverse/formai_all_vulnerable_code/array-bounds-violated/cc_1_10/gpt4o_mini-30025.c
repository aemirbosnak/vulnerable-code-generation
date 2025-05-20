//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 40
#define HEIGHT 20
#define PADDLE_WIDTH 5
#define BRICK_ROWS 5
#define BRICK_COLUMNS 8
#define MAX_BRICKS (BRICK_ROWS * BRICK_COLUMNS)
#define EMPTY ' '
#define BRICK '#'
#define PADDLE '-'
#define BALL 'o'

char screen[HEIGHT][WIDTH];
int paddle_position = WIDTH / 2 - PADDLE_WIDTH / 2;
int ball_x = WIDTH / 2, ball_y = HEIGHT - 3;
int ball_direction_x = 1, ball_direction_y = -1;
int bricks[BRICK_ROWS][BRICK_COLUMNS];

void init_bricks() {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLUMNS; j++) {
            bricks[i][j] = 1; // All bricks are present
        }
    }
}

void draw_screen() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            screen[y][x] = EMPTY;

            if (y < BRICK_ROWS && bricks[y][x] == 1) {
                screen[y][x] = BRICK; // Draw brick
            }
            if (y == HEIGHT - 2) {
                // Draw paddle
                for (int p = 0; p < PADDLE_WIDTH; p++) {
                    screen[y][paddle_position + p] = PADDLE;
                }
            }
            if (y == ball_y && x == ball_x) {
                screen[y][x] = BALL; // Draw ball
            }
        }
    }

    // Print the screen buffer
    printf("\033[H\033[J"); // Clear the terminal
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(screen[y][x]);
        }
        putchar('\n');
    }
}

int kbhit() {
    struct termios oldt, newt;
    int oldf;
    char ch;
    int res;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    res = read(STDIN_FILENO, &ch, 1);
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if (res == 1) {
        return ch;
    }

    return 0;
}

void update_game() {
    ball_x += ball_direction_x;
    ball_y += ball_direction_y;

    // Ball collision with walls
    if (ball_x <= 0 || ball_x >= WIDTH - 1) {
        ball_direction_x = -ball_direction_x;
    }
    if (ball_y <= 0) {
        ball_direction_y = -ball_direction_y;
    }
    
    // Ball collision with paddle
    if (ball_y == HEIGHT - 2 && ball_x >= paddle_position && ball_x < paddle_position + PADDLE_WIDTH) {
        ball_direction_y = -ball_direction_y;
    }

    // Ball collision with bricks
    if (ball_y < BRICK_ROWS) {
        if (bricks[ball_y][ball_x] == 1) {
            bricks[ball_y][ball_x] = 0;
            ball_direction_y = -ball_direction_y;
        }
    }

    // Check if ball falls below the paddle
    if (ball_y >= HEIGHT - 1) {
        printf("Game Over! The ball has fallen!\n");
        exit(0);
    }
}

int main() {
    init_bricks();
    
    while (1) {
        draw_screen();
        usleep(100000); // Sleep for 100 milliseconds
        update_game();

        int key = kbhit();
        if (key == 'a' && paddle_position > 0) {
            paddle_position--; // Move left
        } else if (key == 'd' && paddle_position < WIDTH - PADDLE_WIDTH) {
            paddle_position++; // Move right
        }
    }

    return 0;
}