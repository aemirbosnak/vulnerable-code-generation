//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_ROADS 1000

typedef struct {
    int id;
    char name[50];
    double lat;
    double lon;
} City;

typedef struct {
    int id;
    int from_city_id;
    int to_city_id;
    double distance;
} Road;

City cities[MAX_CITIES];
Road roads[MAX_ROADS];

int num_cities = 0;
int num_roads = 0;

void generate_random_city() {
    int id = rand() % MAX_CITIES;
    while (id < 0 || id >= MAX_CITIES) {
        id = rand() % MAX_CITIES;
    }
    printf("Enter name of city %d: ", id);
    scanf("%s", cities[id].name);
    cities[id].id = id;
    cities[id].lat = rand() % 90 - 45;
    cities[id].lon = rand() % 180 - 90;
    num_cities++;
}

void generate_random_road() {
    int from_id, to_id;
    do {
        from_id = rand() % num_cities;
        to_id = rand() % num_cities;
    } while (from_id == to_id);
    roads[num_roads].id = num_roads;
    roads[num_roads].from_city_id = from_id;
    roads[num_roads].to_city_id = to_id;
    roads[num_roads].distance = hypot(cities[from_id].lat - cities[to_id].lat, cities[from_id].lon - cities[to_id].lon);
    num_roads++;
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX_CITIES; i++) {
        generate_random_city();
    }
    for (i = 0; i < MAX_ROADS; i++) {
        generate_random_road();
    }
    return 0;
}