//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define WIDTH 20
#define HEIGHT 10
#define PADDLE_SIZE 3
#define TICK_RATE 1000000
#define MAX_SCORE 5

// Terminal input functions
static struct termios orig_termios;

char getch(){
    char ch;
    struct termios new_termios;
    tcgetattr(0, &orig_termios);
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new_termios);
    ch = getchar();
    tcsetattr(0, TCSANOW, &orig_termios);
    return ch;
}

// Game state
typedef enum { false, true } bool;

typedef struct {
    int x, y;
} Point;

Point ball;
Point paddle_left, paddle_right;
int score_left = 0, score_right = 0;

void reset_ball() {
    srand(time(NULL));
    ball.x = WIDTH / 2;
    ball.y = rand() % HEIGHT;
    if (ball.y < 2) ball.y += 2;
    if (ball.y > HEIGHT - 2) ball.y -= 2;
}

void reset_paddles() {
    paddle_left.x = 1;
    paddle_left.y = HEIGHT / 2 - PADDLE_SIZE / 2;
    paddle_right.x = WIDTH - 2;
    paddle_right.y = HEIGHT / 2 - PADDLE_SIZE / 2;
}

// AI opponent
void ai_move() {
    // Simple algorithm: try to center paddle with ball
    int paddle_center = paddle_right.y + PADDLE_SIZE / 2;
    int ball_diff = paddle_center - ball.y;
    if (ball_diff < 0 && paddle_right.y <= HEIGHT - PADDLE_SIZE)
        paddle_right.y++;
    else if (ball_diff > 0 && paddle_right.y >= 0)
        paddle_right.y--;
}

// Keyboard input
void handle_input(char ch) {
    switch (ch) {
        case 'q': exit(0);
        case 'w': case 'W':
            if (paddle_left.y >= 1)
                paddle_left.y--;
            break;
        case 's': case 'S':
            if (paddle_left.y <= HEIGHT - PADDLE_SIZE)
                paddle_left.y++;
            break;
    }
}

// Drawing
void draw_point(Point p, char c) {
    printf("\033[%d;%dH%c", p.y+1, p.x+1, c);
}

void draw_paddle(Point p) {
    int i;
    for (i = 0; i < PADDLE_SIZE; i++)
        draw_point((Point){p.x, p.y+i}, '|');
}

void draw_ball() {
    draw_point(ball, 'O');
}

void draw_scores() {
    printf("\033[1;%dH%d", WIDTH/2-2, score_left);
    printf("\033[1;%dH%d", WIDTH/2+2, score_right);
}

void draw_screen() {
    int i;
    for (i = 0; i < WIDTH; i++)
        draw_point((Point){i, 0}, '-');
    for (i = 1; i < HEIGHT; i++)
        draw_point((Point){0, i}, '|');
    for (i = 1; i < HEIGHT; i++)
        draw_point((Point){WIDTH-1, i}, '|');
    for (i = 0; i < WIDTH; i++)
        draw_point((Point){i, HEIGHT-1}, '-');
}

// Collision detection
bool is_point_on_paddle(Point p, Point pa) {
    return p.y >= pa.y && p.y < pa.y + PADDLE_SIZE;
}

bool check_collision() {
    // Check for collision with walls
    if (ball.y == 1 || ball.y == HEIGHT - 2)
        return true;
    // Check for collision with left paddle
    if (ball.x == paddle_left.x + 1 && is_point_on_paddle(ball, paddle_left))
        return true;
    // Check for collision with right paddle
    if (ball.x == paddle_right.x - 1 && is_point_on_paddle(ball, paddle_right))
        return true;
    return false;
}

// Main loop
int main() {
    struct timespec delay = {0, TICK_RATE};
    int ch, i;

    // Setup terminal
    tcgetattr(STDIN_FILENO, &orig_termios);
    setbuf(stdout, NULL);

    // Initial state
    reset_ball();
    reset_paddles();

    // Game loop
    while (score_left < MAX_SCORE && score_right < MAX_SCORE) {
        // Get keyboard input
        ch = getchar();
        if (ch != EOF)
            handle_input(ch);

        // AI move
        ai_move();

        // Move ball
        ball.x += 1;
        if (check_collision()) {
            ball.x -= 2;
            if (ball.x == 0) {
                score_right++;
                reset_ball();
                reset_paddles();
            } else if (ball.x == WIDTH - 1) {
                score_left++;
                reset_ball();
                reset_paddles();
            }
        }

        // Draw screen
        printf("\033[2J");
        draw_screen();
        draw_paddle(paddle_left);
        draw_paddle(paddle_right);
        draw_ball();
        draw_scores();
        fflush(stdout);

        // Wait
        nanosleep(&delay, NULL);
    }

    // Exit
    printf("\033[2J\033[%d;%dH", HEIGHT+1, 0);
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    return 0;
}