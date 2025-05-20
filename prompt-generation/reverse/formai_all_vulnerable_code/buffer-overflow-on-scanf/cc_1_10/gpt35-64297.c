//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Global variable to store the current location
int current_location = 0;

// Function to print the menu for navigation options
void print_menu() {
    printf("\n GPS Navigation Simulation\n");
    printf("------------------------------\n");
    printf("Current Location: %d\n", current_location);
    printf("1. Go North\n");
    printf("2. Go South\n");
    printf("3. Go East\n");
    printf("4. Go West\n");
    printf("5. Check Location\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    printf("Starting GPS Navigation Simulation...\n");

    // Loop till user chooses to exit
    while (true) {
        print_menu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Go North
                current_location += 10;
                printf("You have arrived at Location %d\n", current_location);
                break;

            case 2: // Go South
                if (current_location - 10 >= 0) {
                    current_location -= 10;
                    printf("You have arrived at Location %d\n", current_location);
                } else {
                    printf("You cannot go further south.\n");
                }
                break;

            case 3: // Go East
                current_location++;
                printf("You have arrived at Location %d\n", current_location);
                break;

            case 4: // Go West
                if (current_location > 0) {
                    current_location--;
                    printf("You have arrived at Location %d\n", current_location);
                } else {
                    printf("You cannot go further west.\n");
                }
                break;

            case 5: // Check Location
                printf("You are currently at Location %d\n", current_location);
                break;

            case 6: // Exit
                printf("Exiting GPS Navigation Simulation...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}