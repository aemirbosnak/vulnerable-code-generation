//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i, j, k, score_player1 = 0, score_player2 = 0, score_ai = 0;
    char player1_name[50], player2_name[50];
    char paddle_name[50];

    printf("Welcome to Pong Game with AI Opponent!\n");
    printf("Please enter your name for Player 1: ");
    scanf("%s", player1_name);
    printf("Please enter your name for Player 2: ");
    scanf("%s", player2_name);

    printf("Let's start the game!\n");

    // Initialize paddles
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        k = rand() % 1000 + 1;
        if (k % 2 == 0) {
            paddle_name[i] = 'X';
        } else {
            paddle_name[i] = 'O';
        }
    }

    // Display paddles
    printf("Player 1: ");
    for (i = 0; i < 10; i++) {
        printf("%c ", paddle_name[i]);
    }
    printf("\nPlayer 2: ");
    for (i = 0; i < 10; i++) {
        printf("%c ", paddle_name[i]);
    }
    printf("\n");

    // Game loop
    while (score_player1 < 3 || score_player2 < 3 || score_ai < 3) {
        // Move paddles
        for (i = 0; i < 10; i++) {
            printf("%c", paddle_name[i]);
        }
        printf("\n");

        // Check for collision
        for (i = 0; i < 10; i++) {
            if (paddle_name[i] == 'X') {
                if (i % 2 == 0) {
                    if (paddle_name[i + 1] == 'O') {
                        score_player1++;
                    }
                } else {
                    if (paddle_name[i - 1] == 'O') {
                        score_player1++;
                    }
                }
            } else if (paddle_name[i] == 'O') {
                if (i % 2 == 0) {
                    if (paddle_name[i + 1] == 'X') {
                        score_player2++;
                    }
                } else {
                    if (paddle_name[i - 1] == 'X') {
                        score_player2++;
                    }
                }
            }
        }

        // AI move
        if (score_ai < 3) {
            k = rand() % 1000 + 1;
            if (k % 2 == 0) {
                for (i = 0; i < 10; i++) {
                    if (paddle_name[i] == 'X') {
                        paddle_name[i] = 'O';
                    } else if (paddle_name[i] == 'O') {
                        paddle_name[i] = 'X';
                    }
                }
            }
        }

        // Display scores
        printf("Player 1: %d\n", score_player1);
        printf("Player 2: %d\n", score_player2);
        printf("AI: %d\n", score_ai);

        // Check for game over
        if (score_player1 == 3 || score_player2 == 3 || score_ai == 3) {
            break;
        }
    }

    // Print final score
    printf("Congratulations!\n");
    printf("Player 1: %d\n", score_player1);
    printf("Player 2: %d\n", score_player2);
    printf("AI: %d\n", score_ai);

    return 0;
}