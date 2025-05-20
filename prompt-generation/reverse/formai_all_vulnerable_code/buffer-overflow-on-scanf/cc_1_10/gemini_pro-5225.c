//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_menu();
void move_forward();
void move_backward();
void turn_left();
void turn_right();
void exit_program();

// Main function
int main() {
    // Print the welcome message
    printf("Welcome to the RC Vehicle Simulator!\n");

    // Print the menu
    print_menu();

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // Loop until the user exits
    while (choice != 5) {
        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                move_forward();
                break;
            case 2:
                move_backward();
                break;
            case 3:
                turn_left();
                break;
            case 4:
                turn_right();
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }

        // Print the menu again
        print_menu();

        // Get the user's choice
        scanf("%d", &choice);
    }

    // Exit the program
    exit_program();

    return 0;
}

// Function to print the menu
void print_menu() {
    printf("\nPlease choose an option:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Exit\n");
}

// Function to move the vehicle forward
void move_forward() {
    printf("The vehicle is moving forward.\n");
}

// Function to move the vehicle backward
void move_backward() {
    printf("The vehicle is moving backward.\n");
}

// Function to turn the vehicle left
void turn_left() {
    printf("The vehicle is turning left.\n");
}

// Function to turn the vehicle right
void turn_right() {
    printf("The vehicle is turning right.\n");
}

// Function to exit the program
void exit_program() {
    printf("Thank you for using the RC Vehicle Simulator!\n");
}