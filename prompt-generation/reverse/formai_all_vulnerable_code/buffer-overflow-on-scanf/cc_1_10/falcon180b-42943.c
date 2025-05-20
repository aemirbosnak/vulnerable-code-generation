//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

typedef struct {
    char name[20];
    int temperature;
} City;

void generate_random_weather(City* cities, int num_cities, int num_days) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_days; j++) {
            cities[i].temperature = rand() % 40 - 20;
        }
    }
}

void print_weather_forecast(City* cities, int num_cities, int num_days) {
    printf("Weather Forecast:\n");

    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);

        for (int j = 0; j < num_days; j++) {
            printf("Day %d: %d degrees Celsius\n", j + 1, cities[i].temperature);
        }

        printf("\n");
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities, num_days;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    printf("Enter the number of days: ");
    scanf("%d", &num_days);

    generate_random_weather(cities, num_cities, num_days);
    print_weather_forecast(cities, num_cities, num_days);

    return 0;
}