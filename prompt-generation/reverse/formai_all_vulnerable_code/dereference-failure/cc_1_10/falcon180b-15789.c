//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

//GPS Coordinates
struct GPS_Coordinates {
    double latitude;
    double longitude;
};

//GPS Point
struct GPS_Point {
    struct GPS_Coordinates coordinates;
    int visited;
};

//GPS Map
struct GPS_Map {
    struct GPS_Point **points;
    int size;
};

//Function to calculate distance between two GPS coordinates
double calculate_distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

//Function to initialize GPS Map
struct GPS_Map *initialize_map(int size) {
    struct GPS_Map *map = (struct GPS_Map *)malloc(sizeof(struct GPS_Map));
    map->size = size;
    map->points = (struct GPS_Point **)malloc(sizeof(struct GPS_Point *) * size);
    for(int i=0; i<size; i++) {
        map->points[i] = (struct GPS_Point *)malloc(sizeof(struct GPS_Point));
        map->points[i]->coordinates.latitude = 0;
        map->points[i]->coordinates.longitude = 0;
        map->points[i]->visited = 0;
    }
    return map;
}

//Function to add point to map
void add_point_to_map(struct GPS_Map *map, double lat, double lon) {
    int index = rand() % map->size;
    map->points[index]->coordinates.latitude = lat;
    map->points[index]->coordinates.longitude = lon;
    map->points[index]->visited = 1;
}

//Function to calculate shortest path between two points
void calculate_shortest_path(struct GPS_Map *map, int start, int end) {
    struct GPS_Point *current_point = map->points[start];
    struct GPS_Point *destination_point = map->points[end];
    double shortest_distance = calculate_distance(current_point->coordinates.latitude, current_point->coordinates.longitude, destination_point->coordinates.latitude, destination_point->coordinates.longitude);
    printf("Shortest distance between (%f, %f) and (%f, %f) is %f\n", current_point->coordinates.latitude, current_point->coordinates.longitude, destination_point->coordinates.latitude, destination_point->coordinates.longitude, shortest_distance);
}

//Main function
int main() {
    int size = 10;
    struct GPS_Map *map = initialize_map(size);
    for(int i=0; i<size; i++) {
        add_point_to_map(map, rand() % 90 + 1, rand() % 180 + 1);
    }
    int start = rand() % size;
    int end = rand() % size;
    calculate_shortest_path(map, start, end);
    return 0;
}