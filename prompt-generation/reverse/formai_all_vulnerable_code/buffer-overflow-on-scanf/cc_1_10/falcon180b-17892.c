//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

struct city {
    char name[20];
    int temperature[MAX_DAYS];
};

void generate_weather(struct city *cities, int num_cities, int num_days) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_days; j++) {
            cities[i].temperature[j] = rand() % 40 + 1; // Temperature between 1 and 40 degrees Celsius
        }
    }
}

void print_weather_report(struct city *cities, int num_cities, int num_days) {
    printf("Weather Report:\n");
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Day 1: %d degrees Celsius\n", cities[i].temperature[0]);
        for (int j = 1; j < num_days; j++) {
            printf("Day %d: %d degrees Celsius\n", j + 1, cities[i].temperature[j]);
        }
        printf("\n");
    }
}

int main() {
    struct city cities[MAX_CITIES];
    int num_cities, num_days;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    printf("Enter the name of each city:\n");
    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    printf("Enter the number of days: ");
    scanf("%d", &num_days);

    generate_weather(cities, num_cities, num_days);
    print_weather_report(cities, num_cities, num_days);

    return 0;
}