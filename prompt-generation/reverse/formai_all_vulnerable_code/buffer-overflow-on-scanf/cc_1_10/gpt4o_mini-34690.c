//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void takeOff() {
    printf("\nDrone is taking off! 🚀\n\n");
    sleep(2);
    printf("Drone is now airborne! 🌤️\n");
}

void land() {
    printf("\nDrone is landing! 🛬\n\n");
    sleep(2);
    printf("Drone has successfully landed. 🕊️\n");
}

void fly(int altitude) {
    printf("\nDrone is flying at %d meters! 🌈\n", altitude);
    printf("Enjoy the view from up high! 🌍✨\n");
    sleep(1);
}

void maneuver(char direction) {
    switch(direction) {
        case 'l':
            printf("Drone is turning left! ⬅️\n");
            break;
        case 'r':
            printf("Drone is turning right! ➡️\n");
            break;
        case 'f':
            printf("Drone is moving forward! ⬆️\n");
            break;
        case 'b':
            printf("Drone is moving backward! ⬇️\n");
            break;
        default:
            printf("Invalid direction! Please choose l, r, f, or b.\n");
            return;
    }
    sleep(1);
    printf("Maneuver complete! ✨\n");
}

int main() {
    int choice;
    int altitude = 0;
    
    while(1) {
        printf("\n--- Drone Remote Control ---\n");
        printf("1. Take Off\n");
        printf("2. Fly\n");
        printf("3. Maneuver\n");
        printf("4. Land\n");
        printf("5. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Taking off
                takeOff();
                altitude = 100; // Set a default altitude
                fly(altitude); // Automatically fly after takeoff
                break;
            case 2:
                // Flying
                if (altitude > 0) {
                    fly(altitude);
                } else {
                    printf("Drone must be airborne before flying. ⛔\n");
                }
                break;
            case 3:
                // Maneuvering
                if (altitude > 0) {
                    char direction;
                    printf("Enter direction (l:left, r:right, f:forward, b:backward): ");
                    while ((getchar()) != '\n'); // Clear the buffer
                    scanf("%c", &direction);
                    maneuver(direction);
                } else {
                    printf("Drone must be airborne to maneuver. ⛔\n");
                }
                break;
            case 4:
                // Landing
                if (altitude > 0) {
                    land();
                    altitude = 0; // Reset altitude after landing
                } else {
                    printf("Drone is already on the ground. 🙅‍♂️\n");
                }
                break;
            case 5:
                // Exit the program
                printf("Shutting down the remote control system. 🔌\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select a valid option. ❗\n");
                break;
        }
    }
    return 0;
}