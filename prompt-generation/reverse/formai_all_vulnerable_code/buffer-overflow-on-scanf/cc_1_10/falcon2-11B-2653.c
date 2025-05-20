//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROADS 100
#define MAX_VEHICLES 1000

int roads[MAX_ROADS][2];
int vehicles[MAX_VEHICLES];
int num_roads, num_vehicles;
int time;

void add_road(int x1, int y1, int x2, int y2) {
    roads[num_roads][0] = x1;
    roads[num_roads][1] = y1;
    roads[num_roads][2] = x2;
    roads[num_roads][3] = y2;
    num_roads++;
}

void add_vehicle(int x, int y) {
    vehicles[num_vehicles] = 0;
    vehicles[num_vehicles] = 0;
    vehicles[num_vehicles] = x;
    vehicles[num_vehicles] = y;
    num_vehicles++;
}

int get_closest_road(int x, int y) {
    int closest_distance = MAX_ROADS;
    int closest_road_index = -1;

    for (int i = 0; i < num_roads; i++) {
        int distance = sqrt((roads[i][0] - x) * (roads[i][0] - x) + (roads[i][1] - y) * (roads[i][1] - y));
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_road_index = i;
        }
    }
    return closest_road_index;
}

void move_vehicle(int x, int y, int closest_road_index) {
    int next_road_index = -1;
    double angle = atan2(y - roads[closest_road_index][1], x - roads[closest_road_index][0]);
    double distance = sqrt((x - roads[closest_road_index][0]) * (x - roads[closest_road_index][0]) + (y - roads[closest_road_index][1]) * (y - roads[closest_road_index][1]));
    double speed = 5.0;
    double time_to_move = distance / speed;

    while (time_to_move >= 0.1) {
        time_to_move -= 0.1;
        if (angle < 0.0) {
            angle += 2 * M_PI;
        } else {
            angle -= 2 * M_PI;
        }
        double dx = distance * cos(angle);
        double dy = distance * sin(angle);
        x += dx;
        y += dy;
        int road_index = get_closest_road(x, y);
        if (road_index!= -1) {
            next_road_index = road_index;
        } else {
            next_road_index = -1;
        }
    }

    vehicles[num_vehicles] = x;
    vehicles[num_vehicles] = y;
    vehicles[num_vehicles] = next_road_index;
    num_vehicles++;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n!= 0) {
        num_roads = 0;
        num_vehicles = 0;
        time = 0.0;
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            add_road(x1, y1, x2, y2);
        }
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            add_vehicle(x, y);
        }
        for (int i = 0; i < n; i++) {
            int x, y, road_index;
            scanf("%d %d %d", &x, &y, &road_index);
            move_vehicle(x, y, road_index);
        }
        printf("%d\n", num_vehicles - n);
        scanf("%d", &n);
    }
    return 0;
}