//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

//Global variables
int xPos = 0;
int yPos = 0;

//Functions
void moveForward(int distance);
void moveBackward(int distance);
void moveLeft(int distance);
void moveRight(int distance);

int main() {
    int choice = 0;
    int distance = 0;
    bool exitFlag = false;
    
    printf("Welcome to RC Vehicle Simulation\n");
    
    do {
        printf("\n\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Move Left\n");
        printf("4. Move Right\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter distance (in meters): ");
                scanf("%d", &distance);
                moveForward(distance);
                break;
            case 2:
                printf("Enter distance (in meters): ");
                scanf("%d", &distance);
                moveBackward(distance);
                break;
            case 3:
                printf("Enter distance (in meters): ");
                scanf("%d", &distance);
                moveLeft(distance);
                break;
            case 4:
                printf("Enter distance (in meters): ");
                scanf("%d", &distance);
                moveRight(distance);
                break;
            case 5:
                exitFlag = true;
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(!exitFlag);
    
    printf("\nThank you for using RC Vehicle Simulation!\n");
    
    return 0;
}

void moveForward(int distance) {
    yPos += distance;
    printf("Vehicle moved forward %d meters. Current Position: (%d, %d)\n", distance, xPos, yPos);
}

void moveBackward(int distance) {
    yPos -= distance;
    printf("Vehicle moved backward %d meters. Current Position: (%d, %d)\n", distance, xPos, yPos);
}

void moveLeft(int distance) {
    xPos -= distance;
    printf("Vehicle moved left %d meters. Current Position: (%d, %d)\n", distance, xPos, yPos);
}

void moveRight(int distance) {
    xPos += distance;
    printf("Vehicle moved right %d meters. Current Position: (%d, %d)\n", distance, xPos, yPos);
}