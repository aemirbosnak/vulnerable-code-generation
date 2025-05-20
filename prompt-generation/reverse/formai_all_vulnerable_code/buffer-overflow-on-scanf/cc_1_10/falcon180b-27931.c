//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

struct City {
    char name[20];
    int temperature[MAX_DAYS];
};

void generate_weather(struct City *cities, int num_cities, int num_days) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_days; j++) {
            cities[i].temperature[j] = rand() % 101 - 50;
        }
    }
}

void print_weather(struct City *cities, int num_cities, int num_days) {
    for (int i = 0; i < num_cities; i++) {
        printf("Weather in %s for the next %d days:\n", cities[i].name, num_days);

        for (int j = 0; j < num_days; j++) {
            printf("%d degrees Celsius\n", cities[i].temperature[j]);
        }

        printf("\n");
    }
}

int main() {
    struct City cities[MAX_CITIES];

    int num_cities, num_days;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    printf("Enter the number of days to generate weather for: ");
    scanf("%d", &num_days);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    generate_weather(cities, num_cities, num_days);
    print_weather(cities, num_cities, num_days);

    return 0;
}