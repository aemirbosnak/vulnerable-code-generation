//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_ROADS 1000

typedef struct {
    int id;
    double lat;
    double lon;
} City;

typedef struct {
    int src;
    int dest;
    double distance;
} Road;

City cities[MAX_CITIES];
Road roads[MAX_ROADS];

void generate_cities(int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        cities[i].id = i;
        cities[i].lat = rand() % 180 - 90;
        cities[i].lon = rand() % 360 - 180;
    }
}

void generate_roads(int count) {
    for (int i = 0; i < count; i++) {
        int src = rand() % MAX_CITIES;
        int dest = rand() % MAX_CITIES;
        while (src == dest) {
            dest = rand() % MAX_CITIES;
        }
        roads[i].src = src;
        roads[i].dest = dest;
        roads[i].distance = hypot(cities[src].lat - cities[dest].lat, cities[src].lon - cities[dest].lon);
    }
}

int main() {
    int num_cities, num_roads;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);
    printf("Enter the number of roads: ");
    scanf("%d", &num_roads);

    generate_cities(num_cities);
    generate_roads(num_roads);

    return 0;
}