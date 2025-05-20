//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int wind_speed;
} City;

void generate_random_data(City* cities, int num_cities, int num_days) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        sprintf(cities[i].name, "City %d", i + 1);
    }

    for (int j = 0; j < num_days; j++) {
        for (int k = 0; k < num_cities; k++) {
            cities[k].temperature = rand() % 101;
            cities[k].humidity = rand() % 101;
            cities[k].wind_speed = rand() % 101;
        }
    }
}

void print_city_data(City* cities, int num_cities, int num_days) {
    for (int j = 0; j < num_days; j++) {
        printf("\nDay %d:\n", j + 1);
        for (int k = 0; k < num_cities; k++) {
            printf("City %s: Temperature %d°C, Humidity %d%, Wind Speed %d km/h\n", cities[k].name, cities[k].temperature, cities[k].humidity, cities[k].wind_speed);
        }
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities, num_days;

    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    printf("Enter the number of days (max %d): ", MAX_DAYS);
    scanf("%d", &num_days);

    if (num_cities > MAX_CITIES || num_days > MAX_DAYS) {
        printf("Invalid input. Exiting program.\n");
        return 1;
    }

    generate_random_data(cities, num_cities, num_days);
    print_city_data(cities, num_cities, num_days);

    return 0;
}