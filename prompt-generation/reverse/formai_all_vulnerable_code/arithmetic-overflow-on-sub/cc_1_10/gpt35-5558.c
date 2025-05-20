//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

#define MAX_HEIGHT 10000 //in millimeters
#define MAX_SPEED 500 // in km/hr
#define MAX_DISTANCE 5000 //in meters
#define MAX_BATTERY_LIFE 120 //in minutes

typedef struct {
    int height; //current height of drone in millimeters
    int speed; //current speed of drone in km/hr
    int distance_traveled; //distance traveled by drone in meters
    int battery_life; //remaining battery life of drone in minutes
} Drone;

void takeoff(Drone *d, int height) {
    if(height > MAX_HEIGHT) {
        printf("Error: Height cannot exceed maximum height of %d millimeters.\n", MAX_HEIGHT);
    }
    else {
        d->height = height;
        printf("Drone has taken off to a height of %d millimeters.\n", d->height);
    }
}

void land(Drone *d) {
    d->height = 0;
    printf("Drone has landed.\n");
}

void increase_speed(Drone *d, int speed) {
    if(speed > MAX_SPEED) {
        printf("Error: Speed cannot exceed maximum speed of %d km/hr.\n", MAX_SPEED);
    }
    else {
        d->speed = speed;
        printf("Drone has increased speed to %d km/hr.\n", d->speed);
    }
}

void decrease_speed(Drone *d, int speed) {
    if(speed < 0) {
        printf("Error: Speed cannot be negative.\n");
    }
    else {
        d->speed = speed;
        printf("Drone has decreased speed to %d km/hr.\n", d->speed);
    }
}

void move_forward(Drone *d, int distance) {
    if(distance + d->distance_traveled > MAX_DISTANCE) {
        printf("Error: Distance traveled cannot exceed maximum distance of %d meters.\n", MAX_DISTANCE);
    }
    else {
        d->distance_traveled += distance;
        printf("Drone has moved forward %d meters.\n", distance);
    }
}

void move_backward(Drone *d, int distance) {
    if(d->distance_traveled - distance < 0) {
        printf("Error: Distance traveled cannot be negative.\n");
    }
    else {
        d->distance_traveled -= distance;
        printf("Drone has moved backward %d meters.\n", distance);
    }
}

void decrease_battery_life(Drone *d, int time) {
    if(d->battery_life - time < 0) {
        printf("Error: Battery life cannot be negative.\n");
    }
    else {
        d->battery_life -= time;
        printf("Battery life has decreased to %d minutes.\n", d->battery_life);
    }
}

int main() {
    int choice, height, speed, distance, time;
    Drone d = {0, 0, 0, MAX_BATTERY_LIFE};
    
    printf("Drone Remote Control\n");
    printf("---------------------\n\n");
    
    do {
        printf("Current height: %d millimeters\n", d.height);
        printf("Current speed: %d km/hr\n", d.speed);
        printf("Current distance traveled: %d meters\n", d.distance_traveled);
        printf("Current battery life: %d minutes\n\n", d.battery_life);
        
        printf("Enter 1 to take off\n");
        printf("Enter 2 to land\n");
        printf("Enter 3 to increase speed\n");
        printf("Enter 4 to decrease speed\n");
        printf("Enter 5 to move forward\n");
        printf("Enter 6 to move backward\n");
        printf("Enter 7 to decrease battery life\n");
        printf("Enter 8 to quit\n");
        printf("Choice: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter height to take off to (in millimeters): ");
                scanf("%d", &height);
                takeoff(&d, height);
                break;
            case 2:
                land(&d);
                break;
            case 3:
                printf("Enter speed to increase to (in km/hr): ");
                scanf("%d", &speed);
                increase_speed(&d, speed);
                break;
            case 4:
                printf("Enter speed to decrease to (in km/hr): ");
                scanf("%d", &speed);
                decrease_speed(&d, speed);
                break;
            case 5:
                printf("Enter distance to move forward (in meters): ");
                scanf("%d", &distance);
                move_forward(&d, distance);
                break;
            case 6:
                printf("Enter distance to move backward (in meters): ");
                scanf("%d", &distance);
                move_backward(&d, distance);
                break;
            case 7:
                printf("Enter time to decrease battery life (in minutes): ");
                scanf("%d", &time);
                decrease_battery_life(&d, time);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
        
        printf("\n");
        
    } while(choice != 8);
    
    return 0;
}