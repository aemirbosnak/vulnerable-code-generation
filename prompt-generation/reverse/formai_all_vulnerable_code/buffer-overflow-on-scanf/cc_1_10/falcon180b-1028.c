//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the drone's current position
void print_position(int x, int y) {
    printf("Drone's current position: (%d, %d)\n", x, y);
}

// Function to move the drone
void move_drone(int dx, int dy, int *x, int *y) {
    *x += dx;
    *y += dy;
    if (*x < 0 || *x >= 10 || *y < 0 || *y >= 10) {
        printf("Drone crashed at position (%d, %d)\n", *x, *y);
        exit(1);
    }
}

// Function to take off the drone
void takeoff() {
    printf("Taking off...\n");
}

// Function to land the drone
void land() {
    printf("Landing...\n");
}

// Function to control the drone using the remote
void control_drone(int *x, int *y) {
    int choice;
    printf("Enter your choice:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Move left\n");
    printf("4. Move right\n");
    printf("5. Take off\n");
    printf("6. Land\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            move_drone(0, -1, x, y);
            break;
        case 2:
            move_drone(0, 1, x, y);
            break;
        case 3:
            move_drone(-1, 0, x, y);
            break;
        case 4:
            move_drone(1, 0, x, y);
            break;
        case 5:
            takeoff();
            break;
        case 6:
            land();
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    srand(time(NULL));
    int x = rand_num(0, 9);
    int y = rand_num(0, 9);

    printf("Welcome to the drone remote control!\n");
    printf("Your drone's initial position is (%d, %d)\n", x, y);

    while (1) {
        system("clear");
        print_position(x, y);
        control_drone(&x, &y);
    }

    return 0;
}