//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a drone's position
void print_drone_position(int x, int y, char direction) {
    printf("Drone is at (%d, %d) facing %c\n", x, y, direction);
}

// Function to move the drone
void move_drone(int *x, int *y, char direction) {
    int dx, dy;

    switch (direction) {
        case 'N':
            dy = -1;
            break;
        case 'S':
            dy = 1;
            break;
        case 'E':
            dx = 1;
            break;
        case 'W':
            dx = -1;
            break;
        default:
            printf("Invalid direction\n");
            return;
    }

    (*x) += dx;
    (*y) += dy;
}

int main() {
    srand(time(NULL));

    int x = 0, y = 0;
    char direction = 'N';

    while (1) {
        system("clear");
        print_drone_position(x, y, direction);

        int choice;
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_drone(&x, &y, direction);
                break;
            case 2:
                direction = (direction + 3) % 4;
                break;
            case 3:
                direction = (direction + 1) % 4;
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        usleep(100000); // Delay for smooth animation
    }

    return 0;
}