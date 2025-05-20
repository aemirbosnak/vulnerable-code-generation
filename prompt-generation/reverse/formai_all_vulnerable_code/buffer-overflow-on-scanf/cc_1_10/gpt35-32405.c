//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 1000.0 // maximum distance the drone can fly
#define MAX_SPEED 50.0 // maximum speed the drone can fly at
#define MIN_BATTERY 20.0 // minimum battery level for safe landing

struct drone {
    double distance_travelled;
    double battery_level;
    double current_speed;
    bool is_flying;
};

void print_status(struct drone my_drone) {
    printf("Current distance travelled: %.2lf\n", my_drone.distance_travelled);
    printf("Current battery level: %.2lf\n", my_drone.battery_level);
    printf("Current speed: %.2lf\n", my_drone.current_speed);
    printf("Current status: %s\n\n", my_drone.is_flying ? "Flying" : "Landed");
}

void take_off(struct drone* my_drone) {
    if (my_drone->is_flying) {
        printf("Error: drone is already flying\n\n");
    }
    else {
        printf("Taking off...\n");
        my_drone->is_flying = true;
        my_drone->current_speed = MAX_SPEED;
        printf("Drone is now flying\n\n");
    }
}

void land(struct drone* my_drone) {
    if (!my_drone->is_flying) {
        printf("Error: drone is already landed\n\n");
    }
    else if (my_drone->battery_level < MIN_BATTERY) {
        printf("Error: battery level too low for safe landing\n\n");
    }
    else {
        printf("Landing...\n");
        my_drone->is_flying = false;
        my_drone->current_speed = 0;
        printf("Drone has landed\n\n");
    }
}

void fly(struct drone* my_drone, double distance) {
    if (!my_drone->is_flying) {
        printf("Error: drone is not flying\n\n");
    }
    else if (distance <= 0) {
        printf("Error: distance must be greater than 0\n\n");
    }
    else if (my_drone->distance_travelled + distance > MAX_DISTANCE) {
        printf("Error: cannot fly that far, max distance is %.2lf\n\n", MAX_DISTANCE);
    }
    else {
        double time = distance / my_drone->current_speed;
        my_drone->distance_travelled += distance;
        my_drone->battery_level -= (distance / MAX_DISTANCE) * 100;
        
        printf("Flying for %.2lf seconds...\n", time);
        printf("Travelled %.2lf meters\n", distance);
        printf("Current distance travelled: %.2lf\n", my_drone->distance_travelled);
        printf("Current battery level: %.2lf\n\n", my_drone->battery_level);
        
        // random chance of battery dying mid-flight
        double random_num = ((double) rand() / RAND_MAX) * 100;
        if (random_num <= 5) {
            printf("Warning: battery level low, returning drone to base\n\n");
            land(my_drone);
        }
    }
}

int main() {
    struct drone my_drone = {
        .distance_travelled = 0,
        .battery_level = 100,
        .current_speed = 0,
        .is_flying = false
    };
    
    int choice;
    double distance;
    
    srand(time(0)); // for generating random number
    
    do {
        printf("---- Drone Remote Control ----\n\n");
        printf("1. Take off\n");
        printf("2. Land\n");
        printf("3. Fly\n");
        printf("4. Check status\n");
        printf("5. Quit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                take_off(&my_drone);
                break;
            case 2:
                land(&my_drone);
                break;
            case 3:
                printf("Enter distance to fly: ");
                scanf("%lf", &distance);
                fly(&my_drone, distance);
                break;
            case 4:
                print_status(my_drone);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Error: invalid choice\n\n");
        }
    } while (choice != 5);
    
    return 0;
}