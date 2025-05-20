//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct City {
    char name[20];
    int temperature;
};

struct Day {
    int day;
    struct City cities[MAX_CITIES];
};

void generate_random_weather(struct City *city) {
    srand(time(NULL));
    city->temperature = rand() % 101;
}

void print_weather(struct City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d\n", city.temperature);
}

int main() {
    int num_cities, num_days;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);
    printf("Enter the number of days: ");
    scanf("%d", &num_days);

    struct City cities[num_cities];
    for (int i = 0; i < num_cities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generate_random_weather(&cities[i]);
    }

    struct Day days[num_days];
    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_cities; j++) {
            days[i].cities[j] = cities[j];
        }
        days[i].day = i + 1;
    }

    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_cities; j++) {
            print_weather(days[i].cities[j]);
        }
    }

    return 0;
}