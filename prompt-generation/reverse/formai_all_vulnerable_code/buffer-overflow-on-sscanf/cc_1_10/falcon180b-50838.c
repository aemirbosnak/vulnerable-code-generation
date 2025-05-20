//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_ROUTES 1000

typedef struct {
    char name[20];
    double lat;
    double lon;
} City;

typedef struct {
    int from;
    int to;
    double distance;
    double time;
} Route;

City cities[MAX_CITIES];
Route routes[MAX_ROUTES];
int num_cities, num_routes;

void read_cities(FILE *fp) {
    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %lf %lf", cities[num_cities].name, &cities[num_cities].lat, &cities[num_cities].lon);
        num_cities++;
    }
}

void calculate_distances() {
    for (int i = 0; i < num_cities; i++) {
        for (int j = i+1; j < num_cities; j++) {
            double dlat = cities[j].lat - cities[i].lat;
            double dlon = cities[j].lon - cities[i].lon;
            double a = sin(dlat/2) * sin(dlat/2) + cos(cities[i].lat) * cos(cities[j].lat) * sin(dlon/2) * sin(dlon/2);
            double c = 2 * atan2(sqrt(a), sqrt(1-a));
            routes[num_routes].distance = 6371 * c; // Earth's radius in km
            routes[num_routes].time = routes[num_routes].distance / 100; // Assuming 100 km/h speed limit
            routes[num_routes].from = i;
            routes[num_routes].to = j;
            num_routes++;
        }
    }
}

void print_routes() {
    for (int i = 0; i < num_routes; i++) {
        printf("%s -> %s: %.2f km, %.2f hours\n", cities[routes[i].from].name, cities[routes[i].to].name, routes[i].distance, routes[i].time);
    }
}

int main() {
    FILE *fp;
    fp = fopen("cities.txt", "r");
    if (fp == NULL) {
        printf("Error: cities.txt not found.\n");
        exit(1);
    }
    read_cities(fp);
    fclose(fp);

    calculate_distances();

    print_routes();

    return 0;
}