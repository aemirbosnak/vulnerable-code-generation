//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

struct city {
    char name[20];
    int temperature[MAX_DAYS];
    int precipitation[MAX_DAYS];
    int windSpeed[MAX_DAYS];
};

void generateRandomWeather(struct city *city) {
    srand(time(NULL));
    for (int i = 0; i < MAX_DAYS; i++) {
        city->temperature[i] = rand() % 30 + 10;
        city->precipitation[i] = rand() % 10;
        city->windSpeed[i] = rand() % 20;
    }
}

void printWeather(struct city *city, int day) {
    printf("Weather in %s on day %d:\n", city->name, day);
    printf("Temperature: %d°C\n", city->temperature[day]);
    printf("Precipitation: %d mm\n", city->precipitation[day]);
    printf("Wind Speed: %d m/s\n", city->windSpeed[day]);
}

int main() {
    struct city cities[MAX_CITIES];
    int numCities;

    printf("How many cities do you want to simulate? (max %d)\n", MAX_CITIES);
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d:\n", i+1);
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i]);
    }

    int day;
    while (1) {
        printf("\nEnter day number to view weather (0 to exit):\n");
        scanf("%d", &day);
        if (day == 0) {
            break;
        }
        if (day > MAX_DAYS) {
            printf("Invalid day number.\n");
            continue;
        }
        for (int i = 0; i < numCities; i++) {
            printWeather(&cities[i], day);
        }
    }

    return 0;
}