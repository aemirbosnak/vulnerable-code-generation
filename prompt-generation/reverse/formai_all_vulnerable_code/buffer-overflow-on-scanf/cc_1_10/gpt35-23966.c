//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include<stdio.h>
#include<math.h>

#define MAX_SIZE 100

double lat_to_rad(double lat) {
    /* Convert latitude to radians */
    return lat * M_PI / 180.0;
}

double long_to_rad(double lon) {
    /* Convert longitude to radians */
    return lon * M_PI / 180.0;
}

double haversine(double lat1, double lat2, double long1, double long2) {
    /* Calculate distance between two points on Earth's surface using Haversine formula */
    double lat1_rad = lat_to_rad(lat1), lat2_rad = lat_to_rad(lat2);
    double long1_rad = long_to_rad(long1), long2_rad = long_to_rad(long2);
    double lat_diff = lat2_rad - lat1_rad, long_diff = long2_rad - long1_rad;
    double a = pow(sin(lat_diff / 2), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(long_diff / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371000 * c; // Earth's radius = 6371000 m
    return distance;
}

int get_destination_index(double lat2, double long2, double lat[], double longitudes[], int size) {
    /* Get the index of destination location in arrays */
    int i, index = -1;
    double min_dist = INFINITY;
    for (i = 0; i < size; i++) {
        double curr_dist = haversine(lat2, lat[i], long2, longitudes[i]);
        if (curr_dist < min_dist) {
            min_dist = curr_dist;
            index = i;
        }
    }
    return index;
}

void print_route(int start, int end, int parent[], double lat[], double longitudes[]) {
    /* Print the route from start to end location using parents array*/
    int curr = end, i, path[MAX_SIZE], path_len = 0;
    while (curr != start) {
        path[path_len++] = curr;
        curr = parent[curr];
    }
    path[path_len++] = start;
    printf("Route:\n");
    for (i = path_len - 1; i >= 0; i--) {
        printf("%lf,%lf\n", lat[path[i]], longitudes[path[i]]);
    }
}

void shortest_path(double lat[], double longitudes[], int size, double lat1, double long1, double lat2, double long2) {
    int i, visited[MAX_SIZE], parent[MAX_SIZE], q[MAX_SIZE], start, end, curr, front = -1, rear = -1;
    double distance[MAX_SIZE];
    /* Initialize visited array to 0 */
    for (i = 0; i < size; i++) {
        visited[i] = 0;
    }
    /* Initialize distance array to infinity */
    for (i = 0; i < size; i++) {
        distance[i] = INFINITY;
    }
    /* Initialize parent array to -1 */
    for (i = 0; i < size; i++) {
        parent[i] = -1;
    }
    /* Get start and end indices */
    start = get_destination_index(lat1, long1, lat, longitudes, size);
    end = get_destination_index(lat2, long2, lat, longitudes, size);
    /* Add start vertex to queue and set its distance to 0 */
    q[++rear] = start;
    distance[start] = 0;
    visited[start] = 1;
    while (front != rear) {
        /* Dequeue vertex */
        curr = q[++front];
        for (i = 0; i < size; i++) {
            /* Check if vertex is adjacent */
            if (haversine(lat[curr], lat[i], longitudes[curr], longitudes[i]) != INFINITY) {
                /* Calculate the distance to the adjacent vertex */
                double dist = distance[curr] + haversine(lat[curr], lat[i], longitudes[curr], longitudes[i]);
                /* Check if the new distance is shorter than the stored distance */
                if (dist < distance[i]) {
                    distance[i] = dist;
                    parent[i] = curr;
                    if (!visited[i]) {
                        /* Add vertex to queue */
                        q[++rear] = i;
                        visited[i] = 1;
                    }
                }
            }
        }
    }
    print_route(start, end, parent, lat, longitudes);
}

int main() {
    /* Sample data */
    double lat[] = {38.8977, 38.8951, 40.7128, 34.0522};
    double longitudes[] = {-77.0366, -77.0364, -74.0060, -118.2437};
    int size = 4;
    double lat1, lat2, long1, long2;
    printf("Enter your current latitude: ");
    scanf("%lf", &lat1);
    printf("Enter your current longitude: ");
    scanf("%lf", &long1);
    printf("Enter your destination latitude: ");
    scanf("%lf", &lat2);
    printf("Enter your destination longitude: ");
    scanf("%lf", &long2);
    shortest_path(lat, longitudes, size, lat1, long1, lat2, long2);
    return 0;
}