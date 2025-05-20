//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: protected
#include <stdio.h>
#include <stdbool.h>

// Function to validate user input
bool validateInput(int input, int max_value) {
    if (input < 0 || input > max_value) {
        printf("Invalid input. Please select a number between 0 and %d.\n", max_value);
        return false;
    }
    return true;
}

// Function to control drone movements
void controlDrone(int movement) {
    // Code to control drone movement based on input
    printf("Drone movement: %d\n", movement);
}

// Main function
int main() {
    int current_movement = 0;
    int max_movement = 10;
    int input;

    // Print instructions
    printf("Welcome to the Drone Controller!\n");
    printf("Use the number keys to control drone movements as follows:\n");
    printf("0 = Stop\n");
    printf("1 = Forward\n");
    printf("2 = Backward\n");
    printf("3 = Left\n");
    printf("4 = Right\n");

    // Loop to receive user input
    while (true) {
        // Print current drone movement
        printf("\nCurrent Movement: %d\n", current_movement);
      
        // Prompt user for input
        printf("Enter a number: ");
        scanf("%d", &input);
      
        // Validate user input
        if (validateInput(input, max_movement)) {
            // Update current drone movement
            current_movement = input;
          
            // Control drone movement based on input
            controlDrone(input);
        }
    }

    return 0;
}