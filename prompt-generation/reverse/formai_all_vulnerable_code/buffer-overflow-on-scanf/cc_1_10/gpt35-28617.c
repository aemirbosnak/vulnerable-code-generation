//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the minimum and maximum values for pitch, roll, and yaw
#define MIN_PITCH -45
#define MAX_PITCH 45
#define MIN_ROLL -45
#define MAX_ROLL 45
#define MIN_YAW -180
#define MAX_YAW 180

// Define the function to check if the input is within the minimum and maximum
int check_input(int input, int min, int max) {
    if (input < min || input > max) {
        printf("ERROR: Input must be between %d and %d.\n", min, max);
        return 0;
    }
    return 1;
}

int main() {
    // Initialize the variables for pitch, roll, and yaw
    int pitch = 0;
    int roll = 0;
    int yaw = 0;

    // Create the welcome message and instructions
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Please enter the pitch, roll, and yaw values you would like to send to the drone.\n");
    printf("Pitch values must be between %d and %d.\n", MIN_PITCH, MAX_PITCH);
    printf("Roll values must be between %d and %d.\n", MIN_ROLL, MAX_ROLL);
    printf("Yaw values must be between %d and %d.\n", MIN_YAW, MAX_YAW);

    // Get the user input for pitch, roll, and yaw
    printf("Pitch: ");
    scanf("%d", &pitch);
    if (!check_input(pitch, MIN_PITCH, MAX_PITCH)) {
        return 1;
    }

    printf("Roll: ");
    scanf("%d", &roll);
    if (!check_input(roll, MIN_ROLL, MAX_ROLL)) {
        return 1;
    }

    printf("Yaw: ");
    scanf("%d", &yaw);
    if (!check_input(yaw, MIN_YAW, MAX_YAW)) {
        return 1;
    }

    // Print the values that will be sent to the drone
    printf("Sending values to drone:\n");
    printf("Pitch: %d\n", pitch);
    printf("Roll: %d\n", roll);
    printf("Yaw: %d\n", yaw);

    // Send the values to the drone
    // CODE TO SEND VALUES TO DRONE

    // Print the success message
    printf("Values sent to drone successfully!\n");

    return 0;
}