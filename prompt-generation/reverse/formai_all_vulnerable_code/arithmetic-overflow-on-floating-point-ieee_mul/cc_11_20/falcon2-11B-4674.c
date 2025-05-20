//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    position paddle;
    int score;
} player;

typedef struct {
    player left;
    player right;
} game;

int main() {
    srand(time(NULL));

    game game = { { { 100, 100 }, 0 }, { { 100, 200 }, 0 } };

    while (1) {
        printf("Left: %d, Right: %d\n", game.left.score, game.right.score);

        if (game.left.score > 10) {
            break;
        }

        if (game.right.score > 10) {
            break;
        }

        if (game.left.paddle.y < 10 || game.left.paddle.y > 200) {
            game.left.paddle.y = rand() % (200 - 10) + 10;
        }
        else {
            game.left.paddle.y += 10;
        }

        if (game.right.paddle.y < 10 || game.right.paddle.y > 200) {
            game.right.paddle.y = rand() % (200 - 10) + 10;
        }
        else {
            game.right.paddle.y -= 10;
        }

        int left_x = 100 + game.left.paddle.x;
        int right_x = 100 + game.right.paddle.x;
        int left_y = 100 + game.left.paddle.y;
        int right_y = 100 + game.right.paddle.y;

        int distance = sqrt(pow(left_x - right_x, 2) + pow(left_y - right_y, 2));

        if (distance < 50) {
            int ball_x = 100 + (rand() % 50) - 25;
            int ball_y = 100 + (rand() % 50) - 25;

            if (ball_y > right_y && ball_y < right_y + 10) {
                game.right.score++;
            }
            else if (ball_y < left_y && ball_y > left_y - 10) {
                game.left.score++;
            }

            ball_x += 1;
            ball_y += 1;
        }
    }

    return 0;
}