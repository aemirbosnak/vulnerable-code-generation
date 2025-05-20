//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAD_WIDTH 20
#define PAD_HEIGHT 100
#define PADDLE_SPEED 5

int main() {
    srand(time(NULL));

    int playerScore = 0;
    int aiScore = 0;

    printf("Welcome to Pong Game!\n");
    printf("Please choose the difficulty level (1-5): ");
    int difficulty;
    scanf("%d", &difficulty);

    if (difficulty == 1) {
        printf("Easy Mode\n");
        printf("Starting the game...\n");
    } else if (difficulty == 2) {
        printf("Medium Mode\n");
        printf("Starting the game...\n");
    } else if (difficulty == 3) {
        printf("Hard Mode\n");
        printf("Starting the game...\n");
    } else if (difficulty == 4) {
        printf("Insane Mode\n");
        printf("Starting the game...\n");
    } else if (difficulty == 5) {
        printf("God Mode\n");
        printf("Starting the game...\n");
    } else {
        printf("Invalid difficulty level\n");
        return 0;
    }

    int playerX = PAD_WIDTH / 2 - 5;
    int playerY = PAD_HEIGHT - 10;
    int aiX = PAD_WIDTH / 2 + 5;
    int aiY = PAD_HEIGHT - 10;

    int ballX = (PAD_WIDTH - 10) / 2;
    int ballY = (PAD_HEIGHT - 10) / 2;

    int ballSpeedX = 2;
    int ballSpeedY = 2;

    int score = 0;

    while (score < 11) {
        printf("Ball: (%d, %d)\n", ballX, ballY);
        printf("Player: (%d, %d)\n", playerX, playerY);
        printf("AI: (%d, %d)\n", aiX, aiY);

        if (ballX <= 0 || ballX >= PAD_WIDTH - 10 || ballY <= 0 || ballY >= PAD_HEIGHT - 10) {
            ballSpeedX = -ballSpeedX;
            ballSpeedY = -ballSpeedY;
        }

        if (playerX <= 0) {
            playerX = 0;
            ballSpeedY = -ballSpeedY;
        } else if (playerX >= PAD_WIDTH - 10) {
            playerX = PAD_WIDTH - 10;
            ballSpeedY = -ballSpeedY;
        }

        if (aiX <= 0) {
            aiX = 0;
            ballSpeedY = -ballSpeedY;
        } else if (aiX >= PAD_WIDTH - 10) {
            aiX = PAD_WIDTH - 10;
            ballSpeedY = -ballSpeedY;
        }

        if (ballX < playerX && ballX > playerX - 5 && ballY < playerY && ballY > playerY - 5) {
            score++;
            playerX = PAD_WIDTH / 2 - 5;
            playerY = PAD_HEIGHT - 10;
            ballSpeedX = -ballSpeedX;
            ballSpeedY = -ballSpeedY;
        } else if (ballX < aiX && ballX > aiX - 5 && ballY < aiY && ballY > aiY - 5) {
            score++;
            aiX = PAD_WIDTH / 2 + 5;
            aiY = PAD_HEIGHT - 10;
            ballSpeedX = -ballSpeedX;
            ballSpeedY = -ballSpeedY;
        } else {
            ballX += ballSpeedX;
            ballY += ballSpeedY;
        }

        printf("Score: Player - %d, AI - %d\n", playerScore, aiScore);
        printf("Ball: (%d, %d)\n", ballX, ballY);
        printf("Player: (%d, %d)\n", playerX, playerY);
        printf("AI: (%d, %d)\n", aiX, aiY);

        if (playerScore == 5 || aiScore == 5) {
            printf("Game Over!\n");
            printf("Player Score: %d\n", playerScore);
            printf("AI Score: %d\n", aiScore);
            break;
        }

        usleep(10000); // Delay for 10 milliseconds
    }

    return 0;
}