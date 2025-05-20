//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_WEATHER_TYPES 4

typedef struct {
    char name[20];
    int x;
    int y;
    int weather_type;
} City;

void generate_weather(City cities[NUM_CITIES]) {
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_CITIES; i++) {
        int rand_weather = rand() % NUM_WEATHER_TYPES;
        switch (rand_weather) {
            case 0:
                cities[i].weather_type = "Sunny";
                break;
            case 1:
                cities[i].weather_type = "Rainy";
                break;
            case 2:
                cities[i].weather_type = "Cloudy";
                break;
            case 3:
                cities[i].weather_type = "Stormy";
                break;
        }
    }
}

void print_weather(City cities[NUM_CITIES]) {
    int i;
    for (i = 0; i < NUM_CITIES; i++) {
        printf("%s: %s\n", cities[i].name, cities[i].weather_type);
    }
}

int main() {
    City cities[NUM_CITIES];
    int i;
    for (i = 0; i < NUM_CITIES; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        printf("Enter city coordinates (x,y): ");
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }
    generate_weather(cities);
    print_weather(cities);
    return 0;
}