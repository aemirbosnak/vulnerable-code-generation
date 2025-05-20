//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int num_vehicles = rand() % 100 + 1;
    int total_time = 3600;
    int vehicle_speed = 30;
    int traffic_light_duration = 60;
    int vehicles_in_lane = 4;
    int vehicles_in_queue = 0;
    int i, j;

    int vehicles_in_road[] = {0};

    printf("Simulating Traffic Flow\n");

    for (i = 0; i < num_vehicles; i++) {
        vehicles_in_road[i] = 1;
    }

    printf("Simulation Started\n");

    for (j = 0; j < total_time; j++) {
        int vehicles_in_road_copy[num_vehicles];
        int vehicles_in_queue_copy;
        int vehicles_in_queue_copy_traffic_light;
        int vehicles_in_lane_copy;

        for (i = 0; i < num_vehicles; i++) {
            vehicles_in_road_copy[i] = vehicles_in_road[i];
        }

        vehicles_in_queue = 0;

        for (i = 0; i < num_vehicles; i++) {
            if (vehicles_in_road_copy[i] == 1) {
                vehicles_in_queue++;
            }
        }

        vehicles_in_queue_copy_traffic_light = 0;

        if (vehicles_in_queue > vehicles_in_lane - 1) {
            vehicles_in_queue_copy_traffic_light = vehicles_in_queue - (vehicles_in_lane - 1);
        }

        vehicles_in_queue = 0;

        for (i = 0; i < num_vehicles; i++) {
            if (vehicles_in_road_copy[i] == 1) {
                vehicles_in_queue++;
            }
        }

        vehicles_in_queue_copy_traffic_light += vehicles_in_queue;

        if (vehicles_in_queue_copy_traffic_light > vehicles_in_queue) {
            vehicles_in_queue_copy_traffic_light = vehicles_in_queue;
        }

        for (i = 0; i < num_vehicles; i++) {
            if (vehicles_in_road_copy[i] == 1) {
                vehicles_in_lane_copy = vehicles_in_lane;
                vehicles_in_lane_copy--;
                vehicles_in_road_copy[i] = 0;
            }
        }

        printf("\r%d", vehicles_in_queue_copy_traffic_light);
        fflush(stdout);

        sleep(traffic_light_duration);

        for (i = 0; i < num_vehicles; i++) {
            if (vehicles_in_road_copy[i] == 0) {
                vehicles_in_lane_copy = vehicles_in_lane;
                vehicles_in_lane_copy++;
                vehicles_in_road_copy[i] = 1;
            }
        }
    }

    printf("Simulation Completed\n");

    return 0;
}