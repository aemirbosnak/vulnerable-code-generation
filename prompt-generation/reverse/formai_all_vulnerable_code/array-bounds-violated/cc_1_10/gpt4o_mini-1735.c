//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>

#define WIDTH 40
#define HEIGHT 20
#define PADDLE_WIDTH 7
#define BRICK_COUNT 28

char screen[HEIGHT][WIDTH];
int paddle_x = (WIDTH / 2) - (PADDLE_WIDTH / 2);
int paddle_y = HEIGHT - 1;
int ball_x = WIDTH / 2;
int ball_y = HEIGHT - 2;
int ball_dx = 1; // Ball's horizontal direction
int ball_dy = -1; // Ball's vertical direction
int bricks[BRICK_COUNT][3]; // x, y position of bricks and active status

void init_bricks() {
    int index = 0;
    for (int y = 2; y < 7; y++) {
        for (int x = 1; x < WIDTH - 1; x += 2) {
            bricks[index][0] = x; // x position
            bricks[index][1] = y; // y position
            bricks[index][2] = 1; // active
            index++;
        }
    }
}

void render() {
    system("clear");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == paddle_y && x >= paddle_x && x < paddle_x + PADDLE_WIDTH) {
                printf("=");
            } else if (y == ball_y && x == ball_x) {
                printf("O");
            } else {
                int brick_found = 0;
                for (int i = 0; i < BRICK_COUNT; i++) {
                    if (bricks[i][0] == x && bricks[i][1] == y && bricks[i][2] == 1) {
                        printf("#");
                        brick_found = 1;
                        break;
                    }
                }
                if (!brick_found) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int kbhit(void) {
    struct termios oldt, newt;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void update_ball() {
    ball_x += ball_dx;
    ball_y += ball_dy;

    // Ball collision with walls
    if (ball_x <= 0 || ball_x >= WIDTH - 1) {
        ball_dx = -ball_dx;
    }

    if (ball_y <= 0) {
        ball_dy = -ball_dy;
    }

    // Ball collision with paddle
    if (ball_y == paddle_y - 1 && ball_x >= paddle_x && ball_x < paddle_x + PADDLE_WIDTH) {
        ball_dy = -ball_dy;
    }

    // Ball collision with bricks
    for (int i = 0; i < BRICK_COUNT; i++) {
        if (bricks[i][2] == 1 && ball_x == bricks[i][0] && ball_y == bricks[i][1]) {
            bricks[i][2] = 0; // Brick is now inactive
            ball_dy = -ball_dy; // Change direction
            break;
        }
    }
}

void update_paddle(char direction) {
    if (direction == 'l' && paddle_x > 0) {
        paddle_x--;
    } else if (direction == 'r' && paddle_x < WIDTH - PADDLE_WIDTH) {
        paddle_x++;
    }
}

void signal_handler(int signum) {
    exit(0);
}

int main() {
    signal(SIGINT, signal_handler);
    init_bricks();
    
    while (1) {
        render();
        if (kbhit()) {
            char ch = getchar();
            if (ch == 'q') break; // Exit on 'q'
            else if (ch == 'a') update_paddle('l'); // Move paddle left
            else if (ch == 'd') update_paddle('r'); // Move paddle right
        }
        update_ball();
        usleep(50000); // Control the speed of ball movement
    }

    return 0;
}