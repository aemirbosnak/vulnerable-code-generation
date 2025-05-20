//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_TEMPERATURES 100

struct City {
    char name[20];
    int temperature[MAX_TEMPERATURES];
    int current_temperature;
    int humidity;
};

void generate_random_temperature(struct City* city) {
    srand(time(NULL));
    int min_temp = -10;
    int max_temp = 30;
    for (int i = 0; i < MAX_TEMPERATURES; i++) {
        city->temperature[i] = rand() % (max_temp - min_temp + 1) + min_temp;
    }
}

void print_city_info(struct City* city) {
    printf("City name: %s\n", city->name);
    printf("Current temperature: %d\n", city->current_temperature);
    printf("Humidity: %d\n", city->humidity);
    printf("Temperature history:\n");
    for (int i = 0; i < MAX_TEMPERATURES; i++) {
        printf("%d ", city->temperature[i]);
    }
    printf("\n");
}

int main() {
    struct City cities[MAX_CITIES];
    int num_cities;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generate_random_temperature(&cities[i]);
    }

    while (1) {
        for (int i = 0; i < num_cities; i++) {
            int index = rand() % MAX_TEMPERATURES;
            cities[i].current_temperature = cities[i].temperature[index];
        }
        for (int i = 0; i < num_cities; i++) {
            print_city_info(&cities[i]);
        }
        sleep(1);
    }

    return 0;
}