//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VEHICLES 5
#define NAME_LENGTH 20

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP,
    EXIT
} Command;

typedef struct {
    char name[NAME_LENGTH];
    int speed;
    int direction; // 0: Forward, 1: Backward
} Vehicle;

void initializeVehicle(Vehicle* v, const char* name);
void displayStatus(Vehicle* v);
void executeCommand(Vehicle* v, Command cmd);
void printMenu();
Command getUserCommand();

int main() {
    Vehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 0;
    Command command;

    printf("Welcome to the Remote Control Vehicle Simulation\n");
    
    while (vehicleCount < MAX_VEHICLES) {
        char name[NAME_LENGTH];
        printf("Entering a vehicle (up to %d vehicles) - Enter name (or 'done' to finish): ", MAX_VEHICLES);
        scanf("%s", name);
        
        if (strcmp(name, "done") == 0) break;
        
        initializeVehicle(&vehicles[vehicleCount], name);
        vehicleCount++;
    }

    printf("You have %d vehicles. Control them now!\n", vehicleCount);
    
    while (1) {
        printMenu();
        command = getUserCommand();

        if (command == EXIT) {
            printf("Exiting simulation...\n");
            break;
        }

        for (int i = 0; i < vehicleCount; i++) {
            executeCommand(&vehicles[i], command);
            displayStatus(&vehicles[i]);
        }
    }
    
    return 0;
}

void initializeVehicle(Vehicle* v, const char* name) {
    strncpy(v->name, name, NAME_LENGTH);
    v->speed = 0;
    v->direction = FORWARD;
    printf("Initialized vehicle: %s\n", v->name);
}

void displayStatus(Vehicle* v) {
    printf("Vehicle: %s | Speed: %d | Direction: %s\n", 
           v->name, 
           v->speed, 
           (v->direction == FORWARD) ? "Forward" : "Backward");
}

void executeCommand(Vehicle* v, Command cmd) {
    switch (cmd) {
        case FORWARD:
            v->speed += 5;
            v->direction = FORWARD;
            break;
        case BACKWARD:
            if (v->speed > 0) v->speed -= 5;
            v->direction = BACKWARD;
            break;
        case LEFT:
            printf("%s is turning left!\n", v->name);
            break;
        case RIGHT:
            printf("%s is turning right!\n", v->name);
            break;
        case STOP:
            v->speed = 0;
            printf("%s has stopped.\n", v->name);
            break;
        case EXIT:
            break; // Handled in the main loop
    }
}

void printMenu() {
    printf("Commands:\n");
    printf("0: Move Forward\n");
    printf("1: Move Backward\n");
    printf("2: Turn Left\n");
    printf("3: Turn Right\n");
    printf("4: Stop\n");
    printf("5: Exit\n");
    printf("Enter command: ");
}

Command getUserCommand() {
    int cmd;
    scanf("%d", &cmd);
    
    switch (cmd) {
        case 0: return FORWARD;
        case 1: return BACKWARD;
        case 2: return LEFT;
        case 3: return RIGHT;
        case 4: return STOP;
        case 5: return EXIT;
        default: 
            printf("Invalid command! Try again.\n");
            return STOP; // Default to stop
    }
}