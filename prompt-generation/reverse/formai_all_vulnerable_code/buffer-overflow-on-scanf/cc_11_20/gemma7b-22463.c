//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_WALL 0
#define RIGHT_WALL 1
#define TOP_WALL 2
#define BOTTOM_WALL 3

#define BALL_SIZE 5
#define PADDLE_SIZE 20

#define PADDLE_SPEED 10
#define BALL_SPEED 5

int main() {
    int x_ball = BALL_SIZE / 2;
    int y_ball = BOTTOM_WALL - BALL_SIZE / 2;
    int x_paddle = PADDLE_SIZE / 2;
    int y_paddle = TOP_WALL - PADDLE_SIZE;

    int score_player = 0;
    int score_ai = 0;

    time_t t = time(NULL);
    srand(t);

    // AI opponent's paddle movement logic
    int ai_move = rand() % 2;

    while (1) {
        // Player's turn
        printf("Enter your move (h/l/u/d): ");
        char move;
        scanf("%c", &move);

        switch (move) {
            case 'h':
                x_paddle--;
                break;
            case 'l':
                x_paddle++;
                break;
            case 'u':
                y_paddle--;
                break;
            case 'd':
                y_paddle++;
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        // Ball movement
        x_ball += BALL_SPEED * (ai_move ? -1 : 1);
        y_ball -= BALL_SPEED;

        // AI opponent's turn
        ai_move = rand() % 2;
        switch (ai_move) {
            case 0:
                y_paddle--;
                break;
            case 1:
                y_paddle++;
                break;
        }

        // Check if the ball has hit a wall
        if (x_ball < LEFT_WALL || x_ball > RIGHT_WALL) {
            x_ball = BALL_SIZE / 2;
            score_player++;
        }
        if (y_ball < TOP_WALL || y_ball > BOTTOM_WALL) {
            y_ball = BOTTOM_WALL - BALL_SIZE / 2;
            score_ai++;
        }

        // Print the score
        printf("Score: Player %d, AI %d\n", score_player, score_ai);

        // Check if the game is over
        if (score_player == score_ai) {
            printf("Game over! It's a draw!\n");
            break;
        } else if (score_player > score_ai) {
            printf("Game over! You won!\n");
            break;
        } else {
            printf("Game over! AI won!\n");
            break;
        }
    }

    return 0;
}