//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

struct City {
    char name[32];
    int temperature;
    int humidity;
};

void init_cities(struct City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        cities[i].temperature = rand() % 101;
        cities[i].humidity = rand() % 101;
        sprintf(cities[i].name, "City %d", i + 1);
    }
}

void print_city(const struct City *city) {
    printf("%.32s: Temperature %d°C, Humidity %d%%\n", city->name, city->temperature, city->humidity);
}

void print_cities(const struct City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        print_city(&cities[i]);
    }
}

int main() {
    srand(time(NULL));

    int num_cities;
    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    struct City cities[num_cities];
    init_cities(cities, num_cities);

    while (1) {
        system("clear");
        print_cities(cities, num_cities);
        printf("\nPress enter to update weather conditions...\n");
        getchar();

        for (int i = 0; i < num_cities; i++) {
            cities[i].temperature = rand() % 101;
            cities[i].humidity = rand() % 101;
        }
    }

    return 0;
}