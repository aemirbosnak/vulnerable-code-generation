//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct city {
    char name[20];
    int temperature;
    int humidity;
};

struct city create_city(char *name) {
    struct city city;
    strcpy(city.name, name);
    city.temperature = rand() % 41 - 20;
    city.humidity = rand() % 81;
    return city;
}

void print_city(struct city city) {
    printf("%s: Temperature %d°C, Humidity %d%%\n", city.name, city.temperature, city.humidity);
}

int main() {
    srand(time(NULL));

    struct city cities[MAX_CITIES];
    int num_cities = 0;

    while (num_cities < MAX_CITIES) {
        char input[50];
        printf("Enter a city name (or leave blank to finish): ");
        scanf("%s", input);

        if (strcmp(input, "")!= 0) {
            cities[num_cities] = create_city(input);
            num_cities++;
        }
    }

    int day = 0;
    while (day < MAX_DAYS) {
        for (int i = 0; i < num_cities; i++) {
            cities[i].temperature += rand() % 6 - 3;
            cities[i].humidity += rand() % 6 - 3;

            if (cities[i].temperature > 40) {
                cities[i].temperature = 40;
            } else if (cities[i].temperature < -20) {
                cities[i].temperature = -20;
            }

            if (cities[i].humidity > 80) {
                cities[i].humidity = 80;
            } else if (cities[i].humidity < 20) {
                cities[i].humidity = 20;
            }
        }

        printf("Day %d:\n", day + 1);
        for (int i = 0; i < num_cities; i++) {
            print_city(cities[i]);
        }

        day++;
    }

    return 0;
}