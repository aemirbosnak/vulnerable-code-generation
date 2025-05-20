//GEMINI-pro DATASET v1.0 Category: Pong Game with AI Opponent ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

/*AI paddle movement speeds*/
#define AI_SLOW 1
#define AI_MEDIUM 2
#define AI_FAST 3

/*Ball movement directions*/
#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1

struct ball {
    int x, y;
    int dx, dy;
};

struct paddle {
    int x, y;
    int w, h;
};

int main() {
    /*Initialize random number generator*/
    srand(time(NULL));

    /*Create game structures*/
    struct ball ball;
    struct paddle player1;
    struct paddle ai;

    /*Initialize game variables*/
    ball.x = WIDTH / 2;
    ball.y = HEIGHT / 2;
    ball.dx = LEFT;
    ball.dy = UP;

    player1.x = 10;
    player1.y = HEIGHT / 2 - player1.h / 2;
    player1.w = 10;
    player1.h = 100;

    ai.x = WIDTH - 10 - ai.w;
    ai.y = HEIGHT / 2 - ai.h / 2;
    ai.w = 10;
    ai.h = 100;

    int ai_speed = AI_MEDIUM;

    /*Game loop*/
    while (1) {
        /*Update ball position*/
        ball.x += ball.dx;
        ball.y += ball.dy;

        /*Check if ball hit left or right wall*/
        if (ball.x <= 0 || ball.x >= WIDTH) {
            ball.dx *= -1;
        }

        /*Check if ball hit top or bottom wall*/
        if (ball.y <= 0 || ball.y >= HEIGHT) {
            ball.dy *= -1;
        }

        /*Check if ball hit player paddle*/
        if (ball.x <= player1.x + player1.w && ball.y >= player1.y && ball.y <= player1.y + player1.h) {
            ball.dx *= -1;
        }

        /*Check if ball hit AI paddle*/
        if (ball.x >= ai.x && ball.y >= ai.y && ball.y <= ai.y + ai.h) {
            ball.dx *= -1;
        }

        /*Move AI paddle*/
        if (ai_speed == AI_SLOW) {
            if (ball.y > ai.y + ai.h / 2) {
                ai.y += 1;
            } else if (ball.y < ai.y + ai.h / 2) {
                ai.y -= 1;
            }
        } else if (ai_speed == AI_MEDIUM) {
            if (ball.y > ai.y + ai.h / 2) {
                ai.y += 2;
            } else if (ball.y < ai.y + ai.h / 2) {
                ai.y -= 2;
            }
        } else if (ai_speed == AI_FAST) {
            if (ball.y > ai.y + ai.h / 2) {
                ai.y += 3;
            } else if (ball.y < ai.y + ai.h / 2) {
                ai.y -= 3;
            }
        }

        /*Check if player won*/
        if (ball.x >= WIDTH) {
            printf("Player 1 wins!\n");
            break;
        }

        /*Check if AI won*/
        if (ball.x <= 0) {
            printf("AI wins!\n");
            break;
        }

        /*Draw game*/
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (x == ball.x && y == ball.y) {
                    printf("O");
                } else if (x >= player1.x && x <= player1.x + player1.w && y >= player1.y && y <= player1.y + player1.h) {
                    printf("|");
                } else if (x >= ai.x && x <= ai.x + ai.w && y >= ai.y && y <= ai.y + ai.h) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        /*Sleep for 10 milliseconds*/
        usleep(10000);
    }

    return 0;
}