//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define LED_PIN 7  // Define LED pin to simulate drone indication
#define MAX_SPEED 100  // Define maximum speed

typedef enum {
    LAND,
    TAKE_OFF,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    TURN_LEFT,
    TURN_RIGHT,
    HOVER,
    EXIT
} Command;

struct Drone {
    int speed;
    int altitude;
    int led_status;
};

void initializeDrone(struct Drone *drone) {
    drone->speed = 0;
    drone->altitude = 0;
    drone->led_status = 0;
    printf("The drone is initialized and ready for commands, Holmes.\n");
}

void takeOff(struct Drone *drone) {
    if (drone->altitude == 0) {
        drone->altitude = 10;  // Ascending to 10 meters
        drone->led_status = 1;  // Indicate taking off
        printf("The drone takes off into the air, Watson! Altitude: %d m\n", drone->altitude);
    } else {
        printf("The drone is already airborne, my friend!\n");
    }
}

void land(struct Drone *drone) {
    if (drone->altitude > 0) {
        drone->altitude = 0;  // Descending to ground level
        drone->led_status = 0;  // Turn off LED
        printf("The drone gracefully lands, Watson!\n");
    } else {
        printf("The drone is already on the ground, no need for landing!\n");
    }
}

void moveForward(struct Drone *drone) {
    if (drone->altitude > 0) {
        printf("The drone moves forward with speed %d m/s, Watson!\n", drone->speed);
    } else {
        printf("The drone must take off first!\n");
    }
}

void moveBackward(struct Drone *drone) {
    if (drone->altitude > 0) {
        printf("The drone moves backward at speed %d m/s, Holmes!\n", drone->speed);
    } else {
        printf("The drone must take off before moving!\n");
    }
}

void turnLeft(struct Drone *drone) {
    if (drone->altitude > 0) {
        printf("The drone now turns left, adjusting direction!\n");
    } else {
        printf("The drone needs to be airborne to turn!\n");
    }
}

void turnRight(struct Drone *drone) {
    if (drone->altitude > 0) {
        printf("The drone turns right, Watson! Swift as a hawk!\n");
    } else {
        printf("The drone cannot turn while on the ground!\n");
    }
}

void hover(struct Drone *drone) {
    if (drone->altitude > 0) {
        printf("The drone hovers, suspended in the air like a mystery waiting to be solved!\n");
    } else {
        printf("The drone cannot hover without altitude!\n");
    }
}

void setSpeed(struct Drone *drone, int speed) {
    if (speed >= 0 && speed <= MAX_SPEED) {
        drone->speed = speed;
        printf("The drone's speed is set to %d m/s, Watson!\n", drone->speed);
    } else {
        printf("Speed must be between 0 and %d m/s!\n", MAX_SPEED);
    }
}

void displayMenu() {
    printf("\n--- Drone Control Menu ---\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Turn Left\n");
    printf("6. Turn Right\n");
    printf("7. Hover\n");
    printf("8. Set Speed\n");
    printf("9. Exit\n");
    printf("--------------------------\n");
    printf("Enter your choice: ");
}

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main() {
    struct Drone myDrone;
    int choice, speed;
    
    initializeDrone(&myDrone);

    while (1) {
        displayMenu();
        choice = getch() - '0';  // Convert char to int for menu selection
        
        switch (choice) {
            case 1:
                takeOff(&myDrone);
                break;
            case 2:
                land(&myDrone);
                break;
            case 3:
                moveForward(&myDrone);
                break;
            case 4:
                moveBackward(&myDrone);
                break;
            case 5:
                turnLeft(&myDrone);
                break;
            case 6:
                turnRight(&myDrone);
                break;
            case 7:
                hover(&myDrone);
                break;
            case 8:
                printf("Enter speed (0-%d): ", MAX_SPEED);
                scanf("%d", &speed);
                setSpeed(&myDrone, speed);
                break;
            case 9:
                printf("Exiting the drone control system, Watson. Until next time!\n");
                return 0;
            default:
                printf("Invalid choice, my dear Watson!\n");
                break;
        }
    }
    return 0;
}