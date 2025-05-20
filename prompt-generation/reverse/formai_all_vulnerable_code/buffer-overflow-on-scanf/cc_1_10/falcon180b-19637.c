//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITY 10
#define MAX_DAY 30

struct city {
    char name[20];
    int temperature[MAX_DAY];
    int humidity[MAX_DAY];
};

void init_weather(struct city *cities, int num_cities) {
    int i, j;
    for (i = 0; i < num_cities; i++) {
        for (j = 0; j < MAX_DAY; j++) {
            cities[i].temperature[j] = rand() % 31 + 1;
            cities[i].humidity[j] = rand() % 101;
        }
    }
}

void print_weather(struct city *cities, int num_cities, int day) {
    int i;
    printf("Day %d weather forecast:\n", day);
    for (i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d\n", cities[i].temperature[day % MAX_DAY]);
        printf("Humidity: %d\n\n", cities[i].humidity[day % MAX_DAY]);
    }
}

int main() {
    int num_cities, day;
    struct city cities[MAX_CITY];

    printf("Enter number of cities: ");
    scanf("%d", &num_cities);

    printf("Enter city names:\n");
    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    init_weather(cities, num_cities);

    while (1) {
        printf("Enter day to forecast (0 to exit): ");
        scanf("%d", &day);

        if (day == 0) {
            break;
        }

        print_weather(cities, num_cities, day);
    }

    return 0;
}