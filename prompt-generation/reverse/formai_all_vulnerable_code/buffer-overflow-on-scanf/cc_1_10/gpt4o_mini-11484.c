//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 5

char map[MAP_SIZE][MAP_SIZE] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', 'S', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
};

int posX = 2;
int posY = 2;

void displayMap() {
    system("clear"); // Clear the terminal screen
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == posX && j == posY) {
                printf(" S ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void move(char direction) {
    if (direction == 'w' && posX > 0) {
        posX--;
    } else if (direction == 's' && posX < MAP_SIZE - 1) {
        posX++;
    } else if (direction == 'a' && posY > 0) {
        posY--;
    } else if (direction == 'd' && posY < MAP_SIZE - 1) {
        posY++;
    } else {
        printf("Invalid Move!\n");
        return;
    }
    displayMap();
}

void navigate() {
    char command[10];
    printf("Enter direction (w/a/s/d) to move, or 'exit' to stop: ");
    scanf("%s", command);

    if (strcmp(command, "exit") == 0) {
        printf("Navigation ended.\n");
        return;
    } else if (strcmp(command, "w") == 0 || strcmp(command, "a") == 0 || 
               strcmp(command, "s") == 0 || strcmp(command, "d") == 0) {
        move(command[0]);
    } else {
        printf("Invalid command!\n");
    }
    
    navigate(); // Recursive call
}

int main(void) {
    printf("Welcome to GPS Navigation Simulation!\n");
    printf("You start at position (2, 2) marked as 'S'.\n");
    displayMap();
    
    navigate(); // Start navigation

    return 0;
}