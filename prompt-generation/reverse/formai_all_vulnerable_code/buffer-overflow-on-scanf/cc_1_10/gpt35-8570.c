//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// defining a struct for the vehicle with x and y axis values
struct Vehicle {
    int x;
    int y;
};

int main() {
    // creating a pointer to the struct
    struct Vehicle *car = (struct Vehicle*) malloc(sizeof(struct Vehicle));

    // setting initial x and y values
    car->x = 0;
    car->y = 0;

    // printing current position
    printf("Current position: X=%d, Y=%d\n", car->x, car->y);

    // moving the car based on user input
    int direction;
    printf("Enter direction to move the vehicle (1 for up, 2 for down, 3 for left, 4 for right): ");
    scanf("%d", &direction);

    switch(direction) {
        case 1:
            // move up
            car->y += 1;
            break;
        case 2:
            // move down
            car->y -= 1;
            break;
        case 3:
            // move left
            car->x -= 1;
            break;
        case 4:
            // move right
            car->x += 1;
            break;
        default:
            printf("Invalid input!\n");
            break;
    }
    
    // printing new position
    printf("New position: X=%d, Y=%d\n", car->x, car->y);

    free(car); // freeing memory
    return 0;
}