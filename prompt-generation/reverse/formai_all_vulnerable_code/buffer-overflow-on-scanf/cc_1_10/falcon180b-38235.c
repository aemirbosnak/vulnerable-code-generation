//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
    int precipitation[MAX_DAYS];
} City;

City cities[MAX_CITIES];

void generate_weather(City* city) {
    for (int i = 0; i < MAX_DAYS; i++) {
        city->temperature[i] = rand() % 50 + 10;
        city->humidity[i] = rand() % 80 + 20;
        city->precipitation[i] = rand() % 10 + 1;
    }
}

void print_city_weather(City* city) {
    printf("City: %s\n", city->name);
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: Temperature = %d, Humidity = %d, Precipitation = %d\n", i+1, city->temperature[i], city->humidity[i], city->precipitation[i]);
    }
}

int main() {
    srand(time(NULL));

    int num_cities;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generate_weather(&cities[i]);
    }

    int city_index;
    printf("Enter the city index: ");
    scanf("%d", &city_index);

    if (city_index >= 0 && city_index < num_cities) {
        print_city_weather(&cities[city_index]);
    } else {
        printf("Invalid city index.\n");
    }

    return 0;
}