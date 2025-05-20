//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITY 100
#define MAX_DAY 30
#define MIN_TEMP -50
#define MAX_TEMP 50
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 100

typedef struct {
    char name[20];
    int temp;
    int humidity;
    int wind_speed;
} City;

void generate_city(City *city) {
    city->temp = rand() % MAX_TEMP + MIN_TEMP;
    city->humidity = rand() % MAX_HUMIDITY + MIN_HUMIDITY;
    city->wind_speed = rand() % MAX_WIND_SPEED + MIN_WIND_SPEED;
}

void print_city(City *city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d°C\n", city->temp);
    printf("Humidity: %d%%\n", city->humidity);
    printf("Wind Speed: %d km/h\n\n", city->wind_speed);
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITY];
    int num_cities = 0;

    printf("Weather Simulation\n\n");

    while (num_cities < MAX_CITY) {
        printf("Enter city name (or type 'q' to quit): ");
        scanf("%s", cities[num_cities].name);

        if (strcmp(cities[num_cities].name, "q") == 0) {
            break;
        }

        num_cities++;
    }

    printf("\nEnter number of days to simulate (1-30): ");
    int num_days;
    scanf("%d", &num_days);

    for (int i = 0; i < num_cities; i++) {
        printf("\nCity %d: %s\n", i+1, cities[i].name);
        print_city(&cities[i]);
    }

    for (int day = 1; day <= num_days; day++) {
        printf("\nDay %d:\n", day);

        for (int i = 0; i < num_cities; i++) {
            generate_city(&cities[i]);
            print_city(&cities[i]);
        }

        printf("\n\n");
    }

    return 0;
}