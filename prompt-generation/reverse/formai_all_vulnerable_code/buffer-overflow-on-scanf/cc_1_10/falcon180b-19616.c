//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, speed;
    char direction;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please choose your vehicle:\n");
    printf("1. Car\n");
    printf("2. Truck\n");
    printf("3. Motorcycle\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have chosen a car.\n");
            break;
        case 2:
            printf("You have chosen a truck.\n");
            break;
        case 3:
            printf("You have chosen a motorcycle.\n");
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    printf("Please choose your speed:\n");
    printf("1. Slow\n");
    printf("2. Medium\n");
    printf("3. Fast\n");
    scanf("%d", &speed);

    printf("Please choose your direction:\n");
    printf("1. Forward\n");
    printf("2. Backward\n");
    scanf("%c", &direction);

    if(direction == '1') {
        printf("Your vehicle is going forward at %d speed.\n", speed);
    }
    else if(direction == '2') {
        printf("Your vehicle is going backward at %d speed.\n", speed);
    }
    else {
        printf("Invalid direction.\n");
    }

    return 0;
}