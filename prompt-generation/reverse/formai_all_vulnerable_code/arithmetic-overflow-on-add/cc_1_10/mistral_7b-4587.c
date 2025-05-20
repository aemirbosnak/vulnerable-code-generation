//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERONA_TEMP_MIN -5
#define VERONA_TEMP_MAX 25
#define VERONA_RANDOM_FACTOR 5

typedef enum { SUNNY, CLOUDY, RAINY, SNOWY } Weather;

void GenerateWeather(int *day, int *month, int *temp) {
    time_t rawtime;
    struct tm *timeinfo;
    char time_string[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    *day = timeinfo->tm_mday;
    *month = timeinfo->tm_mon + 1;

    *temp = rand() % (VERONA_TEMP_MAX - VERONA_TEMP_MIN + VERONA_RANDOM_FACTOR) + VERONA_TEMP_MIN;
}

void PrintWeather(Weather weather) {
    switch (weather) {
        case SUNNY:
            printf("'Tis a fine day in fair Verona,\n");
            printf("Where we lay our scene,\n");
            printf("And in this hot and sticky clime,\n");
            printf("Our love shall bloom as the bright sun shines.\n");
            break;
        case CLOUDY:
            printf("The grey clouds gather overhead,\n");
            printf("And the wind whispers tales of woe,\n");
            printf("But our love shall not be swayed,\n");
            printf("For it burns with the passion of the sun.\n");
            break;
        case RAINY:
            printf("The rain pours down in torrents,\n");
            printf("And the thunder roars through the night,\n");
            printf("But our love shall not falter,\n");
            printf("For it is stronger than the mightiest storm.\n");
            break;
        case SNOWY:
            printf("The snow falls gently on Verona,\n");
            printf("And the world is hushed in a blanket of white,\n");
            printf("But our love shall not be hidden,\n");
            printf("For it shines as bright as the morning sun.\n");
            break;
        default:
            printf("Invalid weather type.\n");
    }
}

int main() {
    int day, month, temp;
    Weather weather;

    GenerateWeather(&day, &month, &temp);
    srand(time(NULL));

    if (temp > 15) {
        weather = SUNNY;
    } else if (rand() % 2) {
        weather = CLOUDY;
    } else {
        if (month < 3 || month > 9) {
            weather = RAINY;
        } else {
            weather = SNOWY;
        }
    }

    PrintWeather(weather);

    return 0;
}