//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100

struct City {
    int id;
    int x, y;
    int resources;
};

int getMaxResources(int numCities, struct City cities[]) {
    int maxResources = 0;
    for (int i = 0; i < numCities; i++) {
        if (cities[i].resources > maxResources) {
            maxResources = cities[i].resources;
        }
    }
    return maxResources;
}

void printCities(int numCities, struct City cities[]) {
    for (int i = 0; i < numCities; i++) {
        printf("City %d: (%d, %d) - Resources: %d\n", cities[i].id, cities[i].x, cities[i].y, cities[i].resources);
    }
}

int main() {
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    struct City cities[MAX_CITIES];
    for (int i = 0; i < numCities; i++) {
        printf("Enter the details for City %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &cities[i].id);
        printf("X-coordinate: ");
        scanf("%d", &cities[i].x);
        printf("Y-coordinate: ");
        scanf("%d", &cities[i].y);
        printf("Resources: ");
        scanf("%d", &cities[i].resources);
    }

    int maxResources = getMaxResources(numCities, cities);
    printf("The maximum resources available in the given cities are: %d\n", maxResources);

    return 0;
}