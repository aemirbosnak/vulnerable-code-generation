//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 30
#define COLS 80
#define PADDLE_LENGTH 10
#define BALL_POSITION_X 15
#define BALL_POSITION_Y 40
#define MAX_BRICKS 150

typedef enum {LEFT, UP_LEFT, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN_LEFT} direction_t;

struct brick {
    int x;
    int y;
    int is_alive;
};

struct ball {
    int x;
    int y;
    int direction;
};

struct paddle {
    int x;
    int y;
};

int score = 0;
int lives = 3;
int bricks_left = MAX_BRICKS;
struct brick bricks[MAX_BRICKS];
struct ball ball = {BALL_POSITION_X, BALL_POSITION_Y, UP_LEFT};
struct paddle paddle = {ROWS - 2, COLS / 2 - PADDLE_LENGTH / 2};

void init_bricks() {
    int i, j, k;
    k = 0;
    for (i = 2; i < ROWS / 2; i++) {
        for (j = (i % 2 == 0) ? 3 : 2; j < COLS - 2; j += 4) {
            bricks[k].x = i;
            bricks[k].y = j;
            bricks[k].is_alive = 1;
            k++;
        }
    }
}

void draw_bricks() {
    int i;
    for (i = 0; i < MAX_BRICKS; i++) {
        if (bricks[i].is_alive) {
            printf("\033[%d;%dH*", bricks[i].x, bricks[i].y);
        }
    }
}

void draw_paddle() {
    int i;
    for (i = 0; i < PADDLE_LENGTH; i++) {
        printf("\033[%d;%dH=", paddle.x, paddle.y + i);
    }
}

void erase_ball() {
    printf("\033[%d;%dH ", ball.x, ball.y);
}

void draw_ball() {
    printf("\033[%d;%dH0", ball.x, ball.y);
}

void move_paddle_left() {
    if (paddle.y > 2) {
        paddle.y--;
    }
}

void move_paddle_right() {
    if (paddle.y + PADDLE_LENGTH < COLS - 2) {
        paddle.y++;
    }
}

void* keyboard_input(void* arg) {
    int* running = (int*)arg;
    struct termios old_tio, new_tio;
    unsigned char c;
    tcgetattr(STDIN_FILENO, &old_tio);
    memcpy(&new_tio, &old_tio, sizeof(struct termios));
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    while (*running) {
        read(STDIN_FILENO, &c, 1);
        switch(c) {
            case 'q':
                *running = 0;
                break;
            case 'a':
                move_paddle_left();
                break;
            case 'd':
                move_paddle_right();
                break;
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    pthread_exit(NULL);
}

void move_ball() {
    direction_t dir = ball.direction;
    erase_ball();
    switch(dir) {
        case LEFT:
            if (ball.y > 2) {
                ball.y--;
            } else {
                dir = RIGHT;
            }
            break;
        case UP_LEFT:
            if (ball.x > 1 && ball.y > 2) {
                ball.x--;
                ball.y--;
            } else if (ball.x == 1 && ball.y > 2) {
                ball.x++;
                dir = DOWN_LEFT;
            } else if (ball.x > 1 && ball.y == 2) {
                ball.y++;
                dir = UP_RIGHT;
            } else {
                ball.x++;
                ball.y++;
                dir = DOWN_RIGHT;
            }
            break;
        case UP_RIGHT:
            if (ball.x > 1 && ball.y < COLS - 2) {
                ball.x--;
                ball.y++;
            } else if (ball.x == 1 && ball.y < COLS - 2) {
                ball.x++;
                dir = DOWN_RIGHT;
            } else if (ball.x > 1 && ball.y == COLS - 2) {
                ball.y--;
                dir = UP_LEFT;
            } else {
                ball.x++;
                ball.y--;
                dir = DOWN_LEFT;
            }
            break;
        case RIGHT:
            if (ball.y < COLS - 2) {
                ball.y++;
            } else {
                dir = LEFT;
            }
            break;
        case DOWN_RIGHT:
            if (ball.x < ROWS - 3 && ball.y < COLS - 2) {
                ball.x++;
                ball.y++;
            } else if (ball.x == ROWS - 3 && ball.y < COLS - 2) {
                ball.x--;
                dir = UP_RIGHT;
            } else if (ball.x < ROWS - 3 && ball.y == COLS - 2) {
                ball.x++;
                dir = DOWN_LEFT;
            } else {
                ball.x--;
                ball.y--;
                dir = UP_LEFT;
            }
            break;
        case DOWN_LEFT:
            if (ball.x < ROWS - 3 && ball.y > 2) {
                ball.x++;
                ball.y--;
            } else if (ball.x == ROWS - 3 && ball.y > 2) {
                ball.x--;
                dir = UP_LEFT;
            } else if (ball.x < ROWS - 3 && ball.y == 2) {
                ball.x++;
                dir = DOWN_RIGHT;
            } else {
                ball.x--;
                ball.y++;
                dir = UP_RIGHT;
            }
            break;
    }
    ball.direction = dir;
    draw_ball();
}

void check_collisions() {
    int i;
    if (ball.x == ROWS - 3) {
        if (ball.y >= paddle.y && ball.y <= paddle.y + PADDLE_LENGTH) {
            ball.direction = DOWN_LEFT;
        } else {
            lives--;
            if (lives == 0) {
                printf("\033[%d;%dHGame Over!", ROWS / 2, COLS / 2 - 5);
                exit(0);
            } else {
                ball.x = BALL_POSITION_X;
                ball.y = BALL_POSITION_Y;
                ball.direction = UP_LEFT;
            }
        }
    }
    for (i = 0; i < MAX_BRICKS; i++) {
        if (bricks[i].is_alive && ball.x == bricks[i].x && ball.y == bricks[i].y) {
            score += 10;
            bricks[i].is_alive = 0;
            erase_ball();
            if (ball.direction == UP_LEFT) {
                ball.direction = DOWN_LEFT;
            } else if (ball.direction == UP_RIGHT) {
                ball.direction = DOWN_RIGHT;
            } else if (ball.direction == DOWN_LEFT) {
                ball.direction = UP_LEFT;
            } else if (ball.direction == DOWN_RIGHT) {
                ball.direction = UP_RIGHT;
            }
            bricks_left--;
            if (bricks_left == 0) {
                printf("\033[%d;%dHYou won!", ROWS / 2, COLS / 2 - 5);
                exit(0);
            }
            draw_bricks();
            usleep(10000);
            draw_ball();
        }
    }
}

int main() {
    int running = 1;
    pthread_t input_thread;
    int input_thread_ret;
    int i;
    srand(time(0));
    printf("\033[2J");
    init_bricks();
    draw_bricks();
    draw_ball();
    draw_paddle();
    input_thread_ret = pthread_create(&input_thread, NULL, keyboard_input, &running);
    if (input_thread_ret != 0) {
        printf("Failed to create input thread.\n");
        exit(-1);
    }
    while (running) {
        move_ball();
        check_collisions();
        printf("\033[%d;%dHScore: %d\t\tLives: %d", ROWS + 2, 2, score, lives);
        fflush(stdout);
        usleep(10000);
    }
    pthread_join(input_thread, NULL);
    return 0;
}