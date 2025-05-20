//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct city {
    char name[20];
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
};

void generate_weather(struct city *cities, int num_cities, int start_day, int end_day) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        for (int j = start_day; j <= end_day; j++) {
            int temp = rand() % 41 - 20;
            int humid = rand() % 81;

            cities[i].temperature[j] = temp;
            cities[i].humidity[j] = humid;
        }
    }
}

void print_weather(struct city *cities, int num_cities, int start_day, int end_day) {
    printf("Weather forecast for %d days starting from day %d:\n", end_day - start_day + 1, start_day);

    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);

        for (int j = start_day; j <= end_day; j++) {
            printf("Day %d: Temperature = %d°C, Humidity = %d%%\n", j, cities[i].temperature[j], cities[i].humidity[j]);
        }

        printf("\n");
    }
}

int main() {
    struct city cities[MAX_CITIES];
    int num_cities;

    printf("Enter the number of cities (maximum %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    printf("Enter the names of the cities:\n");

    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    int start_day, end_day;

    printf("Enter the start day (1 to %d): ", MAX_DAYS);
    scanf("%d", &start_day);

    printf("Enter the end day (1 to %d): ", MAX_DAYS);
    scanf("%d", &end_day);

    generate_weather(cities, num_cities, start_day, end_day);
    print_weather(cities, num_cities, start_day, end_day);

    return 0;
}