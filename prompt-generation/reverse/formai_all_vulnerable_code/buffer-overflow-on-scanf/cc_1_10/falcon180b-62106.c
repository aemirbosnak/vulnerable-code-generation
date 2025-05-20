//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365
#define MIN_TEMP -20
#define MAX_TEMP 50
#define MIN_RAIN 0
#define MAX_RAIN 100

typedef struct {
    char name[20];
    int temp;
    int rain;
} City;

void generate_cities(City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        sprintf(cities[i].name, "City_%d", i + 1);
        cities[i].temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        cities[i].rain = rand() % (MAX_RAIN - MIN_RAIN + 1) + MIN_RAIN;
    }
}

void print_cities(City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("%s: Temperature %d, Rainfall %d\n", cities[i].name, cities[i].temp, cities[i].rain);
    }
}

void simulate_weather(City cities[], int num_cities, int num_days) {
    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_days; j++) {
            cities[i].temp += rand() % 5 - 2;
            cities[i].rain += rand() % 10;
        }
    }
}

int main() {
    srand(time(NULL));
    City cities[MAX_CITIES];
    int num_cities;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    if (num_cities > MAX_CITIES) {
        printf("Error: Number of cities cannot exceed %d\n", MAX_CITIES);
        return 1;
    }

    printf("Enter the names of the cities:\n");
    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    generate_cities(cities, num_cities);
    print_cities(cities, num_cities);

    printf("Simulating weather for %d days...\n", MAX_DAYS);
    simulate_weather(cities, num_cities, MAX_DAYS);

    printf("Weather simulation complete!\n");

    return 0;
}