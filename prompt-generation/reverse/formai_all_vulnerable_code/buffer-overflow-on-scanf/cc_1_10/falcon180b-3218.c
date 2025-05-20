//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

#define INTERSECTION_SIZE 4
#define LIGHT_DELAY 3

int current_light = RED_LIGHT;
int light_countdown[INTERSECTION_SIZE] = {LIGHT_DELAY, LIGHT_DELAY, LIGHT_DELAY, LIGHT_DELAY};

void change_light(int intersection) {
    if (current_light == RED_LIGHT) {
        current_light = GREEN_LIGHT;
    } else if (current_light == GREEN_LIGHT) {
        current_light = YELLOW_LIGHT;
    } else if (current_light == YELLOW_LIGHT) {
        current_light = RED_LIGHT;
    }
}

void adjust_light_countdown(int intersection) {
    if (light_countdown[intersection] > 0) {
        light_countdown[intersection]--;
    }
}

void print_intersection(int intersection) {
    printf("Intersection %d:\n", intersection+1);
    if (current_light == RED_LIGHT) {
        printf("   Red light is on\n");
    } else if (current_light == YELLOW_LIGHT) {
        printf("   Yellow light is on\n");
    } else if (current_light == GREEN_LIGHT) {
        printf("   Green light is on\n");
    }
    printf("   Light countdown: %d\n\n", light_countdown[intersection]);
}

int main() {
    srand(time(NULL));
    int intersections[INTERSECTION_SIZE] = {0, 1, 2, 3};
    for (int i = 0; i < INTERSECTION_SIZE; i++) {
        current_light = RED_LIGHT;
        light_countdown[i] = LIGHT_DELAY;
    }

    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Change light\n");
        printf("2. Print intersection\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter intersection number: ");
                scanf("%d", &intersections[rand() % INTERSECTION_SIZE]);
                change_light(intersections[rand() % INTERSECTION_SIZE]);
                break;
            case 2:
                printf("Intersections:\n");
                for (int i = 0; i < INTERSECTION_SIZE; i++) {
                    print_intersection(i);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}