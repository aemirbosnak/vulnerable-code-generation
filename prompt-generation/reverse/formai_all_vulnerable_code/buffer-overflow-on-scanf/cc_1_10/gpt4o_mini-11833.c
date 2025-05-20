//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent the Drone
typedef struct {
    int altitude;  // The altitude of the drone
    int direction; // The direction the drone is facing (in degrees)
    int speed;     // The speed of the drone
} Drone;

void initialize_drone(Drone* drone) {
    drone->altitude = 0;
    drone->direction = 0;
    drone->speed = 0;
    printf("The drone is initialized, hovering at a low altitude, resembling the calm before the detective storm...\n");
}

void takeoff(Drone* drone) {
    drone->altitude += 10; // Take off to an altitude of 10
    printf("The drone ascends into the air, taking flight with elegance... Altitude: %d meters\n", drone->altitude);
}

void land(Drone* drone) {
    if (drone->altitude > 0) {
        drone->altitude = 0; // Reset altitude to 0
        printf("Descending gracefully as a well-tuned plot comes to a swift conclusion. The drone lands.\n");
    } else {
        printf("The drone is already on the ground, like a well-worn case file.\n");
    }
}

void move_forward(Drone* drone) {
    printf("The drone moves forward with determination, cutting through the air...\n");
    drone->direction = (drone->direction + 0) % 360; // Continue forward
}

void change_direction(Drone* drone, int degrees) {
    drone->direction = (drone->direction + degrees) % 360;
    printf("The drone pivots, now facing %d degrees, like a detective turning a corner to follow a clue...\n", drone->direction);
}

void set_speed(Drone* drone, int speed) {
    if (speed >= 0 && speed <= 100) {
        drone->speed = speed;
        printf("The speed of the drone has been set to %d, an appropriate rate for weaving through mystery...\n", speed);
    } else {
        printf("Alas, the speed must be between 0 to 100; such is the dictate of aerodynamic justice!\n");
    }
}

void display_status(Drone* drone) {
    printf("Current drone status: \n");
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Direction: %d degrees\n", drone->direction);
    printf("Speed: %d\n", drone->speed);
}

int main() {
    Drone my_drone;
    initialize_drone(&my_drone);

    int choice, speed, dir;
    
    while (1) {
        printf("\n--- Drone Control Menu ---\n");
        printf("1. Take Off\n");
        printf("2. Land\n");
        printf("3. Move Forward\n");
        printf("4. Change Direction\n");
        printf("5. Set Speed\n");
        printf("6. Display Status\n");
        printf("7. Exit\n");
        printf("Please select an option: ");

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Only numbers are accepted. A moment's distraction can lead to a mystery of errors!\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                takeoff(&my_drone);
                break;
            case 2:
                land(&my_drone);
                break;
            case 3:
                move_forward(&my_drone);
                break;
            case 4:
                printf("Enter the degrees to change direction: ");
                if (scanf("%d", &dir) == 1) {
                    change_direction(&my_drone, dir);
                } else {
                    fprintf(stderr, "Alas, that doesn't appear to be a number... A simple arithmetic error, indeed.\n");
                    while(getchar() != '\n'); // Clear input buffer
                }
                break;
            case 5:
                printf("Enter speed (0-100): ");
                if (scanf("%d", &speed) == 1) {
                    set_speed(&my_drone, speed);
                } else {
                    fprintf(stderr, "Again, numbers escape you like an elusive villain!\n");
                    while(getchar() != '\n');
                }
                break;
            case 6:
                display_status(&my_drone);
                break;
            case 7:
                printf("Exiting... As the case comes to a close, we shall few ourselves away.\n");
                exit(0);
                break;
            default:
                printf("That option beckons no sense! Please select a valid one; logic is a fine companion in any case.\n");
        }
    }
    return 0;
}