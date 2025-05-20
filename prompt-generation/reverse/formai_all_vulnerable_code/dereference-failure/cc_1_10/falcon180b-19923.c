//Falcon-180B DATASET v1.0 Category: Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10 // number of players
#define M 100 // maximum number of rounds
#define P 0.5 // probability of winning a round
#define Q 0.1 // probability of losing a round
#define R 0.4 // probability of drawing a round

int main() {
    int i, j, k, n, m, p, q, r, s, t;
    double pi, x, y, z, a, b, c;
    double sum, avg, var, sd, cv;
    double *wins, *losses, *draws;

    srand(time(NULL));

    wins = (double *) malloc(N * sizeof(double));
    losses = (double *) malloc(N * sizeof(double));
    draws = (double *) malloc(N * sizeof(double));

    for (i = 0; i < N; i++) {
        wins[i] = 0;
        losses[i] = 0;
        draws[i] = 0;
    }

    for (m = 0; m < M; m++) {
        for (i = 0; i < N - 1; i++) {
            j = i + 1;
            x = rand() % 100;
            if (x <= P) {
                wins[i]++;
                losses[j]++;
            } else if (x <= P + Q) {
                losses[i]++;
                wins[j]++;
            } else {
                wins[i]++;
                losses[j]++;
                draws[i]++;
                draws[j]++;
            }
        }
    }

    for (i = 0; i < N; i++) {
        printf("Player %d: Wins = %d, Losses = %d, Draws = %d\n", i + 1, wins[i], losses[i], draws[i]);
    }

    free(wins);
    free(losses);
    free(draws);

    return 0;
}