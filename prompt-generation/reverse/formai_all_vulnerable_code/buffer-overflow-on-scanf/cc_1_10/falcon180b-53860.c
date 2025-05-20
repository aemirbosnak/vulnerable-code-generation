//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_TEMPS 50

struct city {
    char name[20];
    int population;
    int temperature[MAX_TEMPS];
    int precipitation[MAX_TEMPS];
};

void generate_weather(struct city *cities, int num_cities, int num_temps) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_temps; j++) {
            cities[i].temperature[j] = rand() % 100;
            cities[i].precipitation[j] = rand() % 100;
        }
    }
}

void print_weather(struct city *cities, int num_cities, int num_temps) {
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Population: %d\n", cities[i].population);
        for (int j = 0; j < num_temps; j++) {
            printf("Temperature on day %d: %d degrees\n", j + 1, cities[i].temperature[j]);
            printf("Precipitation on day %d: %d mm\n", j + 1, cities[i].precipitation[j]);
        }
        printf("\n");
    }
}

int main() {
    struct city cities[MAX_CITIES];
    int num_cities, num_temps;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        printf("Enter the population of city %s: ", cities[i].name);
        scanf("%d", &cities[i].population);
    }

    printf("Enter the number of days to simulate weather for: ");
    scanf("%d", &num_temps);

    generate_weather(cities, num_cities, num_temps);
    print_weather(cities, num_cities, num_temps);

    return 0;
}