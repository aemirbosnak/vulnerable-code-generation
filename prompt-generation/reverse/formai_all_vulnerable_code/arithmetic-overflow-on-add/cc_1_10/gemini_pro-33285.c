//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROBOTS 100
#define NUM_MOVES 1000

// Robot struct
typedef struct {
    int x;
    int y;
    int direction; // 0 = up, 1 = right, 2 = down, 3 = left
} Robot;

// Function to move a robot in a given direction
void move_robot(Robot *robot, int direction) {
    switch (direction) {
        case 0: // up
            robot->y--;
            break;
        case 1: // right
            robot->x++;
            break;
        case 2: // down
            robot->y++;
            break;
        case 3: // left
            robot->x--;
            break;
    }
}

// Function to generate a random direction
int generate_random_direction() {
    return rand() % 4;
}

// Function to simulate the movement of robots
void simulate_robot_movement(Robot *robots, int num_robots, int num_moves) {
    for (int i = 0; i < num_moves; i++) {
        for (int j = 0; j < num_robots; j++) {
            // Generate a random direction for the robot to move in
            int direction = generate_random_direction();

            // Move the robot in the given direction
            move_robot(&robots[j], direction);
        }
    }
}

// Function to calculate the mean distance of the robots from the origin
double calculate_mean_distance(Robot *robots, int num_robots) {
    double total_distance = 0;

    for (int i = 0; i < num_robots; i++) {
        // Calculate the distance of the robot from the origin
        double distance = sqrt(robots[i].x * robots[i].x + robots[i].y * robots[i].y);

        // Add the distance to the total distance
        total_distance += distance;
    }

    // Calculate the mean distance
    double mean_distance = total_distance / num_robots;

    return mean_distance;
}

// Function to print the results of the simulation
void print_results(double mean_distance) {
    printf("The mean distance of the robots from the origin is: %f\n", mean_distance);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create an array of robots
    Robot robots[NUM_ROBOTS];

    // Simulate the movement of the robots
    simulate_robot_movement(robots, NUM_ROBOTS, NUM_MOVES);

    // Calculate the mean distance of the robots from the origin
    double mean_distance = calculate_mean_distance(robots, NUM_ROBOTS);

    // Print the results of the simulation
    print_results(mean_distance);

    return 0;
}