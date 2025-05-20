//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_planets, num_civilizations, num_invaders;
    int i, j;
    int **civilizations;
    int **invaders;
    int **results;

    //initialize variables
    srand(time(NULL));
    num_planets = rand() % 1000 + 1;
    num_civilizations = rand() % num_planets + 1;
    num_invaders = rand() % num_civilizations + 1;

    //initialize arrays
    civilizations = (int **)malloc(num_civilizations * sizeof(int *));
    for (i = 0; i < num_civilizations; i++) {
        civilizations[i] = (int *)malloc(num_planets * sizeof(int));
    }
    invaders = (int **)malloc(num_invaders * sizeof(int *));
    for (i = 0; i < num_invaders; i++) {
        invaders[i] = (int *)malloc(num_planets * sizeof(int));
    }
    results = (int **)malloc(num_invaders * sizeof(int *));
    for (i = 0; i < num_invaders; i++) {
        results[i] = (int *)malloc(num_civilizations * sizeof(int));
    }

    //initialize arrays with random values
    for (i = 0; i < num_civilizations; i++) {
        for (j = 0; j < num_planets; j++) {
            civilizations[i][j] = rand() % 1000 + 1;
        }
    }
    for (i = 0; i < num_invaders; i++) {
        for (j = 0; j < num_planets; j++) {
            invaders[i][j] = rand() % 1000 + 1;
        }
    }

    //calculate probability of invasion for each civilization
    for (i = 0; i < num_invaders; i++) {
        for (j = 0; j < num_civilizations; j++) {
            int sum = 0;
            for (int k = 0; k < num_planets; k++) {
                sum += civilizations[j][k] * invaders[i][k];
            }
            results[i][j] = sum / (num_planets * civilizations[j][i]);
        }
    }

    //print results
    for (i = 0; i < num_invaders; i++) {
        for (j = 0; j < num_civilizations; j++) {
            printf("%d ", results[i][j]);
        }
        printf("\n");
    }

    return 0;
}