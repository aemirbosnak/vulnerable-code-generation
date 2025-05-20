//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 30

enum WEATHER {
    SUNNY,
    RAINY,
    CLOUDY,
    THUNDERSTORM,
    HURRICANE,
    TORNADO
};

struct City {
    char name[20];
    float temperature;
    enum WEATHER weather;
};

void generateWeather(struct City *cities, int numCities, int day) {
    for (int i = 0; i < numCities; i++) {
        float temp = rand() % 30 + 1;
        enum WEATHER weather = (enum WEATHER) rand() % 6;

        switch (weather) {
            case SUNNY:
                printf("City %s is experiencing sunny weather with a temperature of %.2f degrees Celsius.\n", cities[i].name, temp);
                break;
            case RAINY:
                printf("City %s is experiencing rainy weather with a temperature of %.2f degrees Celsius.\n", cities[i].name, temp);
                break;
            case CLOUDY:
                printf("City %s is experiencing cloudy weather with a temperature of %.2f degrees Celsius.\n", cities[i].name, temp);
                break;
            case THUNDERSTORM:
                printf("City %s is experiencing a thunderstorm with a temperature of %.2f degrees Celsius.\n", cities[i].name, temp);
                break;
            case HURRICANE:
                printf("City %s is experiencing a hurricane with a temperature of %.2f degrees Celsius.\n", cities[i].name, temp);
                break;
            case TORNADO:
                printf("City %s is experiencing a tornado with a temperature of %.2f degrees Celsius.\n", cities[i].name, temp);
                break;
        }

        cities[i].temperature = temp;
        cities[i].weather = weather;
    }
}

int main() {
    srand(time(NULL));

    struct City cities[NUM_CITIES];

    for (int i = 0; i < NUM_CITIES; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);

        cities[i].temperature = rand() % 30 + 1;
        cities[i].weather = (enum WEATHER) rand() % 6;
    }

    for (int day = 1; day <= NUM_DAYS; day++) {
        printf("\nDay %d\n", day);

        for (int i = 0; i < NUM_CITIES; i++) {
            generateWeather(cities, NUM_CITIES, day);
        }
    }

    return 0;
}