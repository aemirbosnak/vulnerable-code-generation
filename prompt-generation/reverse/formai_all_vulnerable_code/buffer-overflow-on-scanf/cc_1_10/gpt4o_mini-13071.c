//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Drone action enums
typedef enum {
    TAKE_OFF,
    LAND,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    STATUS,
    EXIT
} Action;

// Drone structure
typedef struct {
    int altitude;
    int horizontal_position;
    int vertical_position;
    int is_flying;
} Drone;

// Function prototypes
void execute_action(Drone *drone, Action action);
void print_status(const Drone *drone);
Action get_user_action();

int main() {
    Drone drone = {0, 0, 0, 0}; // Initial state
    Action action;

    printf("Welcome to the Drone Remote Control Program!\n");

    while (1) {
        action = get_user_action();
        execute_action(&drone, action);
        
        if (action == EXIT) {
            printf("Exiting the Drone Remote Control Program. Goodbye!\n");
            break;
        }
    }

    return 0;
}

Action get_user_action() {
    int choice;
    printf("\nSelect an action:\n");
    printf("0: Take Off\n");
    printf("1: Land\n");
    printf("2: Move Up\n");
    printf("3: Move Down\n");
    printf("4: Move Left\n");
    printf("5: Move Right\n");
    printf("6: Status\n");
    printf("7: Exit\n");
    printf("Enter your choice: ");
    
    scanf("%d", &choice);
    return (Action)choice;
}

void execute_action(Drone *drone, Action action) {
    switch (action) {
        case TAKE_OFF:
            if (!drone->is_flying) {
                printf("Taking off...\n");
                drone->is_flying = 1;
                drone->altitude = 100; // Arbitrary altitude
            } else {
                printf("Drone is already flying!\n");
            }
            break;
        case LAND:
            if (drone->is_flying) {
                printf("Landing...\n");
                drone->is_flying = 0;
                drone->altitude = 0; // Reset altitude
            } else {
                printf("Drone is already on the ground.\n");
            }
            break;
        case MOVE_UP:
            if (drone->is_flying) {
                drone->altitude += 10;
                printf("Moving up to altitude: %d\n", drone->altitude);
            } else {
                printf("Drone must be flying to move up!\n");
            }
            break;
        case MOVE_DOWN:
            if (drone->is_flying && drone->altitude >= 10) {
                drone->altitude -= 10;
                printf("Moving down to altitude: %d\n", drone->altitude);
            } else {
                printf("Drone must be flying and above ground to move down!\n");
            }
            break;
        case MOVE_LEFT:
            if (drone->is_flying) {
                drone->horizontal_position -= 10;
                printf("Moving left to position: %d\n", drone->horizontal_position);
            } else {
                printf("Drone must be flying to move left!\n");
            }
            break;
        case MOVE_RIGHT:
            if (drone->is_flying) {
                drone->horizontal_position += 10;
                printf("Moving right to position: %d\n", drone->horizontal_position);
            } else {
                printf("Drone must be flying to move right!\n");
            }
            break;
        case STATUS:
            print_status(drone);
            break;
        case EXIT:
            // handled in main loop, do nothing here
            break;
        default:
            printf("Invalid action\n");
            break;
    }
}

void print_status(const Drone *drone) {
    printf("Drone Status:\n");
    printf("Flying: %s\n", drone->is_flying ? "Yes" : "No");
    printf("Altitude: %d\n", drone->altitude);
    printf("Horizontal Position: %d\n", drone->horizontal_position);
    printf("Vertical Position: %d\n", drone->vertical_position);
}