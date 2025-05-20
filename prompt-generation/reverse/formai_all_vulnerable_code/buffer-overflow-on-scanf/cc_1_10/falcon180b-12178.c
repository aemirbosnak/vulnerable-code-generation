//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

struct City {
    char name[20];
    int temperature[MAX_DAYS];
    int precipitation[MAX_DAYS];
};

void generateWeather(struct City *city, int day) {
    int temp = rand() % 50 + 1;
    int precip = rand() % 11;

    city->temperature[day] = temp;
    city->precipitation[day] = precip;
}

void printWeather(struct City *city, int day) {
    printf("Day %d in %s: Temperature %d°C, Precipitation %dmm\n",
           day + 1, city->name, city->temperature[day], city->precipitation[day]);
}

int main() {
    srand(time(NULL));

    struct City cities[MAX_CITIES];

    for (int i = 0; i < MAX_CITIES; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);

        for (int j = 0; j < MAX_DAYS; j++) {
            generateWeather(&cities[i], j);
        }
    }

    int cityIndex, dayIndex;

    printf("Which city's weather forecast would you like to see? ");
    scanf("%d", &cityIndex);

    printf("For how many days? ");
    scanf("%d", &dayIndex);

    for (int i = 0; i < dayIndex; i++) {
        printWeather(&cities[cityIndex - 1], i);
    }

    return 0;
}