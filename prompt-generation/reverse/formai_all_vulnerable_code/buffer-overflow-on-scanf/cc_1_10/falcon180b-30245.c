//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the remote control vehicle
typedef struct {
    int speed;
    int direction;
} Vehicle;

// Initialize the vehicle
void initVehicle(Vehicle* v) {
    v->speed = 0;
    v->direction = 0;
}

// Move the vehicle
void moveVehicle(Vehicle* v) {
    printf("Vehicle is moving...\n");
}

// Turn the vehicle
void turnVehicle(Vehicle* v) {
    printf("Vehicle is turning...\n");
}

// Stop the vehicle
void stopVehicle(Vehicle* v) {
    printf("Vehicle has stopped.\n");
}

// Define the remote control
typedef struct {
    int button;
    void (*function)(Vehicle*);
} Button;

// Initialize the remote control
void initRemote(Button buttons[], int numButtons) {
    for (int i = 0; i < numButtons; i++) {
        buttons[i].function = NULL;
    }
}

// Press a button on the remote control
void pressButton(Button buttons[], int numButtons, int buttonNumber) {
    if (buttonNumber >= 0 && buttonNumber < numButtons) {
        if (buttons[buttonNumber].function!= NULL) {
            buttons[buttonNumber].function(NULL);
        } else {
            printf("Button %d does nothing.\n", buttonNumber);
        }
    } else {
        printf("Invalid button number: %d\n", buttonNumber);
    }
}

// Simulate the remote control vehicle
void simulate(int speed, int direction) {
    Vehicle vehicle;
    initVehicle(&vehicle);

    Button buttons[3] = {
        {1, moveVehicle},
        {2, turnVehicle},
        {3, stopVehicle}
    };

    initRemote(buttons, 3);

    while (1) {
        int choice;
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            pressButton(buttons, 3, choice);
        } else if (choice == 4) {
            stopVehicle(&vehicle);
        } else {
            printf("Invalid choice: %d\n", choice);
        }

        usleep(100000); // Simulate a delay
    }
}

int main() {
    srand(time(NULL));
    int speed = rand() % 10 + 1;
    int direction = rand() % 360;

    printf("Simulating remote control vehicle...\n");
    printf("Initial speed: %d\n", speed);
    printf("Initial direction: %d degrees\n", direction);

    simulate(speed, direction);

    return 0;
}