//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>

int main() {
    // Initialize some variables for the elevator simulation
    int currentFloor = 1;
    int destinationFloor, elevatorWeight = 0;

    // Print a cheerful welcome message
    printf("Welcome to the joyful elevator simulation!\n");

    // Print out the current floor
    printf("You are currently on floor %d.\n", currentFloor);

    // Get the user's desired destination floor
    printf("What floor would you like to go to? ");
    scanf("%d", &destinationFloor);

    // Get the user's estimated weight
    printf("How much do you estimate that you weigh (in kg)? ");
    scanf("%d", &elevatorWeight);

    // Print out some fun elevator music
    printf("♪♪♪ ♫♫♫♪♪♪\n");

    // Simulate the elevator moving up or down floors
    while (currentFloor != destinationFloor) {
        if (currentFloor < destinationFloor) {
            currentFloor++;
            printf("Ding! The elevator is now on floor %d.\n", currentFloor);
        } else {
            currentFloor--;
            printf("Bing! The elevator is now on floor %d.\n", currentFloor);
        }
    }

    // Print a happy completion message
    printf("Congratulations! You have arrived at your destination on floor %d.\n", destinationFloor);

    // Simulate the elevator door opening and closing
    printf("The elevator door is opening. Please exit the elevator.\n");
    printf("The elevator door is closing.\n");

    // Print out some joyful elevator music
    printf("♪♪♪ ♫♫♫♪♪♪\n");

    // Print out the estimated weight of the user
    printf("By the way, you estimated that you weigh %d kg.\n", elevatorWeight);

    // Finish with a friendly goodbye message
    printf("Thanks for using the joyful elevator simulation! Goodbye!\n");

    return 0;
}