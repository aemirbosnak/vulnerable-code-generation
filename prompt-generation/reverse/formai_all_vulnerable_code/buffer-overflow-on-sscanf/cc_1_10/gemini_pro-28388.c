//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    double latitude;
    double longitude;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int num_points;
} Route;

Route load_route(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Route route;
    route.num_points = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        double latitude, longitude;
        if (sscanf(line, "%lf %lf", &latitude, &longitude) != 2) {
            fprintf(stderr, "Error parsing line: %s", line);
            continue;
        }

        route.points[route.num_points].latitude = latitude;
        route.points[route.num_points].longitude = longitude;
        route.num_points++;
    }

    fclose(fp);
    return route;
}

void print_route(const Route *route) {
    for (int i = 0; i < route->num_points; i++) {
        printf("%f %f\n", route->points[i].latitude, route->points[i].longitude);
    }
}

double distance(Point a, Point b) {
    double dx = a.longitude - b.longitude;
    double dy = a.latitude - b.latitude;
    return sqrt(dx * dx + dy * dy);
}

double total_distance(const Route *route) {
    double total = 0;
    for (int i = 1; i < route->num_points; i++) {
        total += distance(route->points[i - 1], route->points[i]);
    }
    return total;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <route_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    Route route = load_route(filename);

    printf("Loaded route with %d points.\n", route.num_points);
    print_route(&route);

    double total = total_distance(&route);
    printf("Total distance: %.2f km\n", total);

    return EXIT_SUCCESS;
}