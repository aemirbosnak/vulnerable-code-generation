//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Define constants
#define WIDTH 800
#define HEIGHT 600
#define BALL_RADIUS 10
#define PADDLE_WIDTH 50
#define PADDLE_HEIGHT 150

// Define data structures
typedef struct {
    int x;
    int y;
    int dx;
    int dy;
    bool ai;
    int score;
} Ball;

typedef struct {
    int x;
    int y;
    int width;
    int height;
    int score;
} Paddle;

typedef struct {
    Ball ball;
    Paddle paddle;
    Paddle paddle_ai;
} Game;

// Define functions
void init_game(Game* game) {
    game->ball.x = (WIDTH - BALL_RADIUS) / 2;
    game->ball.y = (HEIGHT - BALL_RADIUS) / 2;
    game->ball.dx = (rand() % 2) * 0.5 - 0.25;
    game->ball.dy = (rand() % 2) * 0.5 - 0.25;
    game->paddle.x = (WIDTH / 2) - (PADDLE_WIDTH / 2);
    game->paddle.y = (HEIGHT - PADDLE_HEIGHT) / 2;
    game->paddle.score = 0;
    game->paddle_ai.x = (WIDTH / 2) - (PADDLE_WIDTH / 2);
    game->paddle_ai.y = (HEIGHT - PADDLE_HEIGHT) / 2;
    game->paddle_ai.score = 0;
}

void update_game(Game* game) {
    if (game->ball.x >= WIDTH - BALL_RADIUS || game->ball.x <= BALL_RADIUS || game->ball.y >= HEIGHT - BALL_RADIUS || game->ball.y <= BALL_RADIUS) {
        game->ball.dx *= -1;
        game->ball.dy *= -1;
    }
    game->ball.x += game->ball.dx;
    game->ball.y += game->ball.dy;
    if (game->ball.x >= WIDTH - BALL_RADIUS || game->ball.x <= BALL_RADIUS || game->ball.y >= HEIGHT - BALL_RADIUS || game->ball.y <= BALL_RADIUS) {
        game->ball.dx *= -1;
        game->ball.dy *= -1;
        if (game->ball.x < PADDLE_WIDTH || game->ball.y < PADDLE_HEIGHT || game->ball.x > (WIDTH - PADDLE_WIDTH) || game->ball.y > (HEIGHT - PADDLE_HEIGHT)) {
            game->paddle.score++;
        }
        if (game->paddle_ai.x < PADDLE_WIDTH || game->paddle_ai.y < PADDLE_HEIGHT || game->paddle_ai.x > (WIDTH - PADDLE_WIDTH) || game->paddle_ai.y > (HEIGHT - PADDLE_HEIGHT)) {
            game->paddle_ai.score++;
        }
        game->paddle.x = (WIDTH / 2) - (PADDLE_WIDTH / 2);
        game->paddle.y = (HEIGHT - PADDLE_HEIGHT) / 2;
        game->paddle_ai.x = (WIDTH / 2) - (PADDLE_WIDTH / 2);
        game->paddle_ai.y = (HEIGHT - PADDLE_HEIGHT) / 2;
    }
    if (game->ball.x > game->paddle.x && game->ball.y < game->paddle.y + PADDLE_HEIGHT && game->ball.y > game->paddle.y && abs(game->ball.x - game->paddle.x) < game->ball.dx * 2 && abs(game->ball.y - game->paddle.y) < game->ball.dy * 2) {
        game->ball.dx *= -1;
        game->ball.dy *= -1;
    }
    if (game->ball.x > game->paddle_ai.x && game->ball.y < game->paddle_ai.y + PADDLE_HEIGHT && game->ball.y > game->paddle_ai.y && abs(game->ball.x - game->paddle_ai.x) < game->ball.dx * 2 && abs(game->ball.y - game->paddle_ai.y) < game->ball.dy * 2) {
        game->ball.dx *= -1;
        game->ball.dy *= -1;
    }
}

void draw_game(Game* game) {
    printf("Score: %d - %d\n", game->paddle.score, game->paddle_ai.score);
    printf("Ball: %d %d\n", game->ball.x, game->ball.y);
    printf("Paddle: %d %d\n", game->paddle.x, game->paddle.y);
    printf("Paddle AI: %d %d\n", game->paddle_ai.x, game->paddle_ai.y);
    printf("Paddle Width: %d\n", PADDLE_WIDTH);
    printf("Paddle Height: %d\n", PADDLE_HEIGHT);
}

int main() {
    Game game;
    init_game(&game);
    while (true) {
        update_game(&game);
        draw_game(&game);
        printf("\n");
        printf("Press Enter to play again or q to quit: ");
        char c;
        scanf("%c", &c);
        if (c == 'q') {
            break;
        }
    }
    return 0;
}