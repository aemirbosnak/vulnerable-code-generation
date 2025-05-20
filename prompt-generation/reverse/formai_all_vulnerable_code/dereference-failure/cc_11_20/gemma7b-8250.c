//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, l, n, m;
    char **weather_map;
    time_t t;
    srand(time(NULL));

    n = 10;
    m = 10;
    weather_map = (char **)malloc(n * sizeof(char *) + m * sizeof(char));
    for (i = 0; i < n; i++) {
        weather_map[i] = (char *)malloc(m * sizeof(char));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            weather_map[i][j] = ' ';
        }
    }

    t = time(NULL);
    for (k = 0; k < 100; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (rand() % 2 == 0) {
                    weather_map[i][j] = 'H';
                } else if (rand() % 3 == 0) {
                    weather_map[i][j] = 'C';
                } else if (rand() % 4 == 0) {
                    weather_map[i][j] = 'R';
                }
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%c ", weather_map[i][j]);
            }
            printf("\n");
        }

        sleep(1);
    }

    for (i = 0; i < n; i++) {
        free(weather_map[i]);
    }
    free(weather_map);

    return 0;
}