//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_STARS 100000000
#define ALIEN_PROB 0.000001
#define EARTH_X 7
#define EARTH_Y 3

typedef struct {
    int x, y;
} star_t;

star_t stars[MAX_STARS];

void init_stars() {
    int i;
    for (i = 0; i < MAX_STARS; i++) {
        stars[i].x = (int)(RAND_MAX * rand() / (RAND_MAX + 1.0) * MAX_STARS);
        stars[i].y = (int)(RAND_MAX * rand() / (RAND_MAX + 1.0) * MAX_STARS);
    }
}

int is_earth_nearby(int x, int y) {
    return (abs(EARTH_X - x) < 10 && abs(EARTH_Y - y) < 10);
}

int main() {
    int i, invaded = 0, total_stars = 0;
    double invasion_rate;

    srand(time(NULL));
    init_stars();

    while (1) {
        for (i = 0; i < MAX_STARS; i++) {
            if (is_earth_nearby(stars[i].x, stars[i].y)) {
                invaded++;
                printf("Aliens have invaded Earth!\n");
                break;
            }
            total_stars++;
        }
        if (invaded) break;

        invasion_rate = invaded * ALIEN_PROB / total_stars;
        printf("Invasion rate: %.12f\n", invasion_rate);
        sleep(1);
    }

    printf("Game over. Earth has been invaded.\n");
    return 0;
}