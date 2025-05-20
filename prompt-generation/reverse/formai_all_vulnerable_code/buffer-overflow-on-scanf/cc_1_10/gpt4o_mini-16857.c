//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

void displayInstructions() {
    printf("GPS Navigation Simulation\n");
    printf("Commands:\n");
    printf("  'north' - Move Up\n");
    printf("  'south' - Move Down\n");
    printf("  'east' - Move Right\n");
    printf("  'west' - Move Left\n");
    printf("  'status' - Show Current Position\n");
    printf("  'exit' - Exit the program\n");
}

void displayPosition(Position pos) {
    printf("Current Position: (%d, %d)\n", pos.x, pos.y);
}

int isValidMove(Position pos) {
    return (pos.x >= 0 && pos.x < GRID_SIZE) && (pos.y >= 0 && pos.y < GRID_SIZE);
}

void move(Position *pos, const char *direction) {
    if (strcmp(direction, "north") == 0) {
        pos->y += 1;
    } else if (strcmp(direction, "south") == 0) {
        pos->y -= 1;
    } else if (strcmp(direction, "east") == 0) {
        pos->x += 1;
    } else if (strcmp(direction, "west") == 0) {
        pos->x -= 1;
    }

    if (!isValidMove(*pos)) {
        printf("Warning: You have moved out of bounds! Reverting to previous position.\n");
        if (strcmp(direction, "north") == 0) {
            pos->y -= 1;
        } else if (strcmp(direction, "south") == 0) {
            pos->y += 1;
        } else if (strcmp(direction, "east") == 0) {
            pos->x -= 1;
        } else if (strcmp(direction, "west") == 0) {
            pos->x += 1;
        }
    }
}

void gpsNavigation() {
    Position pos = { GRID_SIZE / 2, GRID_SIZE / 2 };
    char command[10];

    displayInstructions();
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting GPS Navigation Simulation.\n");
            break;
        } else if (strcmp(command, "status") == 0) {
            displayPosition(pos);
        } else if (strcmp(command, "north") == 0 || 
                   strcmp(command, "south") == 0 || 
                   strcmp(command, "east") == 0 || 
                   strcmp(command, "west") == 0) {
            move(&pos, command);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

int main() {
    gpsNavigation();
    return 0;
}