//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to simulate the behavior of a smart home device
void simulate_smart_device(int device_id, int command) {
    printf("Device %d : Executing command %d\n", device_id, command);
    if (command == 1) {
        // Turn on the device
        printf("Device %d : On\n", device_id);
    } else if (command == 2) {
        // Turn off the device
        printf("Device %d : Off\n", device_id);
    } else {
        // Invalid command
        printf("Device %d : Invalid command\n", device_id);
    }
}

// Function to handle user input
void handle_user_input() {
    int device_id, command;
    printf("Enter the device ID (1-10): ");
    scanf("%d", &device_id);
    printf("Enter the command (1/2/3): ");
    scanf("%d", &command);
    simulate_smart_device(device_id, command);
}

// Main function
int main() {
    int choice;
    do {
        printf("1. Turn on device\n2. Turn off device\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                handle_user_input();
                break;
            case 2:
                handle_user_input();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}