//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

#define MAX_BLOCKS 60
#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int x, y;
    int width, height;
} Paddle;

typedef struct {
    int x, y;
    int dx, dy;
    int alive;
} Ball;

typedef struct {
    int x, y;
    int alive;
} Block;

Block blocks[MAX_BLOCKS];
Paddle paddle;
Ball ball;

void init();
void draw();
void update();
int kbhit();
int getch();
void resetGame();
void createBlocks();
void updateBlocks();

int main() {
    init();
    while (1) {
        draw();
        update();
        usleep(100000); // sleep for 0.1 seconds
        if (ball.y >= HEIGHT) {
            resetGame();
        }
    }
    return 0;
}

void init() {
    paddle.x = WIDTH / 2 - 2;
    paddle.y = HEIGHT - 1;
    paddle.width = 5;
    paddle.height = 1;

    ball.x = WIDTH / 2;
    ball.y = paddle.y - 1;
    ball.dx = 1;
    ball.dy = -1;
    ball.alive = 1;

    createBlocks();
}

void createBlocks() {
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if (index >= MAX_BLOCKS) break;
            blocks[index].x = j * 2;
            blocks[index].y = i;
            blocks[index].alive = 1;
            index++;
        }
    }
}

void draw() {
    system("clear"); // clear the screen
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        printf("#");
        for (int x = 0; x < WIDTH; x++) {
            if (blocks[y * WIDTH + x].alive) {
                printf("[]"); // block
            } else if (x >= paddle.x && x < paddle.x + paddle.width && y == paddle.y) {
                printf("=="); // paddle
            } else if (x == ball.x && y == ball.y) {
                printf("O"); // ball
            } else {
                printf("  "); // empty space
            }
        }
        printf("#\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
}

void update() {
    if (kbhit()) {
        char ch = getch();
        if (ch == 'a' && paddle.x > 0) paddle.x -= 2;
        if (ch == 'd' && paddle.x < WIDTH - paddle.width) paddle.x += 2;
    }

    ball.x += ball.dx;
    ball.y += ball.dy;

    // Collision with walls
    if (ball.x <= 0 || ball.x >= WIDTH - 1) ball.dx = -ball.dx;
    if (ball.y <= 0) ball.dy = -ball.dy;

    // Collision with paddle
    if (ball.y == paddle.y - 1 && ball.x >= paddle.x && ball.x < paddle.x + paddle.width) {
        ball.dy = -ball.dy;
    }

    // Collision with blocks
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (blocks[i].alive && ball.x >= blocks[i].x && ball.x < blocks[i].x + 2 && ball.y == blocks[i].y) {
            blocks[i].alive = 0;
            ball.dy = -ball.dy;
        }
    }
}

void resetGame() {
    printf("Game Over! Restarting...\n");
    sleep(2);
    init();
}

int kbhit() {
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

int getch() {
    int ch = getchar();
    return ch;
}