//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int temperature;
    int humidity;
} City;

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];
    int num_cities = 0;

    printf("Welcome to the Weather Simulation!\n");
    printf("How many cities do you want to simulate? ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);

        cities[i].temperature = rand() % 41 - 20;
        cities[i].humidity = rand() % 81;

        printf("Initial weather for %s: Temperature = %d, Humidity = %d\n", cities[i].name, cities[i].temperature, cities[i].humidity);
    }

    int day = 1;
    while (day <= MAX_DAYS) {
        printf("\nDay %d\n", day);

        for (int i = 0; i < num_cities; i++) {
            int temp_change = rand() % 6 - 3;
            cities[i].temperature += temp_change;

            if (cities[i].temperature < 0) {
                cities[i].temperature = 0;
            }

            int humidity_change = rand() % 6 - 3;
            cities[i].humidity += humidity_change;

            if (cities[i].humidity < 0) {
                cities[i].humidity = 0;
            }

            printf("City: %s, Temperature: %d, Humidity: %d\n", cities[i].name, cities[i].temperature, cities[i].humidity);
        }

        day++;
    }

    return 0;
}