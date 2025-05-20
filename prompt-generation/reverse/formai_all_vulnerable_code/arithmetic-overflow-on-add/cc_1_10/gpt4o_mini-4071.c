//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function prototypes
void controlDrone(int altitude, int speed, int distance);
void ascend(int altitude, int speed, int distance);
void descend(int altitude, int speed, int distance);
void move_forward(int altitude, int speed, int distance);
void move_backward(int altitude, int speed, int distance);
void turn_left(int altitude, int speed, int distance);
void turn_right(int altitude, int speed, int distance);

// Main Function
int main() {
    int altitude = 0;
    int speed = 0;
    int distance = 0;

    printf("Enter initial altitude (0 to 100 meters): ");
    scanf("%d", &altitude);
    printf("Enter speed (0 to 30 m/s): ");
    scanf("%d", &speed);
    printf("Enter distance to cover (0 to 1000 meters): ");
    scanf("%d", &distance);

    printf("Initializing drone control...\n");
    controlDrone(altitude, speed, distance);

    return 0;
}

// Recursive function to control drone actions
void controlDrone(int altitude, int speed, int distance) {
    if (distance <= 0) {
        printf("Drone has reached the destination.\n");
        return;
    }

    printf("Current Altitude: %d m, Speed: %d m/s, Remaining Distance: %d m\n", 
            altitude, speed, distance);

    printf("Select an action (1: Ascend, 2: Descend, 3: Move Forward, 4: Move Backward, 5: Turn Left, 6: Turn Right, 0: Exit): ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            ascend(altitude, speed, distance);
            break;
        case 2:
            descend(altitude, speed, distance);
            break;
        case 3:
            move_forward(altitude, speed, distance);
            break;
        case 4:
            move_backward(altitude, speed, distance);
            break;
        case 5:
            turn_left(altitude, speed, distance);
            break;
        case 6:
            turn_right(altitude, speed, distance);
            break;
        case 0:
            printf("Exiting drone control program.\n");
            exit(0);
        default:
            printf("Invalid option! Please choose a valid action.\n");
            break;
    }
    
    // Continue control loop
    controlDrone(altitude, speed, distance);
}

// Function to ascend the drone
void ascend(int altitude, int speed, int distance) {
    if (altitude < 100) {
        altitude += 10; // Ascending 10 meters
        printf("Ascending... New Altitude: %d m\n", altitude);
    } else {
        printf("Already at max altitude of 100 m.\n");
    }
}

// Function to descend the drone
void descend(int altitude, int speed, int distance) {
    if (altitude > 0) {
        altitude -= 10; // Descending 10 meters
        printf("Descending... New Altitude: %d m\n", altitude);
    } else {
        printf("Already at ground level.\n");
    }
}

// Function to move the drone forward
void move_forward(int altitude, int speed, int distance) {
    if (distance > 0) {
        distance -= 20; // Moving 20 meters forward
        printf("Moving Forward... Remaining Distance: %d m\n", distance);
    } else {
        printf("No distance left to cover.\n");
    }
}

// Function to move the drone backward
void move_backward(int altitude, int speed, int distance) {
    distance += 20; // Moving 20 meters backward
    printf("Moving Backward... New Remaining Distance: %d m\n", distance);
}

// Function to turn the drone left
void turn_left(int altitude, int speed, int distance) {
    printf("Turning Left... Current Altitude: %d m\n", altitude);
}

// Function to turn the drone right
void turn_right(int altitude, int speed, int distance) {
    printf("Turning Right... Current Altitude: %d m\n", altitude);
}