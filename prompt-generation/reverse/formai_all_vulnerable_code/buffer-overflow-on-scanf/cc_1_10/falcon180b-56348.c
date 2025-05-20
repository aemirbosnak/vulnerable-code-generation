//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define WEATHER_TYPES 5

// Weather types
#define SUNNY 0
#define CLOUDY 1
#define RAINY 2
#define SNOWY 3
#define STORMY 4

struct City {
    char name[20];
    int weather;
};

void init_cities(struct City* cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        cities[i].weather = SUNNY;
        strcpy(cities[i].name, "City ");
        int len = strlen(cities[i].name);
        cities[i].name[len] = '0' + i;
    }
}

void print_cities(struct City* cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("%s: ", cities[i].name);
        switch (cities[i].weather) {
            case SUNNY:
                printf("Sunny\n");
                break;
            case CLOUDY:
                printf("Cloudy\n");
                break;
            case RAINY:
                printf("Rainy\n");
                break;
            case SNOWY:
                printf("Snowy\n");
                break;
            case STORMY:
                printf("Stormy\n");
                break;
            default:
                printf("Unknown weather\n");
        }
    }
}

void update_weather(struct City* cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        int rand_num = rand() % WEATHER_TYPES;
        cities[i].weather = rand_num;
    }
}

int main() {
    struct City cities[MAX_CITIES];
    int num_cities;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    if (num_cities > MAX_CITIES || num_cities < 1) {
        printf("Invalid number of cities\n");
        return 1;
    }

    init_cities(cities, num_cities);

    while (1) {
        print_cities(cities, num_cities);
        update_weather(cities, num_cities);
        sleep(1);
    }

    return 0;
}