//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    char direction; // 'N', 'E', 'S', 'W'
} Vehicle;

void print_position(Vehicle v) {
    printf("Vehicle Position: (%d, %d) facing %c\n", v.x, v.y, v.direction);
}

void move_forward(Vehicle *v) {
    switch(v->direction) {
        case 'N': v->y += 1; break;
        case 'E': v->x += 1; break;
        case 'S': v->y -= 1; break;
        case 'W': v->x -= 1; break;
        default: break;
    }
}

void move_backward(Vehicle *v) {
    switch(v->direction) {
        case 'N': v->y -= 1; break;
        case 'E': v->x -= 1; break;
        case 'S': v->y += 1; break;
        case 'W': v->x += 1; break;
        default: break;
    }
}

void turn_left(Vehicle *v) {
    switch(v->direction) {
        case 'N': v->direction = 'W'; break;
        case 'E': v->direction = 'N'; break;
        case 'S': v->direction = 'E'; break;
        case 'W': v->direction = 'S'; break;
        default: break;
    }
}

void turn_right(Vehicle *v) {
    switch(v->direction) {
        case 'N': v->direction = 'E'; break;
        case 'E': v->direction = 'S'; break;
        case 'S': v->direction = 'W'; break;
        case 'W': v->direction = 'N'; break;
        default: break;
    }
}

void display_menu() {
    printf("\nRemote Control Vehicle Simulation Menu:\n");
    printf("1. Move Forward\n");
    printf("2. Move Backward\n");
    printf("3. Turn Left\n");
    printf("4. Turn Right\n");
    printf("5. Display Position\n");
    printf("6. Exit\n");
}

void control_vehicle(Vehicle *v) {
    int choice;
    display_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            move_forward(v);
            control_vehicle(v); // Recursive call
            break;
        case 2:
            move_backward(v);
            control_vehicle(v); // Recursive call
            break;
        case 3:
            turn_left(v);
            control_vehicle(v); // Recursive call
            break;
        case 4:
            turn_right(v);
            control_vehicle(v); // Recursive call
            break;
        case 5:
            print_position(*v);
            control_vehicle(v); // Recursive call
            break;
        case 6:
            printf("Exiting the simulation.\n");
            return;
        default:
            printf("Invalid choice. Please try again.\n");
            control_vehicle(v); // Recursive call
            break;
    }
}

int main() {
    Vehicle myVehicle = {0, 0, 'N'};
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    control_vehicle(&myVehicle); // Starting the vehicle control
    return 0;
}