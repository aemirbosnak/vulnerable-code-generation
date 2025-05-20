//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 23

#define MAX_BRICKS 50

#define PADDLE_LENGTH 5

#define BALL_SYMBOL 'o'
#define PADDLE_SYMBOL '|'

#define NORMAL_BLOCK 'X'
#define UNBREAKABLE_BLOCK 'U'

#define SLEEP_TIME 40000

int score = 0;
int lives = 3;

int bricks_left = 0;

char grid[HEIGHT][WIDTH+1] = {0};

void update_score(int points) {
    score += points;
    printf("Score: %d\n", score);
}

void draw_grid() {
    system("clear");

    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", grid[i]);
    }

    printf("\n");
    printf("Lives: %d\n", lives);
    printf("Score: %d\n", score);
}

struct Brick {
    int x;
    int y;
    int type;
    int health;
};

struct Ball {
    int x;
    int y;
    int x_dir;
    int y_dir;
};

struct Paddle {
    int x;
    int y;
};

struct Brick bricks[MAX_BRICKS];
int num_bricks = 0;

struct Ball ball;
struct Paddle paddle;

void fill_grid() {
    for (int i = 0; i < HEIGHT; i++) {
        memset(grid[i], ' ', WIDTH);
    }
}

void create_bricks() {
    int x_offset = WIDTH / 2 - 4;
    int y_offset = 3;

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 10; i++) {
            bricks[num_bricks].x = i*5 + x_offset;
            bricks[num_bricks].y = j + y_offset;
            bricks[num_bricks].type = NORMAL_BLOCK;
            bricks[num_bricks].health = 1;
            num_bricks++;
        }
    }

    bricks_left = num_bricks;
}

void draw_bricks() {
    for (int i = 0; i < num_bricks; i++) {
        if (bricks[i].type == NORMAL_BLOCK) {
            grid[bricks[i].y][bricks[i].x] = NORMAL_BLOCK;
        }
        else {
            grid[bricks[i].y][bricks[i].x] = UNBREAKABLE_BLOCK;
        }
    }
}

void draw_ball() {
    grid[ball.y][ball.x] = BALL_SYMBOL;
}

void draw_paddle() {
    for (int i = 0; i < PADDLE_LENGTH; i++) {
        grid[paddle.y+i][paddle.x] = PADDLE_SYMBOL;
    }
}

void move_ball() {
    ball.x += ball.x_dir;
    ball.y += ball.y_dir;

    if (ball.x < 0 || ball.x >= WIDTH) {
        ball.x_dir = -ball.x_dir;
    }

    if (ball.y < 0) {
        ball.y_dir = -ball.y_dir;
    }

    if (ball.y >= HEIGHT) {
        lives--;
        if (lives > 0) {
            ball.x = paddle.x + PADDLE_LENGTH / 2;
            ball.y = paddle.y - 1;
            ball.x_dir = -1;
            ball.y_dir = -1;
        }
        else {
            printf("Game Over!\n");
            exit(0);
        }
    }

    if (ball.y == paddle.y - 1 && ball.x >= paddle.x && ball.x < paddle.x + PADDLE_LENGTH) {
        ball.y_dir = -ball.y_dir;
    }

    for (int i = 0; i < num_bricks; i++) {
        if (bricks[i].health <= 0) {
            continue;
        }

        if (ball.x == bricks[i].x && ball.y == bricks[i].y) {
            bricks[i].health--;
            if (bricks[i].type == NORMAL_BLOCK) {
                score += 10;
                bricks_left--;
            }
            if (bricks[i].health == 0) {
                grid[bricks[i].y][bricks[i].x] = ' ';
            }
            ball.y_dir = -ball.y_dir;
            break;
        }
    }
}

void move_paddle(int direction) {
    if (direction < 0 && paddle.x > 0) {
        paddle.x--;
    }

    if (direction > 0 && paddle.x + PADDLE_LENGTH < WIDTH) {
        paddle.x++;
    }

}

void handle_input() {
    struct timeval tv;
    fd_set fds;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);

    if (FD_ISSET(STDIN_FILENO, &fds)) {
        char c = getchar();
        if (c == 'a' || c == 'A') {
            move_paddle(-1);
        }
        if (c == 'd' || c == 'D') {
            move_paddle(1);
        }
    }
}

void init_game() {
    ball.x = WIDTH / 2;
    ball.y = HEIGHT - 3;
    ball.x_dir = -1;
    ball.y_dir = -1;

    paddle.x = WIDTH / 2 - PADDLE_LENGTH / 2;
    paddle.y = HEIGHT - 2;

    fill_grid();
    draw_bricks();
    draw_ball();
    draw_paddle();

    update_score(0);
}

void loop() {
    while (bricks_left > 0) {
        usleep(SLEEP_TIME);

        fill_grid();

        handle_input();

        move_ball();

        draw_ball();
        draw_paddle();
        draw_bricks();

        draw_grid();
    }

    printf("You Won!\n");
}

int main(int argc, char const *argv[]) {
    create_bricks();

    init_game();

    loop();

    return 0;
}