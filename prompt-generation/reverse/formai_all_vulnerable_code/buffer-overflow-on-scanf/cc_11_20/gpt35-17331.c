//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int car_x = 0, car_y = 0;

    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Use 'w' to move the car up, 's' to move the car down, 'a' to move the car left, and 'd' to move the car right.\n");
    printf("The car is currently at position (%d, %d).\n", car_x, car_y);

    while (1) {

        char input;
        scanf(" %c", &input);

        if (input == 'w') {
            car_y++;
        } else if (input == 's') {
            car_y--;
        } else if (input == 'a') {
            car_x--;
        } else if (input == 'd') {
            car_x++;
        }

        printf("The car is now at position (%d, %d).\n", car_x, car_y);

        if (car_x == 10 && car_y == 10) {
            printf("Congratulations! You have successfully navigated the car to the end point!\n");
            break;
        }

        if (car_x < 0 || car_x > 20 || car_y < 0 || car_y > 20) {
            printf("The car has gone out of bounds. Game over.\n");
            break;
        }

        int obstacle_x = rand() % 21;
        int obstacle_y = rand() % 21;

        if (car_x == obstacle_x && car_y == obstacle_y) {
            printf("The car has collided with an obstacle at position (%d, %d). Game over.\n", obstacle_x, obstacle_y);
            break;
        }

        if ((car_x + car_y) % 2 == 0) {
            printf("The car is on a safe zone.\n");
        } else {
            printf("Warning: The car is on an unsafe zone!\n");
        }
    }

    printf("Thanks for playing the Remote Control Vehicle Simulator!\n");

    return 0;
}