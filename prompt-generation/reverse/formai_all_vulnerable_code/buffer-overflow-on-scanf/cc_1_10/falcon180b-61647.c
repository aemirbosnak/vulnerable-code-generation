//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[30];
    float temperature;
    float humidity;
} City;

void generate_weather(City* cities, int num_cities, int day) {
    srand(time(0));
    for (int i = 0; i < num_cities; i++) {
        cities[i].temperature = rand() % 41 - 20;
        cities[i].humidity = rand() % 101;
    }
}

void print_weather(City* cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("%s: %.2f°C, %.2f%% humidity\n", cities[i].name, cities[i].temperature, cities[i].humidity);
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities;
    printf("Enter number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
    }

    int num_days;
    printf("Enter number of days to simulate: ");
    scanf("%d", &num_days);

    for (int day = 1; day <= num_days; day++) {
        generate_weather(cities, num_cities, day);
        printf("Day %d:\n", day);
        print_weather(cities, num_cities);
        printf("\n");
    }

    return 0;
}