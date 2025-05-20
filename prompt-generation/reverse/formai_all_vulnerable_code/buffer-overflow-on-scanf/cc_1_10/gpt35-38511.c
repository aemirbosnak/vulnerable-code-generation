//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to clear the console screen
void clearScreen() {
    system("clear");
}

// simple function to get a random number
int getRandomNumber(int max) {
    srand(time(NULL));
    return rand() % max;
}

// structure to represent a ball
typedef struct ball {
    int x, y;
    int xVelocity, yVelocity;
} Ball;

// structure to represent a paddle
typedef struct paddle {
    int x, y;
    int width, height;
} Paddle;

// function to move the ball
void moveBall(Ball* ball, Paddle* player, Paddle* computer) {
    ball->x += ball->xVelocity;
    ball->y += ball->yVelocity;

    // if the ball hits the top or bottom of the screen, reverse the y velocity
    if ((ball->y < 0) || (ball->y > 23)) {
        ball->yVelocity *= -1;
    }

    // if the ball hits the player paddle, reverse the x velocity and adjust the y velocity based on where the ball hit the paddle
    if ((ball->x == player->x + player->width) && (ball->y >= player->y) && (ball->y <= player->y + player->height)) {
        ball->xVelocity *= -1;
        ball->yVelocity += getRandomNumber(3) - 1;
    }

    // if the ball hits the computer paddle, reverse the x velocity and adjust the y velocity based on where the ball hit the paddle
    if ((ball->x == computer->x) && (ball->y >= computer->y) && (ball->y <= computer->y + computer->height)) {
        ball->xVelocity *= -1;
        ball->yVelocity += getRandomNumber(3) - 1;
    }
}

// function to move the player paddle
void movePlayer(Paddle* player) {
    char input = ' ';
    while ((input != 'w') && (input != 's')) {
        printf("Move paddle up (w) or down (s): ");
        scanf("%c", &input);
        getchar();
    }

    if ((input == 'w') && (player->y > 0)) {
        player->y--;
    } else if ((input == 's') && (player->y < 23)) {
        player->y++;
    }
}

// function to move the computer paddle
void moveComputer(Paddle* computer, Ball* ball) {
    if (ball->y < computer->y) {
        computer->y--;
    } else if (ball->y > computer->y + computer->height) {
        computer->y++;
    }
}

// function to draw the game board
void draw(Paddle player, Paddle computer, Ball ball) {
    clearScreen();
    printf("+----------+\n");
    for (int y = 0; y < 24; y++) {
        printf("|");
        for (int x = 0; x < 10; x++) {
            if ((x == player.x + player.width) && (y >= player.y) && (y <= player.y + player.height)) {
                printf("=");
            } else if ((x == computer.x) && (y >= computer.y) && (y <= computer.y + computer.height)) {
                printf("=");
            } else if ((x == ball.x) && (y == ball.y)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("+----------+\n");
}

int main() {
    Ball ball = {5, 12, 1, 1};
    Paddle player = {1, 11, 1, 3};
    Paddle computer = {8, 11, 1, 3};

    // main game loop
    while (true) {
        movePlayer(&player);
        moveComputer(&computer, &ball);
        moveBall(&ball, &player, &computer);
        draw(player, computer, ball);
    }

    return 0;
}