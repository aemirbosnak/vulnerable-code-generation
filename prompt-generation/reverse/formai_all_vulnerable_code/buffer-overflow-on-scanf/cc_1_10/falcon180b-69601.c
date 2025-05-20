//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to control the vehicle
void control_vehicle(int direction) {
    printf("Vehicle moving in %s direction\n", direction == 1? "forward" : "reverse");
}

// Function to simulate the sound of the vehicle
void simulate_sound() {
    printf("Brrrr...\n");
}

// Function to simulate the lights of the vehicle
void simulate_lights() {
    printf("Lights on!\n");
}

int main() {
    int choice;

    // Initializing the vehicle
    printf("Initializing the vehicle...\n");
    simulate_sound();
    simulate_lights();

    // Main menu
    while(1) {
        printf("\nMain menu:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handling the user's choice
        switch(choice) {
            case 1:
                control_vehicle(1);
                break;
            case 2:
                control_vehicle(2);
                break;
            case 3:
                printf("Turning left...\n");
                break;
            case 4:
                printf("Turning right...\n");
                break;
            case 5:
                printf("Vehicle stopped.\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}