//FormAI DATASET v1.0 Category: Smart home automation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to turn on the lights in the living room
void living_room_lights_on() {
    printf("Turning on living room lights\n");
}

// Function to turn off the lights in the living room
void living_room_lights_off() {
    printf("Turning off living room lights\n");
}

// Function to adjust the temperature in the living room
void adjust_living_room_temp(int temp) {
    printf("Setting living room temperature to %d degrees\n", temp);
}

// Function to lock the front door
void lock_front_door() {
    printf("Locking front door\n");
}

// Function to unlock the front door
void unlock_front_door() {
    printf("Unlocking front door\n");
}

int main() {
    int living_room_light_status = 0;      // 0 is off, 1 is on
    int living_room_temp = 70;             // Starting temperature is 70 degrees
    int front_door_locked = 1;             // 0 is unlocked, 1 is locked

    printf("Welcome to Smart Home\n\n");

    while (1) { // Infinite loop to keep the program running

        char choice;

        printf("Choose an option:\n");
        printf("1. Turn on living room lights\n");
        printf("2. Turn off living room lights\n");
        printf("3. Adjust living room temperature\n");
        printf("4. Lock front door\n");
        printf("5. Unlock front door\n");
        printf("6. Exit\n");

        scanf(" %c", &choice); // Scanning the user choice

        switch (choice) {
            case '1':  // turning on the living room lights
                if (living_room_light_status == 0) {   // Checking if the light is already on or not
                    living_room_lights_on();
                    living_room_light_status = 1;
                } else {
                    printf("Living room lights are already on\n");
                }
                break;

            case '2':  // Turning off the living room lights
                if (living_room_light_status == 1) {   // Checking if the light is already off or not
                    living_room_lights_off();
                    living_room_light_status = 0;
                } else {
                    printf("Living room lights are already off\n");
                }
                break;

            case '3':  // Adjusting the temperature in the living room
                printf("Enter the temperature you want to set (in degrees): ");
                scanf("%d", &living_room_temp);  // Scanning the user choice for the temperature
                adjust_living_room_temp(living_room_temp); // calling the function and passing temperature as an argument
                break;

            case '4':  // Locking the front door
                if (front_door_locked == 0) {   // Checking if the door is already locked or not
                    lock_front_door();
                    front_door_locked = 1;
                } else {
                    printf("Front door is already locked\n");
                }
                break;

            case '5':  // Unlocking the front door
                if (front_door_locked == 1) {   // Checking if the door is already unlocked or not
                    unlock_front_door();
                    front_door_locked = 0;
                } else {
                    printf("Front door is already unlocked\n");
                }
                break;

            case '6':  // Exiting the program
                printf("Exiting Smart Home\n");
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\n\n"); // Printing a new line after each iteration
    }

    return 0;
}