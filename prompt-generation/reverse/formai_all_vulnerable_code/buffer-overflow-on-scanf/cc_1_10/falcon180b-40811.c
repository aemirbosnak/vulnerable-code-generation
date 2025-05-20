//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELAY 100000 // 100ms delay

// Function to move the vehicle forward
void move_forward() {
    printf("Vehicle moving forward...\n");
    system("sleep 1"); // delay for 1 second
}

// Function to turn the vehicle left
void turn_left() {
    printf("Vehicle turning left...\n");
    system("sleep 1"); // delay for 1 second
}

// Function to turn the vehicle right
void turn_right() {
    printf("Vehicle turning right...\n");
    system("sleep 1"); // delay for 1 second
}

// Function to stop the vehicle
void stop_vehicle() {
    printf("Vehicle stopped...\n");
}

// Function to simulate the remote control functionality
void remote_control() {
    int choice;

    while(1) {
        printf("\nRemote Control Options:\n");
        printf("1. Move Forward\n");
        printf("2. Turn Left\n");
        printf("3. Turn Right\n");
        printf("4. Stop Vehicle\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move_forward();
                break;
            case 2:
                turn_left();
                break;
            case 3:
                turn_right();
                break;
            case 4:
                stop_vehicle();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice...\n");
        }

        system("sleep 1"); // delay for 1 second
    }
}

int main() {
    srand(time(NULL)); // initialize random seed

    remote_control(); // simulate remote control functionality

    return 0;
}