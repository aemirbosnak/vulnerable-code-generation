//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 365

struct city {
    char name[50];
    int x, y;
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
    int pressure[MAX_DAYS];
};

void generate_weather(int day, struct city *cities, int num_cities) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        int temp = rand() % 30 + 1;
        int hum = rand() % 90 + 10;
        int pres = rand() % 30 + 1;
        cities[i].temperature[day] = temp;
        cities[i].humidity[day] = hum;
        cities[i].pressure[day] = pres;
    }
}

void print_weather(int day, struct city *cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("City %s: Temperature %d°C, Humidity %d%%\n", cities[i].name, cities[i].temperature[day], cities[i].humidity[day]);
    }
}

int main() {
    struct city cities[MAX_CITIES];
    int num_cities = 0;

    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter city name %d: ", i+1);
        scanf("%s", cities[i].name);
        printf("Enter the coordinates of city %s (x y): ", cities[i].name);
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }

    int day = 1;
    while (day <= MAX_DAYS) {
        generate_weather(day, cities, num_cities);
        printf("Day %d weather:\n", day);
        print_weather(day, cities, num_cities);
        day++;
    }

    return 0;
}