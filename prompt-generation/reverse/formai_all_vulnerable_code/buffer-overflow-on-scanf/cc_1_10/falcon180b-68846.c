//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int pressure;
} City;

void generate_weather_data(City cities[], int num_cities, int start_day) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        for (int j = start_day; j < start_day + MAX_DAYS; j++) {
            cities[i].temperature = rand() % 301 - 150;
            cities[i].humidity = rand() % 101;
            cities[i].pressure = rand() % 101;
        }
    }
}

void print_weather_data(City cities[], int num_cities, int start_day, int end_day) {
    for (int i = 0; i < num_cities; i++) {
        printf("Weather data for %s:\n", cities[i].name);
        for (int j = start_day; j <= end_day; j++) {
            printf("Day %d: Temperature = %d, Humidity = %d, Pressure = %d\n", j, cities[i].temperature, cities[i].humidity, cities[i].pressure);
        }
        printf("\n");
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    int start_day, end_day;

    printf("Enter the start day (1-365): ");
    scanf("%d", &start_day);
    printf("Enter the end day (1-365): ");
    scanf("%d", &end_day);

    generate_weather_data(cities, num_cities, start_day);
    print_weather_data(cities, num_cities, start_day, end_day);

    return 0;
}