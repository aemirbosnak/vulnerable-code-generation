//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Structure for the Remote Control Vehicle
typedef struct vehicle {
    int speed;
    int direction;
    int battery_level;
} Vehicle;

// Function to initialize the Vehicle
Vehicle initialize_vehicle(int speed, int direction, int battery_level) {
    Vehicle new_vehicle;
    new_vehicle.speed = speed;
    new_vehicle.direction = direction;
    new_vehicle.battery_level = battery_level;
    return new_vehicle;
}

// Function to display the Vehicle status
void display_vehicle_status(Vehicle vehicle) {
    printf("Speed: %d\nDirection: %d\nBattery Level: %d\n", vehicle.speed, vehicle.direction, vehicle.battery_level);
}

// Function to move the Vehicle forward
void move_forward(Vehicle* vehicle) {
    vehicle->direction = 1;
    vehicle->speed = 50;
    vehicle->battery_level -= 5;
}

// Function to move the Vehicle backward
void move_backward(Vehicle* vehicle) {
    vehicle->direction = -1;
    vehicle->speed = 30;
    vehicle->battery_level -= 3;
}

// Function to turn the Vehicle left
void turn_left(Vehicle* vehicle) {
    vehicle->direction -= 10;
    vehicle->battery_level -= 1;
}

// Function to turn the Vehicle right
void turn_right(Vehicle* vehicle) {
    vehicle->direction += 10;
    vehicle->battery_level -= 1;
}

int main() {
    // Initialize the Vehicle
    Vehicle rc_vehicle = initialize_vehicle(0, 0, 100);
    char choice;

    do {
        // Display the Vehicle Status
        printf("Vehicle Status:\n");
        display_vehicle_status(rc_vehicle);

        // Display the Menu
        printf("\n\nMenu\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Exit\n");

        printf("\n\nEnter Your Choice: ");
        scanf("%c", &choice);

        // Perform the selected action
        switch (choice) {
            case '1':
                move_forward(&rc_vehicle);
                break;

            case '2':
                move_backward(&rc_vehicle);
                break;

            case '3':
                turn_left(&rc_vehicle);
                break;

            case '4':
                turn_right(&rc_vehicle);
                break;

            case '5':
                break;
        }

        // Ignore unwanted characters from the input
        fflush(stdin);

        // Clear the Screen for better UI
        system("cls");

    } while (choice != '5');

    return 0;
}