//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

// define the duration of each traffic light phase in seconds
#define RED_DURATION 30
#define YELLOW_DURATION 5
#define GREEN_DURATION 60

// define the number of intersections
#define NUM_INTERSECTIONS 4

// define the intersections
struct intersection {
    int id;
    int phase;
    time_t next_change;
};

// initialize intersections
void init_intersections() {
    struct intersection intersections[NUM_INTERSECTIONS];
    for (int i = 0; i < NUM_INTERSECTIONS; i++) {
        intersections[i].id = i;
        intersections[i].phase = RED;
        intersections[i].next_change = time(NULL) + RED_DURATION;
    }
}

// update intersections
void update_intersections() {
    struct intersection intersections[NUM_INTERSECTIONS];
    time_t current_time = time(NULL);
    for (int i = 0; i < NUM_INTERSECTIONS; i++) {
        intersections[i].next_change = current_time + (intersections[i].phase == RED? RED_DURATION : (intersections[i].phase == YELLOW? YELLOW_DURATION : GREEN_DURATION));
        if (current_time >= intersections[i].next_change) {
            intersections[i].phase = (intersections[i].phase == RED? GREEN : (intersections[i].phase == YELLOW? RED : GREEN));
            intersections[i].next_change = current_time + (intersections[i].phase == RED? RED_DURATION : (intersections[i].phase == YELLOW? YELLOW_DURATION : GREEN_DURATION));
        }
    }
}

// print intersection status
void print_intersection_status(int intersection_id) {
    struct intersection intersections[NUM_INTERSECTIONS];
    for (int i = 0; i < NUM_INTERSECTIONS; i++) {
        if (intersections[i].id == intersection_id) {
            printf("Intersection %d: ", intersection_id);
            if (intersections[i].phase == RED) {
                printf("red light\n");
            } else if (intersections[i].phase == YELLOW) {
                printf("yellow light\n");
            } else {
                printf("green light\n");
            }
            return;
        }
    }
    printf("Invalid intersection ID\n");
}

int main() {
    srand(time(NULL));
    init_intersections();

    while (1) {
        system("clear");
        printf("Post-Apocalyptic Traffic Light Controller\n");
        printf("Intersection 1 (press 1): ");
        print_intersection_status(1);
        printf("Intersection 2 (press 2): ");
        print_intersection_status(2);
        printf("Intersection 3 (press 3): ");
        print_intersection_status(3);
        printf("Intersection 4 (press 4): ");
        print_intersection_status(4);
        int choice;
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4) {
            update_intersections();
        }
    }

    return 0;
}