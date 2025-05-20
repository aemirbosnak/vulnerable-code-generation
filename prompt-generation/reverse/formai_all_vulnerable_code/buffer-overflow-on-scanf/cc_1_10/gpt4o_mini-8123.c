//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_VEHICLES 10
#define GRID_SIZE 10

typedef struct {
    int id;
    int x;
    int y;
} RemoteControlVehicle;

RemoteControlVehicle vehicles[MAX_VEHICLES];
int vehicleCount = 0;

void initializeVehicles() {
    for (int i = 0; i < MAX_VEHICLES; ++i) {
        vehicles[i].id = i + 1;
        vehicles[i].x = rand() % GRID_SIZE;
        vehicles[i].y = rand() % GRID_SIZE;
    }
    vehicleCount = MAX_VEHICLES;
}

void displayGrid() {
    char grid[GRID_SIZE][GRID_SIZE] = { ' ' };

    for (int i = 0; i < vehicleCount; ++i) {
        grid[vehicles[i].y][vehicles[i].x] = vehicles[i].id + '0'; // Convert ID to char
    }

    printf("\nGrid Status:\n");
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            printf("[%c]", grid[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(int newX, int newY) {
    return newX >= 0 && newY >= 0 && newX < GRID_SIZE && newY < GRID_SIZE;
}

void moveVehicle(int vehicleId, int dx, int dy) {
    for (int i = 0; i < vehicleCount; ++i) {
        if (vehicles[i].id == vehicleId) {
            int newX = vehicles[i].x + dx;
            int newY = vehicles[i].y + dy;
            if (isValidMove(newX, newY)) {
                vehicles[i].x = newX;
                vehicles[i].y = newY;
                printf("Vehicle %d moved to (%d, %d)\n", vehicleId, newX, newY);
            } else {
                printf("Invalid move for Vehicle %d!\n", vehicleId);
            }
            return;
        }
    }
    printf("Vehicle %d not found!\n", vehicleId);
}

void processCommand(char command) {
    int vehicleId, dx = 0, dy = 0;
    
    switch (command) {
        case 'W': dy = -1; break; // Move up
        case 'S': dy = 1; break;  // Move down
        case 'A': dx = -1; break; // Move left
        case 'D': dx = 1; break;  // Move right
        case 'Q': exit(0);        // Quit
        default: printf("Invalid command!\n"); return;
    }
    
    printf("Enter Vehicle ID to move: ");
    scanf("%d", &vehicleId);
    moveVehicle(vehicleId, dx, dy);
}

void startSimulation() {
    char command;
    while (1) {
        displayGrid();
        printf("Enter command (W/A/S/D to move, Q to quit): ");
        getchar(); // To consume newline character
        command = getchar();
        processCommand(command);
        sleep(1); // Sleep for a second to slow down simulation
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    initializeVehicles();
    startSimulation();
    return 0;
}