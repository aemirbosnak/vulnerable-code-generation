//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

// define drone struct
typedef struct {
    int altitude;
    int battery_level;
    bool is_flying;
} drone;

// function to takeoff the drone
void takeoff(drone *my_drone) {
    if(my_drone->is_flying) {
        printf("Drone is already flying!\n");
        return;
    }
    my_drone->altitude = 10;
    my_drone->is_flying = true;
    printf("Drone is taking off...\n");
}

// function to land the drone
void land(drone *my_drone) {
    if(!my_drone->is_flying) {
        printf("Drone is already on the ground!\n");
        return;
    }
    my_drone->altitude = 0;
    my_drone->is_flying = false;
    printf("Drone is landing...\n");
}

// function to increase the altitude of the drone
void increase_altitude(drone *my_drone, int amount) {
    if(!my_drone->is_flying) {
        printf("Drone is not flying!\n");
        return;
    }
    my_drone->altitude += amount;
    printf("Altitude increased by %d meters!\n", amount);
}

// function to decrease the altitude of the drone
void decrease_altitude(drone *my_drone, int amount) {
    if(!my_drone->is_flying) {
        printf("Drone is not flying!\n");
        return;
    }
    if(my_drone->altitude - amount < 0) {
        printf("Cannot decrease altitude below 0 meters!\n");
        return;
    }
    my_drone->altitude -= amount;
    printf("Altitude decreased by %d meters!\n", amount);
}

// function to check the battery level of the drone
void check_battery_level(drone *my_drone) {
    printf("Battery level: %d%%\n", my_drone->battery_level);
}

int main() {
    drone my_drone = {0, 100, false};
    
    printf("Control the drone with the following commands:\n");
    printf("1 to takeoff | 2 to land | 3 to increase altitude | 4 to decrease altitude | 5 to check battery level | 0 to quit\n");
    
    int choice;
    while(true) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 0:
                printf("Quitting program...\n");
                return 0;
            
            case 1:
                takeoff(&my_drone);
                break;
            
            case 2:
                land(&my_drone);
                break;
            
            case 3:
                printf("How many meters to increase altitude? ");
                int increase_amount;
                scanf("%d", &increase_amount);
                increase_altitude(&my_drone, increase_amount);
                break;
            
            case 4:
                printf("How many meters to decrease altitude? ");
                int decrease_amount;
                scanf("%d", &decrease_amount);
                decrease_altitude(&my_drone, decrease_amount);
                break;
            
            case 5:
                check_battery_level(&my_drone);
                break;
            
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}