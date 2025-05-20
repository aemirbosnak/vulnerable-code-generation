//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

int main() {
    int speed = 0;
    bool power = false;
    char input;

    printf("\nWelcome to the Remote Control Vehicle Simulation!\n");
    printf("Press 'p' to power on/off your vehicle and 's' to change the speed.\n");

    while(true) {
        printf("\nCurrent Speed: %d\n", speed);

        if(power) {
            printf("Your vehicle is currently on.\n");
        } else {
            printf("Your vehicle is currently off.\n");
        }

        printf("Enter your choice: ");
        scanf(" %c", &input);

        switch(input) {
            case 'p': 
                power = !power;
                break;
            case 's': 
                if(power) {
                    printf("Enter a speed between %d and %d: ", MIN_SPEED, MAX_SPEED);
                    scanf("%d", &speed);

                    if(speed < MIN_SPEED) {
                        speed = MIN_SPEED;
                    } else if(speed > MAX_SPEED) {
                        speed = MAX_SPEED;
                    }
                } else {
                    printf("Your vehicle is currently off. Please power on first.\n");
                }
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}