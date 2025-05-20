//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define NORTH_SOUTH_STRAIGHT 0
#define EAST_WEST_STRAIGHT 1
#define NORTH_SOUTH_LEFT 2
#define EAST_WEST_LEFT 3

typedef struct {
    int direction;
    int light_color;
} Lane;

typedef struct {
    Lane north_south_left;
    Lane north_south_straight;
    Lane east_west_left;
    Lane east_west_straight;
} Intersection;

void init_intersection(Intersection* intersection, int mode) {
    switch(mode) {
        case 0:
            intersection->north_south_left.direction = NORTH_SOUTH_LEFT;
            intersection->north_south_left.light_color = GREEN;
            intersection->north_south_straight.direction = NORTH_SOUTH_STRAIGHT;
            intersection->north_south_straight.light_color = RED;
            intersection->east_west_left.direction = EAST_WEST_LEFT;
            intersection->east_west_left.light_color = RED;
            intersection->east_west_straight.direction = EAST_WEST_STRAIGHT;
            intersection->east_west_straight.light_color = GREEN;
            break;
        case 1:
            intersection->north_south_left.direction = NORTH_SOUTH_LEFT;
            intersection->north_south_left.light_color = RED;
            intersection->north_south_straight.direction = NORTH_SOUTH_STRAIGHT;
            intersection->north_south_straight.light_color = GREEN;
            intersection->east_west_left.direction = EAST_WEST_LEFT;
            intersection->east_west_left.light_color = GREEN;
            intersection->east_west_straight.direction = EAST_WEST_STRAIGHT;
            intersection->east_west_straight.light_color = RED;
            break;
    }
}

void print_lane(Lane lane) {
    switch(lane.direction) {
        case NORTH_SOUTH_STRAIGHT:
            printf("North-South Straight lane: ");
            break;
        case EAST_WEST_STRAIGHT:
            printf("East-West Straight lane: ");
            break;
        case NORTH_SOUTH_LEFT:
            printf("North-South Left lane: ");
            break;
        case EAST_WEST_LEFT:
            printf("East-West Left lane: ");
            break;
    }

    switch(lane.light_color) {
        case RED:
            printf("Red\n");
            break;
        case YELLOW:
            printf("Yellow\n");
            break;
        case GREEN:
            printf("Green\n");
            break;
    }
}

void print_intersection(Intersection intersection) {
    printf("\nIntersection Status:\n");
    print_lane(intersection.north_south_left);
    print_lane(intersection.north_south_straight);
    print_lane(intersection.east_west_left);
    print_lane(intersection.east_west_straight);
}

void update_light(Intersection* intersection) {
    switch(intersection->north_south_left.light_color) {
        case GREEN:
            intersection->north_south_left.light_color = YELLOW;
            break;
        case YELLOW:
            intersection->north_south_left.light_color = RED;
            intersection->north_south_straight.light_color = GREEN;
            break;
        case RED:
            intersection->north_south_left.light_color = GREEN;
            break;
    }

    switch(intersection->north_south_straight.light_color) {
        case GREEN:
            intersection->north_south_straight.light_color = YELLOW;
            break;
        case YELLOW:
            intersection->north_south_straight.light_color = RED;
            intersection->east_west_left.light_color = GREEN;
            break;
        case RED:
            intersection->north_south_straight.light_color = GREEN;
            break;
    }

    switch(intersection->east_west_left.light_color) {
        case GREEN:
            intersection->east_west_left.light_color = YELLOW;
            break;
        case YELLOW:
            intersection->east_west_left.light_color = RED;
            intersection->east_west_straight.light_color = GREEN;
            break;
        case RED:
            intersection->east_west_left.light_color = GREEN;
            break;
    }

    switch(intersection->east_west_straight.light_color) {
        case GREEN:
            intersection->east_west_straight.light_color = YELLOW;
            break;
        case YELLOW:
            intersection->east_west_straight.light_color = RED;
            intersection->north_south_left.light_color = GREEN;
            break;
        case RED:
            intersection->east_west_straight.light_color = GREEN;
            break;
    }
}

int main() {
    srand(time(NULL));
    int mode = rand() % 2;
    Intersection intersection;
    init_intersection(&intersection, mode);

    while(true) {
        print_intersection(intersection);
        update_light(&intersection);
        printf("\n");

        // Wait for 2 seconds
        clock_t start = clock();
        while((clock() - start) * 1000 / CLOCKS_PER_SEC < 2000);
    }

    return 0;
}