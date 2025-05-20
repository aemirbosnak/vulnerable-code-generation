//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITY 100

typedef struct {
    int temp;
    int humidity;
    int wind_speed;
    int precipitation;
} Weather;

typedef struct {
    char name[20];
    int x;
    int y;
} City;

Weather weather[MAX_CITY];
City city[MAX_CITY];

int main() {
    int i, j;
    char filename[20];
    FILE *fp;

    // Initialize random seed
    srand(time(NULL));

    // Read city data from file
    sprintf(filename, "city_data.txt");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (i = 0; i < MAX_CITY; i++) {
        fscanf(fp, "%s %d %d", city[i].name, &city[i].x, &city[i].y);
    }
    fclose(fp);

    // Initialize weather data
    for (i = 0; i < MAX_CITY; i++) {
        weather[i].temp = rand() % 41 - 20;
        weather[i].humidity = rand() % 101;
        weather[i].wind_speed = rand() % 21;
        weather[i].precipitation = rand() % 101;
    }

    // Simulate weather changes
    for (i = 0; i < 100; i++) {
        for (j = 0; j < MAX_CITY; j++) {
            weather[j].temp += rand() % 6 - 3;
            weather[j].humidity += rand() % 6 - 3;
            weather[j].wind_speed += rand() % 6 - 3;
            weather[j].precipitation += rand() % 6 - 3;
        }
        printf("\nDay %d\n", i + 1);
        for (j = 0; j < MAX_CITY; j++) {
            printf("City: %s\n", city[j].name);
            printf("Temperature: %d°C\n", weather[j].temp);
            printf("Humidity: %d%%\n", weather[j].humidity);
            printf("Wind Speed: %d m/s\n", weather[j].wind_speed);
            printf("Precipitation: %d mm\n", weather[j].precipitation);
            printf("\n");
        }
    }

    return 0;
}