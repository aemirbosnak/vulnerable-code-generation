//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846

// Drone remote control functions
void drone_takeoff() {
    printf("Drone takeoff...\n");
}

void drone_land() {
    printf("Drone landing...\n");
}

void drone_move_forward() {
    printf("Drone moving forward...\n");
}

void drone_move_backward() {
    printf("Drone moving backward...\n");
}

void drone_move_left() {
    printf("Drone moving left...\n");
}

void drone_move_right() {
    printf("Drone moving right...\n");
}

void drone_rotate_left() {
    printf("Drone rotating left...\n");
}

void drone_rotate_right() {
    printf("Drone rotating right...\n");
}

// Shape shifting functions
void shape_square() {
    printf("Shape shifting to square...\n");
}

void shape_circle() {
    printf("Shape shifting to circle...\n");
}

void shape_triangle() {
    printf("Shape shifting to triangle...\n");
}

// Main program
int main() {
    srand(time(NULL));

    // Drone remote control
    int choice_drone;
    printf("Enter 1 for takeoff, 2 for landing, 3 for forward, 4 for backward, 5 for left, 6 for right, 7 for rotate left, 8 for rotate right: ");
    scanf("%d", &choice_drone);

    switch (choice_drone) {
        case 1:
            drone_takeoff();
            break;
        case 2:
            drone_land();
            break;
        case 3:
            drone_move_forward();
            break;
        case 4:
            drone_move_backward();
            break;
        case 5:
            drone_move_left();
            break;
        case 6:
            drone_move_right();
            break;
        case 7:
            drone_rotate_left();
            break;
        case 8:
            drone_rotate_right();
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    // Shape shifting
    int choice_shape;
    printf("Enter 1 for square, 2 for circle, 3 for triangle: ");
    scanf("%d", &choice_shape);

    switch (choice_shape) {
        case 1:
            shape_square();
            break;
        case 2:
            shape_circle();
            break;
        case 3:
            shape_triangle();
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}