//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Drone states
#define DRONE_IDLE 0
#define DRONE_FLYING 1

// Drone structure
typedef struct {
    int state;
    int x;
    int y;
} Drone;

// Function declarations
void initializeDrone(Drone *drone);
void displayDrone(Drone *drone);
void moveDrone(Drone *drone, char direction);
void shapeShift(int state);

// Main program
int main() {
    Drone myDrone;
    initializeDrone(&myDrone);

    char command[10];
    while (1) {
        displayDrone(&myDrone);
        printf("\nEnter command (FLY/LEFT/RIGHT/UP/DOWN/EXIT): ");
        scanf("%s", command);
        
        if (strcmp(command, "EXIT") == 0) {
            printf("Exiting the drone control system.\n");
            break;
        }
        
        if (strcmp(command, "FLY") == 0) {
            myDrone.state = DRONE_FLYING;
            shapeShift(myDrone.state);
        } else if (myDrone.state == DRONE_FLYING) {
            moveDrone(&myDrone, command[0]);
        } else {
            printf("Drone is idle. Please FLY it first.\n");
        }
        
        sleep(1); // Delay for better visualization
    }

    return 0;
}

// Function to initialize the drone
void initializeDrone(Drone *drone) {
    drone->state = DRONE_IDLE;
    drone->x = 0;
    drone->y = 0;
}

// Function to display the drone's position and state
void displayDrone(Drone *drone) {
    printf("Drone Position: (%d, %d) | State: %s\n", 
           drone->x, drone->y, drone->state == DRONE_FLYING ? "FLYING" : "IDLE");
}

// Function to move the drone based on user input
void moveDrone(Drone *drone, char direction) {
    switch(direction) {
        case 'L':
            drone->x--;
            printf("Moving LEFT!\n");
            break;
        case 'R':
            drone->x++;
            printf("Moving RIGHT!\n");
            break;
        case 'U':
            drone->y++;
            printf("Moving UP!\n");
            break;
        case 'D':
            drone->y--;
            printf("Moving DOWN!\n");
            break;
        default:
            printf("Invalid command. Use LEFT (L), RIGHT (R), UP (U), DOWN (D).\n");
            break;
    }
}

// Function that causes the drone to shape-shift based on its state
void shapeShift(int state) {
    if (state == DRONE_FLYING) {
        const char *shapes[] = {
            "     |\n"
            " ___|___ \n"
            "   /     \n",
            "  __/\n"
            " |  /\n"
            "  \\/ \n",
            "  /|\\\n"
            " / | \\\n"
            "   |   \n"
        };
        
        for (int i = 0; i < 3; i++) {
            system("clear"); // Clear the console
            printf("%s", shapes[i]);
            sleep(1); // Shape animation delay
        }
    }
}