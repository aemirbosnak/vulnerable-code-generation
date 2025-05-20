//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYERS 4
#define GUESSES 10

struct player {
    int score;
    char name[20];
};

struct game {
    int round;
    int correct;
    int guesses[PLAYERS][GUESSES];
};

int main() {
    struct game g;
    struct player p[PLAYERS];

    // Initialize game and players
    g.round = 1;
    g.correct = 0;
    for (int i = 0; i < PLAYERS; i++) {
        p[i].score = 0;
        strcpy(p[i].name, "Player ");
        p[i].name[strcspn(p[i].name, "")] = 0;
        for (int j = 0; j < GUESSES; j++) {
            g.guesses[i][j] = 0;
        }
    }

    // Start game loop
    while (1) {
        // Display current round and correct answer
        printf("Round %d: Correct answer is %d\n", g.round, g.correct);

        // Get guesses from players
        for (int i = 0; i < PLAYERS; i++) {
            for (int j = 0; j < GUESSES; j++) {
                scanf("%d", &g.guesses[i][j]);
            }
        }

        // Check for correct guesses
        for (int i = 0; i < PLAYERS; i++) {
            for (int j = 0; j < GUESSES; j++) {
                if (g.guesses[i][j] == g.correct) {
                    g.correct++;
                    p[i].score++;
                }
            }
        }

        // Update round and display scores
        g.round++;
        printf("Scores after Round %d:\n", g.round);
        for (int i = 0; i < PLAYERS; i++) {
            printf("Player %d: %d\n", i + 1, p[i].score);
        }

        // Check for game over
        if (g.round > 10) {
            break;
        }
    }

    // Display final scores and end game
    printf("Final Scores:\n");
    for (int i = 0; i < PLAYERS; i++) {
        printf("Player %d: %d\n", i + 1, p[i].score);
    }
    printf("Game Over!\n");

    return 0;
}