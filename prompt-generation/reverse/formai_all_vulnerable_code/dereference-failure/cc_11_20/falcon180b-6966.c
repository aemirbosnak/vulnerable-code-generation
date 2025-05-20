//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define DAYS 7

int main() {
    int weather[ROWS][COLS] = { {0} };
    char weather_str[ROWS][COLS];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            weather[i][j] = rand() % 5;
            switch (weather[i][j]) {
                case 0:
                    strcpy(weather_str[i][j], ".");
                    break;
                case 1:
                    strcpy(weather_str[i][j], "☁");
                    break;
                case 2:
                    strcpy(weather_str[i][j], "☂");
                    break;
                case 3:
                    strcpy(weather_str[i][j], "☀");
                    break;
                case 4:
                    strcpy(weather_str[i][j], "⛅");
                    break;
            }
        }
    }

    for (i = 0; i < DAYS; i++) {
        for (j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                if (weather[j][k] == 0) {
                    weather[j][k] = rand() % 5;
                }
            }
        }
        for (j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                printf("%c", weather_str[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}