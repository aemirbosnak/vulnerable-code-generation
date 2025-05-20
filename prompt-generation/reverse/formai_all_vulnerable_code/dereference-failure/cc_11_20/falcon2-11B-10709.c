//Falcon2-11B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_ALIENS 1000
#define N_SHOTS 10
#define ALIEN_HEALTH 5
#define ALIEN_KILL_RATE 0.1
#define SHOT_HIT_RATE 0.8

int main()
{
    // Initialize variables
    int i, j, k, n_aliens_left, n_shots_left;
    int *shots;
    int *aliens;

    // Allocate memory for shots and aliens
    shots = (int*)malloc(N_SHOTS * sizeof(int));
    aliens = (int*)malloc(N_ALIENS * sizeof(int));

    // Initialize shots and aliens
    for (i = 0; i < N_SHOTS; i++) {
        shots[i] = 1;
    }
    for (i = 0; i < N_ALIENS; i++) {
        aliens[i] = 0;
    }

    // Calculate probability of aliens invading
    srand(time(NULL));
    for (i = 0; i < N_ALIENS; i++) {
        if (rand() % 100 < ALIEN_KILL_RATE) {
            aliens[i] = 1;
        }
    }

    // Simulate battle
    n_aliens_left = 0;
    n_shots_left = N_SHOTS;
    while (n_aliens_left < N_ALIENS && n_shots_left > 0) {
        for (j = 0; j < N_SHOTS; j++) {
            if (shots[j] == 1 && aliens[rand() % N_ALIENS] == 1) {
                shots[j] = 0;
                aliens[rand() % N_ALIENS] = 0;
                n_aliens_left++;
            }
        }
        for (j = 0; j < N_SHOTS; j++) {
            if (shots[j] == 1 && aliens[rand() % N_ALIENS] == 0) {
                shots[j] = 0;
                n_shots_left--;
            }
        }
    }

    // Print results
    printf("Alien Invasion Probability: %d\n", n_aliens_left);
    printf("Number of Shots Left: %d\n", n_shots_left);

    // Free memory
    free(shots);
    free(aliens);

    return 0;
}