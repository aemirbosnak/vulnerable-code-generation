//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3
#define PED_REQUEST 4

#define MAX_ROADS 4
#define MAX_PED_REQUESTS 5

int road_status[MAX_ROADS] = {RED, RED, RED, RED};
int ped_request[MAX_PED_REQUESTS] = {0, 0, 0, 0, 0};
int road_counter[MAX_ROADS] = {0, 0, 0, 0};
int ped_counter[MAX_PED_REQUESTS] = {0, 0, 0, 0, 0};
int current_road = 0;

void init() {
    srand(time(NULL));
    for (int i = 0; i < MAX_ROADS; i++) {
        road_status[i] = RED;
    }
}

void change_road() {
    current_road++;
    if (current_road >= MAX_ROADS) {
        current_road = 0;
    }
}

void handle_ped_request() {
    int road = current_road;
    int status = road_status[road];
    if (status == RED) {
        road_status[road] = YELLOW;
        printf("Pedestrian request on road %d\n", road);
        ped_request[ped_counter[0]] = road;
        ped_counter[0]++;
    }
}

void handle_road_change() {
    int status = road_status[current_road];
    if (status == YELLOW) {
        road_status[current_road] = GREEN;
        printf("Road %d is now green\n", current_road);
    } else if (status == GREEN) {
        road_status[current_road] = RED;
        printf("Road %d is now red\n", current_road);
    }
}

int main() {
    init();
    while (1) {
        printf("Current road: %d\n", current_road);
        handle_ped_request();
        handle_road_change();
        sleep(1);
    }
    return 0;
}