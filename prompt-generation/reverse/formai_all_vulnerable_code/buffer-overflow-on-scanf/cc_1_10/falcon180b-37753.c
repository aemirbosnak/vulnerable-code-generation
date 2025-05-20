//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int temperature;
    int humidity;
} City;

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];
    int num_cities;
    int num_days;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);

        cities[i].temperature = rand() % 50 + 10;
        cities[i].humidity = rand() % 100;

        printf("City %s has a temperature of %d degrees and a humidity of %d%%\n", cities[i].name, cities[i].temperature, cities[i].humidity);
    }

    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    for (int day = 1; day <= num_days; day++) {
        printf("\nDay %d\n", day);

        for (int i = 0; i < num_cities; i++) {
            printf("City %s has a temperature of %d degrees and a humidity of %d%%\n", cities[i].name, cities[i].temperature, cities[i].humidity);
        }

        for (int i = 0; i < num_cities; i++) {
            cities[i].temperature += rand() % 5 - 2;
            cities[i].humidity += rand() % 10;

            if (cities[i].temperature > 50) {
                cities[i].temperature = 50;
            } else if (cities[i].temperature < 10) {
                cities[i].temperature = 10;
            }

            if (cities[i].humidity > 100) {
                cities[i].humidity = 100;
            } else if (cities[i].humidity < 0) {
                cities[i].humidity = 0;
            }
        }
    }

    return 0;
}