//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265359
#define R 6371.0
#define DEG_TO_RAD (PI/180.0)

struct point {
    double lat;
    double lon;
};

double distance(struct point p1, struct point p2) {
    double dlat = p2.lat - p1.lat;
    double dlon = p2.lon - p1.lon;
    double a = sin(dlat/2) * sin(dlat/2) + cos(p1.lat * DEG_TO_RAD) * cos(p2.lat * DEG_TO_RAD) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}

int main() {
    int num_points;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    struct point points[num_points];
    for (int i = 0; i < num_points; i++) {
        printf("Enter the latitude and longitude for point %d: ", i+1);
        scanf("%lf %lf", &points[i].lat, &points[i].lon);
    }

    int num_routes;
    printf("Enter the number of routes: ");
    scanf("%d", &num_routes);

    for (int i = 0; i < num_routes; i++) {
        int num_points_in_route;
        printf("Enter the number of points in route %d: ", i+1);
        scanf("%d", &num_points_in_route);

        struct point route[num_points_in_route];
        for (int j = 0; j < num_points_in_route; j++) {
            int point_index;
            printf("Enter the index of the %dth point in route %d: ", j+1, i+1);
            scanf("%d", &point_index);
            route[j] = points[point_index-1];
        }

        double total_distance = 0;
        for (int j = 0; j < num_points_in_route-1; j++) {
            total_distance += distance(route[j], route[j+1]);
        }

        printf("The total distance of route %d is %.2lf km.\n", i+1, total_distance);
    }

    return 0;
}