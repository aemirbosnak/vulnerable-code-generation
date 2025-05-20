//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_SIZE 30
#define CAR_GEN_PROB 0.5 // probability of generating a new car each second

// define the state of each cell in the road
enum cell_state {
    EMPTY,
    OCCUPIED,
    OUT_OF_BOUNDS
};

// define the direction a car can move in
enum direction {
    LEFT,
    RIGHT
};

// define a car as a struct with a position and direction
typedef struct car {
    int pos;
    enum direction dir;
} Car;

// function to print the state of the road
void print_road(enum cell_state road[ROAD_SIZE]) {
    for (int i = 0; i < ROAD_SIZE; i++) {
        switch (road[i]) {
            case EMPTY:
                printf("-");
                break;
            case OCCUPIED:
                printf("X");
                break;
            case OUT_OF_BOUNDS:
                printf("#");
                break;
        }
    }
    printf("\n");
}

// function to move a car one step in its direction
void move_car(Car *car) {
    if(car->dir == RIGHT) {
        car->pos++;
    } else {
        car->pos--;
    }
}

// function to generate a new car with random direction
Car generate_car() {
    Car car;
    car.dir = (rand() % 2) ? LEFT : RIGHT;
    car.pos = (car.dir == RIGHT) ? 0 : ROAD_SIZE-1;
    return car;
}

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // initialize road and place first car
    enum cell_state road[ROAD_SIZE];
    Car car = generate_car();
    road[car.pos] = OCCUPIED;
    
    // simulate traffic flow for 100 seconds
    for (int time = 0; time < 100; time++) {
        // generate new cars with probability CAR_GEN_PROB
        if ((double)rand() / RAND_MAX < CAR_GEN_PROB) {
            Car new_car = generate_car();
            if (road[new_car.pos] == EMPTY) {
                road[new_car.pos] = OCCUPIED;
            }
        }
        
        // move cars along the road
        for (int i = 0; i < ROAD_SIZE; i++) {
            if (road[i] == OCCUPIED) {
                move_car(&car);
                if (car.pos >= ROAD_SIZE) {
                    road[i] = EMPTY;
                } else {
                    road[car.pos] = OCCUPIED;
                    road[i] = EMPTY;
                }
            }
        }
        
        // print the state of the road at each time step
        print_road(road);
    }
    
    return 0;
}