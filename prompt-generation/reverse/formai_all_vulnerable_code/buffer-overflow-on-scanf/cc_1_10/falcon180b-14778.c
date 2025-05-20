//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

void surreal_vehicle(int speed, int direction) {
    printf("Surreal Vehicle is moving at %d units per second in the %s direction.\n", speed, (direction == 1)? "forward" : "backward");
}

int main() {
    int choice, speed, direction;

    printf("Welcome to the Surreal Remote Control Vehicle Simulation!\n\n");

    while(1) {
        printf("Please enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        printf("6. Exit\n");

        if(scanf("%d", &choice)!= 1 || choice < 1 || choice > 6) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        switch(choice) {
            case 1:
                printf("Enter speed (1-10): ");
                if(scanf("%d", &speed)!= 1 || speed < 1 || speed > 10) {
                    printf("Invalid speed. Please try again.\n");
                    break;
                }
                surreal_vehicle(speed, 1);
                break;
            case 2:
                printf("Enter speed (1-10): ");
                if(scanf("%d", &speed)!= 1 || speed < 1 || speed > 10) {
                    printf("Invalid speed. Please try again.\n");
                    break;
                }
                surreal_vehicle(-speed, 1);
                break;
            case 3:
                surreal_vehicle(5, 2);
                break;
            case 4:
                surreal_vehicle(-5, 2);
                break;
            case 5:
                surreal_vehicle(0, 1);
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}