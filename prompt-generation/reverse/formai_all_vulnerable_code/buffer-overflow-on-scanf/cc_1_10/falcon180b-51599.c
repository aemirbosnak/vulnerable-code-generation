//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[50];
    int temperature;
    int humidity;
    int wind_speed;
} City;

void generate_random_city(City* city) {
    city->temperature = rand() % 100;
    city->humidity = rand() % 100;
    city->wind_speed = rand() % 50;
}

void print_city(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d\n", city.temperature);
    printf("Humidity: %d\n", city.humidity);
    printf("Wind Speed: %d\n", city.wind_speed);
    printf("\n");
}

void simulate_weather(City* cities, int num_cities, int num_days) {
    int i, j;
    for (i = 0; i < num_cities; i++) {
        generate_random_city(&cities[i]);
    }
    for (j = 0; j < num_days; j++) {
        for (i = 0; i < num_cities; i++) {
            cities[i].temperature += rand() % 10 - 5;
            cities[i].humidity += rand() % 10;
            cities[i].wind_speed += rand() % 10;
        }
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities, num_days;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
    }

    simulate_weather(cities, num_cities, num_days);

    for (int i = 0; i < num_cities; i++) {
        print_city(cities[i]);
    }

    return 0;
}