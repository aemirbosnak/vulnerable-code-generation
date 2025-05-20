//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define COMMAND_BUFFER_SIZE 100
#define MAX_COMMANDS 10

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    TAKEOFF,
    LAND,
    INVALID
} CommandType;

typedef struct {
    CommandType commands[MAX_COMMANDS];
    int commandCount;
} DroneControl;

void initializeDrone(DroneControl *drone) {
    drone->commandCount = 0;
}

void printMenu() {
    printf("Drone Remote Control Menu:\n");
    printf("1. Move Forward\n");
    printf("2. Move Backward\n");
    printf("3. Move Left\n");
    printf("4. Move Right\n");
    printf("5. Take Off\n");
    printf("6. Land\n");
    printf("7. Exit\n");
}

CommandType getCommandFromInput(int input) {
    switch (input) {
        case 1: return FORWARD;
        case 2: return BACKWARD;
        case 3: return LEFT;
        case 4: return RIGHT;
        case 5: return TAKEOFF;
        case 6: return LAND;
        default: return INVALID;
    }
}

bool addCommand(DroneControl *drone, CommandType command) {
    if (drone->commandCount < MAX_COMMANDS) {
        drone->commands[drone->commandCount++] = command;
        return true;
    } else {
        printf("Command buffer full!\n");
        return false;
    }
}

void executeCommands(DroneControl *drone) {
    for (int i = 0; i < drone->commandCount; i++) {
        switch (drone->commands[i]) {
            case FORWARD:
                printf("Drone moving forward\n");
                break;
            case BACKWARD:
                printf("Drone moving backward\n");
                break;
            case LEFT:
                printf("Drone moving left\n");
                break;
            case RIGHT:
                printf("Drone moving right\n");
                break;
            case TAKEOFF:
                printf("Drone taking off\n");
                break;
            case LAND:
                printf("Drone landing\n");
                break;
            default:
                break;
        }
    }
    // Reset command count after execution
    drone->commandCount = 0;
}

int main() {
    DroneControl drone;
    initializeDrone(&drone);

    int input;

    while (true) {
        printMenu();
        
        if (scanf("%d", &input) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        CommandType command = getCommandFromInput(input);
        if (command == INVALID) {
            printf("Exiting the program.\n");
            break;
        }

        if (addCommand(&drone, command)) {
            printf("Command added successfully.\n");
            executeCommands(&drone);
        } else {
            printf("Failed to add command.\n");
        }
    }
    
    return 0;
}