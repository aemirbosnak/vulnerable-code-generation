//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

#define MAX_TRAFFIC 100
#define LEFT_LANE 0
#define RIGHT_LANE 1

void simulate_traffic(int traffic[], int num_cars);
void move_car(int traffic[], int pos);
void print_traffic(int traffic[], int num_cars);

int main() {
    int num_cars;
    int traffic[MAX_TRAFFIC];

    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    // set initial positions of cars
    for (int i=0; i<num_cars; i++) {
        if (i % 2 == 0) {
            traffic[i] = 0; // left lane
        } else {
            traffic[i] = 1; // right lane
        }
    }

    simulate_traffic(traffic, num_cars);

    return 0;
}

void simulate_traffic(int traffic[], int num_cars) {
    print_traffic(traffic, num_cars);

    // base case: all cars reached end of road
    int end_counter = 0;
    for (int i=0; i<num_cars; i++) {
        if (traffic[i] == 2) {
            end_counter++;
        }
    }
    if (end_counter == num_cars) {
        return;
    }

    // recursive case: move cars and simulate again
    for (int i=0; i<num_cars; i++) {
        if (traffic[i] != 2) {
            if (traffic[i] == LEFT_LANE) {
                move_car(traffic, i);
            } else if (traffic[i] == RIGHT_LANE) {
                move_car(traffic, i);
            }
        }
    }
    simulate_traffic(traffic, num_cars);
}

void move_car(int traffic[], int pos) {
    if (traffic[pos] == LEFT_LANE) {
        // check if car can switch lanes
        if (pos % 2 == 0 && traffic[pos+1] == 1) {
            traffic[pos] = RIGHT_LANE;
            traffic[pos+1] = LEFT_LANE;
        } else if (pos % 2 == 1 && traffic[pos-1] == 0) {
            traffic[pos] = RIGHT_LANE;
            traffic[pos-1] = LEFT_LANE;
        // otherwise move car forward
        } else {
            traffic[pos] = 1;
        }
    } else if (traffic[pos] == RIGHT_LANE) {
        // check if car can switch lanes
        if (pos % 2 == 1 && traffic[pos+1] == 0) {
            traffic[pos] = LEFT_LANE;
            traffic[pos+1] = RIGHT_LANE;
        } else if (pos % 2 == 0 && traffic[pos-1] == 1) {
            traffic[pos] = LEFT_LANE;
            traffic[pos-1] = RIGHT_LANE;
        // otherwise move car forward
        } else {
            traffic[pos] = 0;
        }
    }
}

void print_traffic(int traffic[], int num_cars) {
    for (int i=0; i<num_cars; i++) {
        if (traffic[i] == LEFT_LANE) {
            printf("<");
        } else if (traffic[i] == RIGHT_LANE) {
            printf(">");
        } else {
            printf("X");
        }
    }
    printf("\n");
}