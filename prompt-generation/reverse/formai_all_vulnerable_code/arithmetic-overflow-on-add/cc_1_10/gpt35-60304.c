//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>

// Define some constants
#define MAX_X 50
#define MAX_Y 20
#define PADDLE_WIDTH 3
#define PADDLE_HEIGHT 1
#define BALL_RADIUS 1
#define AI_DIFFICULTY 3

// Define some data structures
struct point {
    int x;
    int y;
};

struct game {
    struct point ball;
    struct point ball_motion;
    struct point paddle_player;
    struct point paddle_ai;
    int player_score;
    int ai_score;
};

// Define some helper functions
void clear_screen() {
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #else
    system("clear");
    #endif
}

struct point get_input() {
    struct termios old, new;
    struct point input = {0, 0};
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new);
    if (read(0, &input, sizeof(input)) < 0) {
        input = (struct point){0, 0};
    }
    tcsetattr(0, TCSANOW, &old);
    return input;
}

int random_between(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int sign(int n) {
    return (n > 0) - (n < 0);
}

// Define the game functions
void init_game(struct game *g) {
    // Initialize the ball in the center of the screen
    g->ball = (struct point){MAX_X / 2, MAX_Y / 2};
    // Set the ball motion to a random direction
    g->ball_motion = (struct point){random_between(-1, 1), random_between(-1, 1)};
    // Initialize the player paddle on the left side of the screen
    g->paddle_player = (struct point){0, MAX_Y / 2};
    // Initialize the AI paddle on the right side of the screen
    g->paddle_ai = (struct point){MAX_X - PADDLE_WIDTH, MAX_Y / 2};
    // Initialize the score counters to zero
    g->player_score = 0;
    g->ai_score = 0;
}

void draw_ball(struct game *g) {
    // Draw the ball as an asterisk at its current position
    printf("\033[%d;%dH*", g->ball.y, g->ball.x);
}

void draw_paddle(struct point paddle) {
    // Draw the paddle as a solid rectangle at its current position
    for (int y=paddle.y; y<paddle.y+PADDLE_HEIGHT; y++) {
        for (int x=paddle.x; x<paddle.x+PADDLE_WIDTH; x++) {
            printf("\033[%d;%dH#", y, x);
        }
    }
}

void draw_score(struct game *g) {
    // Draw the score counters at the top of the screen
    printf("\033[1;1HPlayer: %d", g->player_score);
    printf("\033[1;%dHAI: %d", MAX_X - 10, g->ai_score);
}

void move_ball(struct game *g) {
    // Move the ball by its current motion vector
    g->ball.x += g->ball_motion.x;
    g->ball.y += g->ball_motion.y;
    // If the ball hits the top or bottom of the screen, reverse its y motion
    if (g->ball.y == 0 || g->ball.y == MAX_Y) {
        g->ball_motion.y = -g->ball_motion.y;
    }
    // If the ball hits the left or right wall, reset the game
    if (g->ball.x == 0 || g->ball.x == MAX_X) {
        init_game(g);
    }
    // If the ball hits the player paddle, rebound it and increase the player's score
    if (g->ball.x == g->paddle_player.x + PADDLE_WIDTH && g->ball.y >= g->paddle_player.y && g->ball.y < g->paddle_player.y + PADDLE_HEIGHT) {
        g->ball_motion.x = -g->ball_motion.x;
        g->player_score++;
    }
    // If the ball hits the AI paddle, rebound it and increase the AI's score
    if (g->ball.x == g->paddle_ai.x && g->ball.y >= g->paddle_ai.y && g->ball.y < g->paddle_ai.y + PADDLE_HEIGHT) {
        g->ball_motion.x = -g->ball_motion.x;
        g->ai_score++;
    }
}

void move_paddle(struct point *paddle, struct point motion) {
    // Move the paddle by the given motion vector
    paddle->y += motion.y;
    // If the paddle hits the top or bottom of the screen, stop it from moving further
    if (paddle->y < 0) {
        paddle->y = 0;
    }
    if (paddle->y > MAX_Y - PADDLE_HEIGHT) {
        paddle->y = MAX_Y - PADDLE_HEIGHT;
    }
}

void ai_move_paddle(struct game *g) {
    // Calculate the difference in y position between the ball and the AI paddle
    int y_diff = g->ball.y - (g->paddle_ai.y + PADDLE_HEIGHT / 2);
    // Move the AI paddle towards the ball with a speed proportional to the difference
    move_paddle(&g->paddle_ai, (struct point){0, sign(y_diff) * fmin(abs(y_diff) / AI_DIFFICULTY, 1)});
}

// Define the main program
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the game state and input variables
    struct game g;
    struct point input = {0, 0};
    int quit = 0;

    // Play the game until the player quits
    while (!quit) {
        // Clear the screen and draw the game elements
        clear_screen();
        draw_ball(&g);
        draw_paddle(g.paddle_player);
        draw_paddle(g.paddle_ai);
        draw_score(&g);

        // Get player input and move the player paddle accordingly
        input = get_input();
        move_paddle(&g.paddle_player, (struct point){0, input.y});

        // Move the AI paddle
        ai_move_paddle(&g);

        // Move the ball and update the game state
        move_ball(&g);

        // If the player presses the Q key, quit the game
        if (input.x == 'q' || input.x == 'Q') {
            quit = 1;
        }

        // Sleep for a short time to slow down the game loop
        usleep(50000);
    }

    return 0;
}