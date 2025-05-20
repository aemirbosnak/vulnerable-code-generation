//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 365
#define MIN_TEMP -20
#define MAX_TEMP 50

struct City {
    char name[20];
    int temp;
};

void generate_weather(struct City *cities, int num_cities, int day) {
    for (int i = 0; i < num_cities; i++) {
        srand(time(NULL) + i);
        int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        cities[i].temp = temp;
    }
}

void print_weather(struct City *cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("%s: %d°C\n", cities[i].name, cities[i].temp);
    }
}

int main() {
    struct City cities[MAX_CITIES];
    int num_cities = 0;
    char city_name[20];

    printf("Enter the names of the cities (up to %d):\n", MAX_CITIES - 1);

    while (num_cities < MAX_CITIES && scanf("%s", city_name) == 1) {
        strcpy(cities[num_cities].name, city_name);
        num_cities++;
    }

    int num_days = 0;

    while (num_days < MAX_DAYS) {
        printf("\nDay %d:\n", num_days + 1);
        generate_weather(cities, num_cities, num_days);
        print_weather(cities, num_cities);
        num_days++;
        printf("\n");
    }

    return 0;
}