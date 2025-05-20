//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>

// Define a structure for the drone's position and speed
struct drone_position {
    int x;
    int y;
    int z;
    int speed;
};

// Define a structure for the remote control buttons
struct remote_control {
    int up;
    int down;
    int left;
    int right;
    int forward;
    int backward;
};

// Function to move the drone based on the remote control buttons pressed
void move_drone(struct drone_position *drone, struct remote_control *control) {
    if (control->up) {
        drone->z--;
    }
    if (control->down) {
        drone->z++;
    }
    if (control->left) {
        drone->x--;
    }
    if (control->right) {
        drone->x++;
    }
    if (control->forward) {
        drone->y--;
    }
    if (control->backward) {
        drone->y++;
    }
}

// Function to print the drone's position
void print_drone_position(struct drone_position *drone) {
    printf("Drone position: (%d, %d, %d)\n", drone->x, drone->y, drone->z);
}

// Function to print the remote control buttons
void print_remote_control(struct remote_control *control) {
    printf("Remote control:\n");
    printf("Up: %d\n", control->up);
    printf("Down: %d\n", control->down);
    printf("Left: %d\n", control->left);
    printf("Right: %d\n", control->right);
    printf("Forward: %d\n", control->forward);
    printf("Backward: %d\n", control->backward);
}

// Main function
int main() {
    // Initialize the drone's position
    struct drone_position drone = {0, 0, 0, 0};

    // Initialize the remote control buttons
    struct remote_control control = {0, 0, 0, 0, 0, 0};

    // Get user input for the remote control buttons
    printf("Enter remote control buttons:\n");
    scanf("%d%d%d%d%d%d", &control.up, &control.down, &control.left, &control.right, &control.forward, &control.backward);

    // Move the drone based on the remote control buttons
    move_drone(&drone, &control);

    // Print the drone's position
    print_drone_position(&drone);

    // Print the remote control buttons
    print_remote_control(&control);

    return 0;
}