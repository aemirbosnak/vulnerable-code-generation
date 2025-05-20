//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TRIALS 1000000
#define NUM_ALIENS 10
#define NUM_CITIES 100
#define CITY_SIZE 10000
#define ALIEN_SIZE 500

int main() {
    srand(time(NULL));

    int num_cities_destroyed = 0;

    for (int i = 0; i < NUM_TRIALS; i++) {
        int num_aliens_landed = 0;
        int num_aliens_destroyed = 0;

        int **cities = (int **)malloc(NUM_CITIES * sizeof(int *));
        for (int j = 0; j < NUM_CITIES; j++) {
            cities[j] = (int *)malloc(CITY_SIZE * sizeof(int));
            for (int k = 0; k < CITY_SIZE; k++) {
                cities[j][k] = rand() % 2;
            }
        }

        for (int j = 0; j < NUM_ALIENS; j++) {
            int x = rand() % NUM_CITIES;
            int y = rand() % CITY_SIZE;

            if (cities[x][y] == 0) {
                num_aliens_landed++;
                cities[x][y] = 1;
            }
        }

        for (int j = 0; j < NUM_CITIES; j++) {
            for (int k = 0; k < CITY_SIZE; k++) {
                if (cities[j][k] == 1) {
                    for (int l = 0; l < NUM_ALIENS; l++) {
                        int x = rand() % NUM_CITIES;
                        int y = rand() % CITY_SIZE;

                        if (cities[x][y] == 0) {
                            cities[x][y] = 1;
                            num_aliens_destroyed++;
                        }
                    }
                }
            }
        }

        if (num_aliens_landed == NUM_ALIENS) {
            num_cities_destroyed++;
        }

        for (int j = 0; j < NUM_CITIES; j++) {
            free(cities[j]);
        }
        free(cities);
    }

    double probability = ((double)num_cities_destroyed / NUM_TRIALS) * 100;

    printf("The probability of alien invasion is %.2f%%\n", probability);

    return 0;
}