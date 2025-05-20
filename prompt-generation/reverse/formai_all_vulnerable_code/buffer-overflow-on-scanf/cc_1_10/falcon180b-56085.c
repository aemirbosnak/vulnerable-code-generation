//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_UFOs 100
#define MAX_CITIES 100

struct UFO {
    int x;
    int y;
    int speed;
    int direction;
};

struct City {
    int x;
    int y;
    int population;
};

void initializeUFOs(struct UFO ufos[], int numUFOs) {
    srand(time(NULL));
    for (int i = 0; i < numUFOs; i++) {
        ufos[i].x = rand() % 100;
        ufos[i].y = rand() % 100;
        ufos[i].speed = rand() % 10 + 1;
        ufos[i].direction = rand() % 4;
    }
}

void initializeCities(struct City cities[], int numCities) {
    for (int i = 0; i < numCities; i++) {
        cities[i].x = rand() % 100;
        cities[i].y = rand() % 100;
        cities[i].population = rand() % 101;
    }
}

int isUFOInCity(struct UFO ufo, struct City city) {
    int distance = abs(ufo.x - city.x) + abs(ufo.y - city.y);
    return distance <= 10;
}

int main() {
    int numUFOs, numCities;
    printf("Enter the number of UFOs: ");
    scanf("%d", &numUFOs);
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    struct UFO ufos[MAX_UFOs];
    initializeUFOs(ufos, numUFOs);

    struct City cities[MAX_CITIES];
    initializeCities(cities, numCities);

    int invasionProbability = 0;
    for (int i = 0; i < numUFOs; i++) {
        for (int j = 0; j < numCities; j++) {
            if (isUFOInCity(ufos[i], cities[j])) {
                invasionProbability++;
                break;
            }
        }
    }

    printf("The probability of alien invasion is %d%%\n", invasionProbability * 10);

    return 0;
}