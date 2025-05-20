//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the traffic lights
void initialize_traffic_lights(int red_light, int yellow_light, int green_light) {
    printf("Initializing traffic lights\n");
    printf("Red light: %d\n", red_light);
    printf("Yellow light: %d\n", yellow_light);
    printf("Green light: %d\n", green_light);
}

// Function to control the traffic lights
void control_traffic_lights(int red_light, int yellow_light, int green_light) {
    printf("Controlling traffic lights\n");
    printf("Red light: %d\n", red_light);
    printf("Yellow light: %d\n", yellow_light);
    printf("Green light: %d\n", green_light);
}

// Function to handle user input
void handle_user_input(int red_light, int yellow_light, int green_light) {
    printf("Please enter the length of the cycle in seconds:\n");
    int cycle_length;
    scanf("%d", &cycle_length);

    printf("Please enter the initial state of the traffic lights (R, Y, G):\n");
    char initial_state;
    scanf(" %c", &initial_state);

    if (initial_state == 'R') {
        red_light = 1;
    } else if (initial_state == 'Y') {
        yellow_light = 1;
    } else if (initial_state == 'G') {
        green_light = 1;
    } else {
        printf("Invalid initial state\n");
        return;
    }

    printf("Initializing traffic lights with the following settings:\n");
    printf("Red light: %d\n", red_light);
    printf("Yellow light: %d\n", yellow_light);
    printf("Green light: %d\n", green_light);
}

// Function to print the current state of the traffic lights
void print_traffic_lights(int red_light, int yellow_light, int green_light) {
    printf("Current state of traffic lights:\n");
    printf("Red light: %d\n", red_light);
    printf("Yellow light: %d\n", yellow_light);
    printf("Green light: %d\n", green_light);
}

// Function to check if the user wants to continue or exit the program
void check_exit_conditions() {
    char continue_choice;
    printf("Do you want to continue (Y/N)?\n");
    scanf(" %c", &continue_choice);

    if (continue_choice == 'Y' || continue_choice == 'y') {
        return;
    } else if (continue_choice == 'N' || continue_choice == 'n') {
        printf("Exiting the program\n");
        return;
    } else {
        printf("Invalid choice\n");
        return;
    }
}

// Main function to call traffic light controller functions
int main() {
    int red_light = 0;
    int yellow_light = 0;
    int green_light = 0;

    initialize_traffic_lights(red_light, yellow_light, green_light);
    control_traffic_lights(red_light, yellow_light, green_light);
    handle_user_input(red_light, yellow_light, green_light);
    print_traffic_lights(red_light, yellow_light, green_light);
    check_exit_conditions();

    return 0;
}